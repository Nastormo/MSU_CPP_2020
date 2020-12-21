#include <iostream>
#include <map>
#include <iomanip>
#include <chrono>

int main(int argc, char const *argv[])
{
    int num_iter = 1e7;
    std::string str = "MAP";
    std::map<int, int> map; 
    auto start = std::chrono::system_clock::now();   
    map.insert({0, 0});
    for (int i = 1; i < num_iter; i++) {
        map.insert({i, i});
    }
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Elapsed time insert: " << elapsed.count() << "s" << std::endl;

	return 0;
}