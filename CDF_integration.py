import sympy as sy
from math import *
x = sy.symbols('x') # x를 변수로 사용함을 선언
f = sy.exp(-(x**2))

F = sy.integrate(f, x)
m = 0#5.504
s = 1#25.467
p = 0.67449
t1 = (p-m)/(s*(2**0.5))
t2 = (-p-m)/(s*(2**0.5))
# x에 대하여 범위에서 정적분 값 계산
y=(F.subs(x, t1) - F.subs(x, t2)).evalf()
y = y/(pi**0.5)*100 #[%]
print(y)
