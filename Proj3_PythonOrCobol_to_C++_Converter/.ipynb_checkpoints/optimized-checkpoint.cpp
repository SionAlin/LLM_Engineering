#include <iostream>
#include <vector>
#include <limits>
#include <chrono>

// Linear Congruential Generator function
class LCG {
public:
    LCG(uint32_t seed, uint32_t a = 1664525, uint32_t c = 1013904223, uint64_t m = 1ULL << 32)
        : value(seed), a(a), c(c), m(m) {}

    uint32_t next() {
        value = (a * value + c) % m;
        return value;
    }

private:
    uint64_t value, a, c, m;
};

// Function to calculate the maximum subarray sum
int64_t max_subarray_sum(int n, uint32_t seed, int min_val, int max_val) {
    LCG lcg_gen(seed);
    std::vector<int> random_numbers(n);

    for (int i = 0; i < n; ++i) {
        random_numbers[i] = static_cast<int>(lcg_gen.next() % (max_val - min_val + 1) + min_val);
    }

    int64_t max_sum = std::numeric_limits<int64_t>::min();
    for (int i = 0; i < n; ++i) {
        int64_t current_sum = 0;
        for (int j = i; j < n; ++j) {
            current_sum += random_numbers[j];
            if (current_sum > max_sum) {
                max_sum = current_sum;
            }
        }
    }
    return max_sum;
}

// Function to execute total_max_subarray_sum
int64_t total_max_subarray_sum(int n, uint32_t initial_seed, int min_val, int max_val) {
    int64_t total_sum = 0;
    LCG lcg_gen(initial_seed);
    for (int i = 0; i < 20; ++i) {
        uint32_t seed = lcg_gen.next();
        total_sum += max_subarray_sum(n, seed, min_val, max_val);
    }
    return total_sum;
}

// Main function with timing
int main() {
    int n = 10000;
    uint32_t initial_seed = 42;
    int min_val = -10;
    int max_val = 10;

    auto start_time = std::chrono::high_resolution_clock::now();
    int64_t result = total_max_subarray_sum(n, initial_seed, min_val, max_val);
    auto end_time = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end_time - start_time;

    std::cout << "Total Maximum Subarray Sum (20 runs): " << result << "\n";
    std::cout << "Execution Time: " << duration.count() << " seconds" << std::endl;

    return 0;
}

