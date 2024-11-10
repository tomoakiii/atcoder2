#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    int N, M;
    cin >> N >> M;
    vector A(M, vector<int>{});
    vector S(N, vector<int>{});
    rep(i, N) {
        int a;
        cin >> a;
        S[i].resize(a);
        int s;
        rep(j, a) {
            cin >> s;
            s--;
            S[i][j] = s;
            A[s].push_back(i);
        }
    }
    vector<int> visitS(N, -1);
    vector<bool> visitA(M, false);
    
    queue<int> que;
    for(auto s: A[0]) {
        que.push(s);
        visitS[s] = 0;
    }
    visitA[0] = true;
    while(!que.empty()){
        auto q = que.front();
        que.pop();
        for(auto p: S[q]){
            if (p == M-1) {
                cout << visitS[q] << endl;
                return 0;
            }
            if (visitA[p]) continue;
            visitA[p] = true;
            for (auto s: A[p]) {
                if (visitS[s] > -1) continue;
                visitS[s] = visitS[q] + 1;
                que.push(s);
            }
        }
    }
    cout << -1 << endl;
    return 0;
}