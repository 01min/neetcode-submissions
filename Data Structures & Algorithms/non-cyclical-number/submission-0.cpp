class Solution {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = getNext(n);
       
        while (fast != 1 && slow != fast) {
            slow = getNext(slow);        
            fast = getNext(getNext(fast)); 
        }
        return fast == 1;
    }

private:
    int getNext(int num) {
        int totalSum = 0;
        while (num > 0) {
            int digit = num % 10;
            totalSum += digit * digit;
            num /= 10;
        }
        return totalSum;
    }
};