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
    int N;
    string S; cin>>N>>S;
    deque<int> dq;
    for(auto &c:S) dq.push_back((c=='R')?1:0);
    ll cnt = 0;
    while(true) {
        if(dq.size() == 0) break;
        if(dq[0] == 1) {
            dq.pop_front();
            continue;
        }
        if(dq[dq.size() - 1] == 0) {
            dq.pop_back();
            continue;
        }
        swap(dq[0], dq[dq.size()-1]);
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}