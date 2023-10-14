#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
vector<vector<int>> direction = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
vector<string> split_str(string st)
{
    vector<string> ans;
    while (st.find(" ") != string::npos)
    {
        int pos = st.find(" ");
        ans.push_back(st.substr(0, pos));
        st = st.substr(pos + 1);
    }
    ans.push_back(st);
    return ans;
}
int main()
{
    // 矩阵读取
    vector<vector<string>> matrix;
    string line;
    while (getline(cin, line))
    {
        if (line.size() == 0)
            break;
        else
            matrix.push_back(split_str(line));
    }
    int n = matrix.size(), m = matrix[0].size();
    // 数值转化
    vector<vector<bool>> range(n, vector<bool>(m, false));
    queue<pair<int, int>> que;
    int needs = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            string st = matrix[i][j];
            if (st == "NO")
            {
                range[i][j] = true;
                needs++;
            }
            else if (st == "YES")
                que.push({i, j});
        }
    }
    // 特判
    if (needs == 0 || range.size() == 0)
    {
        printf("0\n");
        return 0;
    }
    // 广度优先搜索
    int turns = 0, cirles = 0;
    while (!que.empty())
    {
        cirles++;
        int size = que.size();
        for (int i = 0; i < size; i++)
        {
            pair<int, int> node = que.front();
            que.pop();
            for (int k = 0; k < 4; k++)
            {
                int x = node.first + direction[k][0], y = node.second + direction[k][1];
                if (x < 0 || y < 0 || x >= n || y >= m)
                    continue;
                if (range[x][y])
                {
                    turns++;
                    que.push({x, y});
                    range[x][y] = false;
                }
            }
        }
    }
    if (needs == turns)
        printf("%d\n", cirles - 1);
    else
        printf("-1\n");
    return 0;
}
/*
测试数据：
YES YES NO
NO NO NO
YES NO NO

YES NO NO NO
NO NO NO NO
NO NO NO NO
NO NO NO NO

YES NO NO YES
NO NO YES NO
NO YES NA NA
YES NO NA NO

*/