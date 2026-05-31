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
    ll N, K; cin>>N>>K;
    ll a = N;
    rep(i,K) {
        vector<int> nm;
        while(a) {
            nm.push_back(a%10);
            a/=10;
        }
        sort(nm.begin(), nm.end());
        ll sm0 = 0, sm1 = 0;
        rep(i,nm.size()) {
            sm0 = sm0 * 10 + nm[i];
            sm1 = sm1 * 10 + nm[nm.size()-1-i];
        }
        a = sm1 - sm0;
    }
    cout << a << endl;
    return 0;
}
