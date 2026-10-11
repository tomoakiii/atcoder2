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
    ll N,D;
    cin >> N >> D;
    vector<pair<ll,int>> A(N);
    rep(i,N) {
        cin>>A[i].first;
        A[i].second=i+1;
    }
    sort(A.begin(),A.end());
    vector<int> ans;
    rep(i,N){
        ll d=INF;
        if(i>0) chmin(d,A[i].first-A[i-1].first);
        if(i<N-1) chmin(d,A[i+1].first-A[i].first);
        if(d>=D) ans.push_back(A[i].second);
    }
    sort(ans.begin(), ans.end());
    cout<<ans.size()<<endl;
    rep(i,ans.size())cout<<ans[i]<<" \n"[i==ans.size()-1];
    return 0;
}