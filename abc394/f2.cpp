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
typedef pair<ll, bool> pib;

int main(){    
    int id = 1;
    auto func = [&](auto func, int cur, int d)->int{
        if(d == 3) return 0;
        rep(i,4) {            
            id++;
            cout << cur << " " << id << endl;
            func(func, id, d+1);
        }
        return 0;
    };
    func(func, 1, 0);


    return 0;
}