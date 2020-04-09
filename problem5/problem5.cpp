#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <limits>
#define mode 1000000007
#define ll long long
using namespace std;

int main(){
    int n,l;
    cin >> n;
    cin >> l;
    vector<int> ans;
    while(n!=0 && l!=0){
        ll dp[l];
        dp[0] = n;
        ll res = n;
        for(int i = 1;i<l;i++){
            dp[i] = (dp[i-1]%mode) * (n%mode) ;
            res += dp[i]%mode;
             res = res%mode;
            //cout << res << ' ';
        }
        ans.push_back(res);
        cin >> n;
        cin >> l;
    }
    for(auto i:ans){
        cout << i << endl;
    }
    return 0;
}