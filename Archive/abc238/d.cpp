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
const int M = 60;
int main(){
    int T;
    cin>>T;
    while(T--) {
        ll a,s;
        cin>>a>>s;
        vector<ll> bit(M);
        rep(i,M){
            bit[i] = a%2;
            a/=2;
            s-=bit[i]<<(i+1);
        }
        for(int i=M-1; i>=0; i--){
            if(bit[i]) continue;
            ll bi = (ll)1<<i;
            if(s >= bi) {
                s-=bi;
            }
        }
        if(s==0) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}