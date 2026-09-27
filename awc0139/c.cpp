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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,K;
    cin >> N >> K;
    ll oK=K;
    rep(i,N){
        string s; cin>>s;
        ll sm=0;
        K=oK;
        for(auto c:s){
            sm+=c-'a'+1;
        }
        if(sm %2 == 1){
            if(K%2 == 1) reverse(s.begin(),s.end());
        } else {
            if(s.size()%2 ==1) {
                for(auto &c:s){
                    if(c=='z')c='a';
                    else c++;
                }
                K--;
                if(K%2 == 1) reverse(s.begin(),s.end());
            } else {
                ll p = 'z'-'a'+1;
                ll pls = K%p;
                for(auto &c:s){
                    if(c+pls > 'z') c=c+pls-p;
                    else c+=pls;
                }
            }
        }
        cout<<s<<endl;
    }
    return 0;
}