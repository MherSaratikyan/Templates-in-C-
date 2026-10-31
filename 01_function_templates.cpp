#include <print>

template <typename T>
T increment(T x) {
    return x + 1;
}

template <typename T>
T count(const T& from, const T& to, const T& step)
{
    T res = from;
    do {std::println("{}", res); } while((res += step) <= to) ;
    return res;
}

int main(){
    std::println("incrment(2) = {}", increment(2));
    std::println("increment(4.2) = {}", increment(4.2));
    std::println("increment('c') = {}", increment('c'));

    std::println("count(0, 10, 2) -> {}", count(0, 10, 2));
}
