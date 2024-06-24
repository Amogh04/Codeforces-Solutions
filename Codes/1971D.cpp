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
    int cuts=1;
    string s;
    cin >> s;
    int flag=0;
    for(int i=0;i<s.size()-1;++i){
        if(s[i]=='1' && s[i+1]=='0'){       // We only need to make cuts if there is a '1' folllowed by '0'
            ++cuts;                          // Made a cut after '1'.
            ++i;
            while(i<s.size() && s[i]!='1')  ++i;    // All the zeroes after that '1' will pe put to the start of string.
            if(i==s.size()) break;
            else{
                if(s[0]=='0')   cuts++;          // If starting character is '0' and we put this cutted string of '0000..00' in start it is fine, as we did in line 28. but now since we have not reached the end of string and '1' has appeared again, we need to make one more cut.
                else{
                    if(!flag)   flag=1;         // If starting char is '1' the string will look like : '00001...'which is fine for the first time.
                    else    cuts++;              // But if this happens again string is like : '000010000' because some zeroes were already shifted to starting and we still have a '1' at s[0]. So, cuts++ i.e. one more cut.
                }
            }
            --i;
        }
    }
    cout << cuts << nl;
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