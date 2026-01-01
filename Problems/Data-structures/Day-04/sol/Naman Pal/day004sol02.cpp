// Submission Link:https://codeforces.com/contest/1912/submission/355954772

/*
I made a vector storing value pair(ll, ll). Now I iterated through each list and started storing current sum of the sublist 
and minimum cost required to reach that point of sublist-. Now if profit>0 at that point we are getting profit so I stored
{cost , profit} in a. This mean we need atleast cost value of x in order to reach that profit and then I set profit to zero for 
next sublist. Now after first substring's profit and cost is stored and for second substring the minimum power required to gain 
profit would be max(cost(for first sublist), cost(for second sublist)) as we would need atleast the cost to make first sublist
an then if cost required for the second sublist is more then we would need that cost and cost for first wouldn't be sufficient
Now I sorted the vector and that would be sorted in order of first element of the pair so that greedily I could 
increase my profit at as minimum cost as possible in order to increase chances for other sublist which require more cost
and if at any point the sublist cannot be added then the sublist after that in a can also never be added so I break my loop 
at that point. After completing this process I printed the final maximum possible value of x.   
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x, k;
    cin>>x>>k;
    vector <pair<long long, long long>> a;
    while(k--) {
        long long n;
        cin>>n;
        long long profit=0, cost=0;
        for(int i=0; i<n; i++) {
            long long x;
            cin>>x;
            profit+=x;
            cost=max(cost, -profit);
            if(profit>0) {
                a.push_back({ cost, profit});
                profit=0;
            }
        }
    }
    sort(a.begin(), a.end());
    for(auto i: a) {
        if(i.first>x) break;
        x+=i.second;
    }
    cout<<x<<endl;
}

