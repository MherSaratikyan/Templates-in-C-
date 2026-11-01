#include <print>
#include <type_traits>
#include <string>

template <typename T> T copy(T&& t)
    requires (sizeof(T) > 1)
{
    return std::forward<T>(t);
}

template <typename T1, typename T2>
std::common_type_t<T1, T2> min(T1&& t1, T2&& t2)
    requires(sizeof(t1 < t2) > 1)
    {
        if(t1 < t2) return std::forward<T1>(t1);
        return std::forward<T2>(t2);
    }


template <typename T1, typename T2>
std::common_type_t<T1, T2> min2(T1&& t1, T2&& t2)
    requires (requires{ t1 < t2; }) {
        if(t1 < t2) return std::forward<T1>(t1);
        return std::forward<T2>(t2);
    }

template <typename T1, typename T2> concept Comparable = requires(T1 t1, T2 t2) { t1 < t2; };

template <typename T1, typename T2>
std::common_type_t<T1, T2> min3(T1&& t1, T2&& t2)
    requires Comparable<T1, T2> {
        if(t1 < t2) return std::forward<T1>(t1);
        return std::forward<T2>(t2);
    }

template <typename T> concept HasXOR = requires(T a, T b) { a ^ b; };
template <HasXOR T> void MySwap(T& x, T& y) {
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
}

template <typename T> concept Assignable = requires(T a, T b) { T(std::move(b)); b = std::move(a); };
template <Assignable T> void MySwap(T& x, T& y) requires (!HasXOR<T>) {
    T tmp(std::move(y));
    y = std::move(x);
    x = std::move(tmp);
}

int main() {
    int a{4}; int b{5};
    std::println("a = {}, b = {}", a, b);
    MySwap(a, b);
    std::println("a = {}, b = {}", a, b);

    std::string s1("Hello"), s2("World");
    std::println("s1 = {}, s2 = {}", s1, s2);
    MySwap(s1, s2);
    std::println("s1 = {}, s2 = {}", s1, s2);

}
