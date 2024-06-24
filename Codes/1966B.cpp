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

int fun(vector<vector<char>> &v, char c, int m, int n){
    int tl=0,tr=0,bl=0,br=0,top=0,btm=0,lft=0,rgt=0;
    for(int j=0;j<n;++j){
        if(v[0][j]==c)  top++;
        if(v[m-1][j]==c)    btm++;      // Top and bottom rows.
    }
    for(int i=0;i<m;++i){
        if(v[i][0]==c)  lft++;
        if(v[i][n-1]==c)    rgt++;      // Left and right columns
    }

    if(v[0][0]==c)  tl=1;               // Top left corner
    if(v[0][n-1]==c)  tr=1;             // Top right corner
    if(v[m-1][0]==c)  bl=1;             // Bottom left corner
    if(v[m-1][n-1]==c)  br=1;           // Bottom right corner

    if(tl+br==2 || tr+bl==2){           // If diagonals have same character, whole matrix can be changed in 1 operation.
        return 1;
    }
    else{                                           // If one corner and opposite 2 sides have any same character we can change the whole matrix in 2 operations.
        if(tl==1 && btm>0 && rgt>0) return 1;
        if(tr==1 && lft>0 && btm>0) return 1;
        if(bl==1 && top>0 && rgt>0) return 1;
        if(br==1 && top>0 && lft>0) return 1;
    }
    return 0;
}

int solve()
{
    int m,n;
    cin >> m >> n;
    vector<vector<char>>v(m);
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            char x;
            cin >> x;
            v[i].push_back(x);
        }
    }
    
    if(fun(v,'W',m,n) || fun(v,'B',m,n))    cout << "YES\n";
    else    cout << "NO\n";
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