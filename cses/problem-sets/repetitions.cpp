#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int max = 0;
    string::size_type back = 0;
    string::size_type front = 0;
    int len = 0;

    while (front < s.size()) {
        if (s[front] == s[back]) {
            len++;
            if (len > max) {
                max = len;
            }
            front++;
        } else {
            back = front;
            len = 0;
        }
    }
    cout << max << "\n";
}
