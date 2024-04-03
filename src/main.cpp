#include <cctype>
#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <map>
#include <utility>  // for std::forward()
#include <memory>

using namespace std;



class Entry {
public:
    Entry() {
        std::cout << "Entry created" << std::endl;
    }
    ~Entry() {
        std::cout << "Entry deleted" << std::endl;
    }

    static void ShowName() {
        std::cout << __FUNCTION__ << std::endl;
    }

    std::string* GetName() {
        return &name;
    }

    std::string* operator->() {
        return &name;
    }

private:
    std::string name = "functionname";

};


int main(int argc, char* argv[]) {



    {
        std::shared_ptr<Entry> entry(new Entry());
        entry->ShowName();
    }

    Entry  data;
    // 注意普通
    data.GetName()->data();






    return 0;
}
