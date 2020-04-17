#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <limits>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> nums;
    for(int i = 0;i < n;i++){
        int tmp;
        cin >> tmp;
        nums.push_back(tmp);
    }
    sort(nums.begin(),nums.end());
    int middle = nums.size()/2;
    int i ;
    for(i = 0;i < nums.size();i++){
        if(nums[i] >= k) break;
    }
    if(i > middle) cout << 2*i - nums.size();
    else cout << nums.size()-2*i;
    return 0;
}