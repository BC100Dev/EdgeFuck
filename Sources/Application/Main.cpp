#include <iostream>
#include <thread>

int main(int argc, char** argv) {
    std::cout << "Hello, World!" << std::endl;

    for (int i = 0; i < argc; i++) {
        std::cout << i << ": " << argv[i] << std::endl;
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(15000));

    return 0;
}