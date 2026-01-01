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
    string S; ll K;
    cin >> S >> K;
    if(S.size() < K) {
        cout<<0<<endl;
        return 0;
    }
    set<deque<char>> st;
    deque<char> d;
    int ind = 0;
    while(d.size() < K) {
        d.push_back(S[ind++]);
    }
    st.insert(d);
    while(ind < S.size()) {
        d.push_back(S[ind++]);
        d.pop_front();
        st.insert(d);
    }
    cout << st.size() << endl;
    return 0;
}