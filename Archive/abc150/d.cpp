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
    cin >> N >> M;
    vector<ll> A(N);
    int t=-1;
    ll lc=1;
    rep(i,N) {
        cin>>A[i];
        A[i]/=2;
        int p=0;
        while(A[i]%2==0) {
            A[i]/=2;
            p++;
        }
        lc = lcm(lc, A[i]);
        if(lc>M) {
            cout<<0<<endl;
            return 0;
        }
        if(t==-1)t=p;
        else if(t!=p){
            cout<<0<<endl;
            return 0;
        }
    }
    ll p2=1;
    rep(i,t) p2*=2;
    if(lc>M/p2){
        cout<<0<<endl;
        return 0;
    }
    if(lc*p2>M) {
        cout<<0<<endl;
        return 0;
    }
    ll ok=1, ng=1e9;
    while(ng-ok>1) {
        ll c = (ok+ng)/2;
        if(lc*p2*c > M) ng=c;
        else ok=c;
    }
    cout<<(ok+1)/2<<endl;
    return 0;
}