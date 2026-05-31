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
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
int main(){
    int Q; cin>>Q;
    int front = 0;
    int mid = 0;
    int last = 0;
    vector<int> nx(Q+1,Q+1), pre(Q+1,-1);
    vector<string> S(Q+1);
    int size = 0;
    int nq = 0;
    for(int id = 1; id <= Q; id++) {
        char q; cin>>q;
        if(q == 'A') {
            string X; cin>>X;
            nq++;
            S[nq] = X;
            nx[last] = nq;
            pre[nq] = last;
            last = nq;
            size++;
            if(size%2 == 1) mid = nx[mid];
        } else if (q == 'B') {
            string X; cin>>X;
            nq++;
            S[nq] = X;
            int n = nx[mid];
            nx[mid] = nq;
            if(n != Q+1) pre[n] = nq;
            pre[nq] = mid;
            nx[nq] = n;
            size++;
            if(size <= 2) last = nq;
            if(size%2 == 1) mid = nq;
        } else if (q == 'C') {
            front = nx[front];
            size--;
            if(size%2 == 1) mid = nx[mid];
        } else {
            cout << S[nx[front]] << endl;
        }
        /*
        cerr << q << " " << front << " " << mid << " " << last << endl;
        int st = 0;
        while(st != Q+1) {
            cerr << st << " ";
            st = nx[st];
        }
        cerr << endl;
        */
    }
    return 0;
}