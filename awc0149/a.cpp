#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x7F7F7F7F7F7F7F7F;
const int INFi = 0x7F0F0F0F;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll H,W,R,C;
    cin >> H>>W>>R>>C;
    vector<string> S(R), T(H,string(W,'.'));
    rep(i,R) cin>>S[i];
    int N; cin>>N;
    vector<pair<ll,ll>> XY(N);
    rep(i,N) {
        cin>>XY[i].first>>XY[i].second;
        XY[i].first--, XY[i].second--;
    }

    rep(i,R) rep(j,C) {
        if(S[i][j]=='.') continue;
        for(auto [a,b] : XY) {
            int nr = i+a;
            int nc = j+b;
            if(nr<0||nc<0||nr>=H||nc>=W)continue;
            T[nr][nc] = '#';
        }
    }
    rep(i,H) cout<<T[i]<<'\n';
    return 0;
}