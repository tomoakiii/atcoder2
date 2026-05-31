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

ll divceil(ll a, ll b){
    return (a+b-1)/b;
}

int main(){
    ll ABC[3];
    ll X,Y; cin>>X>>Y>>ABC[0]>>ABC[1]>>ABC[2];    
    rep(kk,2) {
        rep(k,3) {
            ll A = ABC[k], B = ABC[(k+1)%3], C = ABC[(k+2)%3];
            ll w = divceil(A, Y);
            ll dx = X-w;
            if(dx <= 0) continue;

            ll h = divceil(B, dx);
            ll dy = Y-h;            
            if(dy * dx >= C) {
                cout << "Yes" << endl;
                return 0;
            }
        
            ll w2 = divceil(B, Y);
            ll dx2 = dx - w2;            
            if(dx2 * Y >= C){
                cout << "Yes" << endl;
                return 0;
            }
        }
        swap(X,Y);
    }
    cout << "No" << endl;
    return 0;
}