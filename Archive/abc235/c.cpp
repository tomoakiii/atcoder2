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
    ll N, Q;
    cin >> N >> Q;        
    map<ll, int> mp1; // x times k
    map<ll, map<int, int>> mp2; // mp2[x][j] = p; jth - x is at index-p
    rep(i,N) {
        ll a;
        cin>>a;
        mp1[a]++;
        mp2[a][mp1[a]] = i+1;
    }

    while(Q--){
        ll x, k;
        cin >> x >> k;
        if(!mp2.contains(x) || !mp2[x].contains(k)) cout<<-1<<endl;
        else cout<<mp2[x][k]<<endl;
    }
    return 0;
}