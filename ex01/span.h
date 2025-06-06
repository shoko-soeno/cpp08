#ifndef SPAN_H
#define SPAN_H

#include <vector>
#include <set>
#include <stdexcept>

class Span {
public:
    Span();
    Span(unsigned int n);
    Span(const Span &src);
    ~Span();
    Span &operator=(const Span &src);

    template <class T>
    void addNumbers(T begin, T end) {
        if (vec_.size() + std::distance(begin, end) > capacity_)
            throw std::runtime_error("Span is full");
        for (T it = begin; it != end; ++it) {
            addNumber(*it);
        }
    }

    void addNumber(int num);
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;
    std::vector<int>::size_type size() const;

private:
    unsigned int capacity_;
    std::vector<int> vec_;
    std::multiset<unsigned int> span_;
};

#endif
