#ifndef PYCPPEXAMPLE_MYFUNCTIONS_H_
#define PYCPPEXAMPLE_MYFUNCTIONS_H_
#include <string>
#include <vector>

int fun(int n) {
    for (int i = 0; i < 1000000000; ++i) {
        n++;
    }
    return n;
}

std::string strfun() {
    return std::string("StringFun");
}

double VectorSum(const std::vector<double>& v) {
    double res = 0.0;
    for (const auto& i : v) {
        res += i;
    }
    return res;
}

#endif // !PYCPPEXAMPLE_MYFUNCTIONS_H_