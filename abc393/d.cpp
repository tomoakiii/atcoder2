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
    string S;
    cin >> S;
    vector<int> p1;
    rep(i,N) {
        if(S[i] == '1') p1.emplace_back(i);
    }
    int sz = p1.size();
    if(sz == 1) {
        cout << 0 << endl;
        return 0;
    } else if(sz == 2) {
        cout << p1[1] - p1[0] - 1 << endl;
        return 0;
    }
    int ct = sz / 2;
    ll ans = 0;
    ll c0=0;
    for(int i = p1[ct] + 1; i < N; i++) {
        if(S[i] == '0') {
            c0++;
        } else {            
            ans += c0;
        }
    }
    c0 = 0;
    for(int i = p1[ct] - 1; i >= 0; i--) {
        if(S[i] == '0') {
            c0++;
        } else {            
            ans += c0;
        }
    }
    cout << ans << endl;
    return 0;
}