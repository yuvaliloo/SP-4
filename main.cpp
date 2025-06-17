#include <iostream>
#include "MyContainer.hpp"
#include "MyContainer_Iterators.hpp"

using namespace MyNamespace;

int main() {
    MyContainer<int> container;

    // Add elements
    container.add(7);
    container.add(15);
    container.add(6);
    container.add(1);
    container.add(2);

    std::cout << "Original Container: " << container << "\n";

    std::cout << "AscendingOrder: ";
    for (auto val : AscendingOrder<int>(container)) {
        std::cout << val << " ";
    }
    std::cout << "\n";

    std::cout << "DescendingOrder: ";
    for (auto val : DescendingOrder<int>(container)) {
        std::cout << val << " ";
    }
    std::cout << "\n";

    std::cout << "SideCrossOrder: ";
    for (auto val : SideCrossOrder<int>(container)) {
        std::cout << val << " ";
    }
    std::cout << "\n";

    std::cout << "ReverseOrder: ";
    for (auto val : ReverseOrder<int>(container)) {
        std::cout << val << " ";
    }
    std::cout << "\n";

    std::cout << "Order: ";
    for (auto val : Order<int>(container)) {
        std::cout << val << " ";
    }
    std::cout << "\n";

    std::cout << "MiddleOutOrder: ";
    for (auto val : MiddleOutOrder<int>(container)) {
        std::cout << val << " ";
    }
    std::cout << "\n";

    return 0;
}
