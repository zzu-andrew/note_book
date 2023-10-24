#include <cctype>
#include <string>
#include <iostream>
#include "nlohmann/json.hpp"



int main() {

    std::string stringArr = R"({"code":100,"data":[{"box":[[29,14],[202,14],[202,32],[29,32]],"score":0.9177353382110596,"text":"\u79bb\u7ebfOCR\u7ec4\u4ef6\u7cfb\u5217\u9879\u76ee\uff1a"},{"box":[[40,52],[179,55],[179,70],[40,67]],"score":0.8905366063117981,"text":".PaddleoCR-json"},{"box":[[39,81],[170,81],[170,98],[39,98]],"score":0.8608772158622742,"text":"\u2022 RapidoCR-json"}]})";
    nlohmann::json json_array = nlohmann::json::parse(stringArr);
    if (json_array.find("data") == json_array.end())
    {
        std::cout << "data is not exist!" << std::endl;
        return 0;
    }
    nlohmann::json array = json_array["data"];
    std::cout << array.size() << std::endl;
    std::cout << array.dump() << std::endl;
    std::cout << array[0]["text"].get<std::string>() << std::endl;
    std::cout << array[1]["text"].get<std::string>() << std::endl;
    std::cout << array[2]["text"].get<std::string>() << std::endl;

    //for (const auto& element : array.items()) {
    //    std::cout << element.key() << element.value() << std::endl;
        //std::cout << element.value() << std::endl;
    //}


    return 0;
}
