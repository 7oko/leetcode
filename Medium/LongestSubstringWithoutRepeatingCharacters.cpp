class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        if(s.size() == 0)
            return 0;
        if(s.size() == 1)
            return 1;

        int ans = 0;
        int i = 0, j = 1, k;

        while(j < s.size())
        {
            for(k = i;k < j; k++)
            {
                if(s[k] == s[j])
                {
                    i = k + 1;
                    break;  
                }    
            }
            j++;
            ans = max(j - i, ans);
        }
        return ans;
    }
};