#ifndef NODE_HPP
#define NODE_HPP

template <typename T>
class node {
public:
    node()              : next(0) {};
    node(const T& item) : data(item), next(0) {};
    T        data;
    node<T> *next;
};

#endif
