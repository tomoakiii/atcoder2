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
    vector<string> S(N), T(M);
    rep(i,N) cin>>S[i];
    rep(i,M) cin>>T[i];
    ll cnt=0;
    rep(i,N) {
        rep(j,M){
            bool flg2 = true;
            rep(k,3) if(S[i][k+3]!=T[j][k]) flg2 = false;
            if(flg2) {
                cnt++;
                break;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}