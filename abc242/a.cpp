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
    ll A,B,C,X;
    cin >> A >> B >> C >> X;
    if(X<=A) cout<<0.9999999<<endl;
    else if (X>B) cout<<0.0000001<<endl;
    else {
        double p = (double)C / ((double)B-A);
        printf("%.9f\n", p);
    }
    
    return 0;
}