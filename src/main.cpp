#include "common.h"

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
//���ǹ�������һ��
int count1(vector<int> &arr, int n, long long k)
{
    unordered_map<long long, long long> prefixSum; // ǰ׺�ͼ���k * l1������ֵ�λ��
    long long sum = 0;                             // ��ǰλ��֮ǰ��Ԫ�غ�
    long long maxLength = 0;                       // ������鳤��
    for (long long i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == k * (i + 1))
        {
            maxLength = i + 1;
        }
        else if (prefixSum.find(sum - k * (i + 1)) != prefixSum.end())
        {

            maxLength = max(maxLength, i - prefixSum[sum - k * (i + 1)]);
        }

        if (prefixSum.find(sum - k * (i + 1)) == prefixSum.end())
        {
            prefixSum[sum - k * (i + 1)] = i;
        }
    }
    return maxLength > 0 ? maxLength : -1;
}
int main()
{
    int n, k, sum;
    scanf("%d %d", &n, &k);
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("%d\n", count1(arr, n, k));
    return 0;
}
/*
5:
5 3
1 1 3 5 5

4:
10 6
6 2 5 1 8 4 2 10 1 5

*/