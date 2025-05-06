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


void partitions(int n, int max_n, vector<int>& v, vector<vector<int> >& vv)
{
    if (n == 0) {
        vv.push_back(v);
        return;
    }
    for (int i = min(n, max_n); i > 0; i--) {
        v.push_back(i);
        partitions(n - i, i, v, vv);
        v.pop_back();
    }    
}

int main(){    
    vector<vector<int>> vv{};
    vector<int> vt{};
    partitions(10, 6, vt, vv); // v = [a0, a1, ... ak]. a0 + a1 + ...ak = 10. list up all combinations of v as vv[][]
    return 0;
}