#ifndef FORWARDLIST_TPP
#define FORWARDLIST_TPP

#include "ForwardList.hpp"

template <typename T>
ForwardList<T>::ForwardList(std::pmr::memory_resource* mr) : allocator_(mr), head_(nullptr) {}

template <typename T>
ForwardList<T>::~ForwardList() {
    while (head_) {
        pop_front();
    }
}

template <typename T>
void ForwardList<T>::push_front(const T& value) {
    Node* new_node = allocator_.allocate(1);
    allocator_.construct(new_node, Node{value, head_});
    head_ = new_node;
}

template <typename T>
void ForwardList<T>::pop_front() {
    if (head_) {
        Node* old_head = head_;
        head_ = head_->next;
        std::allocator_traits<std::pmr::polymorphic_allocator<Node>>::destroy(allocator_, old_head);
        allocator_.deallocate(old_head, 1);
    }
}

template <typename T>
typename ForwardList<T>::Iterator ForwardList<T>::begin() {
    return Iterator(head_);
}

template <typename T>
typename ForwardList<T>::Iterator ForwardList<T>::end() {
    return Iterator(nullptr);
}

template <typename T>
class ForwardList<T>::Iterator {
public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T*;
    using reference = T&;

    Iterator(Node* node) : current_(node) {}

    reference operator*() const { return current_->data; }
    pointer operator->() const { return &current_->data; }

    Iterator& operator++() {
        current_ = current_->next;
        return *this;
    }

    Iterator operator++(int) {
        Iterator tmp = *this;
        ++(*this);
        return tmp;
    }

    bool operator==(const Iterator& other) const { return current_ == other.current_; }
    bool operator!=(const Iterator& other) const { return !(*this == other); }

private:
    Node* current_;
};

#endif // FORWARDLIST_TPP