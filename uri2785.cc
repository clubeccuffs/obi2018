#include <iostream>
#include <vector>
#include <limits>
using namespace std;

vector<vector<int>> caixas;
vector<bool> marked;
int N;


int solve(int l) {
    if(l >= N) {
        return 0;
    }

    int tot = 0;
    for(int i = 0; i < N; ++i) {
        tot += marked[i] ? caixas[l][i] : 0;
    }

    int mc = numeric_limits<int>::max();

    for(int i = 0; i < N; ++i) {
        if(!marked[i]) {
            marked[i] = true;
            cout << "marking\n";
            for(int x = 0; x < N; ++x) { cout << marked[x] << ' '; } cout << '\n';
            mc = min(mc, tot + caixas[l][i] + solve(l+1) );
            marked[i] = false;
        }
    }

    return mc;

}

int main() {
    cin >> N;
    caixas.assign(N, vector<int>(N, 0));
    marked.assign(N, false);
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cin >> caixas[i][j];
        }
    }
    cout << solve(0) << '\n';
}
