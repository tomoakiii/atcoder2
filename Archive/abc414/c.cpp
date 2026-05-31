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
    ll A,N;
    cin >> A >> N;
    ll cnt = 0;

    auto f = [&](ll x)->bool{
        if(x > N) return false;
        vector<ll> vA;
        ll y = x;
        while(y) {
            vA.push_back(y%A);
            y/=A;
        }
        rep(j, vA.size()/2) {
            if(vA[j] != vA[vA.size()-j-1]) return false;            
        }
        cnt += x;
        return true;
    };

    for(ll x = 1; x <= 9; x++) f(x);    

    for(ll x = 1; x < 1E6; x++) {
        vector<ll> v10;
        ll x1 = x;
        ll d = 1;
        while(x1) {
            v10.push_back(x1%10);
            x1/=10;
            d *= 10;
        }
        reverse(v10.begin(), v10.end());
        ll p = v10[v10.size()-1];   
        for(int i = v10.size()-2; i>=0; i--) {
            p *= 10;
            p += v10[i];
        }
        f(d * x + p);
        rep(j, 10) f(d * (x * 10 + j) + p);            
    }
    cout<<cnt<<endl;
    return 0;
}