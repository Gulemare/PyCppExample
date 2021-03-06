#define BOOST_PYTHON_STATIC_LIB
#include <boost/python.hpp>
#include "myclass.h"
#include "myfunctions.h"
#include <string>
#include <list>
using namespace boost::python;

// Парсит лист Питона в вектор и использует функцию
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
int LSum(const list& li) {
    int sum = 0.0;
    int length = len(li);
    int i = 0;
    for (i = 0; i < length; ++i) {
        sum += extract<int>(li[i]);
    }
    return sum;
}

// Переброс исключений в Питон
void TranslateError(const std::exception& e) {
    std::stringstream s;
    s << "Oops! Error from C++ code: " << e.what();
    PyErr_SetString(PyExc_Exception, s.str().c_str());
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

// Глобальная переменная
static MyClassLib lib;

BOOST_PYTHON_MODULE(PyCppExample) 
{
    // Обертки функций
    def("Fun", Fun, args("n"), "fun's docstring");
    def("Strfun", Strfun, "strfun's docstring");
    def("VSum", VSum, args("list"));
    def("LSum", LSum, args("list"));
    def("GenerateExeption", GenerateExeption, args("n"));

    // Обертка класса
    class_<MyClass>("MyClass")
        // Конструктор по-умолчанию генерируется сам, другие надо указывать
        .def(init<int, std::string>(args("number", "name")))

        // Для функций, возвращающих ссылки или указатели необходимо явно указывать политику для Питона
        .def("getNum", &MyClass::getNum)
        .def("getName", &MyClass::getName, return_value_policy<copy_const_reference>())
        .def("__str__", MyClass_Str)
        .def("__repr__", MyClass_Repr)
        .add_property("name", make_function( static_cast<const std::string& (MyClass::*)() const>(&MyClass::getName),
            return_value_policy<copy_const_reference>()), &MyClass::setName)
        ;

    class_<MyClassLib>("MyClassLib")
        .def("update", &MyClassLib::updateObj)
        .def("get", &MyClassLib::getObject)
        ;

    scope().attr("lib") = lib;

    // Регистрация функции проброса исключений в Питон
    register_exception_translator<std::exception>(TranslateError);
}
