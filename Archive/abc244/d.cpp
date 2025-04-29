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
    char S[3];
    char T[3];
    rep(i,3) cin>>S[i];
    rep(i,3) cin>>T[i];
    vector<vector<int>> sw = {{0,1}, {0,2}, {1,2}};
    rep(i,3){
        swap(S[sw[i][0]], S[sw[i][1]]);
        if(S[0]==T[0] && S[1]==T[1]){
            cout<<"No"<<endl;
            return 0;
        }
        swap(S[sw[i][0]], S[sw[i][1]]);
    }
    cout<<"Yes"<<endl;
    return 0;
}