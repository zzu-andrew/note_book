//
// Created by andrew on 2022/5/11.
//

#include <iostream>
#include <unordered_set>
#include <strings.h>
#include <map>
#include <algorithm>
#include <utility>
#include <vector>
#include <cassert>
#include <queue>
#include <cstring>
#include <list>
#include <memory>
#include <cmath>
#include <array>
#include <set>
#include <future>

using namespace std;

#include <unistd.h>
#include <unordered_map>


#include <iostream>
#include <string>
#include <tuple>
#include <thread>
#include <functional>
#include <algorithm>
#include <numeric> // std::accumulate
#include <mutex>



#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <cstdarg>
#include <unordered_map>

using namespace std;


#include <cstring>

typedef struct {
    uint32_t id;
} Row;


#define size_of_attribute(Struct, Attribute) sizeof(((Struct*)0)->Attribute)


int main(int argc, char **argv)
{

    char buffer[1024];
    strcpy(buffer, "insert data into new isndins");

    char *keyword = strtok(buffer, " ");
    char *id_string = strtok(nullptr, " ");
    char *username = strtok(nullptr, " ");
    char *email = strtok(nullptr, " ");

    std::cout <<  keyword << " " << id_string << " "  << username << " "  << email << " "  << std::endl;



    return 0;
}