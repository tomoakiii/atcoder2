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
    cin >> S;
    deque<char> Sd;
    for(auto c:S) Sd.push_back(c);
    bool rf = false;
    int Q; cin>>Q;
    while(Q--){
        int p; cin>>p;
        if(p==1) rf = !rf;
        else {
            int f; cin>>f;
            char c; cin>>c;
            bool fb = f==1;
            if(rf) fb = !fb;
            if(fb) {
                Sd.push_front(c);
            } else {
                Sd.push_back(c);
            }
        }
    }
    if(rf) reverse(Sd.begin(), Sd.end());
    for(auto c:Sd) cout<<c;
    cout<<endl;
    return 0;
}