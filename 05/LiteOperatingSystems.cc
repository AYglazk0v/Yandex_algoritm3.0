#include <iostream>
#include <set>
#include <utility>

int main() {
    int M;
    std::cin >> M;

    int N;
    std::cin >> N;

    std::set<std::pair<int, int>> v;
    std::pair<int, int> remove {-1,-1};
    for (int i = 0, tmp_s, tmp_e; i != N; ++i) {
        std::cin >> tmp_s >> tmp_e;
        if (v.empty()) {
            v.insert({tmp_s, tmp_e});
        } else {
            for (auto it = v.begin(); it != v.end(); ++it) {
                if (remove.first != -1) {
                    v.erase(remove);
                    remove = {-1,-1};
                }
                if (((((*it).first <= tmp_s && tmp_s <= (*it).second)) 
                    || ((*it).first <= tmp_e && tmp_s <= (*it).second))
                        || ((tmp_s <= (*it).first && (*it).first <= tmp_e) || ((tmp_s <= (*it).second && (*it).second <= tmp_e)))) {
                    remove=*it;
                    if (v.size() == 0) {
                        break;
                    }
                }
            }
            if (remove.first != -1) {
                v.erase(remove);
                remove = {-1,-1};
            }
            v.insert({tmp_s, tmp_e});
        }
    }
    std::cout << v.size();
    return 0;
}