#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
public:

	UnionFind() = default;

	/// @brief Union-Find 木を構築します。
	/// @param n 要素数
	explicit UnionFind(size_t n)
		: m_parents(n)
		, m_sizes(n, 1)
	{
		std::iota(m_parents.begin(), m_parents.end(), 0);
	}

	/// @brief 頂点 i の root のインデックスを返します。
	/// @param i 調べる頂点のインデックス
	/// @return 頂点 i の root のインデックス
	int find(int i)
	{
		if (m_parents[i] == i)
		{
			return i;
		}

		// 経路圧縮
		return (m_parents[i] = find(m_parents[i]));
	}

	/// @brief a のグループと b のグループを統合します。
	/// @param a 一方のインデックス
	/// @param b 他方のインデックス
	bool unite(int a, int b)
	{
		a = find(a);
		b = find(b);

		if (a != b)
		{
			// union by size (小さいほうが子になる）
			if (m_sizes[a] < m_sizes[b])
			{
				std::swap(a, b);
			}

			m_sizes[a] += m_sizes[b];
			m_parents[b] = a;
            return true;
		} else {
            return false;
        }
	}

	/// @brief a と b が同じグループに属すかを返します。
	/// @param a 一方のインデックス
	/// @param b 他方のインデックス
	/// @return a と b が同じグループに属す場合 true, それ以外の場合は false
	bool same(int a, int b)
	{
		return (find(a) == find(b));
	}

	/// @brief i が属するグループの要素数を返します。
	/// @param i インデックス
	/// @return i が属するグループの要素数
	int size(int i)
	{
		return m_sizes[find(i)];
	}
	vector<int> par(){
		return m_parents;
	}

private:
	// m_parents[i] は i の 親, root の場合は自身が親
	std::vector<int> m_parents;

	// グループの要素数 (root 用), i が root のときのみ, m_sizes[i] はそのグループに属する要素数を表す
	std::vector<int> m_sizes;
};

typedef pair<int, int> pii;

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> A(N+1), V(M), U(M);
    UnionFind uf(N+1);
    auto comp = [](pii &a, pii &b){return a.first > b.first;}; // > (<) is smallest (largest) first
    priority_queue<pii, vector<pii>, decltype(comp)> pqs(comp);
	for(int n=1; n<=N; n++){
        cin >> A[n];
    }
    vector<set<int>> path(N+1);
    for (int i=0; i<M; i++){
        cin >> U[i] >> V[i];
        if (A[U[i]] == A[V[i]]) uf.unite(U[i], V[i]);
    }

    for (int i=0; i<M; i++){
        int u = uf.find(U[i]), v = uf.find(V[i]);
        if (A[u] < A[v]) path[u].insert(v);
        else if (A[u] > A[v]) path[v].insert(u);
    }
	
	vector<bool> isreg(N+1, false);
	for(int n=1; n<=N; n++){
        auto i = uf.find(n);
		if (!isreg[i]){
			isreg[i] = true;
			pqs.push({A[i], i});
		}
    }


    vector<int> lpath(N+1, -4e5); //digits & num
    lpath[uf.find(1)] = 1;
	while(!pqs.empty())
	{
		auto p=pqs.top();
		pqs.pop();
		auto i = uf.find(p.second);
        for (auto a: path[i]){
            if (lpath[a] < lpath[i]+1){
                lpath[a] = lpath[i]+1;
            }
        }
	}
    cout << max(0, lpath[uf.find(N)] - lpath[uf.find(1)] + 1) << endl;

    return 0;
}

