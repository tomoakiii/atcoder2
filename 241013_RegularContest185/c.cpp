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
    ll N, X;
    cin >> N >> X;
    vector<ll> A(N, 0);
    map<ll, int> mp;
    rep(i,N) {
        cin>>A[i];
        mp[A[i]] = i;
    }
    vector B = A;
    sort(B.begin(), B.end());
    
    
    for(int i=0; i<N-2 && A[i]<X-2; i++) {
        for(int j=i+1; j < N-1 && X-B[i]-B[j]>B[j+1] ; j++){
            if(mp.count(X-B[i]-B[j]) > 0) {
                set<int> st;
                st.insert(mp[B[i]] + 1);
                st.insert(mp[B[j]] + 1);
                st.insert(mp[X-B[i]-B[j]]+1);
                if (st.size() < 3) continue;
                for(auto s: st) {
                    cout << s << " ";
                }
                cout << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}