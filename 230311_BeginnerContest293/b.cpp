#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)


int main(){
    int N;
    cin >> N;
    vector<int> A(N+1, 0);
    for(int i=1; i<=N; i++) cin>>A[i];
    vector<bool> visit(N+1, false);
    int K = N;
    for(int i=1; i<=N; i++) {
        if(visit[i]) continue;
        if(visit[A[i]]) continue;
        K--;
        visit[A[i]] = true;
    }
    cout<<K<<endl;
    for(int i=1; i<=N; i++) {
        if(visit[i]) continue;
        cout << i << " ";
    }
    cout << endl;
    return 0;
}