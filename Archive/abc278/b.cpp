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
    ll H, M;
    cin >> H >> M;
    while(true) {
        string h = to_string(H);
        string m = to_string(M);
        if (h.size() == 1) h = "0" + h;
        if (m.size() == 1) m = "0" + m;
        swap(h[1], m[0]); 
        ll hh = stoi(h);
        ll mm = stoi(m);
        if(0 <= hh && hh <= 23 && 0 <= mm && mm <= 59) {
            cout << H << " " << M << endl;
            return 0;
        }

        M++;
        if(M >= 60) {
            M = 0;
            H++;
            if(H >= 24) {
                H = 0;
            }
        }

    }
        
    return 0;
}