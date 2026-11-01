#include <print>

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

template <typename N, typename D>
class Ratio<N*, D*> {
public:
    Ratio(): num_{}, denom_{} {}
    Ratio(N* num, D* denom): num_(num), denom_(denom) {
        std::println("Ratio<N*, D*>::Ratio(N*, D*)");
    }

    explicit operator double() const{
        std::println("Ratio<N*, D*>::operator double()");
        return double(*num_)/double(*denom_);
    }

private:
    N* num_; 
    D* denom_;
};

template<typename D>
class Ratio<double, D> {
public:
    Ratio() : value_() {}
    Ratio(const double& num, const D& denom) : value_(num/double(denom)) {
        std::println("Ratio<double, D>::Ratio(const double&, const D&)");
    }
    explicit operator double() const { return value_; }
private:
    double value_;
};

template<typename N>
class Ratio<N, double> {
public:
    Ratio() : value_() {}
    Ratio(const N& num, const double& denom) : value_(double(num)/denom) {
        std::println("Ratio<N, double>::Ratio(const N&, const double&)");
    }
    explicit operator double() const { return value_; }
private:
    double value_;
};

template<>
class Ratio<double, double> {
public:
    Ratio(): value_() {}

    template <typename N, typename D>
    Ratio(const N& num, const D& denom): value_(double(num) / double(denom)) {
        std::println("Ratio<double, double>::Ratio(const double& num, const double& denom)");
    }

    explicit operator double() const { 
        std::println("Ratio<double, double>::operator double()");
        return value_; 
    }

private:
    double value_;
};

int main(){
    int i{12};
    double e{2.71};
    double pi{3.14};

    Ratio r1(e, i);
    Ratio r2(i, e);
    Ratio r3(&pi, &e);
    Ratio r4(&i, &e);
}
