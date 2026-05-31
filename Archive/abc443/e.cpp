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

void solve(){
    ll N,C;
    cin>>N>>C; C--;
    vector<string> S(N);
    rep(i,N) cin>>S[i];
    vector<ll> last(N,-1);
    rep(j,N) {
        rep(i,N) {
            if(S[i][j] == '#') chmax(last[j], i);
        }
    }
    vector<bool> cur(N);
    cur[C] = true;
    for(int i=N-1; i>0; i--) {
        vector<bool> nx(N);
        rep(j,N) {
            if(!cur[j])continue;
            vector<int> ind;
            for(int d=-1;d<=1;d++) {
                if(j+d < 0 || j+d>=N) continue;
                ind.push_back(j+d);
            }
            for(auto k: ind) {
                if(S[i-1][k] == '.' || last[k] == -1) {
                    nx[k] = true;
                } else {
                    if(last[k] == i-1) {
                        last[k] = -1;
                        nx[k] = true;
                    }
                }
            }
        }
        swap(nx,cur);
    }
    string ans = "";
    for(auto c: cur) {
        if(c) ans.push_back('1');
        else ans.push_back('0');
    }
    cout << ans << endl;
}



int main(){
    ll T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}