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
    ll N;
    cin >> N;
    vector<ll> A(N),B(N);
    rep(i,N) cin>>A[i];
    rep(i,N) cin>>B[i];
    vector<ll> C(N);
    rep(i,N) C[i] = A[i]-B[i];
    bool flg= false;
    for(auto c:C) if(c>0) flg=true;
    if(!flg){
        cout<<"No"<<endl;
        return 0;
    }
    cout<<"Yes"<<endl;
    for(auto c:C) {
        if(c>0) cout<<(unsigned long long)1e18<<" ";
        else cout<<1<<" ";

    }
    cout<<endl;

    return 0;
}