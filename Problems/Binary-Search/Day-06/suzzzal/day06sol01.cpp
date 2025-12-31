// submission - https://codeforces.com/contest/2014/submission/356012129

/*
Approach:
Binary search the extra gold x.
For each x, compute new average and count people with wealth < half of it.
If count > n/2, x is valid. Find minimum such x.

Complexity:
O(n log n)
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<long long>a(n);
        long long sum=0;
        for(int i=0;i<n;i++){cin>>a[i];sum+=a[i];}
        if(n<=2){cout<<-1<<"\n";continue;}
        sort(a.begin(),a.end());
        long long l=0,r=1e18,ans=-1;
        while(l<=r){
            long long mid=(l+r)/2;
            long double avg=(long double)(sum+mid)/n;
            long double half=avg/2.0;
            int cnt=0;
            for(long long v:a) if((long double)v<half) cnt++;
            if(cnt>n/2){ans=mid;r=mid-1;}
            else l=mid+1;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
