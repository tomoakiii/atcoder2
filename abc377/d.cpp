#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N, M;
    cin >> N >> M;
    vector<pair<int, int>> L(N), R(N);
    rep(i,N) {
        cin >> L[i].first >> R[i].first;
        L[i].second = R[i].second = i;
    }

    sort(L.begin(), L.end());
    sort(R.begin(), R.end());
    vector<int> Rord(N);
    rep(i,N) {
        Rord[R[i].second] = i;
    }

    int Lind=0, Rind=0;
    queue<int> que;
    int Rback;
    int stp=1;
    ll cnt=0;
    while(stp <= M) {
        while(!que.empty()) {
            auto q = que.front();
            que.pop();
            R[Rord[q]].first = -1;            
        }
        while(Rind < N) {
            if (R[Rind].first == -1) {
                Rind++;
            } else {
                break;
            }
        }
        if(Rind >= N) Rback = M+1;
        else Rback = R[Rind].first;

        while(Lind < N) {
            if(L[Lind].first == stp) {
                que.push(L[Lind].second);
            } else {
                break;
            }
            Lind++;            
        }
        cnt += Rback - stp;
        stp++;
    }


    cout << cnt << endl;
    return 0;
}