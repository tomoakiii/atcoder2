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
    string S, T; cin>>S>>T;
    if(S.size() < T.size()) {
        cout<<"UNRESTORABLE"<<endl;
        return 0;
    }
    for(int i = S.size() - T.size(); i>=0; i--) {
        bool flg = true;
        for(int j = 0; j < T.size(); j++) {
            if(S[i+j] == '?') continue;
            if(S[i+j] != T[j]) {
                flg = false;
                break;
            }
        }
        if(!flg) continue;
        for(int j = 0; j < T.size(); j++) S[i+j] = T[j];
        for(auto &c: S) if(c=='?') c='a';
        cout<<S<<endl;
        return 0;
    }
    cout<<"UNRESTORABLE"<<endl;
    return 0;
}