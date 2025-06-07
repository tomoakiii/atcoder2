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
    map<int, int> mp;
    vector<ll> A(N);
    rep(i,N) {
        cin >> A[i];
        mp[-A[i]]++;
    }
        
    for(auto m: mp) {
        if(m.second == 1) {
            ll tgt = -1 * m.first;
            rep(i, N) {
                if(A[i] == tgt) {
                    cout << i+1 << endl;
                    return 0;
                }
            }
        }        
    }
    cout << -1 << endl;
    return 0;
}