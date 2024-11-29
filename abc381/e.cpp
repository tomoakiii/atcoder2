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
    ll N,Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    vector<int> si{};
    si.push_back(-1);
    rep(i,N) {
        if(S[i] == '/') si.emplace_back(i);
    }
    si.push_back(INFi);
    int mx = 0;
    vector<int> s1(N);
    vector<int> s2(N);
    int cnt  = 0;
    rep(i,N) {
        if(S[i] == '2') cnt++;
        s2[i] = cnt;
    }
    cnt=0;
    for(int i=N-1; i>=0; i--) {
        if(S[i] == '1') cnt++;
        s1[i] = cnt;
    }
            
    while(Q--) {
        int mx = 0;
        int L, R;
        cin >> L >> R;
        L--, R--;
        int id = lower_bound(si.begin(), si.end(), L) - si.begin();
        int id2 = lower_bound(si.begin(), si.end(), R+1) - si.begin();        
        id2--;
        if(L > si[id] || R < si[id2] || id2 < id) {
            cout << 0 << endl;
            continue;
        }

        while(id2 - id > 1) {
            int c = (id+id2)/2;
            int c1 = s1[L] - s1[si[c]];
            int c2 = s2[R] - s2[si[c]];
            chmax(mx, 1+2*min(c1, c2));
            if(c1 > c2) {
                id2 = c;
            } else {
                id = c;
            }            
        }
        if(si[id] >= 0 && si[id] < N) {
            int c1 = s1[L] - s1[si[id]];
            int c2 = s2[R] - s2[si[id]];
            chmax(mx, 1+2*min(c1, c2));
        }        
        if(si[id2] >= 0 && si[id2] < N) {
            int c1 = s1[L] - s1[si[id2]];
            int c2 = s2[R] - s2[si[id2]];
            chmax(mx, 1+2*min(c1, c2));
        }
        cout << mx << endl;

    }
    return 0;
}