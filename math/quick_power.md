# Quick Power
$a^b=a^{2^{x_1}}a^{2^{x_2}}\cdots a^{2^{x_n}} $  
Where $b=2^{x_1}+2^{x_2}+\dots+2^{x_n} $
As is known to us,if the binary form of b is 1101,$b=2^{0}+2^2+2^3 $.Therefore $a^b=a^{\left(2^{x_1}+2^{x_2}+\cdots +2^{x_n}\right)} $
```c++
long long res=1;
while(b)
{
    if(b&1)
    res*=a;
    a*=a;
    b>>=1;
}
```
