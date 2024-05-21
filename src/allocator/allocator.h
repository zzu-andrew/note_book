//
// Created by andrew on 2024/5/19.
//

#ifndef NODE_BOOKS_SRC_ALLOCATOR_ALLOCATOR_H_
#define NODE_BOOKS_SRC_ALLOCATOR_ALLOCATOR_H_

#include <iostream>


// breaks if we make these template class members:



class Allocator {
public:
    enum {ALIGN = 8};
    enum {MAX_BYTES = 128};
    // 链表个数 128bytes需要定义如下16个类型的链表
    // 8 16 24 32 - 40 48 56 64 - 72 80 88 96 - 104 112 120 128
    enum {NFREELISTS = 16}; // _MAX_BYTES/_ALIGN

    // 按整字节进行取整，比如RoundUp(6) = 8
    static size_t RoundUp(size_t bytes) {
        return (((bytes) + (size_t) ALIGN-1) & ~((size_t) ALIGN - 1));
    }

    // 使用共同体，避免空闲链表和客户使用时出现内存浪费
    // 这里利用了C的两个特性，1. 首位对象的地址和结构体地址相同 2. 结尾的字符串可以用来引用结构体后面紧跟的数据
    union Obj {
        union Obj *lpFreeListLink {nullptr};   // 空闲内存链表
        char ClientData[1];      // 内存数据
    };
    // 计算所属链表的索引
    static size_t FreeListIndex(size_t bytes) {
        return (((bytes) + (size_t)ALIGN-1)/(size_t)ALIGN - 1);
    }

public:
    void* allocate(size_t size) {
        void* ret = nullptr;
        // 如果大于128字节，就直接申请内存
        if (size > (size_t)ALIGN) {
            return malloc(size);
        } else {
            auto freeListIndex = FreeListIndex(size);
            auto lpObjList = _freeListObject + freeListIndex;

            Obj* result = *lpObjList;
            if (nullptr == result) {
                // 申请一个8的倍数的内存给出去
                ret = Refill(RoundUp(size));
            } else {
                // 将空闲链表中的内存给出去
                *lpObjList = result->lpFreeListLink;
                ret = result;
            }
        }

        return ret;
    }

    void deallocate(void* lp, size_t size) {
        // 如果传入的为空，直接返回
        if (nullptr == lp) {
            return ;
        }
        // 小于128的才使用内存池
        if (size > MAX_BYTES) {
            free(lp);
        } else {
            // Obj * _freeListObject[NFREELISTS]; 中，_freeListObject相当于指向指针的指针
            auto freeListIndex = FreeListIndex(size);
            auto** lpObjList = _freeListObject + freeListIndex;
            Obj *lpObj = static_cast<Obj *>(lp);
            // 将释放的内存放到空闲链表中
            lpObj->lpFreeListLink = *lpObjList;
            *lpObjList = lpObj;
        }
    }


    void *Refill(size_t size) {
        // 一次性申请20个，因为内存本身就很小，没有必要每次都单独的申请
        int32_t objSize = 20;
        // 申请一大块内存，并按照同样大小进行切割，使用空闲链表串联起来
        char * lpChunk = ChunkAlloc(size, objSize);
        Obj * result;
        Obj * lpCurrentObj = nullptr;
        Obj * lpNextObj = nullptr;

        auto lpObjList = _freeListObject + FreeListIndex(size);

        // 内存池空间不足可能申请的大小可能小于20个
        if (1 == objSize) return lpChunk;
        result = (Obj *)lpChunk;

        // 当前的 *lpObjList一定是nullptr，因为只有nullptr的时候才会进来该函数
        *lpObjList = lpNextObj = (Obj *)(lpChunk + size);
        // 因为钱买取走一个，本身最后一个又需要指向空因此这里为 1开始， 19的时候，就需要将第十九个直接指向空
        for (int i = 1; ; i++) {
            lpCurrentObj = lpNextObj;
            lpNextObj = (Obj *)((char *)lpNextObj + size);

            // 因为已经取走了一个，这里第19个就得指向空
            if (objSize - 1 == i) {
                lpCurrentObj->lpFreeListLink = nullptr;
                break;
            } else {
                lpCurrentObj->lpFreeListLink = lpNextObj;
            }
        }

        return result;
    }

    // 内存池
    char *ChunkAlloc(size_t size, int& nobjs) {
        char * result = nullptr;
        // 计算出需要申请内存的总大小
        size_t totalSize = size * nobjs;
        size_t bytesLeft = _sEndFree - _sStartFree;

        if (bytesLeft >= totalSize) {
            // 如果空闲内存足够
            result = _sStartFree;
            _sStartFree += totalSize;
            return result;
        } else if (bytesLeft >= size) {
            // 内存池剩余量能满足一个以上的内存申请
            // 计算出能申请多少个
            nobjs = (int)(bytesLeft/size);
            // 重新计算需要总内存的大小
            totalSize = size * nobjs;
            result = _sStartFree;
            _sStartFree += totalSize;
            return result;
        } else {

            // 每次申请，申请出多余的内存，放入内存池
            size_t bytesToGet = 2 * totalSize + RoundUp(_heapSize >> 4);
            // 如果能走到这里说明空闲的内存池已经不够用了，但是重新申请内存会造成剩余内存的浪费(小于128bytes)
            if (bytesLeft > 0) {
                // 剩余的内存也肯定是8的倍数，将这些剩余的零头内存编入到内存池的空间
                auto lpObjList = _freeListObject + FreeListIndex(bytesLeft);
                ((Obj*)_sStartFree)->lpFreeListLink = *lpObjList;
                *lpObjList = (Obj*)_sStartFree;
            }

            _sStartFree = (char *)malloc(bytesToGet);
            if (nullptr == _sStartFree) {
                // 如果malloc已经不能申请出足够的内存，那么尝试使用现有资源来解决问题
                Obj** lpObjList = nullptr;
                Obj* lp = nullptr;

                // 这样做在多处理器的机器上可能会有问题(回调)
                for (size_t i = (size_t)MAX_BYTES; i < (size_t)ALIGN; i -= (size_t)ALIGN) {
                    lpObjList = _freeListObject + FreeListIndex(i);
                    lp = *lpObjList;

                    if (nullptr != lp) {
                        // 取出一个空闲的内存
                        *lpObjList = lp->lpFreeListLink;
                        _sStartFree = (char*)lp;
                        _sEndFree = _sStartFree + i;
                        // 递归调用，看是否能满足需求
                        return (ChunkAlloc(size, nobjs));
                    }
                }

                // 如果经过上述努力还是没有内存
                _sStartFree = nullptr;
                _sStartFree = (char *)allocate(bytesToGet);
                //     如果还是失败，这里抛出异常, 这里是假设一定成功
                //if (nullptr == _sStartFree)
            }

            _heapSize += bytesToGet;
            _sEndFree = _sStartFree + bytesToGet;

            // 内存已经申请好了，可以进行重新的分配了
            return ChunkAlloc(size, nobjs);
        }

    }



private:
    // 8 16 24 32 - 40 48 56 64 - 72 80 88 96 - 104 112 120 128 各个大小空闲链表存放
    Obj * _freeListObject[NFREELISTS]{};
    // 内存池使用
    char * _sStartFree{nullptr};
    char * _sEndFree{nullptr};
    size_t _heapSize{};
};

#endif //NODE_BOOKS_SRC_ALLOCATOR_ALLOCATOR_H_
