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
https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/A
*/


class SegmentTree {
public:
    vector<ll> tree;
    int n;

    SegmentTree(vector<ll>& a) {
        this->n = a.size();

        tree = vector<ll> (4 * n + 3, 0);
        build(1, 0, n - 1, a);
    }

    void build(int v, int tl, int tr, vector<ll>& a) {
        if (tl == tr) {
            tree[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(2*v, tl, tm, a);
            build(2*v + 1, tm + 1, tr, a);
            tree[v] = tree[2*v] + tree[2*v + 1];
        }
    }

    void update(int  v, int tl, int tr, int pos, ll new_val) {
        if (tl == tr) {
            tree[v] = new_val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) {
                update(2*v, tl, tm, pos, new_val);
            } else {
                update(2*v + 1, tm + 1, tr, pos, new_val);
            }
            tree[v] = tree[2*v] + tree[2*v + 1];
        }
    }

    ll query(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            return 0LL;
        }

        if (tl == l && tr == r) {
            return tree[v];
        }

        int tm = (tl + tr) / 2;

        return query(2*v, tl, tm, l, min(r, tm)) + query(2*v + 1, tm + 1, tr, max(l, tm + 1), r);
    }
};


void solve() {
    ll n, m;
    cin >> n >> m;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    SegmentTree st(a);
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;

        if (x == 1) {
            ll i, v;
            cin >> i >> v;

            st.update(1, 0, n - 1, i, v);
        } else {
            ll l, r;
            cin >> l >> r;

            ll ans = st.query(1, 0, n - 1, l, r - 1);
            cout << ans << '\n';
        }
    }
}


int main() {
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
