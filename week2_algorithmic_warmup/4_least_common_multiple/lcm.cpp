#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long gcd_fast(int a, int b) {
    if(a==0)    return b;
    if(b==0)    return a;

    if(a>b)
        return gcd_fast(b,a%b);
    return gcd_fast(a,b%a);
}

long long lcm_fast(int a, int b) {
    long long ans = ((long long)a * (long long)b) / (long long)gcd_fast(a,b);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  //std::cout << lcm_naive(a, b) << std::endl;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
