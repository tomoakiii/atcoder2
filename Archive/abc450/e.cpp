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
    string X,Y; cin>>X>>Y;
    int Q; cin>>Q;
    ll M=26;
    vector Xcnt(X.size()+1,vector<ll>(M)), Ycnt(Y.size()+1,vector<ll>(M));
    rep(kkk,2) {
        rep(i,X.size()) {
            Xcnt[i+1] = Xcnt[i];
            Xcnt[i+1][X[i]-'a']++;
        }
        swap(X,Y); swap(Xcnt,Ycnt);
    }

    struct S{
        ll sm1,sm2,len;
        vector<ll> cnt;
        S(ll sm1, ll sm2, vector<ll> vl):sm1(sm1),sm2(sm2),cnt(vl){
            len = sm1+sm2;
        }
    };

    vector<S> F;
    F.push_back(S(0,X.size(),Xcnt[X.size()]));
    F.push_back(S(0,Y.size(),Ycnt[Y.size()]));

    for(int k=2; F[k-1].len < 2e18; k++) {
        int i=k-2,j=k-1;
        F.push_back(S(F[j].len,F[i].len,vector<ll>(M,0)));
        rep(m,M) F[k].cnt[m] = F[i].cnt[m]+F[j].cnt[m];
    }
    auto get=[&](auto get, ll p, ll k, int c)->ll{
        if(k==0) return Xcnt[p+1][c];
        if (k==1) return Ycnt[p+1][c];
        if(F[k].sm1 > p) return get(get,p,k-1,c);
        return F[k-1].cnt[c] + get(get,p-F[k].sm1,k-2,c);
    };

    ll K=F.size()-1;
    while(Q--){
        ll l,r; char cr; cin>>l>>r>>cr;
        l--,r--;
        int c=cr-'a';
        if(l>0) cout<<get(get,r,K,c)-get(get,l-1,K,c)<<endl;
        else cout<<get(get,r,K,c)<<endl;
    }
    return 0;
}