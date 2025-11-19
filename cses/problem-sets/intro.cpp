#include <bits/stdc++.h>
using namespace std;

void basic_input_output() {
    int a, b;
    string x;
    cin >> a >> b >> x;
    cout << a << " " << b << " " << x << "\n";
}

void get_line() {
    string name;
    cout << "What is your name: ";
    getline(cin, name);
    cout << "Hello " << name << "!" << "\n";
}

void working_with_numbers() {
    long long x = 123456789123456789LL;
    cout << x << "\n";

    double y = 0.9;
    cout << y << "\n";
    if (0.3 * 3 == y) {
        cout << "They are equal!\n";
    } else {
        cout << "They are not equal!\n";
    }
}

void shorter_type() {
    typedef long long ll;

    ll a = 12345;
    ll b = 12345;
    cout << a * b << "\n";
}

int main() {
    // basic_input_output()
    // get_line();
    // working_with_numbers();
    shorter_type();
}
