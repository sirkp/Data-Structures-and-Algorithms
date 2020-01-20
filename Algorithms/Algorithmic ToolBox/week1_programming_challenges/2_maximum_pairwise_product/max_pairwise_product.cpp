#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long int MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long int max_product = 0;
    int n = numbers.size();

    int max_1 = -1,max_2 = -1;
    for(int i=0;i<n;i++)
    {
        // cout<<numbers[i]<<" "<<max_1<<"--";
        if(numbers[i] > max_1)
        {
            // cout<<"inside max1";
            max_2 = max_1;
            max_1 = numbers[i];
            // cout<<" max_1 "<<max_1<<endl;
        }
        else if(numbers[i] > max_2)
        {
            max_2 = numbers[i];    
            // cout<<"inside max2 max_2 "<<max_2<<endl;
        }
    }

    // cout<<max_1<<" "<<max_2<<endl;
    max_product =(long long int) max_1 * max_2;
    // cout<<max_product<<endl;
    return max_product;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers)<< "\n";
    return 0;
}
