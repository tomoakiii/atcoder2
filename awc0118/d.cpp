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
    ll Q; cin>>Q;
    deque<deque<ll>> block{};
    int lmt = 1000;
    int sid = 0;
    while(Q--){
        int k; cin>>k;
        if(k==1){
            ll x; cin>>x; x;
            if(block.empty() || block[block.size()-1].size() == lmt) {
                block.push_back(deque<ll>(1,x));
            } else {
                block[block.size()-1].push_back(x);
            }
        }else if(k==2){
            ll x,k; cin>>x>>k;
            k--;
            if(block.empty()) {
                block.push_back(deque<ll>(1,x));
                continue;
            }
            int sz = 0;
            int i = 0;
            while(sz + block[i].size() < k) {
                sz += block[i].size();
                i++;
            }
            ll rm = k-sz;
            block[i].insert(block[i].begin() + rm, x);
            if(block[i].size() > lmt) {
                deque<ll> dq;
                while(block[i].size() > lmt/2){
                    dq.push_front(block[i].back());
                    block[i].pop_back();
                }
                block.insert(block.begin() + i+1, dq);
            }
        } else {
            cout << block.front().front() << endl;
            block.front().pop_front();
            if(block.front().empty()) block.pop_front();
        }
    }
    return 0;
}