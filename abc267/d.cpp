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
    ll N;
    cin >> N;
    vector<ll> A(N);
    int R1=1, R2=N, C1=1, C2=N;
    while(R2>R1){
        int r = (R1+R2)/2;
        cout << "? " << R1 << " " << r << " " << 1 << " " << N << endl;
        int q;
        cin >> q;
        if (q == (r-R1+1)) {
            R1 = r+1;
        } else {
            R2 = r;
        }
    }
    while(C2>C1){
        int c = (C1+C2)/2;
        cout << "? " << 1 << " " << N << " " << C1 << " " << c << endl;
        int q;
        cin >> q;
        if (q == (c-C1+1)) {
            C1 = c+1;
        } else {
            C2 = c;
        }
    }
    cout << "! " << R1 << " " << C1 << endl;
    return 0;
}