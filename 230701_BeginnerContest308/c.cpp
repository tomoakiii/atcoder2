#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;


int main(){
    int N;
    cin >> N;
    vector<double> P(N, 0);

    vector<ll> A(N), B(N);
    rep(i, N){
        cin >> A[i] >> B[i];
    }
    vector<int> ord(N);
    iota(ord.begin(), ord.end(), 0);
    auto func = [&](int l, int r){
        ll lft = A[l] * (A[r] + B[r]);
        ll rgt = A[r] * (A[l] + B[l]);
        if(lft == rgt) {
            return (l < r); // lインデックスの方が小さいのが正解
        } else {
            return (lft > rgt); // lftの方が大きいのが正解
        }                
    };
    sort(ord.begin(), ord.end(), func);
    rep(i, N){
        cout << ord[i] + 1 << " ";
    }
    cout << endl;
    return 0;
}