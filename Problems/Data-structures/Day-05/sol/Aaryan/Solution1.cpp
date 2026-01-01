//link : https://cses.fi/problemset/result/15779150/

#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define loop(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define F first
#define S second

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

void solve() {
    int n;
    cin >> n;

    vi a(n), ans;
    loop(i, n) cin >> a[i];

    stack<pii> st; // {value, index}

    loop(i, n) {
        while (!st.empty() && st.top().F >= a[i])
            st.pop();

        if (st.empty()) ans.pb(0);
        else ans.pb(st.top().S);

        st.push({a[i], i + 1});
    }

    for (int x : ans) cout << x << " ";
    cout << '\n';
}

int main() {
    fast_io;
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}



/*
Explanation:

We use a monotonic increasing stack to find the nearest smaller element
to the left for each position.

The stack stores pairs (value, index). For each element a[i], we remove
all elements from the stack whose value is greater than or equal to a[i],
since they cannot be the answer for the current or any future element.

After popping:
- If the stack is empty, no smaller element exists on the left → output 0.
- Otherwise, the top of the stack gives the index of the nearest smaller element.

Finally, we push (a[i], i+1) into the stack.

Time Complexity: O(n)   
Space Complexity: O(n)


*/