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
    ll N,Q;
    cin >> N >> Q;
    vector<ll> P(N);
    vector<ll> O(N);

    rep(i,N) {
        cin>>P[i];
        P[i]--;
        O[P[i]] = i;
    }
    while(Q--){
        int a; cin>>a; a--;
        int pos = O[a];
        P[pos] = -1;
        P.push_back(a);
        O[a] = P.size()-1;
    }
    for(auto p:P){
        if(p!=-1) cout<<p+1<<" ";
    }
    cout<<endl;
    return 0;
}