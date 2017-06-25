#ifndef PYCPPEXAMPLE_MYFUNCTIONS_H_
#define PYCPPEXAMPLE_MYFUNCTIONS_H_
#include <string>

int fun(int n) {
    for (int i = 0; i < 1000000000; ++i) {
        n++;
    }
    return n;
}

std::string strfun() {
    return std::string("StringFun");
}

#endif // !PYCPPEXAMPLE_MYFUNCTIONS_H_