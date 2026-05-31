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
    ll N,K;
    cin >> N>>K;
    string S; cin>>S;
    vector<int> SI(N);
    rep(i,N) SI[i] = (S[i]==S[0]);    
    int last = -1;
    for(int i=0; i<N; i++) {
        if(last != SI[i] && SI[i]==0){
            K--;
        }
        last = SI[i];
        if(K>=0) SI[i] = 1;
    }
    ll ans = 0;
    rep(i,N-1) {
        if(SI[i] == SI[i+1]) ans++;
    }
    cout<<ans<<endl;
    return 0;
}