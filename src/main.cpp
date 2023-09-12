#include "common.h"
#include <vector>
#include <iostream>
using namespace std;
class NumArray
{
private:
    vector<int> tree;                        // 线段树
    vector<int> arr;                         // 初始数组
    vector<int> mark;                        // 懒标记数组
    void build(int left, int right, int pos) // 线段树构建
    {
        if (left == right)
            tree[pos] = arr[left];
        else
        {
            int mid = left + ((right - left) >> 1);
            build(left, mid, pos * 2);
            build(mid + 1, right, pos * 2 + 1);
            tree[pos] = min(tree[pos * 2], tree[pos * 2 + 1]);
        }
    }
    void push_down(int pos) // 区间下推
    {
        mark[pos * 2] = mark[pos];
        mark[pos * 2 + 1] = mark[pos];
        tree[pos * 2] += mark[pos];
        tree[pos * 2 + 1] += mark[pos];
        mark[pos] = 0;
    }
    void m_update(int left, int right, int pos, int l, int r)
    {
        if (left == right) // 边界条件，单一节点
            tree[pos]--;
        else if (left == l && right == r) // 区间重合，止步于此，懒标记记录
        {
            tree[pos]--;
            mark[pos]--;
        }
        else
        {
            int mid = left + ((right - left) >> 1);
            if (mark[pos] < 0)
            {
                push_down(pos); // 存在懒标记，区间下推
                printf("after push down:\n");
                print_tree();
            }
            if (l <= mid)
                m_update(left, mid, pos * 2, l, min(mid, r));
            if (r >= mid + 1)
                m_update(mid + 1, right, pos * 2 + 1, max(mid + 1, l), r);
            tree[pos] = min(tree[pos * 2], tree[pos * 2 + 1]);
        }
    }

public:
    NumArray(vector<int> &nums)
    {
        arr = nums;
        tree.assign(arr.size() * 4, INT_MAX);
        mark.assign(arr.size() * 4, 0);
        build(0, arr.size() - 1, 1);
    }
    void update(int left, int right)
    {
        m_update(0, arr.size() - 1, 1, left, right);
    }
    void print_tree()
    {
        printf("tree:\n");
        for (int i = 1; i < tree.size() - 1; i++)
            printf("%d ", tree[i]);
        printf("\n");
    }
    int query_top()
    {
        return tree[1];
    }
};
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);
    int version = 0;
    NumArray seg(nums);
    seg.print_tree();
    for (int i = 0; i < m; i++)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        seg.update(l - 1, r - 1);
        seg.print_tree();
        if (seg.query_top() < 0)
        {
            printf("%d\n", version);
            return 0;
        }
        version++;
    }
    printf("%d\n", version);
    return 0;
}
/*
测试数据：
2 3
2 2
1 1
1 2
2 2

2 3
1 1
1 1
1 2
2 2

6 4
4 3 5 2 4 6
1 4
5 6
1 3
2 2
*/