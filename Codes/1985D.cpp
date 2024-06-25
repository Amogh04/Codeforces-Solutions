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


int code()
{
    int n,m,maxH=-1,maxW=-1,minH=INT_MAX,minW=INT_MAX;
    cin >> n >> m;
    vector<vector<char>>v(n);
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            char c;
            cin >> c;
            v[i].push_back(c);
            if(v[i][j]=='#'){
                if(i>maxH)  maxH=i;     // Last row having #
                if(j>maxW)  maxW=j;     // Last Column having #
                if(i<minH)  minH=i;     // First row having #
                if(j<minW)  minW=j;     // First Column having #
            }   
        }
    }
    cout << (maxH+minH)/2+1 << " " << (maxW+minW)/2+1 << nl;    // Center
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
    while(t--) code();
    return 0;
}
