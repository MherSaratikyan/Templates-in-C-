#include <print>

template <typename... F> struct overload_set;

template <typename F1>
struct overload_set<F1> : public F1 {
    overload_set(F1&& f1) : F1(std::move(f1)) {}
    overload_set(const F1& f1) : F1(f1) {}

    using F1::operator();
};

template <typename F1, typename... F>
struct overload_set<F1, F...> : public F1, public overload_set<F...> {
    overload_set(F1&& f1, F&&... f): F1(std::move(f1)), overload_set<F...>(std::forward<F&&>(f)...) {}
    overload_set(const F1& f1, const F&... f): F1(f1), overload_set<F...>(f...) {}

    using F1::operator();
    using overload_set<F...>::operator();
};

template <typename... F> auto overload(F&&... f) {
    return overload_set<F...>(std::forward<F>(f)...);
}

//The C++17 way + deduction guide
template <typename... F>
struct overloaded : public F... {
    using F::operator()...;
};

template <typename... T> overloaded(T... ) -> overloaded<T...>;

int main() {
    int i = 5;
    double d = 7.3;

    auto l = overload(
        [](int* i) { std::println("i = {}", *i); },
        [](double* d) { std::println("d = {}", *d); }
    );

    l(&i);
    l(&d);

    auto l2 = overloaded {
        [](int* i) { std::println("i = {}", *i); },
        [](double* d) { std::println("d = {}", *d); }
    };

    l2(&i);
    l2(&d);
}
