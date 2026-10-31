#include <print>
#include <utility>

template <typename T>
class ArrayOf2{
public:
    const T& operator[](int idx) const { return arr_[idx]; }
    T& operator[](int idx) { return const_cast<T&>(std::as_const(*this)[idx]); }

    T sum() const { return arr_[0] + arr_[1]; }
private:
    T arr_[2];
};

template <typename T> constexpr T pi = T(3.14159265358979323846264338327950288L);
template <typename T> constexpr T e = T(2.718281828L);

int main(){
    ArrayOf2<int> int_arr;
    int_arr[0] = -23, int_arr[1] = -32;
    std::println("int_arr.sum() = {}", int_arr.sum());

    int_arr[1] = 23;
    std::println("int_arr.sum() = {}", int_arr.sum());

    std::println("pi<double> = {}", pi<double>);
    std::println("pi<float> = {}", pi<float>);
    std::println("e<float> = {}", e<float>);

    ArrayOf2<double> double_arr;
    double_arr[0] = pi<double>, double_arr[1] = e<double>;

    std::println("double_arr.sum() = {}", double_arr.sum());


    ArrayOf2<char*> char_ptr_arr;
    char s[] = "Hello";
    char_ptr_arr[0] = s, char_ptr_arr[1] = s + 3;
}
