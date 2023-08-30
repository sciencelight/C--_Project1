#include "common.h"

#include <iostream>
#include <stdarg.h>
using namespace std;
double average(int count, ...)
{
    va_list args;
    double sum = 0.0;

    // 初始化可变参数列表
    va_start(args, count);

    // 遍历可变参数列表，累加参数值
    for (int i = 0; i < count; i++)
    {
        double value = va_arg(args, double);
        sum += value;
    }

    // 结束可变参数列表的使用
    va_end(args);

    // 计算平均值
    double average = sum / count;

    return average;
}
int main()
{
    double avg2 = average(5, 1.5, 2.5, 3.5, 4.5, 5.5);
    printf("Average 2: %f\n", avg2);
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
