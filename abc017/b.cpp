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
    string X; cin>>X;
    while(X.size() > 0){
        if(X.back()=='o'||X.back()=='k'||X.back()=='u') {
            X.pop_back(); continue;
        }
        if(X.size()>1 && X.back()=='h' && X[X.size()-2]=='c') {
            X.pop_back(); X.pop_back(); continue;
        }
        break;
    }
    if(X.size()==0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}