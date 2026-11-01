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
    ll H,W,N,Q;
    cin >> H >> W >> N >> Q;
    vector<ll> sr, sc;
    rep(i,N){
        ll r,c; cin>>r>>c;
        sr.push_back(r);
        sc.push_back(c);
    }
    sort(sr.begin(),sr.end());
    sort(sc.begin(),sc.end());

    while(Q--){
        int op; ll b,e;
        cin>>op>>b>>e;
        auto func=[](vector<ll> &st, ll a, ll b){
            ll x = upper_bound(st.begin(), st.end(), b) - st.begin();
            ll y = lower_bound(st.begin(), st.end(), a) - st.begin();
            return x-y;
        };

        if(op==1){
            cout << func(sr, b, e) << endl;
        } else {
            cout << func(sc, b, e) << endl;
        }
    }
    return 0;
}