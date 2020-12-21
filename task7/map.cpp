#include <iostream>
#include <map>
#include <iomanip>

int main(int argc, char const *argv[])
{
    int num_iter = 1e7;
    std::string str = "MAP";
    std::map<int, std::string> map;    
    map.insert({0, str + "0"});
    for (int i = 1; i < num_iter; i++) {
        map.insert({i, str + std::to_string(i)});
    }

    int count = 0;
    for (int i = 0; i < num_iter; i++) {
        std::string check = map[i];
        if (check != str + std::to_string(i)) count++;
    }
    std::cout << count;
	return 0;
}