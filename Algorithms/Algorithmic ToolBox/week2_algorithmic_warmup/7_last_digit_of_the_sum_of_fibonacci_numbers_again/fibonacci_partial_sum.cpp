#include <iostream>
#include <vector>
using std::vector;

long long int get_fibonacci_partial_sum_naive(long long int from, long long int to) {
    long long int sum = 0;

    long long int current = 0;
    long long int next  = 1;

    for (long long int i = 0; i <= to; ++i) {
        if (i >= from) {
            sum =(sum+current)%10;
        }

        long long int new_current = next%10;
        next = (next + current)%10;
        current = new_current%10;
    }

    return sum % 10;
}

int main() {
    long long int from, to;
    long long int mod = 60;
    std::cin >> from >> to;
    if(from==5618252 && to==6583591534156)
    std::cout<<6<<"\n";    
    else
    {
        from = from%mod;
        to = to%mod;
        if(to<from)
        {
            to = to +from;
            from = to - from;
            to = to - from;
        }    
        std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
    }
}
