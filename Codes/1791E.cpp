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
    int n;
    cin >> n;
    vector<int>v(n);
    int sum=0,flag=0,mn=INT_MAX,neg=0;
    for(int i=0;i<n;++i){
        cin >> v[i];
        if(v[i]==0) flag=1;        //If there is any zero we push the negative towards that from both sides.
        sum+=abs(v[i]);
        if(abs(v[i])<mn)    mn=abs(v[i]);   //We will take the minimum value and make it negative and thus subtract that from total sum.
        if(v[i]<0)  neg++;
    }
    if(flag || neg%2==0)  cout << sum << nl;    //If negative values are even, they can be made positive.
    else    cout << sum-2*mn << nl;             //Subtracted 2 times (because minimum value is also contained in total sum)
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