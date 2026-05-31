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
    string S;
    cin>>S;

    ll cp=0, cn=0, cm=0;
    for(auto c:S) {
        if(c=='+')cp++;
        else if(c=='-')cn++;
        else cm++;
    }

    ll tp=0, tn=0, tm=0;
    vector<ll> score(cm);
    for(auto c:S) {
        if(c=='M') {
            // select go
            ll inc = (cp-tp) - (cn-tn);
            score[tm] = inc;
            tm++;
        }else if(c=='+') tp++;
        else tn++;
    }
    sort(score.rbegin(), score.rend());
    ll ans=0;
    rep(i,cm/2) ans+=score[i];
    for(auto i=cm-1;i>=cm/2;i--) ans-=score[i];
    cout<<ans<<endl;
    return 0;
}