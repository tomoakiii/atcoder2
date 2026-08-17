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
typedef long double ld;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,K; string S;
    cin >> N >> K >> S;
    ld ok = 0, ng = 1;
    vector<int> L(N,-1);
    int r=0; ll sm=0;
    rep(l,N){
        while(sm<K && r<N){
            if(S[r++]=='o')sm++;
        }
        if(sm==K){
            L[r-1]=l;
        }
        sm-=(S[l]=='o');
    }
    int last = -1;
    rep(i,N){
        if(L[i]!=-1)last=L[i];
        L[i]=last;
    }
    auto chk=[&](ld x)->bool{
        int r=0;
        vector<ld> v(N+1);
        rep(i,N)v[i+1]=(S[i]=='o')?1.0-x:-x;
        rep(i,N)v[i+1]+=v[i];
        int l=0;
        ld mn=1e18;
        rep(r,N){
            if(L[r]==-1)continue;
            while(l<=L[r]){
                chmin(mn, v[l]);
                l++;
            }
            if(v[r+1]-mn>=0) {
                return true;
            }
        }
        return false;
    };
    rep(k,30){
        ld c = (ok+ng)/2;
        if(chk(c))ok=c;
        else ng=c;
    }
    printf("%.20Lf\n", ok);
    return 0;
}