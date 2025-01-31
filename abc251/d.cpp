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
    ll W;
    cin >> W;
    unordered_set<ll> st;
    vector<ll> A{};
    for(int i=1; i<=W; i++) {
        if (!st.contains(i)) {
            st.insert(i);
            for(int j=0; j<A.size(); j++) {
                if(i + A[j] > W) break;
                st.insert(i+A[j]);
                for(int k=j+1; k<A.size(); k++){
                    if(i + A[j] + A[k] > W) break;
                    st.insert(i + A[j] + A[k]);
                }
            }
            A.emplace_back(i);
        }
    }
    cout << A.size() << endl;
    for (auto s: A) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}