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
    int N;
    cin >> N;
    vector<double> S(N);
    double os = (double)1/6;
    double lastEx = 0;
    rep(i, N) {
        double sm = 0;
        for(int j=1; j<=6; j++) {
            if((double)j < lastEx) {
                sm += lastEx;
            } else {
                sm += (double)j;
            }            
        }
        sm *= os;
        lastEx = sm;
    }
    cout << setprecision(24) << lastEx << endl;
    return 0;
}