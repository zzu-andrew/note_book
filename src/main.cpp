//
// Created by andrew on 2022/5/11.
//

#include <iostream>
#include <unordered_set>
#include <strings.h>
#include <map>
#include <algorithm>
#include <vector>
#include <cassert>


using namespace std;
#include <unistd.h>


class DataProcess {
public:
    ~DataProcess() {
        delete []lpName;
    }


    void UseData(char* data) {

    }
    void CreateData() {
        auto data = new char[64];
        UseData(data);
    }

private:
    char *lpName{};
};

#define swiggo_size_assert_eq(x, y, name) typedef char name[(x-y)*(x-y)*-2+1];
#define swiggo_size_assert(t, n) swiggo_size_assert_eq(sizeof(t), n, swiggo_sizeof_##t##_is_not_##n)

int main(int argc, char *argv[]) {



    return 0;
}

