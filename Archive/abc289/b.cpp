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
    ll N, M;
    cin >> N >> M;
    if (M==0){
        rep(i,N) cout<< i+1 << " ";
        cout<<endl;
        return 0;
    }
    vector<int> A(M);
    rep(i,M) {
        cin >> A[i];
        A[i]--;
    }
    stack<int> st;
    int id = 0;
    rep(i,N) {
        st.push(i);
        if (A[id] == i) {
            id++;
            continue;
        }
        while(!st.empty()) {
            cout << st.top()+1 << " ";
            st.pop();
        }
    }
    cout << endl;
    return 0;
}