#include <print>
#include <algorithm>
#include <vector>

bool less_than(int i, int j) { return i < j; }

struct less {
    bool operator()(int i, int j) const {
        return i < j;
    }
};

template <typename T>
void print_vector(const std::vector<T>& vec) {
    for(const T& elem : vec){
        std::print("{} ", elem);
    }

    std::println();
}

int main() {
    std::vector<int> vec1{3, 4, 1, 5, 2};
    std::vector<int> vec2 = vec1;
    std::vector<int> vec3 = vec1;

    std::sort(vec1.begin(), vec1.end(), less_than);
    print_vector(vec1);

    std::sort(vec2.begin(), vec2.end(), [](int i, int j) { return i < j; });
    print_vector(vec2);

    std::sort(vec3.begin(), vec3.end(), less());
    print_vector(vec3);

    auto compare_with_tolerance = [](double i, double j) { return (i < j) && (std::abs(i - j) > 1e-8); };
    std::vector<double> vec4{1.1, 3.3, 2.2, 5.5, 4.4};
    std::sort(vec4.begin(), vec4.end(), compare_with_tolerance);
    print_vector(vec4);

}
