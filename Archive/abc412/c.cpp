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
    ll T; cin>>T;
    while(T--){
        int N; cin>>N;
        vector<ll> S;
        ll st; cin>>st;
        rep(i,N-1) {
            ll a; cin>>a;
            S.push_back(a);            
        }

        if(2*st >= S[N-2]) {
            cout<<2<<endl;
            continue;
        }        
        ll tgt = *S.rbegin();
        sort(S.begin(), S.end());
        
        ll last = st;
        deque<ll> domino;
        domino.push_back(st);
        for(int i=0; i<S.size(); i++) {            
            if(S[i] <= 2*last) {
                if(domino.size() > 1) {
                    domino.pop_back();
                    domino.push_back(S[i]);
                } else {
                    domino.push_back(S[i]);
                }
            } else {
                last = *domino.rbegin();
                domino.push_back(S[i]);
            }
            if(*domino.rbegin() >= tgt ) {break;}
        }
        bool flg = true;
        rep(i, domino.size()-1) {
            if(domino[i+1] > 2*domino[i] ) {
                cout<<-1<<endl;
                flg = false;
                break;
            }
        }
        if(flg) {
            cout<<domino.size()<<endl;
        }
    }

    return 0;
}