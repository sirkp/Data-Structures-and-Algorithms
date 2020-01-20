#include <iostream>
int fibonacci_sum_naive(long long int n) {
    if (n <= 1)
        return n;

    long long int previous = 0;
    long long int current  = 1;
    long long int sum      = 1;

    for (long long int i = 0; i < n - 1; ++i) {
        long long int tmp_previous = previous%10;
        previous = current%10;
        current = (tmp_previous + current)%10;
        sum =(sum + current)%10;
    }
    return sum % 10;
}

int main() {
    long long int n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_naive(n%60);
}
