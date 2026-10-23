#include <iostream>

bool leap_year(int year){
    bool ly;
    if( (year % 4) == 0){ 

        if( (year % 100) == 0){ 

            if( (year % 400) == 0){
                ly = true;
            }
            else{
                ly = false;
            }

        }
        else{   
            ly = true;
        }
    }
    else{
        
        ly = false;
    }

    return ly;
}

void next_date(int d1, int m1, int y1, int& d2, int& m2, int& y2){
    if(d1 == 28 && !leap_year(y1) && m1 == 2){
        d2 = 1, m2 = m1 + 1, y2 = y1;    
    }
    else if(d1 == 29 && leap_year(y1) && m1 == 2){
        d2 = 1, m2 = m1 + 1, y2 = y1;
    }
    else if(d1 == 30 && (m1 == 4 || m1 == 6 || m1 == 9 || m1 == 11)){
        d2 = 1, m2 = m1 + 1, y2 = y1;
    }
    else if(d1 == 31 && m1 != 12){
        d2 = 1, m2 = m1 + 1, y2 = y1;
    }
    else if(d1 == 31 && m1 == 12){
        d2 = 1, m2 = 1, y2 = y1 + 1;
    }
    else{
        d2 = d1 + 1, m2 = m1, y2 = y1;
    }
}

int main(){
    int d1 = 29, m1 = 2, y1 = 2004, d2, m2, y2;
    next_date(d1, m1, y1, d2, m2, y2);
    std::cout << (d2 == 1 && m2 == 3 && y2 == 2004) << std::endl;

    d1 = 31, m1 = 1, y1 = 2004, d2, m2, y2;
    next_date(d1, m1, y1, d2, m2, y2);
    std::cout << (d2 == 1 && m2 == 2 && y2 == 2004) << std::endl;

    d1 = 28, m1 = 2, y1 = 2004, d2, m2, y2;
    next_date(d1, m1, y1, d2, m2, y2);
    std::cout << (d2 == 29 && m2 == 2 && y2 == 2004) << std::endl;

    d1 = 28, m1 = 2, y1 = 2003, d2, m2, y2;
    next_date(d1, m1, y1, d2, m2, y2);
    std::cout << (d2 == 1 && m2 == 3 && y2 == 2003) << std::endl;

    d1 = 30, m1 = 4, y1 = 2004, d2, m2, y2;
    next_date(d1, m1, y1, d2, m2, y2);
    std::cout << (d2 == 1 && m2 == 5 && y2 == 2004) << std::endl;

    d1 = 31, m1 = 12, y1 = 2004, d2, m2, y2;
    next_date(d1, m1, y1, d2, m2, y2);
    std::cout << (d2 == 1 && m2 == 1 && y2 == 2005) << std::endl;

    d1 = 23, m1 = 10, y1 = 2026, d2, m2, y2;
    next_date(d1, m1, y1, d2, m2, y2);
    std::cout << (d2 == 24 && m2 == 10 && y2 == 2026) << std::endl;

    return 0;
}