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
typedef pair<ll, ll> pll;
typedef pair<pll, pll> ppll;


ll divceil(ll a, ll b){
    if (a<0) return 0;
    return ((a+b-1)/b);
}


int main(){
    ll N, X;
    cin >> N >> X;
    vector<ppll> vAPBQ(N);
    rep(i,N){
        pll a, b;
        cin >> a.first >> a.second >> b.first >> b.second;
        if (a.first * b.second < b.first * a.second) {
            swap(a, b);
        }
        vAPBQ[i].first = a;
        vAPBQ[i].second = b;
    }
    auto fin=[&](ll tW, ppll i)->ll{
        pll a = i.first;
        pll b = i.second;
        
/*
        ll unt = tW / (a.first*b.first);
        unt *= b.first * a.first;
        ll acst = unt/a.first*a.second;
        tW -= unt;
        ll dsm = INF;
        ll k1=0, k2;
*/
        ll dsm = INF;    
        rep(k2, a.first+1) {
            ll k1 = divceil(tW-k2*b.first, a.first);
            ll d = k1*a.second + k2*b.second;
            chmin(dsm, d);
        }
        return(dsm);
    };

    auto f=[&](ll W)->bool{
        ll tmpX = 0;
        rep(i,N) {
            tmpX += fin(W, vAPBQ[i]);
        }
        if (tmpX <= X) return true;
        else return false;
    };
    // ll ok=0, ng=1789484;
    ll ok=0, ng=10E11+1;
    while(ng-ok > 1) {
        ll c = (ng+ok)/2;
        if(f(c)) ok=c;
        else ng=c;
  //      cout<<ok << " "<< ng<<endl;
    }
    cout << ok << endl;
    return 0;
}