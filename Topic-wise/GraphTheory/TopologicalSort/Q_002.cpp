#include <bits/stdc++.h>

/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
*/


using namespace std;
// using namespace __gnu_pbds;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int MOD = 998244353;
using ll = long long;
const ll INF = 1e18;

/*
https://www.spoj.com/problems/TOPOSORT/
*/


void solve() {
    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> adjList(n + 1);
    vector<ll> indegree(n + 1, 0);
    
    for (int i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;

        adjList[u].push_back(v);
        ++indegree[v];
    }

    priority_queue<ll, vector<ll>, greater<ll>> q;
    for (int i = 1; i <= n; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<ll> topo;
    while (!q.empty()) {
        ll u = q.top();
        q.pop();

        topo.push_back(u);
        for (ll v: adjList[u]) {
            --indegree[v];

            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    if (topo.size() != n) {
        cout << "Sandro fails.\n";
    } else {
        for (int i = 0; i < n; ++i) {
            cout << topo[i] << ' ';
        }
    }
}



int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    
    int test_cases = 1;
    // cin >> test_cases;

    while (test_cases--) {
        solve();
    }

    #ifndef ONLINE_JUDGE
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif

    return 0;
}
