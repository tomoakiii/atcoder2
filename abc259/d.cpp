#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    int N;    
    cin >> N;
    ll sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    int si, ti;
    dsu UF(N);
    vector<ll> x(N), y(N), r(N);
    rep(i,N) cin>>x[i]>>y[i]>>r[i];        
    rep(i,N) {
        rep(j,N) {
            if((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]) > (r[i]+r[j])*(r[i]+r[j])) continue;
            if((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]) < (r[i]-r[j])*(r[i]-r[j])) continue;
            UF.merge(i,j);
        }
        if((x[i]-sx)*(x[i]-sx) + (y[i]-sy)*(y[i]-sy) == r[i]*r[i]) si = i;
        if((x[i]-tx)*(x[i]-tx) + (y[i]-ty)*(y[i]-ty) == r[i]*r[i]) ti = i;
    }
    if(UF.same(si, ti)) cout<<"Yes"<<endl;
    else  cout<<"No"<<endl;
    
    return 0;
}