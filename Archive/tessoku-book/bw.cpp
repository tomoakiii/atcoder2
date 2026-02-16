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

int main() {
    int N; cin>>N;
    vector<pair<int,int>> DT(N);
    rep(i,N) cin>>DT[i].second>>DT[i].first;
    sort(DT.begin(), DT.end());
    multiset<int> st;
    ll sm = 0;
    rep(i,N) {
        auto [D, T] = DT[i];
        if(st.empty()) {
            if(T<=D) {
                st.insert(T);
                sm += T;
            }
        } else {
            if(sm + T <= D) {
                st.insert(T);
                sm += T;
            } else {
                if(*st.rbegin() > T) {
                    sm -= *st.rbegin();
                    st.erase(st.find(*st.rbegin()));
                    st.insert(T);
                    sm += T;
                }
            }
        }
    }
    cout << st.size() << endl;
}