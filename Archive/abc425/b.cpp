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
    vector<ll> P(N+1,-1);
    set<ll> st;
    for(int i=1; i<=N; i++) st.insert(i);
    for(int i=1; i<=N; i++) {
        int a; cin>>a;        
        if(a!=-1 && !st.contains(a)) {
            cout << "No" << endl;
            return 0;
        }
        st.erase(a);
        P[i] = a;
    }
    cout<<"Yes"<<endl;
    for(int i=1; i<=N; i++) {
        if(P[i] == -1) {
            P[i] = *st.begin();
            st.erase(st.begin());
        }
        cout << P[i] << " ";
    }
    cout<<endl;
    return 0;
}