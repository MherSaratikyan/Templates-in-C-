#include <print>
#include <vector>

template <typename T> T half(T x) { return x / 2; }

template <typename U, typename V> U quarter(V x) { return x / 4; }

template <typename T> T sum(T a, T b) { return a + b; }

template <typename T> T first(const std::vector<T>& vec) { return vec[0]; }

// template <typename U, typename V> std::pair<V, U> swap12(const std::pair<U, V>& x) {
//     return std::make_pair<V, U>(x.second, x.first);
// }

template <typename T> 
auto swap12(const T& p) {
    return std::make_pair(p.second, p.first);
}

int main(){
    std::println("half<int>(7) -> {}", half<int>(7));
    std::println("half<double>(3.14) -> {}", half<double>(3.14));

    //auto x = half(8);       //int
    //auto y = half(1.5);     //double

    std::println("quarter<double>(13) -> {}", quarter<double>(13));

    //sum(11L, 7);      //The argument deduction/substitution failes, deduced conflicting types

    std::vector<double> v{3.14, 2.71, 1.65};
    std::println("first(v) -> {}", first(v));

    swap12(std::make_pair(7, 4.2)); // pair of 4.2, 7
}
