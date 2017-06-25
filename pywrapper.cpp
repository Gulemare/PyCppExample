#include <boost/python.hpp>
#include "myclass.h"
#include "myfunctions.h"
#include <string>
using namespace boost::python;

// Методы класса-обертки для удобства использования в Питоне
const std::string MyClass_Str(const MyClass& obj) {
    std::stringstream output;
    output << "{ Name: " << obj.getName() << ", Number: " << obj.getNum() << " }";
    return output.str();
}
const std::string MyClass_Repr(const MyClass& obj) {
    return "MyClass" + MyClass_Str(obj);
}

BOOST_PYTHON_MODULE(PyCppExample) 
{
    // Обертка функции
    def("fun", fun, args("n"), "fun's docstring");
    def("strfun", strfun, "strfun's docstring");

    // Обертка класса
    class_<MyClass>("MyClass")
        .def(init<int, std::string>(args("number","name")))
        .def("getNum",&MyClass::getNum)
        .def("getName",&MyClass::getName, return_value_policy<copy_const_reference>())
        .def("__str__", MyClass_Str)
        .def("__repr__", MyClass_Repr)
        ;
    
}
