#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1 , vector<int>& rec2 ) {
        return (min(rec1[2],rec2[2]) > max(rec1[0],rec2[0]) &&
        min(rec1[3],rec2[3]) > max(rec1[1],rec2[1]));
    }
};

int main(){
    Solution ans;
    vector<int> rec1;
    vector<int> rec2;
    for(int i = 0;i<4;i++){
        int tmp;
        cin >> tmp;
        rec1.push_back(tmp);
    }
    for(int i = 0;i<4;i++){
        int tmp;
        cin >> tmp;
        rec2.push_back(tmp);
    }
    cout << ans.isRectangleOverlap(rec1,rec2) << endl;
    return 0;
}