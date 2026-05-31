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
    ll N,M;
    cin >> N >> M;
    vector<ll> A(N);
    map<ll, ll> mp;
    rep(i,N) cin>>A[i];
    rep(i,M) {
        ll b,c;
        cin>>b>>c;
        mp[c] += b;
    }
    sort(A.begin(), A.end());
    auto it = mp.rbegin();
    int id = 0;
    auto ans = [&]()->void{
        ll sm = 0;
        for(auto a: A) sm+=a;
        cout<<sm<<endl;
        return;
    };
    while(it != mp.rend()) {
        auto [m, v] = *it;
        rep(i,v) {
            if(m > A[id]) A[id++] = m;
            else {
                ans();
                return 0;
            }
            if(id == N) {
                ans();
                return 0;
            }
        }
        it++;
    }
    ans();
    return 0;
}