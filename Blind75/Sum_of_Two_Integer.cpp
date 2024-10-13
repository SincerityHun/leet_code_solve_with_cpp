#include <iostream>
#include <cmath>
/*
오답노트
1. 범위 확인
-> 1000 + 1000은 2000이라면 여기까지 범위가 가능하게 했어야한다.
2. 덧셈, 뻴셈을 아예 사용하면 안된다.
-> 그래서 1차답안은 사실 틀린거임
-> XOR 연산 => 자리 올림 없이 두 수의 덧셈 결과를 저장함
-> AND 연산 => 두 수의 덧셈 시 각 자리에서 발생하는 자리 올림 결과(Carry)
-> Shift 연산 => 자리 올림 결과를 다음 자릿수에서 사용하기 위해 한 자리 옮김
:::그 결과, Carry가 발생하지 않을 때까지 이 과정을 반복하면 된다.
*/

//1차 답안
// class Solution
// {
// public:
//     int getSum(int a, int b)
//     {
//         // bit operator?
//         // 비트는 11개, 맨 앞에 있는건 부호, 10개는 숫자(-1023 ~ 1023)
//         int bit_of_a[12];
//         int bit_of_b[12];
//         int result[12];
//         set_bit(a, bit_of_a);
//         set_bit(b, bit_of_b);
//         for (int i = 0; i < 12; ++i){
//             std::cout << bit_of_a[i];
//         }
//         std::cout << std::endl;
//         for (int i = 0; i < 12; ++i)
//         {
//             std::cout << bit_of_b[i];
//         }
//         std::cout << std::endl;
//         // 덧셈~
//         int up = 0;
//         for (int i = 11; i >= 0; --i)
//         {
//             int tmp_x = bit_of_a[i] ^ bit_of_b[i];
//             result[i] = tmp_x ^ up;
//             if(tmp_x & up || bit_of_a[i] & bit_of_b[i]){
//                 up = 1;
//             }
//             else{
//                 up = 0;
//             }
//         }
//         for (int i = 0; i < 12; ++i)
//         {
//             std::cout << result[i];
//         }
//         std::cout << std::endl;
//         //계산
//         int flag = 1;
//         if (result[0] == 1)
//         {
//             flag = -1;
//             for (int i = 0; i < 12; ++i)
//             {
//                 if(result[i] == 0)
//                     result[i] = 1;
//                 else
//                     result[i] = 0;
//             }
//             for (int i = 11; i >= 0; --i)
//             {
//                 if (result[i] == 0)
//                 {
//                     result[i] = 1;
//                     break;
//                 }
//                 else
//                 {
//                     result[i] = 0;
//                 }
//             }
//         }
//         int answer = 0;
//         for (int i = 11; i > 0; --i)
//         {
//             answer += (pow(2, 11 - i) * result[i]);
//         }
//         return answer * flag;
//     }

// private:
//     void set_bit(int x, int result[])
//     {
//         int abs_x = abs(x);
//         int tmp_v;
//         result[0] = 0;
//         for (int i = 1; i < 12; ++i)
//         {
//             // 여기 값 = 2 ^ (10-i)
//             tmp_v = pow(2, 11 - i);
//             if (abs_x >= tmp_v)
//             {
//                 result[i] = 1;
//                 abs_x -= tmp_v;
//             }
//             else
//             {
//                 result[i] = 0;
//             }
//         }
//         if (x >= 0)
//         {
//             return;
//         }
//         for (int i = 0; i < 12; ++i)
//         {
//             if (result[i] == 1)
//                 result[i] = 0;
//             else
//                 result[i] = 1;
//         }
//         // add 1
//         for (int i = 11; i >= 0; --i)
//         {
//             // up + 현재값이 1이라면 -> 현재값에 넣고 그만~
//             if (result[i] == 0)
//             {
//                 result[i] = 1;
//                 return;
//             }
//             // up + 현재값이 2이라면 -> 현재값에 0 넣고 up은 다시 1
//             else{
//                 result[i] = 0;
//             }
//         }
//     }
// };

// 2차 답안
class Solution
{
public:
    int getSum(int a, int b)
    {
        //ex: a = 3(011), b = 5(101)
        while (b != 0)
        {
            
            int carry = (a & b) << 1; // a&b = 001 , carry = 010
            a = a ^ b; // a^b = 110
            b = carry; // b = 010
        }
        return a;
    }
};