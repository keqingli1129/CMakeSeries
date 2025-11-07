#include <iostream>
#include <vector>
#include <algorithm>
#include "console.hpp"
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <concepts>


template <typename T>
requires std::integral<T>
T add( T a, T b){
    return a + b;
}
int main() {
    // Create a vector of integers
    std::vector<int> numbers = {5, 2, 9, 1, 5, 6};

    // Sort the vector in ascending order
    std::sort(numbers.begin(), numbers.end());

    // Print the sorted vector
    std::cout << "Sorted numbers: ";
    for (const int& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    Console::print("Hello CMake");
    SDL_Init(SDL_INIT_VIDEO);
    std::cout << "The sum is : " << add(7,3) << std::endl;
    return 0;
}