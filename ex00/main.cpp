#include "easyfind.h"
#include <iostream>
#include <vector>
#include <list>

int main()
{
    std::vector<int> vec(5);
    for (int i = 0; i < 5; ++i) {
        vec[i] = i + 1;
    }
    std::list<int> lst(5);
    for (int i = 0; i < 5; ++i) {
        lst.push_back(i * 5 + 5);
    }

    try {
        std::vector<int>::const_iterator itVec = easyfind(vec, 3);
        std::cout << "Found in vector: " << *itVec << std::endl;

        std::list<int>::const_iterator itLst = easyfind(lst, 20);
        std::cout << "Found in list: " << *itLst << std::endl;

        // This will throw an exception
        // easyfind(vec, 6);
        easyfind(lst, 50);
    } catch (const std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
