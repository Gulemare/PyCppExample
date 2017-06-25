#include <boost/python.hpp>
#include "myclass.h"
using namespace boost::python;

int fun(int n) {
    for (int i = 0; i < 1000000000; ++i) {
        n++;
    }
    return n;
}

BOOST_PYTHON_MODULE(PyCppExample) 
{
    // Обертка функции
    def("fun", fun, args("n"), "fun's docstring");

    // Обертка класса
    class_<MyClass>("MyClass")
        .add_property("num", make_getter(&MyClass::num_), make_setter(&MyClass::num_))
        ;
    
}
