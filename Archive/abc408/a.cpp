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
    ll N,S;
    cin >> N>>S;    
    ll c = 0;
    rep(i,N) {
        ll t;
        cin>>t;        
        if(t-c>S) {
            cout<<"No"<<endl;
            return 0;
        }
        c = t;
    }
    cout<<"Yes"<<endl;
    return 0;
}