#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;

struct CVs{
    int C;
    ll V;
    CVs (int C=-1, ll V=-INF): C(C), V(V) {}
};

struct T2{
    CVs a, b;
    T2 (CVs a = CVs(), CVs b = CVs(-2, -INF)): a(a), b(b) {} 
    void add(CVs x) {
        if (x.V > a.V) {
            swap(a, x);
        }
        if (x.V > b.V) {
            swap(b, x);
        }
        if (a.C == b.C) {
            swap(b, x);
        }
    }
    void addT(T2 x) {
        add(x.a);
        add(x.b);
    }
};


int main () {
    int N, K;
    cin >> N >> K;
    vector<CVs> CV(N);
    for (auto &c: CV) {
        cin >> c.C >> c.V;
    }
    vector<T2> dp(K+1);
    dp[0] = T2(CVs(CV[0].C, CV[0].V), CVs(-1, -INF));
    dp[1] = T2(CVs(-1, 0), CVs(-1, -INF));
    vector<CVs> tv;
    CVs t;
    for (int i=1; i<N; i++){
        vector<T2> old(K+1);
        swap(old, dp);
        for (int j=0; j<=K; j++){
            if (j>0) {
                dp[j].addT(old[j-1]);
            }
            if (CV[i].C != old[j].a.C) {
                dp[j].add(CVs(CV[i].C, old[j].a.V + CV[i].V));
            }
            if (CV[i].C != old[j].b.C) {
                dp[j].add(CVs(CV[i].C, old[j].b.V + CV[i].V));
            }
        }
    }
    if (dp[K].a.V <= 0) {
        cout << -1 << endl;
    } else {
        cout << dp[K].a.V << endl;
    }
    return 0;
}