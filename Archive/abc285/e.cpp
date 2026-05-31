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
    vector<ll> A(N, 0);
    rep(i,N) cin>>A[i];
    if(N==1) {cout<<0<<endl; return 0;}
    if(N==2) {cout<<A[0]<<endl; return 0;}
    if(N==3) {cout<<2*A[0]<<endl; return 0;}

    vector<ll> M(N+10,-1);
    M[0] = 0;
    M[1] = 0;
    M[2] = A[0];
    M[3] = 2*A[0];
    auto func = [&](auto func, ll x)->void{
        if (M[x]!=-1) return;
        M[x] = 0;
        for(ll i=1; i<x; i++) {
            M[x] += A[min(i-1, x-1-i)];
        }
        for(int i=1; i<x-1; i++) {
            if(M[i] == -1) func(func,i);
            if(M[x-i]==-1) func(func, x-i);
            chmax(M[x], M[i] + M[x-i]);
        }
    };
    func(func, N);
    cout<<M[N]<<endl;
    return 0;
}