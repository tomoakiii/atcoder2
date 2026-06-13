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
    rep(i,N) {
        cin>>A[i];
        A[i]--;
    }
    rep(i,N) {
        cin>>B[i];
        B[i]--;
    }
    rep(i,N) {
        ll ax=A[i];
        if(B[ax] != i) {
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;


    return 0;
}