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
    ll N,M,T;
    cin >> N >> M >> T;
    ll eng = N;
    ll t = 0;
    rep(i,M) {
        ll a, b; cin >> a >> b;
        ll use = a-t;
        if(use >= eng) {
            cout << "No" << endl;
            return 0;
        }
        eng -= use;
        ll chg = b-a;
        eng = min(eng + chg, N);
        t = b;
    }
    if(eng <= T-t) cout<<"No"<<endl;
    else cout << "Yes" << endl;
    return 0;
}