#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int n = 0; n < N; n++){
        cin >> A[n];
    }
    sort(A.begin(), A.end());
    int start = 0;
    int cnt = 1, cntmax = 1;
    int n = 1;
    while(n < N){
        if (A[n] - A[start] >= M){
            start++;
        } else {
            cntmax = max(n - start + 1, cntmax);
            n++;
        }
    }
    cout << cntmax << endl;
    
    return 0;
}