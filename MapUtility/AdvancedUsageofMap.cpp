#include <iostream>
#include <map>

// struct CustomCompare {
//     bool operator()(const int &lhs, const int &rhs) const {
//         return lhs < rhs;
//     }// look  at this usage
// };

// Custom opeartor to short by descending order (i.e. hightest score first)
struct DescendingCompare{
    bool operator()(const int& lhs, const int& rhs) const {
        return lhs > rhs; // Reversed from the defult : largest keys come first 
    }

};

int main(){

    // Map of scores to student names, sorted by descending score
    std::map<int, std::string, DescendingCompare> scoreMap;

    scoreMap[85] = "Person 1";
    scoreMap[93] = "Person 2";
    scoreMap[98] = "Person 3";
    scoreMap[90] = "Person 4";

    std::cout<<"Score in descending order: \n";

    for(const auto& pair : scoreMap){
        std::cout<< pair.second <<" scored "<< pair.first<<std::endl;
    }


    // std::map<int, std::string, CustomCompare> exampleMap = {{1, "one"}, {2, "two"}, {3, "three"}};
    // // look at this uage theree are 3 element
    // for(const auto &pair: exampleMap)
    // {
    //     std::cout<<pair.first<<" : "<<pair.second<<std::endl;
    // }



    return 0;
}