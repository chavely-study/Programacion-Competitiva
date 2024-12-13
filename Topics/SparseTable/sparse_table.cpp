#pragma region macros

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

#define SPEED                \
    ios::sync_with_stdio(0); \
    cin.tie(0)

#define reverse(x) reverse(x.begin(), x.end())

#define print(x) cout << x << '\n'

#define all(v) v.begin(), v.end()

#define mod(x) x %= (int)(1e9 + 7)

#define rep(a, b) for (int i = a; i < b; i++)
#define per(a, b) for (int i = b - 1; i >= a; i--)
#define repi(i, a, b) for (int i = a; i < b; i++)
#define peri(i, a, b) for (int i = b - 1; i >= a; i--)

#define NO cout << "NO\n"
#define YES cout << "YES\n"
#define NEW_LINE cout << '\n'

#define dx {+1, +0, -1, +0, +1, +1, -1, -1}
#define dy {+0, +1, +0, -1, +1, -1, +1, -1}

#define ALPHABET "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define alphabet "abcdefghijklmnopqrstuvwxyz"
#define decimal_digits "0123456789"

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