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



int main(int argc, char *argv[]) {

    auto *lp = new DataProcess[4];


    delete[] lp;

    return 0;
}

