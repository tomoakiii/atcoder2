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
    ll N = 10;
    vector<string> S(N);
    rep(i,N) cin>>S[i];
    int A=-1, B=-1, C=-1, D=-1;
    rep(i,N) {
        rep(j, N) {
            if(S[i][j] == '#') {
                if(A == -1) A = i+1;
                if(C == -1) C = j+1;
                B = i+1;
                D = j+1;
            }
        }
    }
    cout << A << " " << B << endl << C << " " << D << endl;
    return 0;
}