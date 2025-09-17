#include <bit>
#include <iostream>

struct student
{
    int id;
    char name[20];
};

int main()
{
    if constexpr (std::endian::native == std::endian::big)
        std::cout << "big-endian\n";
    else if constexpr (std::endian::native == std::endian::little)
        std::cout << "little-endian\n";
    else
        std::cout << "mixed-endian\n";

    std::cout << "size of student: " << sizeof(student) << '\n';
    std::cout << "align of student: " << alignof(student) << '\n';
    std::cout << "size of int " << sizeof(int) << '\n';
    return 0;
}