#include <iostream>
#include <vector>

void insert(std::vector<int>& v) {
    int idx = v.size() - 1;
    while (idx > 0) {
        if (v[idx] > v[(idx - 1) / 2]) {
            std::swap(v[idx],v[(idx - 1) / 2]);
            --idx;
            idx/=2;
        } else {
            break;
        }
    }
}

void extract(std::vector<int>& v) {
    std::cout << v[0] << "\n";
    v[0] = v[v.size() - 1];
    int idx = 0;
    while (idx < v.size()) {
        if (idx * 2 + 2 < v.size()) {
            if (v[idx] >= std::max(v[idx * 2 + 1], v[idx * 2 + 2])) {
                break;
            }
            if (v[idx * 2 + 1] < v[idx * 2 + 2]) {
                std::swap(v[idx * 2 + 2], v[idx]);
                idx = idx * 2 + 2;
            } else {
                std::swap(v[idx * 2 + 1], v[idx]);
                idx = idx * 2 + 1;
            }
        } else {
            break;
        }
    }
    v.pop_back();
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> v;
    for (int i = 0, tmp; i!=n; ++i) {
        std::cin >> tmp;
        if (int val; tmp == 0) {
            std::cin >> val;
            v.push_back(val);
            insert(v);
        } else {
            extract(v);
        }
    }
    return 0;
}