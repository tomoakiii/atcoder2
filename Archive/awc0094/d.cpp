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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,A,B,C;
    cin >> N >> A >> B >>C;
    typedef modint1000000007 mint;
    mint ans = 1;
    ll sm = A*B*C;
    if(sm<N){
        cout<<0<<endl;
        return 0;
    }
    rep(i,N) {
        ans *= sm;
        sm--;
    }
    cout<<ans.val()<<endl;
    return 0;
}