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
    string T1 = S.substr(0, S.size()/2);
    string T2 = S.substr(S.size()/2 + 1, S.size()/2);
    auto judge = [](string s)->bool{
        int n = s.size();        
        rep(i,n) {
            if(s[i] != s[n-i-1]) return false;
        }
        return true;
    };
    if(judge(S) && judge(T1) && judge(T2)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}