

//˵����n��̨�ף�������n��̨�������������Ϸ���Ҫô����һ��һ�ף�Ҫôһ�����ס�
//���n��̨���ж����ַ�����������ȥ��
//һ��쳲��������еı��εĽⷨ��
//���Ը�Ч�����
//��̬�滮
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