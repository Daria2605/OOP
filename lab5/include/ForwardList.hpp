#ifndef FORWARDLIST_HPP
#define FORWARDLIST_HPP

#include <memory_resource>
#include <iterator>

template <typename T>
class ForwardList {
private:
    struct Node {
        T data;
        Node* next;
    };

public:
    using allocator_type = std::pmr::polymorphic_allocator<Node>;

    ForwardList(std::pmr::memory_resource* mr = std::pmr::get_default_resource());
    ~ForwardList();

    void push_front(const T& value);
    void pop_front();

    class Iterator;
    Iterator begin();
    Iterator end();

private:
    Node* head_;
    allocator_type allocator_;
};

#include "ForwardList.tpp"

#endif // FORWARDLIST_HPP