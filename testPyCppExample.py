
import timeit
from PyCppExample import *

def pymlnsum(n):
    res = 0
    i = 0
    while i < 1000000:
        res += n
        i += 1
    return res

# 1 million Python adds
t = timeit.default_timer()
a = pymlnsum(1)
print(timeit.default_timer() - t)

# 1 million C++ adds
t = timeit.default_timer()
b = Fun(1)
print(timeit.default_timer() - t)

print(Strfun());
print(MyClass());

b = MyClass(10,'Ten');
print(str(b));
print(repr(b));

print(b.getName());
pra = b.getNum();
print(b.getNum());


l = range(1000000);
# sum of Python list on Python
t = timeit.default_timer()
a = sum(l)
print(timeit.default_timer() - t)

# sum of Python list on C++
t = timeit.default_timer()
b = LSum(l)
print(timeit.default_timer() - t)

# sum of Python list converted to std::vector on C++
t = timeit.default_timer()
c = VSum(l)
print(timeit.default_timer() - t)

# handling exceptions
try:
    GenerateExeption(11)
except BaseException as e:
    print("Exception from C++ catched!" )
    print(e)




