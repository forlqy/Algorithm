#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int sum = 0;
    for (int i = 0; i < s.length(); i++) {
        sum += (s[i] - '0');
    }
    string num = to_string(sum);
    string str[10] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };
    for (int i = 0; i < num.length(); i++) {
        if (i != num.size() - 1) {
            cout << str[num[i] - '0'] << " ";
        }
        else { cout << str[num[i] - '0']; }

    }

    return 0;
}