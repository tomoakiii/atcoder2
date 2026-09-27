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
    ll N,T;
    cin >> N >> T;
    int N1=(N+1)/2;
    int N2=N-N1;
    vector<ll> A(N1),B(N2);
    rep(i,N1) cin>>A[i];
    rep(i,N2) cin>>B[i];
    if(N==1){
        if(A[0]==T)cout<<"ALMOST"<<endl;
        else cout<<"NO"<<endl;
        return 0;
    }
    ll ful1=1ll<<N1, ful2=1ll<<N2;
    vector<ll> P1(ful1,-INF),P2(ful2,-INF);
    rep(kkk,2){
        rep(S,ful1){
            ll sm=0;
            rep(i,N1){
                if(S>>i & 1){
                    sm+=A[i];
                    if(sm>T) {
                        sm=-1;
                        break;
                    }
                }
            }
            P1[S]=sm;
        }
        swap(P1,P2);
        swap(A,B);
        swap(N1,N2);
    }
    map<ll,ll>mp,mp2;
    rep(S,ful1){
        mp[P1[S]]++;
    }
    rep(S,ful2)mp2[P2[S]]++;
    mp2[0]=1;
    ll ans=0;
    for(auto [m,v]:mp){
        if(m>T)continue;
        if(m<0)continue;

        ll tgt=T-m;
        ans+=v*mp2[tgt];
    }
    if(ans>1)cout<<"YES"<<endl;
    else if(ans==1)cout<<"ALMOST"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}