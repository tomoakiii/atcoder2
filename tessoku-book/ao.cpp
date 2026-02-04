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
typedef pair<ll, pair<int,int>> pl;

int main(){
    ll N;
    string T;
    cin>>N>>T;
    rep(i,N-2) {
        if(T[i] == T[i+1] && T[i+1] == T[i+2]) {
            cout <<"Yes"<<endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}