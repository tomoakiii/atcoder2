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

int main(){
    ll N;
    cin >> N;
    vector S(N, vector<int>{});
    S[0].push_back(1);
    rep(i, N-1) {
        int c = 2;
        c += i;
        S[i+1] = S[i];
        S[i+1].push_back(c);
        copy(S[i].begin(),S[i].end(),back_inserter(S[i+1]));
    }
    for(auto c: S[N-1]) {
        cout << c << " ";
    }
    cout << endl;
    return 0;
}