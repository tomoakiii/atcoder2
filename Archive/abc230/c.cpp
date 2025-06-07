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
    ll N, A, B, P, Q, R, S;
    cin >> N >> A >> B >> P >> Q >> R >> S;
    for(ll i = P; i <= Q; i++) {
        for(ll j = R; j <= S; j++) {            
            if(i==j+(A-B) || i==A+B-j) cout<<"#";
            else cout<<".";            
        }
        cout<<endl;
    }
    return 0;
}