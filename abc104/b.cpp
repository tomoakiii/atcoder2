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
    if(S[0] == 'A') S[0] = '?';
    else {
        cout<<"WA"<<endl;
        return 0;
    }
    int cnt = 0;
    for(int i=2; i<=S.size()-2; i++) {
        if(S[i] == 'C') {
            S[i] = '?';
            cnt++;
        }
    }
    if(cnt!=1) {
        cout<<"WA"<<endl;
        return 0;
    }
    for(auto &c: S) {
        if('a'<=c && c<='z') c='?';
    }
    for(auto c:S) {
        if(c!='?') {
            cout<<"WA"<<endl;
            return 0;
        }
    }
    cout<<"AC"<<endl;
    return 0;
}