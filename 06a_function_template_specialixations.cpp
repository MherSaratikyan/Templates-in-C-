#include <print>

template <typename T> T do_smth(T x) { 
    std::println("do_smt<T>");
    return ++x; 
}

template <> int do_smth<int>(int x) { 
    std::println("do_smth<int>");
    return x << 1; 
}


//Can't change the return type od the number of types of arguments
//The following does not match any template declaration

//template <> long do_smth<int>(int x) { return x*x; }

int main(){
    do_smth(3.14);
    do_smth(5);
}
