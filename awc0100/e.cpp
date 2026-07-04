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
    map<ll,ll> mp;
    vector<pair<ll,int>> A(N);
    vector<ll> ans(N);
    rep(i,N) {
        cin>>A[i].first;
        A[i].second=i;
    }
    sort(A.rbegin(),A.rend());
    ll last=INF;
    ll sm=0;
    ll tmp=0;
    for(auto [a,i]:A){
        if(a<last) {
            sm+=tmp;
            tmp=1;
        } else {
            tmp++;
        }
        ans[i]=sm;
        last=a;
    }
    rep(i,N) cout<<ans[i]<<" \n"[i==N-1];

    return 0;
}