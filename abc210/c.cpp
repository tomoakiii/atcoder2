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
    ll N,K;
    cin >> N >> K;
    map<ll, int> mp;
    vector<ll> C(N);
    rep(i,N) {
        cin>>C[i];
        if(i<K) mp[C[i]]++;
    }

    int ans = mp.size();
    for(int i=K; i<N; i++){
        mp[C[i]]++;
        mp[C[i-K]]--;
        if(mp[C[i-K]] == 0) {
            mp.erase(C[i-K]);
        }
        chmax(ans, (int)mp.size());
    }
    cout<<ans<<endl;
    return 0;
}