#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <cmath>

using namespace std;

// Предварительное объявление шаблонных функций
template<typename T> T Sqr(T x);
template<typename T> vector<T> operator*(vector<T> lhs, vector<T> rhs);
template <typename Key, typename Value> map<Key, Value> operator*(map<Key, Value> lhs, map<Key, Value> rhs);
template <typename Key, typename Value> pair<Key, Value> operator*(pair<Key, Value> lhs, pair<Key, Value> rhs);

// Объявляем шаблонные функции
template <typename T>
T Sqr(T x) {
	return x * x;
}

template <typename Key, typename Value>
map<Key, Value> operator*(map<Key, Value> lhs, map<Key, Value> rhs) {
	map<Key, Value> result;
	for (auto now : lhs) {
		result[now.first] = now.second * now.second;
	}
	return result;
}

template <typename Key, typename Value>
pair<Key, Value> operator*(pair<Key, Value> lhs, pair<Key, Value> rhs) {
	pair<Key, Value> result;
	result.first = lhs.first * lhs.first;
	result.second = lhs.second * lhs.second;
	return result;
}

template <typename T>
vector<T> operator*(vector<T> lhs, vector<T> rhs) {
	vector<T> result;
	for (auto now : lhs) {
		result.push_back(now * now);
	}
	return result;
}

int main() {
	vector<int> v = { 1, 2, 3 };
	cout << "vector:";
	for (int x : Sqr(v)) {
		cout << ' ' << x;
	}
	cout << endl;

	map<int, pair<int, int>> map_of_pairs = {
	  {4, {2, 2}},
	  {7, {4, 3}}
	};
	cout << "map of pairs:" << endl;
	for (const auto& x : Sqr(map_of_pairs)) {
		cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
	}
	return 0;
}
