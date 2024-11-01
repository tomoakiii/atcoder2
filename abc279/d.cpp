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
    double A, B;
    cin >> A >> B;
    double g = cbrt((A/2/B)*(A/2/B));
    double g1 = ceil(g), g2 = floor(g);
    cout << std::setprecision(24) << min(A/sqrt(g1)+(g1-1)*B, A/sqrt(g2)+(g1-1)*B) << endl;
    return 0;
}