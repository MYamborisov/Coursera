#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <cmath>
#include <exception>

using namespace std;

// Предварительное объявление шаблонных функций
template <typename Key, typename Value> Value& GetRefStrict(map<Key, Value>& m, Key k);



template <typename Key, typename Value>
Value& GetRefStrict(map<Key, Value>& m, Key k) {
	if (m.count(k) == 0) {
		throw runtime_error("");
	}
	else {
		return m.at(k);
	}
}



int main() {
	try {
		map<int, string> m = { {0, "value"} };
		string& item = GetRefStrict(m, 0);
		item = "newvalue";
		cout << m[0] << endl; // выведет newvalue
	}
	catch (runtime_error ex){
		cout << "!!!";
	}
	return 0;
}
