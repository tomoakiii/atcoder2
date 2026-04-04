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
    vector<ll> A(N),B(N);
    rep(i,N) {
        cin>>A[i]>>B[i];
        B[i]--;
    }
    ll M; cin>>M;
    vector<string> S(M);
    vector cnd(11, vector<bool>('z'-'a'+1));
    rep(i,M) {
        cin>>S[i];
        rep(j,N) {
            if(A[j] == S[i].size()) {
                int c = S[i][B[j]] - 'a';
                cnd[j][c] = true;
            }
        }
    }
    for(auto s: S) {
        if(s.size()!=N) {
            cout<<"No"<<endl; continue;
        }
        bool flg= true;
        rep(i, s.size()) {
            if(!cnd[i][s[i]-'a']) flg = false;
        }
        if(flg) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}