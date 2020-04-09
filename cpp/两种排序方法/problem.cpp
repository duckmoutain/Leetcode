#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class solution{

    bool judge(const vector<string>& a,const vector<string>& b){
        int size_ = a.size();
        while(size_--){
            if(a[size_] != b[size_]) return false;
        }
        return true;
    }

    static bool cmp1(const string a,const string b){
        return a.size()<b.size();
    }

    static bool cmp2(const string a,const string b){
        int size_ = a.size()>b.size()?b.size():a.size();
        for(int i = 0;i < size_;i++){
            if(a[i] == b[i]) continue;
            return a[i] < b[i];
        }
        return a.size() < b.size();
    }

public:
    string ju(const vector<string>& a){
        vector<string> b(a.begin(),a.end());
        vector<string> c(a.begin(),a.end());
        sort(b.begin(),b.end(),cmp1);
        // for(auto iter = b.begin();iter != b.end();iter++){
        //     cout << *iter<< ' ';
        // }
        sort(c.begin(),c.end(),cmp2);
        bool j1 = judge(a,b);
        bool j2 = judge(a,c);
        if(j1 && j2) return "both";
        else if(j1) return "lenghts";
        else if(j2) return "lexicographically";
        else return "none";

    }

};

int main(){
    
    string tmp;
    vector<string> strs;
    int n;
    cin >> n;
    int i = n;
    while(i--){
        cin >> tmp;
        strs.push_back(tmp);
    }
    solution ans;
    cout << ans.ju(strs);

    return 0;
}