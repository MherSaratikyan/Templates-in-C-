#include <print>

template <typename N, typename D>
class Ratio {
public:
    Ratio(): num_{}, denom_{} {}
    Ratio(const N& num, const D& denom): num_(num), denom_(denom) {
        std::println("Ratio<N, D>::Ratio(const N& num, const D& denom)");
    }

    explicit operator double() const{
        std::println("Ratio<N, D>::operator double()");
        return double(num_)/double(denom_);
    }

private:
    N num_; 
    D denom_;
};

template<>
class Ratio<double, double> {
public:
    Ratio(): value_() {}

    template <typename N, typename D>
    Ratio(const N& num, const D& denom): value_(double(num) / double(denom)) {
        std::println("Ratio<double, double>::Ratio(const N& num, const D& denom)");
    }

    explicit operator double() const { 
        std::println("Ratio<double, double>::operator double()");
        return value_; 
    }

private:
    double value_;
};

// We can explicitly specialize the member function as well
template<> Ratio<float, float>::operator double() const { 
    std::println("Ratio<float, float>::operator double()");
    return num_ / denom_;
}

int main(){
    Ratio r(5, 0.1);
    std::println("Ratio(5, 0.1) = {}", double(r));


    Ratio r2(3.14, 2.71);
    std::println("Ratio(3.14, 2.71) = {}", double(r2));

    float a = 1.2;
    float b = 2.4;
    Ratio r3(a, b);
    std::println("r3 = {}", double(r3));
}
