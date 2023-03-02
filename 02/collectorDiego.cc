#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

int main() {
	int countStickers;
	std::cin >>countStickers;

	std::set<int> stickers;
	for (int tmp, i = 0; i < countStickers; ++i) {
		std::cin >> tmp;
		stickers.insert(tmp);
	}

	std::vector<int> optimiztion_time(stickers.begin(), stickers.end());

	int countCollectors;
	std::cin >> countCollectors;

	std::vector<int> minSticker;
	for (int i = 0, tmp; i < countCollectors ; ++i) {
		std::cin >> tmp;
		minSticker.push_back(tmp);
	}

	for (auto it = minSticker.begin(), ite = minSticker.end(); it != ite; ++it) {
		std::cout << std::distance(optimiztion_time.begin(), std::lower_bound(optimiztion_time.begin(), optimiztion_time.end(), *it)) << std::endl;
	}
	return 0;
}
