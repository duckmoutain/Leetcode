#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <limits>

using namespace std;

bool isvaild(const vector<int> & a){
    if(a.size() %2 == 1) return false;
    for(int i = 0;i < a.size()/2;i++){
        if(a[i] != a[a.size()/2+i]) return false;
    }
    return true;
}

int main(){
    int a,b,m,x;
    cin >> a >> b >> m >> x;
    vector<int> nums;
    while(1){
        x = (a*x+b)%m;
        nums.push_back(x);
        if(isvaild(nums)) {
            cout << nums.size()/2 ;
            break;
        }
    }
    return 0;
}