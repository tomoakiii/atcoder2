#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N), B(N);
    
    int ind = 0;
    map<ll, int> mp_id;    
    vector<int> mp_b(2*N, INFi);
    rep(i,N) {
        cin>>A[i];
        if(!mp_id.contains(A[i])) {
            mp_id[A[i]] = ind;
            ind++;
        }        
    }
    set<int> st;
    vector<int> to_b(N);
    
    rep(i,N) {
        cin>>B[i];
        if(!mp_id.contains(B[i])) {
            mp_id[B[i]] = ind;
            ind++;
        }
        if(!st.contains(B[i])) {
            st.insert(B[i]);            
            to_b[i] = 1;
        }
        chmin(mp_b[mp_id[B[i]]], i);
    }

    int last = N-1;
    vector<int> to(N);
    for(int i=N-1; i>=0; i--) {
        if(to_b[i] == 1) {
            to[i] = last;
            last = i-1;
        } else {
            to[i] = last;
        }
    }


    int mx = 0;
    vector<int> from(N);
    rep(i,N) {
        int id = mp_id[A[i]];
        int j = mp_b[id];
        chmax(mx, j);
        if(i>=mx) from[i] = mx;
    }
    for(int i=N-1; i>0; i--) {
        from[i]
    }
    int Q;
    cin >> Q;
    while(Q--) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        if(y >= from[x] && y <= to[from[x]]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    
    return 0;
}