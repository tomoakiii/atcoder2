#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M, L;
    cin >> N >> M >> L;
    vector<long> av(N);
    vector<long> bv(M);
    for (auto &a : av){
        cin >> a;
    }
    for (auto &b : bv){
        cin >> b;
    }
    vector<long> cdv(L);
    for (int n = 0; n < L; n++){
        int c, d;
        cin >> c >> d;
        cdv[n] = av[c-1] + bv[d-1];
    }
    sort(av.begin(), av.end());
    sort(bv.begin(), bv.end());
    sort(cdv.begin(), cdv.end());
    priority_queue<long long> pq;
    for (int inda = N-1; inda >= 0; inda--){
        for (int indb = M-1; (N-inda) * (M-indb) <= L+1 && indb>=0; indb--){
            pq.push(av[inda] + bv[indb]);
        }
    }
    int indcd = L-1;
    while(indcd >= 0){
        long p =pq.top();
        pq.pop();
        if (p == cdv[indcd]){
            indcd--;
            continue;
        } else if (p > cdv[indcd]){
            cout << p << endl;
            return 0;
        } else {
            return -1;
        }
    }
    cout << pq.top() << endl;
    return 0;
}
