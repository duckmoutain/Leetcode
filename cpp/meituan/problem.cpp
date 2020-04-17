#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class sulotion{

    vector<int> nums1;
public:
    void two_list(int a,int b){
        nums1.clear();
        while(a--){
            int tmp;
            cin >> tmp;
            nums1.push_back(tmp);
        }
        while(b--){
            int tmp;
            cin >> tmp;
            nums1.push_back(tmp);
        }
        sort(nums1.begin(),nums1.end());
        nums1.erase(unique(nums1.begin(),nums1.end()), nums1.end());
        for(int k = 0;k < nums1.size();k++){
            cout << nums1[k];
           if(k!= nums1.size()-1){
               cout << ' ';
           }
        }
        cout << endl;

    }

};

int main(){
    sulotion ans;
    int a,b;
    while(    scanf("%d%d",&a,&b)!=EOF){
        ans.two_list(a,b);
    }
    return 0;
}