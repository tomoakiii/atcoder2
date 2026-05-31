#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    int N, X;
    cin >> N >> X;
    vector<int> A(N-1);
    for(auto &a: A) cin >> a;
    sort(A.begin(), A.end());
    int sm = 0;
    for(auto &a: A) sm+=a;
    // case 1; drop 0
    int tgt = X - (sm - A[0] - A[N-2]);
    if (tgt <= A[0]) {
        cout << 0 << endl;
        return 0;
    }
    if (tgt > A[N-2]) {
        cout << -1 << endl;
        return 0;
    }
    cout << tgt << endl;    
    return 0;
}