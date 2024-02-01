#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> Lotto(int a, int b);

int main()
{
    std::vector<int> res = Lotto(15, 6);
    for (int i = 0; i < res.size(); ++i)
        std::cout << res[i] << std::endl;
}

std::vector<int> Lotto(int a, int b)
{
    srand(time(0));
    std::vector<int> all;
    for (int i = 1; i <= a; ++i)
        all.push_back(i);

    std::random_shuffle(all.begin(), all.end());
    return std::vector<int>(all.begin(), all.begin() + 6);
}