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
    vector<ll> A(N);
    vector<ll> nm(N);
    rep(i,N) {
        cin>>A[i];
        A[i]--;
        nm[A[i]]++;
    }
    ll sm = 0;
    rep(i,N) {
        sm += nm[i] * (nm[i]-1) / 2;
    }
    rep(i,N) {
        ll t = nm[A[i]] * (nm[A[i]]-1) / 2; 
        sm -= t;
        ll p = (nm[A[i]]-1) * (nm[A[i]]-2) / 2;
        sm += p;
        cout << sm << endl;
        sm -= p;
        sm += t;
    }    
    return 0;
}