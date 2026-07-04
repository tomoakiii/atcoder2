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
    ll N,K,M;
    cin >> N >> K >> M;
    vector<ll> A(N),B(N);
    rep(i,N) cin>>A[i];
    rep(i,N) cin>>B[i];
    int r=0;
    unordered_map<ll,ll> mp;
    multiset<ll> stb;
    ll mn=0,mx=0;
    ll ans=0;
    rep(l,N) {
        auto upd=[&]()->void{
            if(stb.empty()) {
                mx=mn=0;
                return;
            }
            mn = *stb.begin();
            auto it=stb.end();
            it--;
            mx = *it;
        };
        while(r<N && mp.size() * (r-l+1) <=K && (mx-mn)<=M ){
            r++;
            if(r==N) break;
            mp[A[r]]++;
            stb.insert(B[r]);
            upd();
        }
        ans += r-l;
        mp[A[l]]--;
        if(mp[A[l]]==0) mp.erase(A[l]);
        stb.erase(stb.find(B[l]));
        upd();
    }
    cout<<ans<<endl;

    return 0;
}