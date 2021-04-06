#include <iostream>
using namespace std;

/*如 a^b  b>100000;
 a ^ b =( (a ^2) ^ (b/ 2) ) * a ^ (b % 2) = （a ^ (b/2)）^ 2 * a ^ (b % 2)
= ( a ^ (b/2) * a ^ (b /2) ） * a ^ (b % 2) … 接着不断的分治
例：
*/
//递归
/*
int fun2(int a, int b)//4 8->fu2(4,4)^2->fun2(4,2)^2^2
{
    int t;
    if (b == 1)//递归结束
        return a;

   if (b % 2 == 0)
   {
       t = fun2 (a, b / 2);
       return t * t;
   }
   else 
   {
    t = fun2 (a, b / 2);
    return t * t * a;
   }
}
//迭代
    int a, b;
    a = 7; b = 9;
    int res = 1;
    while (b > 0)
    {
        if (b % 2 == 1) res = res * a;
        a = a * a;
        b = b / 2;
    }
    4*3 a=4 b=3
    if(b%2==1)res=res+a;
    a=a*2;
    b=b/2;

   

*/
int main()
{
    
    cout << 0%1;
}