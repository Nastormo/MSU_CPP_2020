#include <iostream>


template <typename ...>
struct same : public std::false_type {};

template <typename T>
struct same<T> : public std::true_type {};

template <typename T1, typename T2, typename ... Tn>
struct same<T1, T2, Tn...> {
    static constexpr bool value = std::is_same<std::decay_t<T1>, std::decay_t<T2>>::value && same<Tn...>::value;
};

template<typename ...Tn>
constexpr bool are_same_v = same<Tn...>::value;


int main(int argc, char const *argv[])
{

    bool trueValue0 = are_same_v<int>;
	std::cout << trueValue0 << std::endl;

	bool trueValue1 = are_same_v<int, const int32_t, signed int>;
	std::cout << trueValue1 << std::endl;

    bool falseValue0 = are_same_v<int, long>;
	std::cout << falseValue0 << std::endl;

	bool falseValue1 = are_same_v<int, const int32_t, signed int, long>;
	std::cout << falseValue1 << std::endl;

	static_assert(are_same_v<int, const int32_t, signed int>, "compile assert");
	return 0;
}