#include <print>
#include <utility>
#include <string>

template <typename... Ts> class Group;

template <typename T1>
class Group<T1> {
public:
    Group() = default;
    explicit Group(const T1& t1): t1_(t1) {}
    explicit Group(T1&& t1): t1_(std::move(t1)) {}

    explicit operator const T1&() const { return t1_; }
    explicit operator T1&() { return t1_; }
private:
    T1 t1_;
};

template <typename T1, typename... Ts>
class Group<T1, Ts...> : public Group<Ts...> {
public:
    Group() = default;
    explicit Group(const T1& t1, Ts&&... ts) : Group<Ts...>(std::forward<Ts>(ts)...), t1_(t1) {}
    explicit Group(T1&& t1, Ts&&... ts) : Group<Ts...>(std::forward<Ts>(ts)...), t1_(std::move(t1)) {}

    explicit operator const T1&() const { return t1_; }
    explicit operator T1&() { return t1_; }
private:
    T1 t1_;
};

//Deduction guide
template <typename... T> Group(T&&... t) -> Group<T...>;

int main() {
    Group g(1, 2.2, std::string("xyz"));

    std::println("int(g) is {}", int(g));
    std::println("double(g) is {}", double(g));
    std::println("std::string(g) is {}", std::string(g));
}
