#include <iostream>
#include <vector>

std::vector<unsigned> get_numbers_lesser_than_max(unsigned max_number) {
    std::vector<unsigned> dp;
    if (max_number == 0) {
        return dp;
    }
    dp.push_back(1);
    if (max_number == 1) {
        return dp;
    }
    dp.push_back(1);
    unsigned i = 2;
    while (true) {
        long long unsigned next = dp[i-1] + dp[i-2];
        if (next <= max_number) {
            dp.push_back(next);
            i++;
        } else {
            break;
        }
    }
    
    return dp;
}

std::vector<unsigned> get_num_in_range(unsigned max_number, unsigned min_number) {
    std::vector<unsigned> numbers = get_numbers_lesser_than_max(max_number);
    std::vector<unsigned> result;
    for (size_t i = 0; i < numbers.size(); i++) {
        if (numbers[i] >= min_number) {
            result.push_back(numbers[i]);
        }
    }
    
    return result;
}

void print_numbers(unsigned max_number, unsigned min_number) {
    if (min_number > max_number) {
        std::cout << "Min number can not be bigger than max number" << std::endl;
        return;
    }
    
    std::vector<unsigned> numbers = get_num_in_range(max_number, min_number);
    
    if (numbers.empty()) {
        std::cout << "Have not Fbonachy`s numbers in this range" << std::endl;
    } else {
        for (size_t i = 0; i < numbers.size(); i++) {
            std::cout << numbers[i] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    unsigned max, min;
    std::cout << "enter min number: ";
    std::cin >> min;
    std::cout << "enter max number: ";
    std::cin >> max;
    
    print_numbers(max, min);
    
    return 0;
}