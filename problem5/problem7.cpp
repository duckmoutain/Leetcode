#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <limits>

#define size_ 9

using namespace std;

class solution{

    bool isvaild(vector<vector<int>> & shudu,int row,int col,int temp){
        for(int i = 0;i<9;i++){
            if(shudu[row][i] == temp) return false;
        }
        for(int i = 0;i<9;i++){
            if(shudu[i][col] == temp) return false;
        }
        int i = row /3;
        int j = col /3;
        for(int x = i*3;x<(i*3)+3;x++){
            for(int y = j*3;y <(j*3)+3;y++){
                if(shudu[x][y] == temp)
                    return false;
            }
        }
        //cout << temp;
        return true;
    }

    bool recall(vector<vector<int>> & shudu,int row,int col){
        //bool isvaild(vector<vector<int>> & shudu,int row,int col,int temp);
        if(col == 9){
            col = 0;
            row ++;
        }

        if(row == 9){
            return true;
        }

        if(shudu[row][col] != 0)
            return recall(shudu,row, col +1 );
        else{
            for(int tmp = 1;tmp <= 9;tmp ++){
                //cout << tmp;
                if(isvaild(shudu,row,col,tmp)) {
                    shudu[row][col] = tmp;
                    //cout << tmp;
                }
                else {
                    continue;
                }

                if(recall(shudu,row,col+1)) {
                    return true;
                }
                else {
                    shudu[row][col] = 0;
                }
            }
        }
        return false;
    }
    
    public:
        void solveshudu(vector<vector<int>> & shudu){
            //bool recall(vector<vector<int>> & shudu,int row,int col);
            recall(shudu,0,0);
            return;
        }
    
};



int main(){
    int i = 9;
    vector<vector<int>> shudu;
    vector<int> tmp;
    while(i--){
        string s;
        cin >> s;
        for(auto ch:s){
            if(ch <= '9' && ch >= '0') tmp.push_back(ch-'0');
        } 
        shudu.push_back(tmp);
        tmp.clear();
    }
    solution ans;
    //cout << endl;
    ans.solveshudu(shudu);
    for(int j = 0;j < shudu.size();j++){
        cout << '{' ;
        for(int k = 0;k < 9;k++){
            cout << shudu[j][k];
            if(k != 8) cout << ',';
        }
        cout << '}'<< endl;
    }
    return 0;
}