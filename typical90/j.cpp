#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;
typedef modint1000000007 mint;
int main(){
    int N;
    cin >> N;
    vector sc(2, vector<int>(N));
    map<int, pair<int,int>> mp;
    rep(i,N) {
        int c, p;
        cin >> c >> p;
        c--;
        sc[c][i] = p;
    }
    rep(k,2) rep(i, N-1) {
        sc[k][i+1] += sc[k][i];
    }
    int Q;
    cin >> Q;
    while(Q--){
        int L, R;
        cin >> L >> R;
        L--, R--;
        if(L==0) {
            cout << sc[0][R] << " ";
            cout << sc[1][R] << endl;
        } else {
            cout << sc[0][R] - sc[0][L-1] << " ";
            cout << sc[1][R] - sc[1][L-1] << endl;
        }
    }
    return 0;
}