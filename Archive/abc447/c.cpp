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
    string S, T;cin>>S>>T;
    S.push_back('X');
    T.push_back('X');
    int ca=0, ca2=0;
    int l=0;
    bool flg=true;
    ll ans = 0;
    for(auto c:S) {
        if(c=='A') {
            ca++;
            continue;
        } else {
            while(l<T.size()){
                if(T[l]=='A') {
                    ca2++;
                    l++;
                } else {
                    if(T[l]!=c){
                        flg=false;
                    } else {
                        ans += abs(ca2-ca);
                    }
                    ca2=0;
                    l++;
                    break;
                }
            }
            ca=0;
        }
    }
    if(!flg)cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}