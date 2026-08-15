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
    ll M,D;
    cin >> M >> D;
    string S; cin>>S;
    vector<bool> A(M);
    rep(i,M){
        if(S[i]=='G'){
            for(int j=i-D; j<=i+D; j++){
                if(j<0 || j>=M) continue;
                A[j]=true;
            }
        }
    }
    ll ans=0;
    rep(i,M)if(!A[i])ans++;
    cout<<ans<<endl;
    return 0;
}