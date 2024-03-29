#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M=0;
    cin >> N;
    int n = N-1;
    while(n > 0){
        n/=2;
        M++;
    }

    vector<vector<int>> bintab(N, vector<int>(M, 0));
    for(int i=0; i<N; i++){        
        for(int j=0; j<M; j++){
            bintab[i][j] = (i & (1<<j))>0;
        }
    }
    
    cout << M << endl;
    for(int j=0; j<M; j++){
        int sum = 0;
        for(int i=0; i<N; i++){        
            if (bintab[i][j] == 1) sum++;            
        }
        cout << sum << " ";
        for(int i=0; i<N; i++){        
            if (bintab[i][j] == 1) cout << i+1 << " ";;
        }
        cout << endl;
    }
    
    string s;
    cin >> s;
    int x = 0, p2 = 1;
    for(int j=0; j<M; j++){
        x += p2 * (s[j]-'0');
        p2 *= 2;
    }
    
    cout << x+1 << endl;
    return 0;
}

