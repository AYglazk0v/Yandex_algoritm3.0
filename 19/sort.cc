// Реализация пирамидальной сортировки на C++
#include <iostream>
#include <iterator>
#include <vector>

void heapify(std::vector<int>& v, int n, int i)
{
    int largest = i;   
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && v[l] > v[largest]) {
        largest = l;
    }
    if (r < n && v[r] > v[largest]){
        largest = r;
    }
    if (largest != i) {
        std::swap(v[i], v[largest]);
        heapify(v, n, largest);
    }
}

void heapSort(std::vector<int>& v)
{
    for (int i = (v.size() - 1) / 2; i >= 0; i--) {
        heapify(v, v.size(), i);
    }
    for (int i = v.size() - 1; i>=0; --i)
    {
        std::swap(v[0], v[i]);
        heapify(v, i, 0);
    }
}


int main()
{
    int n;
    std::cin >> n;
    std::vector<int> v;
    v.resize(n);
    for (int i=0,tmp; i != n; ++i) {
        std::cin >> tmp;
        v[i] = tmp;
    }
    heapSort(v);
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
}