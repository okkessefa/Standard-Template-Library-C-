#include <iostream>
#include <map>
#include <unordered_map> 

int main()
{
    std::map<int, std::string> exampleMapOrder = {{1, "one"}, {2, "two"}, {3, "three"}};
    std::map<int, std::string>::iterator it_order;
    
    std::unordered_map<int, std::string> exampleMapUnorder = {{1, "one"}, {2, "two"}, {3, "three"}};
    std::unordered_map<int, std::string>::iterator it_unorder;

    std::cout<<"Ordered map: "<<std::endl;
    for(it_order = exampleMapOrder.begin(); it_order != exampleMapOrder.end(); ++it_order)
    {
        std::cout<<it_order->first <<": "<<it_order->second<<std::endl;
    }

    std::cout<<"############################################################"<<std::endl;

    std::cout<<"############################################################"<<std::endl;
    std::cout<<"Unordered map: "<<std::endl;
    for(it_unorder = exampleMapUnorder.begin(); it_unorder != exampleMapUnorder.end(); ++it_unorder)
    {
        std::cout<<it_unorder->first <<": "<<it_unorder->second<<std::endl;
    }

    return 0;
}



