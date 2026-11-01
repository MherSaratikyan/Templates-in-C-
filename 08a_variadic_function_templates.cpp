#include <print>

template <typename... Args>
auto sum(const Args&... args) {
    return (args + ...);
}

template <typename T>
auto recursive_sum(const T& x) { return x; }

template <typename First, typename... Rest>
auto recursive_sum(const First& first, const Rest&... rest) {
    return first + sum(rest...);
}

int main() {
    std::println("sum(5, 7, 3) -> {}", sum(5, 7, 3));
    std::println("sum(5, 7L, 3) -> {}", sum(5, 7L, 3));
    std::println("sum(5, 2.9, 7L) -> {}", sum(5, 2.9, 7L));

    std::println("recursive_sum(5, 2.9, 7L) -> {}", recursive_sum(5, 2.9, 7L));
}
