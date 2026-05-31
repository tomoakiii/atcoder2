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
    ll N,M;
    cin >> N >> M;
    if(N<M) swap(N,M);
    if((N+M)%2==0){
        if(N!=M) cout<<0<<endl;
        else{
            mint ans = 1;
            for(ll k = 1; k <= N; k++) {
                ans *= k;
            }
            ans *= ans;
            ans *= 2;
            cout<<ans.val()<<endl;
        }
    } else {
        if(N!=M+1) cout<<0<<endl;
        else{
            mint ans = 1;
            for(ll k=1; k<=M; k++) {
                ans *= k;
            }    
            ans = ans * N * ans;
            cout << ans.val() << endl;
        }
    }
    return 0;
}