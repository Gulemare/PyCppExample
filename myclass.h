#ifndef PYCPPEXAMPLE_MYCLASS_H_
#define PYCPPEXAMPLE_MYCLASS_H_
#include <string>
#include <map>

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

class MyClassLib {
    std::map<int, MyClass> lib_;

public:
    void updateObj(int id, const MyClass& c) {
        auto it = lib_.find(id);
        if (it == lib_.end()) {
            lib_.insert(std::pair<int, MyClass>(id, c));
        }
        else {
            (*it).second = c;
        }
    }
    MyClass getObject(int id) {
        return lib_.at(id);
    }
};

#endif // !PYCPPEXAMPLE_MYCLASS_H_