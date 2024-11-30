#include <iostream>
#include "FixedBlockMemoryResource.hpp"
#include "ForwardList.hpp"

int main() {
    FixedBlockMemoryResource mr(1024);
    ForwardList<int> list(&mr);

    list.push_front(1);
    list.push_front(2);
    list.push_front(3);

    for (int value : list) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    list.pop_front();

    for (int value : list) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}