// MyContainer.hpp
#pragma once
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>

namespace MyNamespace {

template <typename T = int>
class MyContainer {
private:
    std::vector<T> elements;

public:
    void add(const T& item) {
        elements.push_back(item);
    }

    void remove(const T& item) {
        auto it = std::remove(elements.begin(), elements.end(), item);
        if (it == elements.end())
            throw std::runtime_error("Item not found");
        elements.erase(it, elements.end());
    }

    size_t size() const {
        return elements.size();
    }

    const std::vector<T> getElements() const {
        return elements;
    }

    friend std::ostream& operator<<(std::ostream& os, const MyContainer& c) {
        os << "[ ";
        for (const auto& el : c.elements)
            os << el << " ";
        os << "]";
        return os;
    }
    class AscendingOrder;
    class DescendingOrder;
    class SideCrossOrder;
    class ReverseOrder;
    class Order;
};
}
