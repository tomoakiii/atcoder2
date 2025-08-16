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
    int m;
    string S;
    cin >> m >> S;
    if(m < 3) {
        cout<<"No"<<endl;
        return 0;
    }
    if(S[m-1] == 'a' && S[m-2] == 'e' && S[m-3] == 't') cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}