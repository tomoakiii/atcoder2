#include <bits/stdc++.h>
using namespace std;
#define INF 10000000
int N, M;
vector<vector<long long>> wsum;
vector<vector<bool>> isp;

void update(int x1, int x2, long long w){
    for (int i=0; i<N; i++){
        if (isp[i][x1]){
            if (!isp[i][x2]){
                isp[i][x2] = true;
                wsum[i][x2] = wsum[i][x1] + w;
            } else {
                if (wsum[i][x2] > wsum[i][x1] + w){
                    wsum[i][x2] = wsum[i][x1] + w;
                    update(i, x2, wsum[i][x2]);
                }
            }
        }
    }
    for (int i=0; i<N; i++){
        if (isp[x2][i]){
            if (!isp[x1][i]){
                isp[x1][i] = true;
                wsum[x1][i] = w + wsum[x2][i];
            } else {
                if (wsum[x1][i] > w + wsum[x2][i]){
                    wsum[x1][i] = w + wsum[x2][i];
                    update(x1, i, wsum[x1][i]);
                }
            }
        }
    }
}


int main(){
    cin >> N >> M;
    isp.resize(N, vector<bool>(N, false));
    wsum.resize(N, vector<long long>(N, INF));
    int x1, x2;
    long long w;
    for (int i=0;i<M;i++) {
        cin >> x1 >> x2 >> w;
        x1--; x2--;
        isp[x1][x2] = true;
        if (wsum[x1][x2] > w){
            wsum[x1][x2] = w;
            update(x1, x2, w);            
        }
    }
    w=0;
    for (int i=0;i<N-1;i++) {
        if(!isp[i][i+1]){
            cout << "No" << endl;
            return 0;
        }
        w += wsum[i][i+1];
    }
    cout << w << endl;    
    return 0;
}

