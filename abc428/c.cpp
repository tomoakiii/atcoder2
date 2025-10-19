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
    int Q; cin>>Q;
    deque<int> sm;
    sm.push_back(0);
    vector<bool> flg(Q+10,true);
    while(Q--){
        int oper; cin>>oper;
        if(oper == 1) {
            char c; cin>>c;
            int last = *sm.rbegin();
            if(c == '(') {                                                
                sm.push_back(last + 1);            
            } else {                
                sm.push_back(last - 1);                
            }
            last = *sm.rbegin();
            if(last<0) flg[sm.size()-1] = false;
            else flg[sm.size()-1] = flg[sm.size()-2];
        } else {
            sm.pop_back();
        }
        int last = *sm.rbegin();        
        if(flg[sm.size()-1] && last == 0) cout<<"Yes"<<endl;        
        else cout<<"No"<<endl;
    }
    return 0;
}