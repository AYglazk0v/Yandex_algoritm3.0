#include <cstdlib>
#include <iostream>
#include <iomanip>

struct Data {
    int hh_ = 0;
    int mm_ = 0;
    int ss_ = 0;

    void print() {
        std::cout << std::setfill('0') << std::setw(2) << hh_
            << ":" << std::setw(2) << mm_ << ":" << std::setw(2) << ss_;
    }

    Data(int hh, int mm, int ss) : hh_(hh), mm_(mm), ss_(ss) {};

    Data(const std::string& s) {
        hh_ = std::atoi(&*s.begin()); 
        mm_ = std::atoi(&*s.begin()+3);
        ss_ = std::atoi(&*s.begin()+6);
    }

    ~Data(){};
    
    Data operator-(const Data& rhs) const{
        int t_hh = hh_ - rhs.hh_;
        int t_mm = mm_ - rhs.mm_;
        int t_ss = ss_ - rhs.ss_;
        if (t_ss < 0) {
            t_ss+=60;
            t_mm--;
        }
        if (t_mm < 0) {
            t_mm+=60;
            t_hh--;
        }
        if (t_hh < 0) {
            t_hh+=24;
        }
        return Data{t_hh,t_mm, t_ss};
    }

    Data operator/(int dev) {
        int time = hh_*60*60 + mm_ * 60 + ss_;
        if (time % 2 != 0) {
            time++;
        }
        time /= 2;
        hh_ = time / 3600 ;
        time -= hh_ * 3600;
        mm_ = time / 60;
        time -= mm_ * 60;
        ss_ = time;
        return *this;
    }

    Data operator+(const Data& rhs) {
        ss_ += rhs.ss_;
        if (ss_ > 59) {
            mm_ += ss_/60;
            ss_ %= 60;
        }
        
        mm_ += rhs.mm_;
        if (mm_ > 59) {
            hh_ += mm_/60;
            mm_%=60;
        }
        hh_ = (hh_ + rhs.hh_) % 24;
        return *this;
    }
};

int main() {

    std::string A,B,C;
    std::cin >> A >> B >> C;

    Data A_d{A};
    Data B_d{B};
    Data C_d{C};

    Data tmp = C_d - A_d;
    tmp = tmp / 2;
    tmp = tmp + B_d;
    tmp.print();
    return 0;
}