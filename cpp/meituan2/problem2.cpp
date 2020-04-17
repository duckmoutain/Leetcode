#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <limits>

using namespace std;

static bool cmp(const pair<int,int> & a,const pair<int,int> & b){
    if(a.first != b.first) {
        return a.first < b.first;
    }
    return a.second < b.second;
}


int main(){
    int n,k;
    cin >> n;
    cin >> k;
    vector<int> nums;
    for(int i = 0;i < n;i++){
        int tmp;
        cin >> tmp;
        nums.push_back(tmp);
    }

    vector<pair<int,int>> need_sort;
    for(int i = 0 ;i<n;i++){
        for(int j = 0;j < n;j++){
            pair<int,int> tmp;
            tmp.first = nums[i];
            tmp.second = nums[j];
            need_sort.push_back(tmp);
        }
    }

    sort(need_sort.begin(),need_sort.end(),cmp);
    for(int i = 0; i<need_sort.size();i++){
        cout << '(' << need_sort[i].first << ',' << need_sort[i].second << ')';
    }
    cout << endl;
    cout << '(' << need_sort[k-1].first << ',' << need_sort[k-1].second << ')';
    return 0;
}