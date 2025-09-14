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
https://codeforces.com/edu/course/2/lesson/4/3/practice/contest/274545/problem/A
*/


class SegmentTree {
public:
    vector<ll> tree;

    SegmentTree(vector<ll>& a) {
        tree = vector<ll> (4 * a.size() + 3, 0);
        build(1, 0, a.size() - 1, a);
    }

    void build(ll v, ll tl, ll tr, vector<ll>& a) {
        if (tl == tr) {
            tree[v] = a[tl];
        } else {
            ll tm = (tl + tr) / 2;
            build(2 * v, tl, tm, a);
            build(2 * v + 1, tm + 1, tr, a);
            tree[v] = tree[2 * v] + tree[2 * v + 1];
        }
    }

    void update(ll v, ll tl, ll tr, ll pos, ll new_val) {
        if (tl == tr) {
            tree[v] = new_val;
        } else {
            ll tm = (tl + tr) / 2;
            if (pos <= tm) {
                update(2 * v, tl, tm, pos, new_val);
            } else {
                update(2 * v + 1, tm + 1, tr, pos, new_val);
            }
            tree[v] = tree[2 * v] + tree[2 * v + 1];
        }
    }

    ll query(ll v, ll tl, ll tr, ll l, ll r) {
        if (l > r) {
            return 0;
        }

        if (l == tl && r == tr) {
            return tree[v];
        }

        ll tm = (tl + tr) / 2;
        return query(2 * v, tl, tm, l, min(r, tm)) + query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
    }
};


void solve() {
    ll n;
    cin >> n;

    vector<ll> zeroes(n, 0);
    vector<ll> arr(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        --arr[i];
    }

    SegmentTree st(zeroes);
    for (ll i = 0; i < n; ++i) {
        st.update(1, 0, n - 1, arr[i], 1);
        cout << st.query(1, 0, n - 1, arr[i] + 1, n - 1) << ' ';
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
