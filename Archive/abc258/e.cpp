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
    ll N,Q,X;
    cin >> N >> Q >> X;
    vector<ll> A(2*N);
    ll sm = 0;
    rep(i,N) {
        cin>>A[i];
        sm+=A[i];
        A[i+N]=A[i];
    }
    rep(i,2*N-1) A[i+1]+=A[i];
    vector nx(100, vector<int>(N));
    rep(i,N) nx[0][i]=i;
    vector<ll> nm(N);
    rep(i,N) {
        ll last = 0; 
        if(i>0) last = A[i-1];
        int np;
        ll tg = X%sm+last;
        np = lower_bound(A.begin(),A.end(),tg)-A.begin();
        nm[i] = np-i+1;
        nx[1][i] = (np+1)%N;
    }
    for(int k=2;k<100;k++){
        rep(i,N) {
            int np = nx[k-1][i];
            nx[k][i] = nx[k-1][np];
        }
    }
    while(Q--){
        ll k; cin>>k;
        k--;
        int st = 0;
        int id = 1;
        while(k) {
            if(k%2) {
                st=nx[id][st];
            }
            id++;
            k/=2;
        }
        ll p=X/sm;
        cout<<p*N+nm[st]<<endl;
    }
    return 0;
}