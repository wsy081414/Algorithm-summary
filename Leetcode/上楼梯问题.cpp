

//说给你n阶台阶，对于这n阶台阶我们有两种上法，要么可以一次一阶，要么一次两阶。
//求得n阶台阶有多少种方法可以爬上去。
//一种斐波那契数列的变形的解法。
//可以高效的求得
//动态规划


class Solution {
public:
    int climbStairs(int n) {
        vector<int >data(n+1,-1);
        data[0] = 1;data[1] = 1;
        for(int i = 2;i <= n;i++)
        {
            data[i] = data[i-1]+data[i+2];
        }
        return data[n];
    }
};