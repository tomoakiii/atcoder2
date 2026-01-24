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
    ll N,M;
    string S,T;
    ll Q;
    cin >> N >> M >> S >> T >> Q;
    set<char> TK, AO;
    for(auto c:S) TK.insert(c);
    for(auto c:T) AO.insert(c);

    while(Q--) {
        string w; cin>>w;
        bool isT=true, isA=true;
        for(auto c:w) {
            if(!TK.contains(c)) isT=false;
            if(!AO.contains(c)) isA=false;
        }
        if(isT && isA)cout<<"Unknown"<<endl;
        else if(!isT && !isA) cout<<"Unknown"<<endl;
        else if(isT) cout<<"Takahashi"<<endl;
        else cout<<"Aoki"<<endl;
    }
    return 0;
}