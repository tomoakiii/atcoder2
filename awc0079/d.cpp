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
    ll N,M,K;
    cin >> N >> M >> K;
    vector<ll> C(M);
    rep(i,M) {
        cin>>C[i];
        chmin(C[i],N);
    }
    ll rm=0;
    for(auto c:C){
        rm += c;
        if(rm >= N) {
            K--;
            rm %= N;
        }
    }
    if(K<=0)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}