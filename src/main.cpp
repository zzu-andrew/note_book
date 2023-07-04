//
// Created by andrew on 2022/5/11.
//

#include <iostream>
#include <strings.h>
#include <thread>
#include <unordered_map>
#include <exception>
#include <mutex>
#include <cstddef>
#include<ctime>



using namespace std;


int32_t BinarySearcher(const int32_t array[], int32_t left, int32_t right, int32_t key) {

    while (left < right) {
        int32_t mid = (left + right) / 2;
        if (key == array[mid]) {
            return mid;// key is found in array
        } else if (key > array[mid]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}


struct Vector2 {
    int x;
    int y;
};

std::ostream& operator<<(std::ostream& stream, const Vector2& vector) {
    stream << vector.x << ", " << vector.y;
    return stream;
}





int main(int argc, char **argv)
{
    Vector2 vector{1,2};

    std::cout << vector << std::endl;






    return 0;
}