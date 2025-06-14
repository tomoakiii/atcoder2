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
    ll N,M;
    cin >> N>>M;
    vector B(N, vector<ll>(M));
    rep(y,N)rep(x,M) {
        cin>>B[y][x];
        B[y][x]--;
        if(y>0) {
            if(B[y][x] != B[y-1][x] + 7) {
                cout<<"No"<<endl;
                return 0;
            }
        }
        if(x>0) {
            if(B[y][x] != B[y][x-1] + 1) {
                cout<<"No"<<endl;
                return 0;
            }
            if(B[y][x]%7 != B[y][x-1]%7 + 1) {
                cout<<"No"<<endl;
                return 0;
            }            
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}