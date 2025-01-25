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

using S = int;
using F = int;
S op(S l, S r) {return max(l, r);}
S e() {return -INF;}
S mapping (F l, S r) {return max(l, r);}
F composition (F l, F r) {return max(l, r);}
F id() {return -INF;}


int main(){
    int N;
    cin >> N;
    vector<int> R(N), L(N);
    rep(i,N) cin>>L[i]>>R[i];
    sort(L.begin(), L.end());
    sort(R.begin(), R.end());

    int mn, mx;
    int cnt = 0, li = 0, ri = 0;
    int i = 0;
    
    while(i <= R[N-1]) {        
        bool flg = false;
        if(li < N && L[li] == i) {
            li++;
            if(cnt == 0) mn = i;
            cnt++;       
            flg = true;     
        }
        if(R[ri] == i) {
            ri++;
            cnt--;
            if(cnt == 0) {
                mx = i;
                cout << mn << " " << mx << endl;
            }
            flg = true;
        }
        if (!flg) i++;
    }
    return 0;
}