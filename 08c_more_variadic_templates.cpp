#include <print>
#include <utility>
#include <string>

template <auto... Values> 
struct value_list {};

template <std::size_t N, auto... Values>
struct nth_value_helper {};

template <auto v1, auto... values>
struct nth_value_helper<0, v1, values...> {
    static constexpr auto value = v1;
};

template <std::size_t n, auto v1, auto... values>
struct nth_value_helper<n, v1, values...> {
    static constexpr auto value = nth_value_helper<n - 1, values...>::value;
};

template <std::size_t N, auto... values>
constexpr auto nth_value(value_list<values...>) {
    return nth_value_helper<N, values...>::value;
}

int main() {
    value_list<12, 3.5, 'c'> my_list;

    std::println("nth_value<0>(my_list) -> {}", nth_value<0>(my_list));
    std::println("nth_value<1>(my_list) -> {}", nth_value<1>(my_list));
    std::println("nth_value<2>(my_list) -> {}", nth_value<2>(my_list));
}
