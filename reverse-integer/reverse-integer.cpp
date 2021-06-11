class Solution {
public:
    int reverse(int x) {
        long ans = 0;
        bool sign = true;
        
        if(x < 0)
            sign = false;
        
        x = abs(x);
        while(x > 0)
        {
               int res = x % 10;
               x = x/10; 
               ans = ans *10 + res;
        }
        if(ans > INT_MAX)
            return 0;
        else
            return sign ? (int)ans : (int)-ans ;
    }
};