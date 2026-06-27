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
    ll N,K;
    cin >> N >> K;
    vector<ll> pos, neg;
    rep(i,N) {
        ll x; cin>>x;
        if(x>=0) pos.push_back(x);
        else neg.push_back(-x);
    }
    auto get=[&K](vector<ll> &X)->ll{
        sort(X.begin(),X.end());
        ll ret = 0;
        while(!X.empty()){
            ret += 2 * X.back();
            rep(i,K) {
                if(!X.empty()) X.pop_back();
            }
        }
        return ret;
    };

    cout << get(pos) + get(neg) << endl;

    return 0;
}