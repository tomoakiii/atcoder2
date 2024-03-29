#include <bits/stdc++.h>
using namespace std;

struct node {    
    int prev;
    int count;
};

vector<node> A;

bool swapnode(int a){
    int prv = A[a].prev;
    if (prv == 0){
        return false;
    }
    if ((A[prv].count < A[a].count) || 
    (A[prv].count == A[a].count && prv > a) ){
        A[a].prev = A[prv].prev;
        A[prv].prev = a;
        return true;
    }
    return false;
}

int topfind(int a){
    if (A[a].prev == 0){
        return a;
    } else {
        return A[a].prev;
    }
}

int main(){
    int N, M;
    cin >> N >> M;
    A.resize(N+1);
    for (int n = 1; n <=N; n++){
        A[n].prev = n-1;
        A[n].count = 0;
    }
    int top=1;

    vector<int> vote(M);
    for (auto &v : vote){
        cin >> v;
    }
    for (auto &v : vote){
        A[v].count++;
        while (swapnode(v)){}
        top = topfind(top);        
        cout << top << endl;
    }
    return 0;
}