// 4 and 5 excersize
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

template <typename T>
int reduce(T ar[], int n);

int main()
{
    long myints[] = { 10,20,20,20,30,30,20,20,10 };
    std::cout << reduce(myints, 9) << std::endl;
}

template <typename T>
int reduce(T ar[], int n)
{
    std::vector<T> tmp_ar(n);
    std::copy(ar, ar + n, tmp_ar.begin());
    std::sort(tmp_ar.begin(), tmp_ar.end());
    auto it = std::unique(tmp_ar.begin(), tmp_ar.end());
    tmp_ar.resize(std::distance(tmp_ar.begin(), it));
    
    return tmp_ar.size();
}