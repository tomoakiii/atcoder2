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
typedef pair<ll,ll> p;
int main(){
    ll D,W; cin>>D>>W;
    string dir;
    D*=10;
    if((34875<=D&&D<=36000) || D<1125) dir="N";
    else if(D<3375) dir="NNE";
    else if(D<5625) dir="NE";
    else if(D<7875) dir="ENE";
    else if(D<10125) dir="E";
    else if(D<12375) dir="ESE";
    else if(D<14625) dir="SE";
    else if(D<16875) dir="SSE";
    else if(D<19125) dir="S";
    else if(D<21375) dir="SSW";
    else if(D<23625) dir="SW";
    else if(D<25875) dir="WSW";
    else if(D<28125) dir="W";
    else if(D<30375) dir="WNW";
    else if(D<32625) dir="NW";
    else if(D<34875) dir="NNW";
    ll pow;
    double ws = W;
    ws /= 60;
    ws *= 10;
    ll wsl = round(ws);
    int th[] = {0,03,16,34,55,80,108,139,172,208,245,285,327,10000};
    rep(i,(int)sizeof(th)) {
        if(wsl >= th[i]) pow = i;
        else break;
    }
    if(pow==0) dir = "C";
    cout << dir << " " << pow << endl;
    return 0;
}

