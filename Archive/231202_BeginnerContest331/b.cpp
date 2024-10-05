#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main(){

    int N, S, M, L;
    struct eggcost{
        int indSML;
        int cost;
        int costNC;
        int qty;
    };
    eggcost ecnt[3];
    auto comp = [](eggcost &a, eggcost &b){return a.costNC > b.costNC;}; // > (<) is smallest (largest) first
    priority_queue<eggcost, vector<eggcost>, decltype(comp)> pq(comp);
    
    cin >> N;

    ecnt[0].indSML = 0;
    cin >> ecnt[0].cost;
    ecnt[0].costNC = ecnt[0].cost * 4;
    ecnt[0].qty = 6;
    pq.push(ecnt[0]);

    ecnt[1].indSML = 1;
    cin >> ecnt[1].cost;
    ecnt[1].costNC = ecnt[1].cost * 3;
    ecnt[1].qty = 8;
    pq.push(ecnt[1]);

    ecnt[2].indSML = 2;
    cin >> ecnt[2].cost;
    ecnt[2].costNC = ecnt[2].cost * 2;
    ecnt[2].qty = 12;
    pq.push(ecnt[2]);

    vector<int> dp(N+1, 100000);
    dp[0] = 0;
    for (int k = 1; k <= N; k++){
        for (auto a : ecnt){
            if (k < a.qty){
                dp[k] = min(dp[k], a.cost);
            } else {
                dp[k] = min(dp[k], dp[k - a.qty] + a.cost);
            }
        }        
    }

    cout << dp[N] << endl;
    return 0;
}
