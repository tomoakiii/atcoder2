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
    string S, T;
    cin >> N >> S >> T;
    S = S + "..";
    T = T + "..";
    set<string> t;
    struct st{
        string S;
        int N;
        int cnt;
        st(string S, int N, int cnt){
            this->S = S;
            this->N = N;
            this->cnt = cnt;
        }
    };
    st init(S, N, 0);
    queue<st> que;  
    que.push(init);
    t.insert(S);
    int mn = INFi;
    while(!que.empty()) {
        auto q = que.front();
        que.pop();
        if (q.S == T) {
            mn = min(q.cnt, mn);
        }
        rep(i, N+1) {
            if(i == q.N || i+1 == q.N || i == q.N+1) {
                continue;
            }
            st s(q.S, i, q.cnt+1);
            swap(s.S[i], s.S[q.N]);
            swap(s.S[i+1], s.S[q.N+1]);
            if (t.count(s.S) != 0) {
                continue;
            }
            t.insert(s.S);
            que.push(s);
        }
    }
    if (mn == INFi) {
        mn = -1;
    }
    cout << mn << endl;
    return 0;
}