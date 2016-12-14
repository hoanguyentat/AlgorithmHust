/**
    * Doc tung dong input
    * Kiem tra dau vao khong hop le
    * Dung dfs duyet, kiểm tra xem có thể bị đổ không, nếu không thì dùng tay knock down
        Đếm số lần gạt tăng thêm một
    * do phuc tap O(n+m)
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void resultDFS(const vector<vector<int> > &dominos,
         vector<bool>               &visited,
         vector<int>                &topoSort,
         int                         u)
{
    visited[u] = true;
    for (int i = 0; i < dominos[u].size(); ++i)
    {
        int v = dominos[u][i];
        if (! visited[v])
            resultDFS(dominos, visited, topoSort, v);
    }
    topoSort.push_back(u);
}

int main()
{  
    int T;
    cin >> T;
    while ( T-- )
    {
        int n, m;
        cin >> n >> m;

        vector<vector<int> > dominos(n + 1);
        vector<bool> visited(n + 1, false);
        vector<int> topoSort;

        for (int i = 0; i < m; ++i)
        {
            int u, v;
            cin >> u >> v;
            dominos[u].push_back(v);
        }
        for (int u = 1; u <= n; ++u)
            if (!visited[u])
                resultDFS(dominos, visited, topoSort, u);

        reverse(topoSort.begin(), topoSort.end());

        visited.assign(n + 1, false);
        int knock = 0;
        for (int i = 0; i < n; ++i)
        {
            int u = topoSort[i];
            if (! visited[u])
            {
                resultDFS(dominos, visited, topoSort, u);
                ++knock;
            }
        }
        cout << knock << endl;
    }
    return 0;
}