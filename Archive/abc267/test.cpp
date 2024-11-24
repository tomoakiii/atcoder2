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

struct val_ind{
    int v;
    int i;
    bool operator== (const val_ind& x) const {
        return v == x.v;
    }
    bool operator!= (const val_ind& x) const {
        return v != x.v;
    }
    bool operator< (const val_ind& x) const {
        return v < x.v;
    }
    bool operator> (const val_ind& x) const {
        return v > x.v;
    }
    bool operator<= (const val_ind& x) const {
        return !(v > x.v);
    }

    bool operator>= (const val_ind& x) const {
        return !(v < x.v);
    }
};

int main(){
    val_ind a, b, c;
    a.v = 1;
    a.i = 2;
    b.v = 3;
    b.i = 4;
    if(a < b) cout << "Yes" << endl;
    else cout << "No" << endl;

    if(a > b) cout << "Yes" << endl;
    else cout << "No" << endl;

    if(a <= b) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    if(a >= b) cout << "Yes" << endl;
    else cout << "No" << endl;

    val_ind min = min(a, b);
    

    return 0;
}