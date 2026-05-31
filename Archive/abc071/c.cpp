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
    map<ll,ll> mp;

    rep(i,N) {
        ll a; cin>>a;
        mp[-a]++;
    }


    vector<ll> edge(2);
    for(auto [vo, c]: mp) {
        ll v = -vo;
        if(c >= 4) {
            chmax(edge[0], v);
            chmax(edge[1], v);
        } else if (c >= 2) {
            chmax(edge[1], v);
        }
        sort(edge.rbegin(), edge.rend());
        if(edge[1] > 0) {
            cout << edge[0] * edge[1] << endl;
            return 0;
        }
    }
    cout<<0<<endl;
    return 0;
}