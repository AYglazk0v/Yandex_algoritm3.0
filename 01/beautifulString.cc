#include <iostream>

int main()
{
    int k;
    std::cin >> k;
    
    std::string s;
    std::cin >> s;

    char alpha[] = "abcdefghijklmnopqrstuvwxyz";

    int max = 0;
    for (auto c : alpha) {
        int t = k, count = 0;
        for (size_t i = 0, j = 0; i <= s.size(); ++i){
			if (max < count) max = count;
			if (c == s[i]) {
				count++;
				continue;
			}
			else if (c != s[i]) {
				count++;
                t--;
            }
            while (t < 0){
                if (s[j] != c) {
                    t++;
                }
                j++;
                count--;
            }
			if (max < count) max = count;
        }
    }
    std::cout << max;
    return 0;
}
