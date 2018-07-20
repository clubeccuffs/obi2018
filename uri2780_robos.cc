#include <iostream>
using namespace std;

int main() {
    int a;
    cin >> a;

    if (a <= 800) {
        cout << "1\n";
    } 
    else if (a <= 1400) {
        cout << "2\n";
    }
    else {
        cout << "3\n";
    }
    return 0;
}
