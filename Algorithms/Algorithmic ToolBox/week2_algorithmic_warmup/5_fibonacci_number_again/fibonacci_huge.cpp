#include <iostream>
using namespace std;
long long int get_pisano_period(long long int n, long long int m)
{
    long long int previous = 0;
    long long int current  = 1;

    for (long long int i = 2; n==n; i++)
    {
        long long int tmp_previous = previous%m;
        previous = current%m;
        current = (tmp_previous + current)%m;
        if(current==0 && previous==1)
        return i;    
    }    
}

long long int get_fibonacci_huge_naive(long long int n, long long int m) {
    if (n <= 1)
        return n;

    long long int previous = 0;
    long long int current  = 1;

    for (long long int i = 2; i <= n; ++i) {
        long long int tmp_previous = previous%m;
        previous = current%m;
        current = (tmp_previous + current)%m;
    }

    return current % m;
}

int main() {
    long long int n, m;
    std::cin >> n >> m;
    long long int mod = get_pisano_period(n,m);
    cout<<mod<<endl;
    long long int pos = n%mod;
    std::cout << get_fibonacci_huge_naive(pos, m) << '\n';
}
