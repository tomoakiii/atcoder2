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
    string S;
    cin>>S;
    string test[] = {"dream", "dreamer", "erase", "eraser"};
    while(!S.empty()) {
        bool flg = false;
        for(auto T: test) {
            if(T.size() > S.size()) continue;
            bool mtc = true;
            rep(j, T.size()) {
                if(S[S.size()-T.size()+j] != T[j]) mtc = false;
            }
            if(mtc) {
                flg = true;
                rep(j,T.size()) S.pop_back();
                break;
            }
        }
        if(!flg) {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}