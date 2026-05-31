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
    vector<ll> A(N);
    map<ll,ll> mp;
    rep(i,N) {
        cin>>A[i];
        mp[A[i]]++;
    }
    ll ans = 0;
    sort(A.begin(), A.end());
    for(auto a: A) {
        if(!mp.contains(a)) continue;
        for(ll i = 2; a * i <= 1E6; i++) {
            if(mp.contains(a * i)) {
                mp.erase(a*i);
            }
        }
        if(mp[a] > 1) mp.erase(a);
    }
    cout << mp.size() << endl;
    return 0;
}