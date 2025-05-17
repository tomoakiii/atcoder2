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
    int N = S.size();
    if(N==1) {
        cout << S << endl;
        return 0;
    }
    unordered_set<string> st;
    string s = "";
    string s2 = "";
    string ans;
    for(int i = N-1; i>=2; i--) {
        s = s + S[i];
        st.insert(s);
        s2 = S[i-2] + s2;
        if(st.contains(s2)) {
            string p = S.substr(0, i-2);
            ans = p + S[i-1];
            reverse(p.front(), p.end());
            ans = ans + p;
        }        
    }
    
    return 0;
}