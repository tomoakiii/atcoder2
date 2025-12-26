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
    string N;
    cin >> N;
    bool flg = false;
    if(N[1]==N[2]){
        if(N[0] == N[1] || N[2]==N[3]) flg = true;
    }
    if(flg) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}