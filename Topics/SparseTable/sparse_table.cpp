#pragma region macros

#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()

#pragma endregion

#define exponent 21
#define power 1048576
int _table[exponent][power];

int log2_floor(unsigned long long i)
{
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

void st_build(vector<int> &input)
{
    copy(all(input), _table[0]);
    for (int i = 1; i <= exponent; i++)
        for (int j = 0; j + (1 << i) <= input.size(); j++)
            _table[i][j] = min(_table[i - 1][j], _table[i - 1][j + (1 << (i - 1))]);
}

int st_query(int left, int right)
{
    if (left == right)
        return _table[0][left];
    int i = log2_floor((unsigned long long)(right - left + 1));
    return min(_table[i][left], _table[i][right - (1 << i) + 1]);
}