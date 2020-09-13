#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

vector<string> SplitIntoWords(const string& s) {
    vector<string> result;
    auto it1 = s.begin();
    auto it2 = find(s.begin(), s.end(), ' ');
    result.push_back({it1, it2});
    while(it2 != s.end()) {
        it1 = ++it2;
        it2 = find(it2, s.end(), ' ');
        result.push_back({it1, it2});
    }
    return result;
}

int main() {
  string s = "C Cpp Java Python";

  vector<string> words = SplitIntoWords(s);
  cout << words.size() << " ";
  for (auto it = begin(words); it != end(words); ++it) {
    if (it != begin(words)) {
      cout << "/";
    }
    cout << *it;
  }
  cout << endl;
  
  return 0;
}
