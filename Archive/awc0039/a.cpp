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
    ll N,M,Q;
    cin >> N >> M >> Q;
    string S(N,'*');
    rep(i,M) {
        int p;
        char c;
        cin>>p>>c;
        p--;
        S[p]=c;
    }
    while(Q--) {
        string T; cin>>T;
        bool flg=true;
        rep(i,N) {
            if(S[i]!='*' && S[i]!=T[i])  {
                flg=false;
                break;
            }
        }
        if(flg)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}