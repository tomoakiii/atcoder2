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
    int cur;      
    set<int> st_o;  
    auto f = [&](auto f, set<int> st)->bool {
        bool ret = true;
        while(cur<S.size()){
            char c = S[cur];
            cur++;
            if(c == ')') {                
                break;
            }
            else if(c == '(') {
                ret &= f(f, st);
            } else {
                if(st.count(c)) ret = false;
                else st.insert(c);
            }            
        }
        return ret;
    };
    cur=0;
    bool ans = f(f, st_o);
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}