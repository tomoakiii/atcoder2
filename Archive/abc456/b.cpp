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
    vector A(3, vector<int>(6));
    rep(i,3) {
        rep(j,6) cin>>A[i][j];
    }
    double ans = 0;
    vector<int> ex(3);
    ex[0]=4, ex[1]=5, ex[2]=6;
    do{
        double p=1;
        rep(i,3){
            double q=0;
            rep(j,6) {
                if(A[i][j] == ex[i]) q++;
            }
            p*=q/6;
        }
        ans+=p;
    }while(next_permutation(ex.begin(),ex.end()));
    printf("%.10f\n", ans);
    return 0;
}