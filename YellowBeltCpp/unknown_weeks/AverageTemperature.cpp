#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int64_t sum = 0;
    cin >> n;
    vector<int> temperatures(n);
    for (auto& now : temperatures) {
        cin >> now;
        sum += now;
    }
    sum /= n;
    cout << count_if(begin(temperatures), end(temperatures), [sum](int a) {return a > sum; }) << endl;
    int i = 0;
    for (auto now : temperatures) {
        if (now > sum) {
            cout << i << " ";
        }
        ++i;
    }
    return 0;
}
