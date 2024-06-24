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
    int n,idx1,idx2,idx;
    cin >> n;
    vector<int>v(n);
    for(int i=0;i<n;++i){
        cin >> v[i];
        if(v[i]==1) idx1=i;         // index where 1 is stored
        else if(v[i]==2) idx2=i;    // index where 2 is stored
        else if(v[i]==n)   idx=i;   // index where n is stored
    }

    //We just need to chack 3 cases as for any permutation, we have to take 1 then 2 so we put n between them. Now for any permutation, we have to take all 1->n elements.
    //So we get only 2 permutations : [1] and [1 2 3 ... n]

    if(idx>min(idx1,idx2) && idx<max(idx1,idx2))            // if order is like : 1 -> n -> 2  or 2 -> n -> 1
        cout << idx1+1 << " " << idx2+1 << nl;              // Then we don't need to do anything just swap 1 and 2 (not necessary but have to do 1 operation)

    else if(idx>max(idx1,idx2))                             // if order is like : 1 -> 2 -> n  or 2 -> 1 -> n
        cout << max(idx1,idx2)+1 << " " << idx+1 << nl;     // Swap middle and n

    else if(idx<min(idx1,idx2))                             // if order is like : n -> 1 -> 2 or n -> 2 -> 1
        cout << idx+1 << " " << min(idx1,idx2)+1 << nl;     // Swap middle and n
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