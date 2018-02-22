//string 拼接 用StringBuffer，性能高，线程安全。用+则会不断的创建string对象，大量的扩容和拷贝，效率低。

class Solution {
    public int numJewelsInStones(String J, String S) {
        if(J.length() <=0 || S.length() <= 0)
            return 0;
        
        StringBuffer tmp = new StringBuffer();
        int count = 0;
        for(int i=0; i<S.length(); i++)
        {
            if(J.charAt(0) == S.charAt(i))
            {
                count++;
            }
            else{
                tmp.append(S.charAt(i)); 
            }
        }
        
        return numJewelsInStones(J.substring(1), tmp.toString()) + count;
    }
}

//优化方法，用set
public int numJewelsInStones(String J, String S) {
        int res = 0;
        Set setJ = new HashSet();
        for (char j: J.toCharArray()) setJ.add(j);
        for (char s: S.toCharArray()) if (setJ.contains(s)) res++;
        return res;
    }