#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string>s;

    for (int i = 0; i < N; ++i) {
        string s1;
        cin >> s1;
        s.push_back(s1);
    }
    int before, after;
    before = after = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < s[i].length(); j++) {
            if (s.at(i)[j] != 'P' || s.at(i)[j] != 'T' || s.at(i)[j] != 'A' || s.at(i)[j] != '0') {
                cout << "NO" << endl;
                continue;
                while (s.at(i)[j] == 'P') before = j;
                while (s.at(i)[j] == 'T') after = j;
            }
            if (before * (after - before - 1) == (s.at(i).length() - 1 - after))cout << "Yes" << endl;
            else cout << "No" << endl;
        }

    }
}
