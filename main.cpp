#include <iostream>
#include "dynamic_array.h"

int main() {
    DynamicArray<int> arr;
    arr.push_back(10);
    arr.push_back(20);
    std::cout << arr.at(1) << std::endl; // 출력: 20

    try {
        arr.at(5); // 예외 발생
    } catch(std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "Size: " << arr.getSize() << std::endl;
    std::cout << "Capacity: " << arr.getCapacity() << std::endl;

    return 0;
}
