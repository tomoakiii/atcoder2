#include <bits/stdc++.h>
#include <atcoder/all>
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
    ll sm = 0;
    rep(i,N) {
        cin>>A[i];
        sm+=A[i];
    }
    if(sm%10 != 0) {
        cout << "No" << endl;
        return 0;
    }
    ll tgt = sm/10;
    int l = 0, r = 0;
    ll sz = A[0];
    while(l < N) {
        if(sz == tgt) {
            cout << "Yes" << endl;
            return 0;
        }
        if(sz > tgt) {
            sz -= A[l];
            l++;
        }
        while(sz < tgt) {
            r++;
            r %= N;
            sz += A[r];
        }
    }
    cout << "No" << endl;
    return 0;
}