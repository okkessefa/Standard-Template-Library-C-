#include <iostream>
#include <map>
#include <unordered_map>

int main()
{
    std::map<int, std::string> exampleMap;

    exampleMap[1]  = "First";
    exampleMap[2]  = "Second";
    exampleMap[3]  = "Third";
    std::cout<<"Ordered Map: "<<std::endl;
    for(const auto& pair : exampleMap)
    {
        std::cout<< pair.first <<" : "<<pair.second<<std::endl;
    }
    std::cout<<"##################################################"<<std::endl;
    std::unordered_map<int, std::string> exampleUnorderedMap;

    exampleUnorderedMap[1]  = "First";
    exampleUnorderedMap[2]  = "Second";
    exampleUnorderedMap[3]  = "Third";

    std::cout<<"Unordered Map: "<<std::endl;
    for(const auto& pair : exampleUnorderedMap)
    {
        std::cout<< pair.first <<" : "<<pair.second<<std::endl;
    }

    return 0;
}