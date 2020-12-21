#include <iostream>
#include <map>
#include <iomanip>

int main(int argc, char const *argv[])
{
    int num_iter = 1e7;
    std::string str = "MAP";
    std::map<int, std::string> hint_map;
    auto [it, success] = hint_map.insert({0, str + "0"});
    for (int i = 1; i < num_iter; i++) {
        it = hint_map.insert(it, {i, str + std::to_string(i)});
    }

    int count = 0;
    for (int i = 0; i < num_iter; i++) {
        std::string check = hint_map[i];
        if (check != str + std::to_string(i)) count++;
    }
    std::cout << count;
	return 0;
}