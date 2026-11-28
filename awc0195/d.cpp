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
    ll N;
    cin >> N;
    vector<ll> C(N);
    rep(i,N) cin>>C[i];
    map<ll,int>mp;
    int l=0;
    int r=0;
    ll ans=0;
    while(r<N){
        while(r<N && mp.size()<7){
            mp[C[r++]]++;
        }
        if(mp.size()<7){
            break;
        }
        ans += N-r+1;
        while(l<r && mp.size()==7){
            mp[C[l]]--;
            if(mp[C[l]]==0) {
                mp.erase(C[l]);
            } else {
                ans += N-r+1;
            }
            l++;
        }
    }
    cout << ans << endl;
    return 0;
}