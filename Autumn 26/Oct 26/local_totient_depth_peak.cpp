#include <iostream>
#include <vector>

int gcd(int a, int b){          //WIP
    int divisor, dividend, remainder;
    if(a > b){
        dividend = a;
        divisor = b;
    }
    else{
        dividend = b;
        divisor = a;
    }

    remainder = dividend % divisor;

    while(remainder > 0){
        dividend = divisor;
        divisor = remainder;
        remainder = dividend % divisor;
    }

    return divisor;
}

int euler_totient(int n){
    int out = 0;
    for(int i=1; i<n; i++){
        if(gcd(i, n) == 1){
            out++;
        }
    }
    return out;
}

int totient_sum(int n, int &depth){
    int sum = 0;
    depth = 0;
    while(n != 1){
        n = euler_totient(n);
        depth++;
        sum += n;
    }
    return sum;
}

int totient_depth_peak(int a, int b, int& dprev, int& dx, int& dpost){  //return x
    int xprev, x, xpost, x_out = -1, peakstrength, pstrenght_out = 0;

    for(int i=a+1; i<b; i++){
        xprev = i-1, x = i, xpost = i+1;
        totient_sum(xprev, dprev);
        totient_sum(x, dx);
        totient_sum(xpost, dpost);

        if(dx > dprev && dx > dpost){
            peakstrength = 2 * dx - (dprev + dpost);

            if(peakstrength > pstrenght_out){
                x_out = x;
                pstrenght_out = peakstrength;
            }
        }
    }

    if(x_out == -1){
        dprev = 0, dx = 0, dpost = 0;
        return x_out;
    }

    totient_sum(x_out - 1, dprev);
    totient_sum(x_out, dx);
    totient_sum(x_out + 1, dpost);
    return x_out;
}


struct TestCase {
    int a;
    int b;
    int expectedX;
    int expectedDprev;
    int expectedDx;
    int expectedDpost;
};

int main() {
    const std::vector<TestCase> tests = {
        {16, 18, 17, 4, 5, 3},
        {4, 6, 5, 2, 3, 2},
        {4, 24, 17, 4, 5, 3},
        {10, 14, 11, 3, 4, 3},
        {40, 55, 41, 5, 6, 4},
        {80, 90, 85, 5, 7, 5},
        {1, 5, -1, 0, 0, 0},
        {1, 2, -1, 0, 0, 0},
        {17, 18, -1, 0, 0, 0},
        {5, 7, -1, 0, 0, 0}
    };

    for (const TestCase& test : tests) {
        int dprev = -99;
        int dx = -99;
        int dpost = -99;

        int result = totient_depth_peak(
            test.a, test.b, dprev, dx, dpost
        );

        bool passed = result == test.expectedX &&
                      dprev == test.expectedDprev &&
                      dx == test.expectedDx &&
                      dpost == test.expectedDpost;

        std::cout << "a = " << test.a
                  << ", b = " << test.b
                  << ": " << (passed ? "PASS" : "FAIL")
                  << "\n  returned: x = " << result
                  << ", depths = (" << dprev << ", " << dx
                  << ", " << dpost << ")"
                  << "\n  expected: x = " << test.expectedX
                  << ", depths = (" << test.expectedDprev << ", "
                  << test.expectedDx << ", " << test.expectedDpost
                  << ")\n\n";
    }

    return 0;
}
