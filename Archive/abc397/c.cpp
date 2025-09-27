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
    rep(i,N) cin>>A[i];
    map<int, int> mp1, mp2;
    mp1[A[0]]++;
    rep(i, N-1) mp2[A[i+1]]++;
    ll mx = 0;
    chmax(mx, (ll)(mp1.size() + mp2.size()));
    rep(i, N-1) {
        mp1[A[i+1]]++;
        mp2[A[i+1]]--;
        if(mp2[A[i+1]] == 0) {
            mp2.erase(A[i+1]);
        }
        chmax(mx, (ll)(mp1.size() + mp2.size()));
    }
    cout << mx << endl;
    return 0;
}