#include "myclass.h"

MyClass::MyClass() : num_(0), name_("default")
{
}

MyClass::MyClass(int num, const std::string& name) : num_(num), name_(name)
{
}
