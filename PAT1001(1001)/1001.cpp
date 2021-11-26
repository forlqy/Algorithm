#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int i = 0;
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
            i++;
        }
        else {
            n = (3 * n) + 1;
            n /= 2;
            i++;
        }
    }
    cout << i;
    return 0;
}