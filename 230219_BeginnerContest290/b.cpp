#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)


int main(){
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    string T = S;
    rep(i, N) {
        if (S[i] == 'o') {
            if (K-- > 0) {
                T[i] = 'o';
                continue;
            }
        }
        T[i] = 'x';
    }
    cout << T << endl;
    return 0;
}