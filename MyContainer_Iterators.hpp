#pragma once

#include <vector>
#include <algorithm>
#include <functional>
#include "MyContainer.hpp"

namespace MyNamespace {

template <typename T>
class AscendingOrder {
private:
    std::vector<T> sorted;
public:
    AscendingOrder(const MyContainer<T>& container) {
        sorted = container.getElements();
        std::sort(sorted.begin(), sorted.end());
    }
    auto begin() { return sorted.begin(); }
    auto end() { return sorted.end(); }
};

template <typename T>
class DescendingOrder {
private:
    std::vector<T> sorted;
public:
    DescendingOrder(const MyContainer<T>& container) {
        sorted = container.getElements();
        std::sort(sorted.begin(), sorted.end(), std::greater<T>());
    }
    auto begin() { return sorted.begin(); }
    auto end() { return sorted.end(); }
};

template <typename T>
class SideCrossOrder {
private:
    std::vector<T> ordered;
public:
    SideCrossOrder(const MyContainer<T>& container) {
        std::vector<T> temp = container.getElements();
        if (temp.empty()) return;
        std::sort(temp.begin(), temp.end());
        size_t i = 0, j = temp.size() - 1;
        while (i <= j) {
            if (i == j) ordered.push_back(temp[i]);
            else {
                ordered.push_back(temp[i]);
                ordered.push_back(temp[j]);
            }
            ++i;
            if (j > 0) --j;
        }
    }
    auto begin() { return ordered.begin(); }
    auto end() { return ordered.end(); }
};

template <typename T>
class ReverseOrder {
private:
    std::vector<T> reversed;
public:
    ReverseOrder(const MyContainer<T>& container) {
        reversed = container.getElements();
        std::reverse(reversed.begin(), reversed.end());
    }
    auto begin() { return reversed.begin(); }
    auto end() { return reversed.end(); }
};

template <typename T>
class Order {
private:
    const std::vector<T> original;
public:
    Order(const MyContainer<T>& container) : original(container.getElements()) {}
    auto begin() { return original.begin(); }
    auto end() { return original.end(); }
};

template <typename T>
class MiddleOutOrder {
private:
    std::vector<T> ordered;
public:
    MiddleOutOrder(const MyContainer<T>& container) {
        const auto& vec = container.getElements();
        if (vec.empty()) return;

        int n = vec.size();
        int mid = n / 2;
        ordered.push_back(vec[mid]);

        int left = mid - 1;
        int right = mid + 1;
        bool toggle = true;

        while (left >= 0 || right < n) {
            if (toggle && left>= 0) ordered.push_back(vec[left--]);
            else if (!toggle && right < n) ordered.push_back(vec[right++]);
            toggle = !toggle;
        }
    }
    auto begin() { return ordered.begin(); }
    auto end() { return ordered.end(); }
};

}
