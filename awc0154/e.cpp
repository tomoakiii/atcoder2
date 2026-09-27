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
    ll N,D;
    cin >> N >> D;
    vector<ll> X(N), Y(N);
    rep(i,N)cin>>X[i]>>Y[i];
    rep(i,N){
        X[i]*=2; Y[i]*=2;
    }
    D*=2;
    set<pair<ll,ll>> st;
    rep(i,N)rep(j,N){
        if(i==j)continue;
        st.insert({(X[i]+X[j])/2, (Y[i]+Y[j])/2});
    }
    struct abc{
        ll a,b,c;
    };
    // X[p0], Y[p0] および X[p1], Y[p1] を通る直線の係数
    auto make_ab = [&](ll x1, ll x2, ll y1, ll y2)-> abc{
        // return abc for a*x + b*y + c = 0
        ll dX = x1 - x2;
        ll dY = y1 - y2;
        abc out;
        if(dX == 0) { // X = X[p0]
            out.a = 1;
            out.b = 0;
            out.c = -1 * x1;
            return out;
        } else if (dY == 0) { // Y = Y[p0];
            out.a = 0;
            out.b = 1;
            out.c = -1 * y1;
            return out;
        }
        ll g = gcd(dX, dY);
        dX /= g, dY /= g;
        if(dX < 0) {
            dX*=-1;
            dY*=-1;
        }
        // y = dY/dX * x + c / dX;
        // dY * x - dX * U + c = 0
        out.a = dY, out.b = -1*dX, out.c = dX*y1 - dY*x1;
        return out; 
    };
    ll ans=0;
    for(auto [x1,y1]:st){
        for(auto [x2,y2]:st){
            if(x1==x2 && y1==y2)continue;
            abc r = make_ab(x1,x2,y1,y2);
            ll cnt=0;
            rep(i,N){
                ll p=(r.a*X[i]+r.b*Y[i]+r.c);
                p*=p;
                ll q=r.a*r.a+r.b*r.b;
                if(p <= D*D*q)cnt++;
            }
            chmax(ans,cnt);
        }
    }
    cout<<ans<<endl;
    return 0;
}