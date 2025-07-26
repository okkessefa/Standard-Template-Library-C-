#include <iostream>
#include <map>

// Define a custom class representing a person
class Person {
public:
    std::string name;  // Name of the person
    int age;           // Age of the person

    // Constructor to initialize a Person object with a name and age
    Person(std::string name, int age) : name(name), age(age) {}

    // Comparison operator overload for use as a key in std::map
    // std::map requires the key type to be "less-than" comparable
    // This version compares based on age (numerical order)
    bool operator<(const Person& other) const {
        return age < other.age;  // You can switch to name < other.name for alphabetical ordering
    }
    // This version compares based on name (alphabetical order)
    // bool operator<(const Person& other) const { 
    //     return name < other.name;} // compare  alphabetical order 

};

int main()
{
    // Create a std::map where the key is a Person object and the value is their job title
    // The map will be sorted based on the Person's age due to the operator< implementation
    std::map<Person, std::string> PersonMap;

    // Insert entries into the map
    PersonMap[Person("Alice", 30)] = "Engineer";
    PersonMap[Person("Daniel", 23)] = "Designer";
    PersonMap[Person("Jane", 41)] = "Teacher";

    // Iterate through the map and print each entry
    // The order will follow the sorting logic defined in operator<
    for(const auto& pair : PersonMap){
        std::cout << pair.first.name << " is " << pair.first.age << " years old. "
                  << "Job: " << pair.second << std::endl;
    }

    return 0;
}
