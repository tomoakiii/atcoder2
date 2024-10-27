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
    const int M = 100005;
    vector<int> A(N, 0), Grundy(M, 0);
    vector<vector<int>> divN(M);
    rep(i, N) cin >> A[i];
    int sum = 0;


    for (int i = 1; i < M; i++) {
        for (int j = 2*i; j < M; j+=i) {
            divN[j].push_back(i);
        }
    }
    for (int i = 1; i < M; i++) {
        set<int> st;
        for (int d: divN[i]) st.insert(Grundy[d]);
        int j=0;
        while (st.count(j) > 0) {
            j++;
        }
        Grundy[i] = j;
    }
    rep(i, N) {
        sum ^= Grundy[A[i]];
    }
    if (sum == 0) cout << "Bruno" << endl;
    else cout << "Anna" << endl;
    return 0;
}