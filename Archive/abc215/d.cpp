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
    cin >> N>>M;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    vector<bool> visit(1E5+1);
    rep(i,N) {
        visit[A[i]] = true;
        for(int j=2; j*j<=A[i]; j++ ){
            if(A[i]%j == 0) {
                visit[j] = true;
                visit[A[i]/j] = true;
            }
        }
    }
    for(int i=2; i<=M; i++) {
        if(!visit[i]) continue;
        for(int j=1; i*j<=M; j++) {
            visit[i*j] = true;
        }
    }

    set<int> ans;
    ans.insert(1);
    for(int m=1; m<=M; m++){
        if(!visit[m]) ans.insert(m);
    }
    cout<<ans.size()<<endl;
    for(auto a: ans) cout<<a<<endl;
    return 0;
}