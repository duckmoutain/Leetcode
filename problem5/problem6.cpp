#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main(){
    string s;
    int n,size_;
    cin >> n;
    vector<string> ans;
    while(n--){
        cin >> size_;
        cin >> s;
        int i;
        for(i = 0;i<s.size();i++){
            if(s[i] == '1') continue;
            if( i < s.size()-1 && s[i] == '0' && s[i+1] == '0'){
                s[i] = '1';
            }
            if( i < s.size()-2  && s[i] == '0' && s[i+1] == '1' ){
                for(int j = i+1;j < s.size();j++){
                    if(s[j] == '0'){
                        for(int k = j;k >= i;k--){
                            s[k] = '1';
                            ////cout << s << endl;
                        }
                        //cout << s << endl;
                        s[i+1] = '0';
                        break;
                    }
                }
            }
        }
        ans.push_back(s);
    }
    for(auto str:ans){
        std::cout << str << endl;
    }
    return 0;
}