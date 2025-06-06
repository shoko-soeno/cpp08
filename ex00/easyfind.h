#ifndef EASYFIND_H
#define EASYFIND_H
#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::const_iterator easyfind(const T &container, int value) {
    typename T::const_iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
        throw std::runtime_error("Value not found");
    }
    return it;
}

#endif
