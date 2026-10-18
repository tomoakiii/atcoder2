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
    ll N;
    cin >> N;
    vector<ll>X(N),Y(N);
    ll ee=0,eo=0,oe=0,oo=0;
    rep(i,N){
        cin>>X[i]>>Y[i];
        if(X[i]%2==0){
            if(Y[i]%2==0)ee++;
            else eo++;
        } else {
            if(Y[i]%2==0)oe++;
            else oo++;
        }
    }
    struct abc{
        ll a,b,c;
        bool operator< (const abc& x) const {
            return ((a==x.a)? ((b==x.b)?(c<x.c) : (b<x.b)) : ((a<x.a)));
        }
    };
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
        out.a = dY, out.b = -1*dX, out.c = dX*y1 - dY*x1;;
        return out; 
    };
    ll dup = 0;
    rep(i,N){
        map<abc,int> mp;
        for(int j=i+1;j<N;j++){
            mp[make_ab(X[i],X[j],Y[i],Y[j])]++;
        }
        for(auto [v,c]:mp){
            dup += c * (c-1) / 2;
        }
    }
    ll tot = N * (N-1) * (N-2) / 6;
    ll ng = oo*oe*eo + oo*oe*ee + oe*eo*ee + oo*eo*ee;
    cout << tot - ng - dup << endl;
    return 0;
}