#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                ((long long)numbers[first]) * numbers[second]);
        }
    }

    return max_product;
}
long long MaxPairwiseProductFast(const std::vector<int>& numbers) {
    int max1 = 0, max2 = 0;
    for(int i=0;i<numbers.size();i++)
    {
        if(numbers[i] >= max1)
        {
            max2 = max1;
            max1 = numbers[i];

        }
        else
            max2 = max(max2,numbers[i]);
        //cout<<max1<<" "<<max2<<endl;
    }
    return ((long long)max1)*((long long)max2);
}
int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProductFast(numbers) << "\n";
    return 0;
}
