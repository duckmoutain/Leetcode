class Solution {
public:
    int longestPalindrome(string s) {
        using namespace std;
        int cnt[52] = {0};//计数器
        int len = s.size();//;获取字符串长度
        while(len --){//对每个字符进行计数；
            if(s[len] >= 'a' )
                cnt[s[len]-'a'+26]++;
            else
                cnt[s[len]-'A']++;
        }

        int judge = 0;
        int res = 0;

        for(int i = 0;i<52;i++){
            if(cnt[i]%2 == 0) res+=cnt[i];//若为偶数则全可用
            else {res+= cnt[i] - 1 ; judge = 1;}//若为奇数则用偶数的部分并且奇数判断为１；
        }
        return res+judge;
    }
};