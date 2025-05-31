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
    string S;
    cin >> S;
    deque<int> que;
    que.push_back(N);
    for(int i=N-1; i>=0; i--) {
        if(S[i] == 'R') {
            que.push_front(i);
        } else {
            que.push_back(i);
        }
    }
    for(auto q: que) cout << q << " ";
    cout << endl;
    return 0;
}