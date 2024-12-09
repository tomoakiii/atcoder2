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
typedef pair<ll, int> pli;

int main(){
    ll n;
    cin >> n;
    set<string> st;
    int day = 0;
    while(n--){
        day++;
        string s;
        cin >> s;
        if(st.count(s) == 0) {
            st.insert(s);
            cout << day << endl;
        }
    }
    return 0;
}