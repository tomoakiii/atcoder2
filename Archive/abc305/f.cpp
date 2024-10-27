#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N, M;
    cin >> N >> M;
    vector<bool> visit(N);
    auto f = [&](auto f, int cur, int pre)->void{
        if (cur == N) {
            string s;
            cin >> s;
            exit(0);
        }
        visit[cur] = true;
        int k;
        cin >> k;
        if (k==-1) exit(0);
        vector<int> T(k);
        rep(i,k) {
            int p;
            cin >> p;
            T[i] = p;
        }
        sort(T.rbegin(), T.rend());
        for(auto p: T) {
            if (visit[p]) continue;
            cout << p << endl;
            f(f, p, cur);
        }
        cout<<pre<<endl;
        cin >> k;
        rep(i,k) {
            int p;
            cin>>p;
        }
    };   
    f(f,1,-1);
    return 0;
}