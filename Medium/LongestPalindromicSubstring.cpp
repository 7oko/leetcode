class Solution {
public:
    string longestPalindrome(string s) {
    int length=s.length();
   if(length<=1)
   {
       return s;
   }
   vector<vector<int>>res (length,vector<int>(length,0));
    //�ȳ�ʼ����ά���飨�Խ��ߣ�
   for(int i=0;i<length;i++)
    {
        res[i][i]=1;
    }
    int start=0;//��¼�������Ӵ��Ŀ�ʼλ��
    int maxlength=1;//��¼�������Ӵ��ĳ���
    for(int i=1;i<length;i++)//����forѭ������ÿһ��λ�õ���һ��λ�õ����
    {
        for(int j=0;j<i;j++)
        {
            if(s[i]==s[j])
            {
                if(i-j<3)//��������������ַ�֮��ֻ��һ���ַ�����ôһ������
                {
                    res[j][i]=1;
                }
                else
                {
                    res[j][i]=res[j+1][i-1];
                }
            }
            if(res[j][i])//��j��i֮����Ӵ�����ʱ�ж��䳤���Ƿ����Ȼ�����
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


