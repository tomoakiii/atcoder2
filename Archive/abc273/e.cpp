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
    ll Q;
    cin >> Q;
    struct StNode{
        int pre=-1;
        ll val;
    };
    vector<StNode> vec{};
    StNode node;
    node.pre = 0;
    node.val = -1;
    int cur = 0;
    vec.push_back(node);
    map<ll, int> mp;
    mp[0] = 0;
    while(Q--){
        string op;
        cin >> op;
        int x;
        if(op == "ADD"){
            cin >> x;
            node.pre = cur;
            node.val = x;
            vec.emplace_back(node);
            cur = vec.size()-1;
        } else if (op == "DELETE") {
            cur = vec[cur].pre;
        } else if (op == "SAVE") {
            cin >> x;
            mp[x] = cur;
        } else {
            cin >> x;
            if (mp.count(x) > 0) cur = mp[x]; 
            else cur = 0;
        }
        cout << vec[cur].val << " ";
    }
    cout << endl;
    return 0;
}