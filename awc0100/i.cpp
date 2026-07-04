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
    ll N, M, s;
    cin >> N >> M >> s;
    s--;
    fenwick_tree<int> FT(N);
    ll sm=N;
    rep(i,N)FT.add(i,1);
    while(M--){
        ll d; cin>>d;
        FT.add(s,-1);
        sm--;
        d=(d-1)%sm;
        d++;
        int ok=N,ng=0;
        while(ok-ng>1){
            int c=(ok+ng)/2;
            int c2=c+s;
            c2%=N;
            ll x;
            if(c2<s){
                x=FT.sum(s,N)+FT.sum(0,c2+1);
            }else{
                x=FT.sum(s,c2+1);
            }
            if(x>=d) ok=c;
            else ng=c;
        }
        s+=ok;
        s%=N;
    }
    cout<<s+1<<endl;
    return 0;
}