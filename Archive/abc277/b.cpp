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
    ll N;
    cin >> N;
    set<string> st;
    char c2[] = {'A' , '2' , '3' , '4' , '5' , '6' , '7' , '8' , '9' , 'T' , 'J' , 'Q' , 'K'};
    while(N--) {
        string s;
        cin >> s;
        if(st.count(s) != 0) {
            cout << "No" << endl;
            return 0;
        }
        if(s[0] == 'H' || s[0] == 'D' || s[0] == 'C' || s[0] == 'S') {}
        else {
            cout << "No" << endl;
            return 0;
        }
        bool flg = false;
        rep(i, 13) {
            if (s[1] == c2[i]) flg = true;
        }
        if(!flg) {
            cout << "No" << endl;
            return 0;
        }
        st.insert(s);
    }
    cout << "Yes" << endl;
    return 0;
}