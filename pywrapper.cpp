#define BOOST_PYTHON_STATIC_LIB
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
    int length = len(li);
    v.reserve(length);
    for (int i = 0; i < length; ++i) {
        v.push_back(extract<double>(li[i]));
    }
    return VectorSum(v);
}

// Аналог функции sum из Питона для листа значений
// Работает дольше из-за необходимости экспорта значений
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
    // Обертки функций
    def("fun", Fun, args("n"), "fun's docstring");
    def("strfun", Strfun, "strfun's docstring");
    def("VSum", VSum, args("list"));
    def("LSum", LSum, args("list"));
    def("GenerateExeption", GenerateExeption, args("n"));

    // Обертка класса
    class_<MyClass>("MyClass")
        .def(init<int, std::string>(args("number","name")))
        // Для функций, возвращающих ссылки или указатели - необходимо явно указывать политику что делать Питону
        .def("getNum",&MyClass::getNum)
        .def("getName",&MyClass::getName, return_value_policy<copy_const_reference>())
        .def("__str__", MyClass_Str)
        .def("__repr__", MyClass_Repr)
        ;
}
