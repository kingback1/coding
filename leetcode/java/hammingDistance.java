public class Solution {
    public int hammingDistance(int x, int y) {
        //首先做异或，相同为0，不同为1
        int c = x ^ y;
        //计算c中有多少个1
        int n = 0;
        while(c != 0)
        {
            c = c & (c-1);
            n++;
        }
        
        return n;
    }
}