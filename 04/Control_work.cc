#include <iostream>

int main(){
    int count_people;
    std::cin >> count_people;

    int count_var;
    std::cin >> count_var;

    int desk;
    std::cin >> desk;

    int position;
    std::cin >> position;

    int var = desk * 2 - position % 2;

    if (var <= count_var && (var + count_var > count_people)) {
        std::cout << -1;
    } else {
        int pos1 = var + count_var;
        int pos2 = var - count_var;
        if (pos2 > 0) {
            if (pos1 <= count_people && ((pos1 + 1) / 2) - (var+1)/2 <= (var+1)/2 - ((pos2 + 1) / 2)) {
                std::cout << (pos1 + 1) / 2 << " " << (pos1 % 2 == 0 ? 2 : 1);
            } else {
                std::cout << (pos2 + 1) / 2 << " " << (pos2 % 2 == 0 ? 2 : 1);
            } 
        } else {
            std::cout << (pos1 + 1) / 2 << " " << (pos1 % 2 == 0 ? 2 : 1);
        }
    }
    return 0;
}