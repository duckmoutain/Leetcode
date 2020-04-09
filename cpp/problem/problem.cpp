#include <limits>
#include <string>
#include <iostream>

using namespace std;

class solution{
        bool judge(string a){
            int i = 0,j = a.size()-1;
            while(i<j){
                if(a[i] != a[j]) return false;
                i++;
                j--;
            }
            return true;
        }

    public:
        int count(string a,string b){
            string tmp = a;
            int res = 0;
            for(int i = 0;i < a.size();i++){
                tmp = a;
                tmp.insert(i,b);
                res += judge(tmp)?1:0;
            }
            return res;
        }
};

int main(){
    string a;
    string b;
    cout << "请输入字符串a: ";
    cin >> a;
    cout << "请输入字符串b： ";
    cin >> b;
    cout << "输入完毕"<<endl;
    solution ans;
    cout << ans.count(a,b);
    return 0;
}