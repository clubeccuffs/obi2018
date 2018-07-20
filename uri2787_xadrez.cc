#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    if (a % 2 == 0) {
        if (b % 2 == 0) {
            cout << "1\n";
        }
        else {
            cout << "0\n";
        }
    }
    else {
        if (b % 2 == 0) {
            cout << "0\n";
        }
        else {
            cout << "1\n";
        }
    }
    return 0;
}
