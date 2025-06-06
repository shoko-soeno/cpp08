#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H
#include <stack>

/*
std::stack does not provide iterators(begin/end),
but has a protected member `c` which is the underlying container.
container_type is usually std::deque, but can be std::vector or std::list.
MutantStack is a subclass of std::stack that provides iterators
*/

template <typename T>
class MutantStack : public std::stack<T> {
public:
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    MutantStack() : std::stack<T>() {}
    MutantStack(const MutantStack &src) : std::stack<T>(src) {}
    virtual ~MutantStack() {}
    MutantStack &operator=(const MutantStack &src) {
        if (this != &src)
            std::stack<T>::operator=(src);
        return *this;
    }
    
    iterator begin() { return this->c.begin();}
    iterator end() { return this->c.end();}
    const_iterator begin() const { return this->c.begin();}
    const_iterator end() const { return this->c.end();}
};

#endif
