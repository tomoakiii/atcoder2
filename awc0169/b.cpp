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
    ll N,M,K;
    cin >> N >> M >> K;
    vector<ll> W(N);
    ll smW=0, smR=0;
    rep(i,N) cin>>W[i];
    sort(W.rbegin(),W.rend());
    rep(i,K){
        smW+=W[i];
    }
    rep(i,M){
        ll r; cin>>r; smR+=r;
    }

    if(smW>=smR)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}