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
    ll N;
    cin >> N;
    string S;
    cin >> S;
    ll N3 = pow(3, N);
    struct edge{
        int n;
        int f1=0, f0=0;
    };
    vector<edge> A(N3);
    rep(i, N3) {
        A[i].n = (S[i] == '1')?1:0;
        if (A[i].n == 1) A[i].f0 = 1;
        if (A[i].n == 0) A[i].f1 = 1;
    }
    while(A.size() > 1) {
        vector<edge> B{};
        for(int i = 0; i<A.size(); i+=3) {
            edge b;
            int sm = 0;
            vector<ll> m1{}, m0{};
            rep(j, 3) {
                sm += A[i+j].n;
                if(A[i+j].n == 1) {
                    m0.push_back(A[i+j].f0);
                } else {
                    m1.push_back(A[i+j].f1);
                }
            }            
            sort(m1.begin(), m1.end());            
            sort(m0.begin(), m0.end());
            if(sm == 0) {
                b.n = 0;
                b.f1 = m1[0] + m1[1];
            } else if (sm == 1) {
                b.n = 0;
                b.f1 = m1[0];
            } else if (sm == 2) {
                b.n = 1;
                b.f0 = m0[0];
            } else if (sm == 3) {
                b.n = 1;
                b.f0 = m0[0] + m0[1];
            }
            B.push_back(b);
        }
        swap(A, B);
    }
    if(A[0].n == 1) {
        cout << A[0].f0 << endl;
    } else {
        cout << A[0].f1 << endl;
    }
    return 0;
}