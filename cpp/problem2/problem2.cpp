#include <iostream>
#include <vector>

using namespace std;

class solution{

    void myqueue(int num){
        vector<int> nums;
        while(num){
            cout << num << ' ';
            nums.insert(nums.begin(),num);
            nums.insert(nums.begin(),nums[nums.size()-1]);
            nums.erase(nums.end()-1);
            num--;
        }
        cout << endl;
        for(int i = 0;i<nums.size();i++){
            cout << nums[i];
            if(i!=nums.size()-1) cout << ' ';
        }
        cout << endl;
    }

public:
    void popthequeue(const vector<int>& nums){
        for(auto i:nums){
            myqueue(i);
        }
    }

};

int main(){
    vector<int> nums;
    int n ;
    cin >> n;
    while(n--){
        int tmp;
        cin >> tmp;
        nums.push_back(tmp);
    }
    solution ans;
    ans.popthequeue(nums);
    return 0;
}