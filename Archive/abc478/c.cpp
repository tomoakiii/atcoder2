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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N),R(N,1);
    rep(i,N) cin>>A[i];
    int last=1;
    for(int i=N-1;i>0;i--){
        if(A[i]<A[i-1])last=0;
        R[i-1]=last;
    }
    multiset<ll> st;
    rep(i,K) st.insert(A[i]);
    for(int i=K; i<N; i++){
        ll mx = *st.rbegin();
        if(R[i]==1 && A[i]>=mx){
            cout << "Yes" << endl;
            return 0;
        }
        st.insert(A[i]);
        st.erase(st.find(A[i-K]));
        if(i-K-1>=0) {
            if(A[i-K]<A[i-K-1])break;
            if(A[i-K]>*st.begin())break;
        }

    }
    cout<<"No"<<endl;
    return 0;
}