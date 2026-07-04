#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x7F7F7F7F7F7F7F7F;
const int INFi = 0x7F0F0F0F;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N;
    cin >> N;
    map<ll,ll> mp, mp2;
    ll mx=0;
    rep(i,N){
        ll a; cin>>a;
        mp[a]++;
        mp2[a]=i+1;
        chmax(mx,a);
    }
    if(mp[mx] > 1) cout<<-1<<endl;
    else cout<<mp2[mx]<<endl;
    return 0;
}