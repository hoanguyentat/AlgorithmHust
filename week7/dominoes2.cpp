/**
    * Doc tung dong input
    * Kiem tra dau vao khong hop le
    * Dung dfs duyet va luu ket qua vao bien count sau moi lan duyet mỗi lần phải dùng tay để gạt
    * do phuc tap O(n + m)
*/


#include <stdio.h>
#include <algorithm>
#include <vector>
#define MAX 10005

using namespace std;

vector <int> check[MAX];
int count;
bool visit_check[MAX];

void dfs(int u)
{
    count++;
    visit_check[u] = true;
    for(int v = 0; v < check[u].size(); v++){
        if(!visit_check[check[u][v]])          
            dfs(check[u][v]);
    }
}

int main()
{
    int test_case, n, m, l, x, y, z;

    scanf("%d", &test_case);
    while(test_case--)
    {
        scanf("%d %d %d", &n, &m, &l);
        while(m--){
            scanf("%d %d", &x, &y);
            check[x].push_back(y);
        }
        while(l--){         
            scanf("%d", &z);
            if(!visit_check[z])        
                dfs(z);
        }
        
        printf("%d\n", count);
        count = 0;
        fill(visit_check, visit_check + MAX, false);
        for(int i = 0; i < n; i++){
            check[i].clear();
        }
    }
    
    return 0;
}