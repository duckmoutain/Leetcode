#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <limits>

#define ll long long
#define mode 1000000007

using namespace std;

int dpstr(string s,string t){
    int ssize = s.size(),tsize = t.size();
    if(tsize == 0) return 1;
    if(ssize == 0) return 0;
    vector<vector<ll>> dp(ssize+1,vector<ll>(tsize+1,0));

    for(int i = 0;i<=ssize;i++){
        dp[i][0] = 1;
    }

    for(int i = 1;i <= ssize;i++){
        for(int j = 1;j <=tsize;j++){
            dp[i][j] = dp[i-1][j];
            if(s[i-1] == t[j-1]) dp[i][j] += dp[i-1][j-1];
        }
    }
    //cout << dp[ssize][tsize];
    return dp[ssize][tsize];
}

int main(){
    string s;
    string t;
    cin >> s;
    cin >> t;
    ll ret = 0;
    for(int i = 0;i < s.size();i++){
        for(int j = i;j < s.size();j++){
            string tmp = s.substr(i,j-i+1);
        
            ret  = (ret%mode + dpstr(t,tmp)%mode)%mode;
            //cout << tmp << endl;
        }
    }
    cout << ret;
    return 0;
}