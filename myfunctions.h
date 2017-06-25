#ifndef PYCPPEXAMPLE_MYFUNCTIONS_H_
#define PYCPPEXAMPLE_MYFUNCTIONS_H_
#include <string>
#include <vector>

int Fun(int n) {
    int res = 0;
    for (int i = 0; i < 1000000; ++i) {
        res += n;
    }
    return res;
}

std::string Strfun() {
    return std::string("StringFun");
}

double VectorSum(const std::vector<double>& v) {
    double res = 0.0;
    for (const auto& i : v) {
        res += i;
    }
    return res;
}

void GenerateExeption(int n) {
    throw std::exception(std::to_string(n).c_str());
}

#endif // !PYCPPEXAMPLE_MYFUNCTIONS_H_