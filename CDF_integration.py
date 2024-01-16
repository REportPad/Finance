import sympy as sy
from math import *
x = sy.symbols('x') # x를 변수로 사용함을 선언
f = sy.exp(-(x**2))

F = sy.integrate(f, x)
m = 68.01#8.75
s = 70.62#17.19
t = -m/(s*(2**0.5))
# x에 대하여 범위에서 정적분 값 계산
y=(F.subs(x, t) - F.subs(x, -100000)).evalf()
y = y/(pi**0.5)*100
print(y)
