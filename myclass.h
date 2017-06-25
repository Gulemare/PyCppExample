#ifndef PYCPPEXAMPLE_MYCLASS_H_
#define PYCPPEXAMPLE_MYCLASS_H_
#include <string>

class MyClass
{
public:
    MyClass();
    MyClass(int num, const std::string& name);
    void setName(const std::string str) {
        name_ = str;
        return;
    }
    const std::string& getName() const { return name_; }
    int getNum() const { return num_; }

private:
    std::string name_;
    int num_;
};

#endif // !PYCPPEXAMPLE_MYCLASS_H_