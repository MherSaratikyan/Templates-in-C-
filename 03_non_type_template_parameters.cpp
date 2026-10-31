#include <print>
#include <utility>
#include <exception>

template <typename T, std::size_t N>
class Array {
public:
    const T& operator[](std::size_t idx) const {
        if(idx >= N) throw std::out_of_range("Bad index");
        return arr_[idx];
    }

    T& operator[](std::size_t idx) {
        return const_cast<T&>(std::as_const(*this)[idx]);
    }

private:
    T arr_[N];
};

int main(){
    Array<int, 5> a;        //ok

    for(int i = 0; i < 5; ++i){
        a[i] = i;
    }

    try {
        std::println("a[2] = {}", a[2]);
        a[7] = 13;
    } catch(std::out_of_range& e){
        std::println("{}", e.what());
    }
    //Array<int, a[2]> a2;  //error: 
}
