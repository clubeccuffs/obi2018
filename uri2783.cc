#include <iostream>
#include <set>
#include <vector>
using namespace std;


vector<bool> carimbada;
vector<int> figurinhas;

int main() {
    int N, C, M;
    cin >> N >> C >> M;

    carimbada.assign(N, false);
    figurinhas.assign(N, 0);

    for(int i = 0; i < C; ++i) {
        int x;
        cin >> x;
        carimbada[x-1] = true;
    }

    for(int i = 0; i < M; ++i) {
        int x;
        cin >> x;
        figurinhas[x-1]++;
    }

    int achadas = 0;

    for(int i = 0; i < N; ++i) {
        if(figurinhas[i] > 0 && carimbada[i]) {
            achadas++;
        }
    }

    cout << C - achadas << '\n';

    return 0;
}
