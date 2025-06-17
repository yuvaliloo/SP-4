#include "MyContainer.hpp"

namespace MyNamespace {

// Explicit instantiation (optional, only if needed)
template class MyContainer<int>;
template class MyContainer<double>;
template class MyContainer<std::string>;

}
