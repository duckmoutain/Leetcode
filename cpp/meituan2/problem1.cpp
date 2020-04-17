#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <limits>

using namespace std;

int main(){
    int m,n;
    cin >> m;
    cin >> n;
    vector<vector<int>> stu_sor;
    unordered_set<int> hashset;
    
    for(int i = 0;i<m;i++){
        vector<int> tmp;
        tmp.push_back(i);
        for(int j = 0;j < n;j++){
            int sor;
            cin >> sor;
            tmp.push_back(sor);
        }
        stu_sor.push_back(tmp);
    }
    for(int i = 1;i <= n;i++){
        vector<int> nums;
        int max_this = 0;
        for(int j = 0;j < m;j++){
            max_this = max_this > stu_sor[j][i] ? max_this : stu_sor[j][i];
        }
        for(int j = 0;j < m;j++){
            if(stu_sor[j][i] == max_this) hashset.insert(j);
        }
    }
    cout << hashset.size();
    return 0;

}