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
typedef pair<int, int> pii;

int main(){
    ll N;
    cin >> N;
    set<pii> st;
    pii cur;
    cur = {0, 0};
    st.insert(cur);
    string S;
    cin >> S;
    for (char c: S) {
        if (c== 'R')  cur.second++;
        else if (c == 'L') cur.second--;
        else if (c == 'U') cur.first++;
        else cur.first--;
        if (st.count(cur)) {
            cout << "Yes" << endl;
            return 0;
        }
        st.insert(cur);
    }
    cout << "No" << endl;
    return 0;
}