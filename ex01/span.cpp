#include "span.h"
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <stdexcept>
#include <algorithm>
#include <cmath>

Span::Span() : capacity_(0) {}
Span::Span(unsigned int n) : capacity_(n) {}
Span::Span(const Span &src) : 
    capacity_(src.capacity_), 
    vec_(src.vec_), 
    span_(src.span_) {}

Span::~Span() {}
Span &Span::operator=(const Span &src) {
    if (this != &src) {
        capacity_ = src.capacity_;
        vec_ = src.vec_;
        span_ = src.span_;
    }
    return *this;
}

void Span::addNumber(int num) {
    if (vec_.size() >= capacity_) {
        throw std::runtime_error("Span is full");
    }
    if (!vec_.empty()) {
        long diff = static_cast<long>(num) - static_cast<long>(vec_.back());
        unsigned int abs_diff = static_cast<unsigned int>(std::abs(diff));
        span_.insert(abs_diff);
    }
    vec_.push_back(num);
}

unsigned int Span::shortestSpan() const {
    if (span_.empty()) {
        throw std::runtime_error("No span to calculate");
    }
    return *span_.begin();
}

unsigned int Span::longestSpan() const {
    if (span_.empty()) {
        throw std::runtime_error("No span to calculate");
    }
    return *span_.rbegin();
}

std::vector<int>::size_type Span::size() const {
    return vec_.size();
}
