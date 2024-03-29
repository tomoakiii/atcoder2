#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main(){
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> c(N);
    struct color{
        int sum=0;
        int boxn=0;
        int lastn=0;
        int rem=0;
    };
    vector<color> col(N);

    int bcnt=0;
    int r;
    bool stp=false;
    for(int i=0; i<N; i++){
        cin >> c[i];
        c[i]--;
        col[c[i]].sum++;
        if (stp) continue;
        if (col[c[i]].lastn%K == 0){
            col[c[i]].lastn = 1;
            bcnt++;
            col[c[i]].boxn++;
            if (bcnt == M){
                r=(i+1)%N;
                stp=true;
                continue;
            }
        } else {
            col[c[i]].lastn++;
        }
    }
    int totalcnt = 0;
    
    for(auto &cl : col){
        if (cl.boxn == 0) continue;
        cl.rem = K - max(0, cl.boxn*K - cl.sum);
        totalcnt += min(cl.boxn*K, cl.sum);
    }
    if (totalcnt==N){
        for (int i=0;i<N;i++){
            cout << totalcnt << endl;
        }
        return 0;
    }
    cout << totalcnt << endl;    
    for (int l=0; l<N-1; l++) {
        col[c[l]].lastn--;
        if (col[c[l]].lastn == 0){
            col[c[l]].boxn--;
            bcnt--;
            totalcnt -= col[c[l]].rem;
            col[c[l]].rem = 0;
        }
        while (bcnt<M && r!=l){
            if (col[c[r]].lastn%K == 0){
                col[c[r]].lastn = 1;
                bcnt++;
                col[c[r]].boxn++;
                col[c[r]].rem = K - max(0, col[c[r]].boxn*K - col[c[r]].sum);
                totalcnt += col[c[r]].rem;
            } else {
                col[c[r]].lastn++;
            }
            r = (r+1)%N;
        }
        cout << totalcnt << endl;
    }
    return 0;
}

