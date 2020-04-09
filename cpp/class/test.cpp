#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <cmath>
#include <iostream>

using namespace std;


class test{

public:

    string testunordered_map(){
        unordered_map<int,int> hashmap;
        unordered_set<int,int> hashset;
        return " ";
    }

    string teststack(){
        stack<int> s;
        int tmp;
        string res;

        while(cin>>tmp){
 
            s.push(tmp);
        }
        while(!s.empty()){
            res += to_string(s.top()) + ' ';
            s.pop();
        }
        return res;
    }


    string testqueue(){
        string tmp;
        queue<string> q;
        int n;
        cin >> n;
        while(n--){
            // cin >> tmp;
            getline(cin,tmp);
            q.push(tmp);
        }
        string res;
        while(!q.empty()){
            res += (q.front()) + ' ';
            q.pop();
        }
        return res;
    }

};





int main(){
    test ans;
    //cout << ans.testqueue() << endl;
    cout << ans.teststack()<<endl;
    return 0;
}