#include <bits/stdc++.h>
using namespace std;
#define INF 100000000000007

int main(){
    int N, Q, P;
    long long X;
    cin >> N;
    vector<long long> vLR(2*N);
    for (int i=0; i<N; i++){
        cin >> vLR[2*i] >> vLR[2*i+1];
    }
    vector<pair<long long, int>> sLR(2*N);
    for(int i=0; i<2*N; i++){
        sLR[i].first = vLR[i];
        sLR[i].second = i;
    }
    sort(sLR.begin(), sLR.end());

    cin >> Q;
    long long dur[2];
    for (int i=0; i<Q; i++){
        cin >> P >> X;
        P--;
        dur[0] = vLR[2*P];
        dur[1] = vLR[2*P+1];
        pair<long long, int> p = {dur[0], 0};
        auto j = lower_bound(sLR.begin(), sLR.end(), p);
        vector<bool> flg(N, false);
        flg[P] = true;
        int cnt=1, id;
        while(j != sLR.end()){
            id = j->second;
            if (!flg[id/2]) { // skip infection person       
                if (id%2 == 1){ // right
                    if (j->first > dur[1] && vLR[id-1] < dur[0]) {
                        cnt++;
                        dur[1] = j->first;
                    } else if (j->first <= dur[1] && vLR[id] - max(vLR[id-1], dur[0]) >= X){
                        flg[id/2] = true;
                        cnt++;
                    }
                } else { // left
                    if (min(vLR[id+1], dur[1]) - vLR[id] >= X){
                        flg[id/2] = true;
                        dur[1] = max(vLR[id+1], dur[1]);
                        cnt++;
                    }
                }
            }
            j++;
        }
        cout << cnt << endl;
    }
    return 0;
}

