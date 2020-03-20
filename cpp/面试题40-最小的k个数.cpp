class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        vector<int> res(arr.begin(),arr.begin()+k);
        //初始化返回数组时，直接将前K个值存入。
        return res;
    }
};