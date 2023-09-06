# **Prime, Divisor, and Euler Totient Function**

## 1. Prime Factorization
Every integer can be expressed as the product of its prime factors, and this representation is unique.

$$n = p_1^{a_1} * p_2^{a_2} * p_3^{a_3} * \ldots * p_n^{a_n}$$

```c++
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 2; i <= n / i; i++) {
        int s = 0;
        while (n % i == 0) {
            n /= i;
            s++;
        }
        cout << i << ' ' << s << endl;
    }
    if (n > 1)
        cout << n << ' ' << 1 << endl;
    return 0;
}
```
> In this code, $s$ represents the number of times the prime $i$ divides into $n$.

> If $n$ is greater than 1 at the end, then $n$ is also a prime factor of the original number $n$.

## Sieving Prime Numbers
### Sieve of Eratosthenes

```c++
void get_primes(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) // i is prime
            primes[cnt++] = i;
        for (int j = 0; j < n / i; j++) {
            st[primes[j] * i] = true;
            // primes[j] is the smallest prime factor of primes[j] * i 
            if (i % primes[j])
                break;
        }
    }
}
```
> Explanation:
> At this point, $primes[j]$ is definitely the smallest prime factor of $primes[j]*i$:
> The key point lies in the statement `if(i % primes[j]) break`. Let's consider that when `i` can be evenly divided by `primes[j]`, it implies that `i` can be expressed as $k*primes[j]$. So, if we don't `break` at this point, we will get `primes[j+1]` in the next loop. During this iteration, we mark $primes[j+1]*i$ as true. While this may be correct for the final result, it is not efficient enough. As previously mentioned, for the algorithm to run in linear time, we must mark each composite number with its smallest prime factor.

> However, when we mark $primes[j+1]*i$ as true using `primes[j+1]`, we will discover that $i=k*primes[j]$. Consequently, $primes[j+1]*i=primes[j]*i*k$. As a result, `primes[j]` is the exact smallest prime factor of `primes[j+1]*i`, and this is why we need to break out of the loop.
## euler totient function
对于正整数$n$,欧拉函数是指$1...n$中与$n$互质的数，记为：
$\phi(n)$
### How to calculate the $\phi(n)$
First ,euler totient function is a 积性函数，meaning that when m and n 互质,$\phi(mn)=\phi(m)*\phi(n)$. 

Therefore,as we konw that n can be only divide in one way to prime as:$n=p_1^{a_1}*p_2^{a_2}\dots{p_x^{a_x}}$.  
So $\phi(x)=\phi(p_1^{a_1})*\phi(p_2^{a_2})\dots*\phi(p_x^{a_x})$  
And we can find that $\phi(p_s^{a_s})=p_s^{a_s}-p_s^{(a_s-1)}$.  
Because $\phi(p_s)$
