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
    vector<pair<ll, int>> A(N);
    rep(i,N) {
        cin>>A[i].first;
        A[i].second = i+1;
    }
    sort(A.begin(), A.end(), greater<pair<ll, int>>());
    cout << A[1].second << endl;
    return 0;
}