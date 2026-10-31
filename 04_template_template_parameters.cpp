#include <print>
#include <utility>
#include <vector>
#include <deque>

template <typename T, template <typename> typename Container>
class Builder {
    Container<T> data_;
public:
    void add(const T& v) { data_.push_bask(v); }
    void print() const {
        for(const auto& obj : data_)
            std::print("{} ", obj);
        std::println();
    }
};

template <typename T, template <typename> typename InContainer, template <typename> typename OutContainer>
OutContainer<T> copy_to(const InContainer<T>& input){
    OutContainer<T> output;
    for(const auto& obj : input) output.push_back(obj);

    return output;
}


int main(){
    template <typename T> class my_vector { … };
    Builder<int, my_vector> b;
    b.add(1);
    b.add(2);
    b.print();

    template <template <typename> class Out_container,
              template <typename> class In_container,
              typename T> Out_container<T>
    resequence(const In_container<T>& in_container) {
      Out_container<T> out_container;
      for (auto x : in_container) {
        out_container.push_back(x);
      }
      return out_container;
}
}
