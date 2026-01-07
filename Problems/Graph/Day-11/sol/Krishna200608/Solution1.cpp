/*
Submission Link:
https://codeforces.com/contest/580/submission/356719898
*/

/*
Problem: Kefa and Park
Link: https://codeforces.com/problemset/problem/580/C
Author: Krishna200608

Problem Summary:
Kefa starts at node 1 and wants to reach any leaf node in the tree. 
He avoids paths that contain more than m consecutive nodes with cats. 
The task is to count how many leaf nodes are reachable without breaking this rule.

Approach:

    1. Treat the given graph as a tree rooted at node 1 and start DFS from it.
    2. While traversing, keep track of consecutive nodes having cats.
    3. Increment the count if the current node has a cat, otherwise reset it to 0.
    4. If at any time the consecutive cat count exceeds m, prune that path.
    5. Identify a leaf node as a node having no children other than its parent.
    6. Count every leaf node reached through a valid path as a safe destination.


Complexity:
    Time: O(N)
    Space: O(N)
*/

#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
const int M = 1e9+7;
const double PI = acos(-1.0);
#define INF 1e18
#define pb push_back
#define ppb pop_back
#define ll long long
#define no cout << "NO" << endl;
#define yes cout << "YES" << endl;
#define ff first
#define ss second
#define inn(x) int x; std::cin >> x;
#define ill(x) ll x; std::cin >> x;
#define all(x) x.begin(),x.end()
#define in(a) for(int i = 0; i<a.size(); i++) cin>>a[i];
#define out(a) for(int i = 0; i<a.size(); i++) cout<<a[i]<< " " ;
typedef vector<int> vi;
typedef vector<ll> vll;
#define ceil_div(n, x)  ( ((n) % (x) == 0) ? ((n) / (x)) : ((n) / (x) + 1) )
#define debug(x) cout << "x -> " << x << endl;
#define outt(x) cout << x << endl;
#define endl "\n"
 
vi cat;
vector<vi> adj;
int n, m;
int ans = 0;

void dfs(int u, int p, int consec) {
    if(cat[u]) consec++;
    else consec = 0;

    if(consec > m) return;

    bool isLeaf = true;
    for(int v : adj[u]) {
        if(v != p) {
            isLeaf = false;
            dfs(v, u, consec);
        }
    }

    if(isLeaf) ans++;
}

void solve(){
    cin >> n >> m;
    cat.resize(n + 1);
    adj.resize(n + 1);

    for(int i = 1; i <= n; i++) cin >> cat[i];

    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1, 0, 0);
    outt(ans);
}

signed main(){
ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
auto begin = std::chrono::high_resolution_clock::now();
    int t=1;
    while(t--){
        solve();
    }
 
 
 
auto end = std::chrono::high_resolution_clock::now();
auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
cerr << "Time measured: " << elapsed.count() * 1e-6 << "ms";
return 0;
}