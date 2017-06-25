#include <boost/python.hpp>
#include "myclass.h"
#include "myfunctions.h"
#include <string>
#include <list>
using namespace boost::python;

// Парсит лист Питона в вектор и использует функцию из библиотеки 
// для суммирования элементов вектора (просто для демонстрации)
double VSum(const list& li) {
    std::vector<double> v;
    for (int i = 0; i < len(li); ++i) {
        v.push_back(extract<double>(li[i]));
    }
    return VectorSum(v);
}

// Аналог функции sum из Питона для листа значений
float LSum(const list& li) {
    float sum = 0.0;
    int length = len(li);
    int i = 0;
    for (i = 0; i < length; ++i) {
        sum += extract<float>(li[i]);
    }
    return sum;
}

// Методы класса-обертки для представления в Питоне
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
    def("VSum", VSum, args("list"));
    def("LSum", LSum, args("list"));

    // Обертка класса
    class_<MyClass>("MyClass")
        .def(init<int, std::string>(args("number","name")))
        .def("getNum",&MyClass::getNum)
        .def("getName",&MyClass::getName, return_value_policy<copy_const_reference>())
        .def("__str__", MyClass_Str)
        .def("__repr__", MyClass_Repr)
        ;
    
}
