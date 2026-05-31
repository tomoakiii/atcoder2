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
    string S; cin>>S;
    bool b = true;
    for(auto c:S) {
        if(b) {
            if(c>='A' && c<='Z') {
                cout<<"No"<<endl;
                return 0;
            }
        } else {
            if(c>='a' && c<='z') {
                cout<<"No"<<endl;
                return 0;
            }
        }
        b = !b;
    }
    cout<<"Yes"<<endl;
    return 0;
}
