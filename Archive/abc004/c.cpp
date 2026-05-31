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
    vector<ll> A(6);
    rep(i,6) A[i]=i+1;
    ll c = 0;
    while(N>0) {
        N--;
        swap(A[c%5], A[c%5 + 1]);
        c++;
        bool flg = true;
        rep(i,6) if(A[i] != i+1) flg = false;
        if(flg) {
            break;
        }
    }
    ll p = N/c;
    N -= p*c;
    c += p*c;
    while(N--) {
        swap(A[c%5], A[c%5 + 1]);
        c++;
    }
    rep(i,6) cout << A[i];
    cout << endl;
    return 0;
}