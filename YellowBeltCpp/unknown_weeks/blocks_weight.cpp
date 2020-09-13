#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>

using namespace std;

int main() {
    uint64_t mass = 0, n, r, w = 0, h = 0, d = 0;
    cin >> n >> r;
    for (uint64_t i = 0; i < n; ++i) {
    cin >> w >> h >> d;
    mass +=  w * h * d;
    }
    cout << mass * r;
    return 0;
}
