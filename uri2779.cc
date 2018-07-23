#include <iostream>
#include <set>
using namespace std;


set<int> figurinhas;

int main() {
    int N;
    int C;
    cin >> N >> C;
    for(int i = 0; i < C; ++i) {
        int x;
        cin >> x;
        figurinhas.insert(x);
    }
    cout << (N - figurinhas.size()) << '\n';
}
