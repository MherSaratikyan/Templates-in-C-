#include <print>
#include <iostream>

void whatami(int x){
    std::println("{} is int", x);
}

void whatami(long x){
    std::println("{} is long", x);
}

template <typename T>
void whatami(T* p){
    std::cout << p << " is a pointer" << std::endl;
}

template <typename T>
void whatami(T&&){
    std::println("Something weird");
}

class C {};

int main(){
    whatami(5);
    //whatami(5.0); //Compilation error

    int a = 10;
    whatami(&a);

    C c;
    whatami(c);
    whatami(&c);
}
