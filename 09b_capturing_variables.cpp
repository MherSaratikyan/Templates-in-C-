#include <print>
#include <utility>
#include <memory>

struct Widget {
    std::string name = "WidgetInstance";

    void demonstrateThisCapture() {
        // 1. Capture 'this' by reference (Changes affect the original object)
        auto captureThisRef = [this]() {
            name = "ModifiedWidget"; 
        };
        captureThisRef();
        std::println("After [this]: {}", name);

        // 2. Capture '*this' by value (C++17/20 way, safe for async/multithreading)
        auto captureThisVal = [*this]() mutable {
            name = "CopiedWidget"; // Only modifies the copy inside the lambda
        };
        captureThisVal();
        std::println("After [*this]: {} (Original unchanged)\n", name);
    }
};

int main() {
    int x = 10;
    int y = 20;

    // 3. Explicit Capture by Value
    // Creates a read-only copy of 'x' inside the lambda.
    auto byValue = [x]() {
        std::println("Explicit Value [x]: {}", x);
    };

    // 4. Explicit Capture by Reference
    // Directly references 'y'. Modifications inside affect the original variable.
    auto byRef = [&y]() {
        y += 5;
        std::println("Explicit Reference [&y]: {}", y);
    };

    // 5. Default Capture Modes (Implicit)
    // [=] copies everything used by value; [&] references everything used.
    auto defaultCopy = [=]() { return x + y; };
    auto defaultRef  = [&]() { x += 2; y += 2; };

    // 6. Init-Capture / Move Capture (C++14)
    // Moves non-copyable assets (like std::unique_ptr) into the lambda closure.
    auto ptr = std::make_unique<int>(42);
    auto moveCapture = [capturedPtr = std::move(ptr)]() {
        std::println("Moved Pointer Value: {}", *capturedPtr);
    };

    // 7. C++23 Static Lambdas
    // C++23 allows 'static' specifier if the lambda has an empty capture list.
    // It can be converted to a regular function pointer and has no overhead.
    auto cxx23Static = []() static {
        std::println("Hello from a C++23 static lambda!");
    };

    // --- Execution ---
    byValue();
    byRef();
    moveCapture();
    cxx23Static();

    std::println("\n--- Member Function Captures ---");
    Widget w;
    w.demonstrateThisCapture();
}
