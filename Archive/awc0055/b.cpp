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
    ll N,P,Q;
    cin >> N >> P >> Q;
    vector<pair<ll,ll>> A(N);
    rep(i,N) cin>>A[i].first >> A[i].second;
    sort(A.begin(),A.end());
    ll mn = INF;
    int p0,p1;
    rep(kkk,2) {
        rep(i,N) {
            ll d = abs(P-A[i].first);
            if(chmin(mn, d)) p0 = i;
        }
        A[p0].second++;
        swap(P,Q);
        swap(p0,p1);
        mn=INF;
    }
    if(p0 == p1) cout<<A[p0].second<<endl;
    else cout<<A[p0].second+A[p1].second<<endl;
    return 0;
}