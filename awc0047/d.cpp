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
    vector<ll> A(N);
    ll sm=0;
    rep(i,N) {
        cin>>A[i];
        sm+=A[i];
    }
    if(sm%N!=0) {
        cout<<-1<<endl;
        return 0;
    }
    ll prem=0,nrem=0;
    ll ave = sm/N;
    ll ans=0;
    rep(i,N-1) {
        ll dl = A[i]-ave;
        if(dl>0) {
            if(nrem >= dl) {
                nrem-=dl;
                dl=0;
            } else {
                dl-=nrem;
                nrem=0;
                prem+=dl;
            }
        } else {
            dl*=-1;
            if(prem >= dl) {
                prem-=dl;
                dl=0;
            }else {
                dl-=prem;
                prem=0;
                nrem+=dl;
            }
        }
        ans+=prem+nrem;
    }
    cout<<ans<<endl;
    return 0;
}