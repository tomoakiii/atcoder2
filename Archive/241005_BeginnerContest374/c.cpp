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
    vector<ll> K(N, 0);
    rep(i,N){
        cin>>K[i];
    }
    ll mn = INF;
    rep(i, 1<<N){
        ll A=0, B=0;
        rep(j,N){
            if((i>>j) & 1) {
                A+=K[j];
            } else{
                B+=K[j];
            } 
        }
        chmin(mn, max(A, B));
    }    
    cout << mn << endl;
    return 0;
}