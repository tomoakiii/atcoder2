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
    vector<ll> A(N+1);
    rep(i,N) cin>>A[i+1];
    vector<ll> B(N+1);
    vector<int> ans;
    for(int i=N;i>=1;i--) {
        int sm = 0;
        for(int j=i*2;j<=N;j+=i){
            sm += B[j];
        }
        sm%=2;
        if(sm!=A[i]) {
            B[i]=1;
            ans.push_back(i);
        }
    }
    cout<<ans.size()<<endl;
    for(auto a: ans)cout<<a<<" ";
    cout<<endl;
    return 0;
}