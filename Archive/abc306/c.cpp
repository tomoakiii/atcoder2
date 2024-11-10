#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N;
    cin >> N;
    vector A(N, vector<int>{});
    rep(i, 3*N) {
        int a;        
        cin >> a;
        a--;
        A[a].push_back(i);
    }
    
    vector<int> ord(N);
    iota(ord.begin(), ord.end(), 0);
    auto func = [&](int l, int r){
        ll lft = A[l][1];
        ll rgt = A[r][1];        
        return (lft < rgt);
        
    };
    sort(ord.begin(), ord.end(), func);
    
    rep(i, N){
        cout << ord[i]+1 << " ";
    }
    cout << endl;
    return 0;
}