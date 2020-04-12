class Solution {
public:
    string longestPalindrome(string s) {
    int length=s.length();
   if(length<=1)
   {
       return s;
   }
   vector<vector<int>>res (length,vector<int>(length,0));
    //先初始化二维数组（对角线）
   for(int i=0;i<length;i++)
    {
        res[i][i]=1;
    }
    int start=0;//记录最大回文子串的开始位置
    int maxlength=1;//记录最大回文子串的长度
    for(int i=1;i<length;i++)//两层for循环遍历每一个位置到另一个位置的情况
    {
        for(int j=0;j<i;j++)
        {
            if(s[i]==s[j])
            {
                if(i-j<3)//如果如果两个相等字符之间只有一个字符，那么一定回文
                {
                    res[j][i]=1;
                }
                else
                {
                    res[j][i]=res[j+1][i-1];
                }
            }
            if(res[j][i])//当j到i之间的子串回文时判断其长度是否最大，然后更改
            {
                if(i-j+1>maxlength)
                {
                    maxlength=i-j+1;
                    start=j;
                }
            }

        }
    }
    return s.substr(start,maxlength);
  }
};


