#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;


int main(){
    int N;
    cin >> N;
    struct dat{
        long long x;
        long long c;
        int ind;
    };
    auto sorter = [](dat &lhs, dat &rhs) {
        if (lhs.x != rhs.x)
            return lhs.x < rhs.x;
        if (lhs.c != rhs.c)
            return lhs.c < rhs.c;
        return lhs.ind < rhs.ind;
    };
    vector<dat> XC(N);
    for(int i=0; i<N; i++){
        cin >> XC[i].c >> XC[i].x;
        XC[i].ind = i;
    }
    sort(XC.begin(), XC.end(), sorter);
    vector<long long> dist(N, 1000000000);
    auto lastc = XC[0], lastc2 = XC[0];
    for(int i=0; i<N; i++){
        if (XC[i].c != lastc.c){
            dist[i] = XC[i].x - lastc.x;
            lastc2 = lastc;
        } else {
            if (XC[i].c != lastc2.c){
                dist[i] = XC[i].x - lastc2.x;
            }
        }
        lastc = XC[i];
    }
    lastc = XC[N-1], lastc2 = XC[N-1];
    for(int i=N-1; i>=0; i--){
        if (XC[i].c != lastc.c){
            dist[i] = min(dist[i], lastc.x - XC[i].x);
            lastc2 = lastc;
        } else {
            if (XC[i].c != lastc2.c){
                dist[i] = min(dist[i], lastc2.x - XC[i].x);
            }
        }
        lastc = XC[i];
    }
    auto dist2 = dist;
    for(int i=0; i<N; i++){
        dist2[XC[i].ind] = dist[i];
    }
    for(int i=0; i<N; i++){
        cout << dist[XC[i].ind] << endl;
    }
    return 0;
}

