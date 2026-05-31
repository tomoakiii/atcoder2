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
    if(N==2){
        cout<<1<<endl;
        return 0;
    }
    ll ans = 2; // itself and N-1
    for(ll k=2;k*k<=N;k++){
        if(N%k==0){
            vector<ll> ki(1,k);
            if(k!=N/k) ki.push_back(N/k);
            for(auto y:ki){
                ll x=N;
                while(x%y==0){
                    x/=y;
                }
                if(x%y == 1)ans++;
            }
        }
    }
    ll N2=N-1;
    for(ll k=2;k*k<=N2;k++){
        if(N2%k==0){
            ans++;
            if(k!=N2/k)ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}