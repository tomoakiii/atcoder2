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
    bool flg1=false, flg2=false;
    unordered_set<char> st;
    for(char c: S) {
        if(c <= 'Z' && c >= 'A') flg1 = true;
        else flg2 = true;
        if(st.contains(c)) {
            cout << "No" << endl;
            return 0;
        }
        st.insert(c);
    }
    if(flg1 && flg2) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}