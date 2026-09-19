class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        long long palin=0;
        int org=x;
        while(x>0){
            palin=palin*10+(x%10);
            x/=10;
        }
        return org==palin;
        
    }
};