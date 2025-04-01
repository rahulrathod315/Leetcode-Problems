#include <iostream>

using namespace std;

class Solution {
    public:
        int arrangeCoins(int n) 
        {
            long long i = 1;
            long long j = n;
            long long result = 1;
            while(i <= j)
            {
                long long mid = i + (j - i) / 2;
    
                if((mid * (mid + 1) / 2) > n)
                {
                    j = mid - 1;
                }
                else
                {
                    result = mid;
                    i = mid + 1;
                }
            }
            return result;
        }
    };