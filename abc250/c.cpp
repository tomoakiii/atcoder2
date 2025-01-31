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
    ll N, Q;
    cin >> N >> Q;
    vector<int> pos(N);
    vector<int> ball(N);    
    rep(i, N) pos[i] = i;
    rep(i, N) ball[i] = i;
    
    while(Q--) {
        int x;
        cin >> x;
        x--;
        int p = pos[x];
        int p2;
        if(p == N-1) p2 = p-1;
        else p2 = p + 1;
        int n = ball[p2];
        swap(ball[p], ball[p2]);
        swap(pos[x], pos[n]);
    }
    for(auto a:ball) {
        cout << a+1 << " ";
    }
    cout << endl;
    return 0;
}