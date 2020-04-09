#include <unordered_map>
#include <iostream>

using namespace std;

class sulotion{
    public:
        int count_word(const string & s,const char a){
            unordered_map<char,int> hashmap;
            for(auto i:s){
                i = tolower(i);
                if(hashmap.count(i) == 0) hashmap[i] = 1;
                else hashmap[i]++;
            }
            if(hashmap.count(a) == 0) return 0;
            return hashmap[a];
            
        }
};

int main(){
    string s;
    getline(cin,s);
    char a;
    scanf("%s",&a)!=EOF;
    sulotion ans;
    cout << ans.count_word(s,a);
    return 0;
}