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
    ll N,S,K;
    cin >> N >> S >> K;
    vector<ll> A(N-1);
    rep(i,N-1) cin>>A[i];
    auto func=[&](ll st)->bool{
        rep(i,N-1){
            if(st>=A[i]) st+=A[i];
            else{
                return false;
            }
        }
        return true;
    };

    if(!func(S+K)) {
        cout<<-1<<endl;
        return 0;
    }

    ll ok=S+K, ng=S-1;
    while(ok-ng>1){
        ll c=(ok+ng)/2;
        if(func(c)) ok=c;
        else ng=c;
    }
    cout<<ok-S<<endl;
    return 0;
}