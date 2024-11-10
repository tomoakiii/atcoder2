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
    string T, S;
    cin >> S >> T;
    bool ans = false;
    
    for(ll i=0; i < (int)S.size() - (int)T.size() + 1; i++) {
        bool tmp = true;
        rep(j, T.size()){
            if (S[i+j] != T[j]) tmp = false;
        }
        ans |= tmp;
    }
    
    if(ans) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}