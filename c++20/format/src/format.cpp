#include <iostream>
#include <string>
#include <memory>
#include <vector>

std::unique_ptr<int> grade = nullptr;

int *grade_leaked = nullptr; // memory leak

int main()
{
    std::vector<std::string> names = {"Alice", "Bob", "Charlie"};

    grade = std::make_unique<int>(100);

    grade_leaked = new int(101); // memory leak

    for (const auto& name : names) {
        std::cout << "Hello, " << name << "!" << std::endl;
    }

    std::cout << "grade, " << *grade << "!" << std::endl;
    std::cout << "grade, " << *grade_leaked << "!!!" << std::endl;

    // delete grade_leaked; // fix memory leak
    grade_leaked = nullptr;

    return 0;
}
