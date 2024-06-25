/*
                        ╭━━━╮╭━╮╭━╮╭━━━╮╭━━━╮╭╮╱╭╮
                        ┃╭━╮┃┃┃╰╯┃┃┃╭━╮┃┃╭━╮┃┃┃╱┃┃
                        ┃┃╱┃┃┃╭╮╭╮┃┃┃╱┃┃┃┃╱╰╯┃╰━╯┃
                        ┃╰━╯┃┃┃┃┃┃┃┃┃╱┃┃┃┃╭━╮┃╭━╮┃
                        ┃╭━╮┃┃┃┃┃┃┃┃╰━╯┃┃╰┻━┃┃┃╱┃┃
                        ╰╯╱╰╯╰╯╰╯╰╯╰━━━╯╰━━━╯╰╯╱╰╯

*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define flush cout << flush;
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl "\n" 
const int INF = LLONG_MAX >> 1;
const int MOD = 1000000007;


int solve()
{
    int n,cnt=0,sum=0;
    map<double,int>mp;
    cin >> n;
    vector<int>v(n);
    for(int i=0;i<n;++i){
        cin >> v[i];
        mp[1.0*v[i]]++;     // Create a map for the elements of vector.
        sum+=v[i];          // Sum till now.

        if(mp[(1.0*sum)/2]!=0)   cnt++;     // If there is any element till now which can be written as the sum of all other elements in sum, the total sum should be (2*that element).
    }
    cout << cnt << nl;
    return 0;
}


signed main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    IO;
    int t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}
