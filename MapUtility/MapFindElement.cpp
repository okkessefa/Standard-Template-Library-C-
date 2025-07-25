#include <iostream>
#include <map>


int main() 
{
    std::map<int, std::string> exampleMap = {{1, "one"}, {2, "two"}, {3, "three"}};
    auto it = exampleMap.find(2);
    if(it != exampleMap.end())
    {
        std::cout<<"Found: "<<it->first<<" -> " << it->second<< std::endl;
    }else
    {
        std::cout<<"Key not found"<<std::endl;
    }


    return 0;
}