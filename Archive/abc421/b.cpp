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

ll f(ll in) {
    vector<int> out{};
    while(in) {
        out.push_back(in%10);
        in /= 10;
    }
    ll ret = 0;
    for(auto k: out) {
        ret = ret*10;
        ret += k;
    }
    return ret;
}


int main(){
    ll X,Y;
    cin>>X>>Y;
    ll ls2 = X, ls1 = Y;    
    for(int i=3; i<=10; i++) {
        ll fg = f(ls1 + ls2); 
        if(i==10) {
            cout << fg << endl;
            return 0;
        }
        ls2 = ls1;
        ls1 = fg;
    }
    return 0;
}