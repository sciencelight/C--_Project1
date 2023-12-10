#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;
vector<vector<int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
void split(vector<int> &nums, string line)
{
    while (line.find(',') != string::npos)
    {
        int pos = line.find(',');
        nums.push_back(stoi(line.substr(0, pos)));
        line = line.substr(pos + 1);
    }
    nums.push_back(stoi(line));
}
void getPmt(string &needle, vector<int> &pmt)
{
    int j = 0;
    pmt[0] = 0;
    int n = needle.length();
    for (int i = 1; i < n; i++)
    {
        if (needle[i] == needle[j])
        {
            pmt[i] = j + 1;
            j++;
        }
        else if (j == 0)
            pmt[i] = 0;
        else
        {
            j = pmt[j - 1];
            i--;
        }
    }
}
int strStr(string haystack, string needle)
{
    int n1 = haystack.length(), n2 = needle.length();
    if (n1 < n2)
        return -1;
    vector<int> pmt(n2);
    getPmt(needle, pmt);
    for (int i = 0, j = 0; i < n1; i++)
    {
        if (haystack[i] == needle[j])
            j++;
        else if (j > 0)
        {
            j = pmt[j - 1];
            i--;
        }
        if (j == n2)
            return i - j + 1;
    }
    return -1;
}