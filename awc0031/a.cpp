#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x7F7F7F7F7F7F7F7F;
const int INFi = 0x7F0F0F0F;

int main(){
    ll N,M,K;
    cin >> N>>M>>K;
    vector<pair<pair<ll,int>,vector<ll>>> A(N);
    rep(i,N) {
        cin>>A[i].first.first;
        A[i].first.first*=-1;
        A[i].first.second=i;
        ll C; cin>>C;
        A[i].second.resize(C);
        rep(j,C) {
            cin>>A[i].second[j];
            A[i].second[j]--;
        }
    }
    sort(A.begin(), A.end());
    vector<ll> cnt(M,K);
    int ans=0;
    rep(i,K){
        for(auto c:A[i].second) {
            cnt[c]--;
            if(cnt[c]==0) ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}