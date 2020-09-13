#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

set<int>::const_iterator FindNearestElement(
    const set<int>& numbers,
    int border) {
        auto it_r = numbers.lower_bound(border);
        if (it_r == numbers.begin()) {
            return it_r;
        }
        if (it_r == numbers.end()) {
            return prev(it_r);
        }
        if (*it_r - border < border - *prev(it_r)) {
            return it_r;
        }
        else {
            return prev(it_r);
        }
    }
// set<int>::const_iterator —
// тип итераторов для константного множества целых чисел

int main() {
  set<int> numbers = {1, 4, 6};
  cout <<
      *FindNearestElement(numbers, 0) << " " <<
      *FindNearestElement(numbers, 3) << " " <<
      *FindNearestElement(numbers, 5) << " " <<
      *FindNearestElement(numbers, 6) << " " <<
      *FindNearestElement(numbers, 100) << endl;
      
  set<int> empty_set;
  
  cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
  return 0;
}
