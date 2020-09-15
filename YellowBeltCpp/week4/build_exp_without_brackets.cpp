#include <iostream>
#include <string>
#include <sstream>
#include <deque>
#include <iterator>

using namespace std;

int main() {
    int n, x;
    cin >> x >> n;
    deque<string> deq;
    deq.push_back(to_string(x));
    string prev_operation = "*";
    for (int i = 0; i < n; ++i) {
      string operation;
      int num;
      cin >> operation >> num;
      if ((operation == "/" || operation == "*") && (prev_operation == "-" || prev_operation == "+")) {
        string result;
        result = ") " + operation + " " + to_string(num);
        deq.push_front("(");
        deq.push_back(result);
      }
      else {
        string result;
        result = " " + operation + " " + to_string(num);
        deq.push_back(result);
      }
      prev_operation = operation;
    }
    for (auto now : deq) {
        cout << now;
    }
    return 0;
}