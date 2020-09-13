#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void PrintVectorPart(const vector<int>& numbers) {
  auto it = find_if(numbers.begin(), numbers.end(), [](int num){return num < 0;});
  while(it != numbers.begin()) {
    it--;
    cout << *it << " ";
  }
}

int main() {
  PrintVectorPart({6, 1, 8, -5, 4});
  cout << endl;
  PrintVectorPart({-6, 1, 8, -5, 4});  // ничего не выведется
  cout << endl;
  PrintVectorPart({6, 1, 8, 5, 4});
  cout << endl;
  return 0;
}

  