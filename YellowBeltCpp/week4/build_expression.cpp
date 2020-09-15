#include <iostream>
#include <string>
#include <sstream>
#include <deque>
#include <iterator>

using namespace std;

int main() {
    int n, x;
    cin >> x >> n;
    string tmp;
    getline(cin,tmp);
    deque<string> deq;
    deq.push_back(to_string(x));
    for (int i = 0; i < n; ++i) {
      string operation;
      getline(cin, operation);
      deq.push_front("(");
      deq.push_back(") ");
      deq.push_back(operation);
    }
    for (auto now : deq) {
        cout << now;
    }
    return 0;
}