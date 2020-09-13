#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border) {
  vector<T> result;
  auto it_brd = find_if(elements.begin(), elements.end(), [border](T elem){return elem > border;});
  return {it_brd, elements.end()};
}

int main() {
  for (int x : FindGreaterElements(set<int>{1, 5, 7, 8}, 5)) {
    cout << x << " ";
  }
  cout << endl;
  
  string to_find = "Python";
  cout << FindGreaterElements(set<string>{"C", "C++"}, to_find).size() << endl;
  return 0;
}