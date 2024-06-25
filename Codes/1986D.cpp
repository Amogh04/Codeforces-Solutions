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
    int n,mn=10,idx=-1;
    cin >> n;
    string s;
    cin >> s;
    if(n==2)    cout << (s[0]-'0')*10+s[1]-'0' << nl;       // If n=2 we can't insert any operations.
    else if(n==3 && s[1]=='0' && s[2]!='0' && s[0]!='0'){   // If n=3 and '0' comes in middle like '102' we can't multiply by zero.
        if(s[2]=='1')   cout << s[0] << nl;
        else if(s[0]=='1')  cout << s[2] << nl;
        else cout << s[0]-'0'+s[2]-'0' << nl;
    }
    else{
        int sum=0;
        for(int i=0;i<n;++i){
            if(s[i]=='0'){
                cout << "0\n";              // If any zero is found in string we can multiple it by zero like : 1204 -> 12*0*4
                return 0;
            }
            if(s[i]-'0'<=mn){
                mn=s[i]-'0';                // Now since there is no '0', we need to insert n-2 symbols i.e. there are symbols between each character of string, except two characters which are joint together without any symbol, to form a 2 digit number.
                idx=i;                      // So we find the minimum number, So that the 2 digit number has the minimum value in 10's place.
            }
        }
        if(idx==n-1){
            int x=10,idx2=-1,y=10;          // If that minimum is at last place, we can't use it to form 10's place of a 2 digit number. So find 2nd minimum.
            for(int i=0;i<n-1;++i){
                if(s[i]-'0'<x ){
                    x=s[i]-'0';
                    idx2=i;
                    y=s[i+1]-'0';
                }
                if(s[i]-'0'<=x && s[i+1]-'0'>=y){
                    x=s[i]-'0';
                    idx2=i;
                    y=s[i+1]-'0';
                }
            } 
            mn=x;
            idx=idx2;
        }
        for(int i=0;i<n;++i){
            if(i!=idx && s[i]=='1') continue;       // If any character (except that one which we are using to form 2-digit no.) is '1' we insert multiply sign instead of adding.
            if(i==idx){
                sum+=(s[i]-'0')*10+s[i+1]-'0';
                ++i;
            }
            else
                sum+=s[i]-'0';
        }
        cout << sum << nl;
    }
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