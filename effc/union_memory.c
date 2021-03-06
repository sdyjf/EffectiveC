/*
union内部成员使用同一空间
赋新值会覆盖之前的值
*/

#include <stdio.h>

union{
    int i;
    double s;
}u;

int main(){
    u.s=45;                         //任意双精度数,其低位(1-32位)不出现1
    u.i=19990718;                   //32位整数

    printf("%.6lf\n%d\n",u.s,u.i);

    /*
    输出结果:
    45.000000
    19990718
    
    解释:
    45的双精度存储空间结构:
    0          1000 0000 100        01101 0000 ... 0000 0000 0000 0000 
    符号位(1)   指数位(11)            小数位(52)
    
    19990718的整数存储空间结构:
    0000 0001 0011 0001 0000 1000 1011 1110

    也就是其只会覆盖双精度45的低32位,而这对双精度浮点的影响较小(在打印精确度较小的情况),若改为%.7lf即可看出变化
    而当以整形解释打印变量时,只会取前32位,也就是其覆盖的部分
    */
    return 0;
}