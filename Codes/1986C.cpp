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
    int m,n;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int>ind(m);
    string c;
    for(int i=0;i<m;++i)    cin >> ind[i];
    cin >> c;

    sort(ind.begin(),ind.end());
    sort(c.begin(),c.end());        // Sort the string and indices vector.
    int j=0;
    map<int,int>mp;
    for(int i=0; i<m&&j<m ;++i){
        while(i<m && mp[ind[i]]>0)   i++;   // if any duplicate indices, skip them as we will have already assigned lower characters to them.
        if(i>=m)  break;
        s[ind[i]-1]=c[j];   //assigning sorted (lower) charaters to lower indices.
        mp[ind[i]]++;
        ++j;
    }
    cout << s << nl;
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