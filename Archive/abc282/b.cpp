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
    ll N, M;
    cin >> N >> M;
    vector<string> S(N);
    rep(i,N) cin>>S[i];
    int cnt = 0;
    rep(i, N-1) for(int j=i+1; j<N; j++) {
        bool flg = true;
        rep(k, M){
            if (S[i][k] == 'x' && S[j][k] == 'x') flg = false;
        }
        if (flg) cnt++;
    }
    cout << cnt << endl;
    return 0;
}