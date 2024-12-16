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

void dfs_visited
(
    int u, int &time, 
    vector<vector<int>> &adj, 
    deque<int> &stk, 
    vector<bool> &done,
    vector<int> &finished
) {
    done[u] = true;
    time = time + 1;
    for (auto v : adj[u]) {
        if (!done[v])
            dfs_visited(v, time, adj, stk, done, finished);
    }
    time = time + 1;
    finished[u] = time;
    stk.push_front(u);
}

deque<int> dfs_topological_sort(vector<vector<int>> &adj)
{
    deque<int> stk;
    int time;
    vector<bool> done(adj.size());
    vector<int> finished(adj.size());
    rep (0, adj.size() - 1) {
        if (!done[i]) 
            dfs_visited(i, time, adj, stk, done, finished);
    }
    return stk;
}

