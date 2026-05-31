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
    int N, x, y;
    cin >> N >> x >> y;
    vector<int> A(N);
    rep(i,N) cin>>A[i];

    set<int> st;
    st.insert(A[0]);
    for(int i=2; i<N; i+=2){
        set<int> st2;
        for(auto s: st) {
            st2.insert(s + A[i]);
            st2.insert(s - A[i]);
        }
        swap(st, st2);
    }
    if (st.count(x) == 0) {
        cout << "No" << endl;
        return 0;
    }
    st.clear();
    st.insert(0);
    for(int i=1; i<N; i+=2){
        set<int> st2;
        for(auto s: st) {
            st2.insert(s + A[i]);
            st2.insert(s - A[i]);
        }
        swap(st, st2);
    }
    if (st.count(y) == 0) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}