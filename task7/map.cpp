#include <iostream>
#include <map>
#include <iomanip>
#include <chrono>

std::map<int, int> hint_order_number(int num_number) {
    std::map<int, int> map;
    for (int i = 0; i < num_number; i++) {
        map.insert(map.end(), {i, i});
    }
    return map;
}

std::map<int, int> order_number(int num_number) {
    std::map<int, int> map;  
    for (int i = 0; i < num_number; i++) {
        map.insert({i, i});
    }
    return map;
}

std::map<double, double> pseudo_rand_number(int num_number) {
    std::map<double, double> map; 
    double num;
    for (int i = 0; i < num_number; i++) {
        num = (rand() / RAND_MAX - 0.5) * i;
        map.insert({num, num});
    }
    return map;
}

std::map<double, double> hint_pseudo_rand_number(int num_number) {
    std::map<double, double> map; 
    double num;
    double nmax, nmin = 0; 
    for (int i = 0; i < num_number; i++) {
        num = (rand() / RAND_MAX - 0.5) * i;
        if (num > nmax) {
            nmax = num;
            map.insert(map.end(), {num, num});
        } else if (num < nmin) {
            nmin = num;
            map.insert(map.begin(), {num, num});
        } else {
            map.insert({num, num});
        }
    }
    return map;
}

int main(int argc, char const *argv[])
{
    int num_number = 1e4;
    int num_iter = 1e3;

    auto start = std::chrono::system_clock::now();
    for (int i = 0; i < num_iter; i++) {
        order_number(num_number);
    }
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Elapsed time order number: " << elapsed.count() << "s" << std::endl;

    start = std::chrono::system_clock::now();
    for (int i = 0; i < num_iter; i++) {
        hint_order_number(num_number);
    }
    end = std::chrono::system_clock::now();
    elapsed = end - start;
    std::cout << "Elapsed time hint order number: " << elapsed.count() << "s" << std::endl;

    srand(0);
    start = std::chrono::system_clock::now();
    for (int i = 0; i < num_iter; i++) {
        pseudo_rand_number(num_number);
    }
    end = std::chrono::system_clock::now();
    elapsed = end - start;
    std::cout << "Elapsed time pseudo rand number: " << elapsed.count() << "s" << std::endl;

    srand(0);
    start = std::chrono::system_clock::now();
    for (int i = 0; i < num_iter; i++) {
        hint_pseudo_rand_number(num_number);
    }
    end = std::chrono::system_clock::now();
    elapsed = end - start;
    std::cout << "Elapsed time hint pseudo rand number: " << elapsed.count() << "s" << std::endl;
	return 0;
}