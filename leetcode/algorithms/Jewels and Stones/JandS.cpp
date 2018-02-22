class Solution {
public:
    int numJewelsInStones(string J, string S) {
        if(J.length() <=0 || S.length() <=0)
            return 0;
        
        string tmp = "";
        int count = 0;
        for(int i =0; i<S.length(); i++)
        {
            if(J[0] == S[i])
            {
                count++;
            }
            else{
                tmp+=S[i];
            }
        }
        
        return numJewelsInStones(J.substr(1), tmp) + count;
    }
    
};

//优化方法，用set
int numJewelsInStones(string J, string S) {
        int res = 0;
        set<char> setJ(J.begin(), J.end());
        for (char s : S) if (setJ.count(s)) res++;
        return res;
    }