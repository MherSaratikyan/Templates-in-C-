#include <print>

template <typename N, typename D>
class Ratio {
public:
    Ratio(): num_{}, denom_{} {}
    Ratio(const N& num, const D& denom): num_(num), denom_(denom) {}

    explicit operator double() const{
        return double(num_)/double(denom_);
    }

private:
    N num_;
    D denom_;
};

int main(){
    Ratio r(5, 0.1);
    std::println("Ratio(5, 0.1) = {}", double(r));

}
