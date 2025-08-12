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
    vector<double> A(N),B(N),T(N);
    double total = 0;
    rep(i,N) {
        cin>>A[i]>>B[i];
        T[i] = A[i]/B[i];
        total += T[i];
    }

    double sub = 0;
    double len = 0;
    rep(i,N) {
        double sub2 = sub + T[i];
        if(sub2 >= total/2) {
            double delta = total/2 - sub;
            double len2 = B[i] * delta;
            printf("%.10f\n", len + len2);
            return 0;
        }
        sub = sub2;
        len += A[i];
    }
    return 0;
}