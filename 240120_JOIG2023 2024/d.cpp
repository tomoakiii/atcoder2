#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
vector<int> A, B;
int N;
int main(){
    cin >> N;
    A.resize(N), B.resize(N);
    for (int &a:A) cin>>a;
    for (int &b:B) cin>>b;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    long long cnt = 0;
    for (int &a: A){
        long long ac = 0, p10 = 1;
        while(p10<=a){ // n dig --> p10 is n+1 dig
            ac++;
            p10 *= 10;
        }
        cnt += ac*N;
        while(true) {
            // 100 - 1 = 99
            auto bit = lower_bound(B.begin(), B.end(), p10-a);
            long long bi = B.end() - bit;
            if (bi<1) break;
            cnt += bi;
            p10 *= 10;
        };
    }
    cout << cnt << endl;
    return 0;
}

