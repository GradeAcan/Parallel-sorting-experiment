#include <algorithm>
#include <execution> // For parallel policy

extern "C" {
    void parallel_sort_bridge(unsigned int* arr, size_t size) {
        std::sort(std::execution::par, arr, arr + size);
    }
}