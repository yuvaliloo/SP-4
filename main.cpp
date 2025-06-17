#include "MyContainer.hpp"
#include "MyContainer_Iterators.hpp"
using namespace MyNamespace;

int main() {
    MyContainer<int> cont;

    SideCrossOrder<int> it(cont);
    auto b = it.begin();
    auto e = it.end();

    if (b == e) {
        std::cout << "✅ AscendingOrder is empty as expected.\n";
    } else {
        std::cout << "❌ AscendingOrder not empty.\n";
    }

    return 0;
}
