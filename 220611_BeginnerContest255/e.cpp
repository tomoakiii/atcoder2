#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> P;

int main () {
    int N, M;
    cin >> N >> M;
    vector<ll> S(N-1), X(M), B(N, 0);
    int x;
    for (auto &s: S) cin >> s;
    for (int j=0; j<M; j++) {
        cin >> X[j];
    }
    for (int i=1; i<N; i++) {
        B[i] = S[i-1] - B[i-1];
    }

    map<ll, int> cnt;
    int c = 1;
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            ll a2 = c * (X[j] - B[i]);
            cnt[a2]++;
        }
        c *= -1;
    }
    int m = 0;
    for (auto it=cnt.begin(); it != cnt.end(); it++){
        m = max(it->second, m);
    }
    cout << m << endl;

    return 0;
}

