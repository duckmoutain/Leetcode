#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class sulotion{

    static bool cmp (vector<int> & a,vector<int> &b){
        if(a[0] != b[0]) return a[0]<b[0];
        return a[1]<b[1];
    }

    public:
    int costmin(vector<int> & blood,vector<vector<int>> & damage){
        sort(blood.begin(),blood.end());
        sort(damage.begin(),damage.end(),cmp);
        int sizeb = blood.size();
        int sized = damage.size();
        int cnt = 0;

        int res = 0;
        int vis[sized+1] = {0};
        for(int i = sizeb-1;i >= 0;i--){
            int thiscost = INT8_MAX;
            int thisplace = sized;
            bool judge = false;
            for(int j = sized - 1;j >= 0 && damage[j][0] >= blood[i];j--){
                
                if(vis[j] == 1) continue;
                //cout << i  << ' ' << blood[i]  << ' '<< j  << ' '<< damage[j][0]  << ' ' << damage[j][1]<< endl;
            
                if(damage[j][0] >= blood[i] && damage[j][1] <= thiscost){
                    thiscost = damage[j][1];
                    thisplace = j;
                    judge = true;
                }
                
                
            }
            if(judge) {
                //cout << thiscost << ' ' << thisplace << endl;
                vis[thisplace] = 1;
                res += thiscost;
                cnt++;
                }
        }
        if(cnt = sizeb)
            return res;
        else return 0;
        }
};


int main(){
    vector<int> res;
    int T ;
    cin >> T;
    sulotion ans;
    while(T--){
        int m,n;
        cin >> m;
        cin >> n;
        vector<int> blood;
        vector<vector<int>> damage;
        for(int i = 0 ;i < m;i++){
            int tmp;
            cin >> tmp;
            blood.push_back(tmp);
        }
        for(int i = 0 ;i < n;i++){
            vector<int> a;
            int tmp;
            cin >> tmp;
            a.push_back(tmp);
            damage.push_back(a);
        }
        for(int i = 0 ;i < n;i++){
            int tmp;
            cin >> tmp;
            damage[i].push_back(tmp);
        }

        res.push_back(ans.costmin(blood,damage));

    }
    for(int i = 0; i < res.size();i++){
        if(res[i] == 0)
            cout << "NO";
        else cout << res[i];
        if(i != res.size()-1) cout << endl;
    }

    return 0;
}
