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
    ll M = 1e6;
    vector<ll> sm(M);
    rep(i,N) {
        sm[0]++;
        sm[A[i]]--;
    }
    rep(i, M - 1) {
        sm[i+1] += sm[i];
    }
    string ans;
    ll r = 0;
    rep(i, M) {
        r += sm[i];
        ans.push_back('0' + r%10);
        r /= 10;
    }
    while(r > 0) {
        ans.push_back('0' + r%10);
        r/=10;
    }
    while(ans.back() == '0') ans.pop_back();
    reverse(ans.begin(),ans.end());
    cout << ans << endl;
    return 0;
}