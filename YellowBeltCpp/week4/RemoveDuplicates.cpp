#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <string>

using namespace std;


int main() {
  int n;
  cin >> n;
  vector<int> v;
  for(int i = n; i > 0; --i) {
      v.push_back(i);
  }
  bool flag = true;
  while(flag){
      for (auto now : v) {
          cout << now << " ";
      }
      cout << endl;
      flag = prev_permutation(v.begin(), v.end());
  }
  return 0;
}