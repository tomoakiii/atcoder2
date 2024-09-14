#include <bits/stdc++.h>
using namespace std;

int main(){

    long long N, Q;
    cin >> N >> Q;
    vector<long long> cnn(N+2, 0);
    vector<long long> A(N+1);
    set<long long> st;
    for (int i=1; i<=N; i++){
        long long a;
        cin >> a;
        if(a<=N){
            cnn[a]++;
        }
        A[i]=a;
    }

    for (int i=0; i<=N+1; i++){
        if (cnn[i] == 0){
            st.insert(i);
        }
    }

    long long iin, x;
    for (int i=1;i<=Q;i++){
        cin >> iin >> x;
        long long a = A[iin];
        if (a <= N){
            if (cnn[a] == 1){
                st.insert(a);
            }
            cnn[a]--;
        } 
        if (x <= N){
            if (cnn[x] == 0){
                st.erase(x);
            }
            cnn[x]++;
        }
        A[iin] = x;
        cout << *st.begin() << endl;   
    }

    return 0;
}