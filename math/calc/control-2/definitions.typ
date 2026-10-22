#import "../../math_utils.typ": *

#let equivalents = [
  = Эквивалентности
  $
    x -> 0 => & x ~ sin x ~ tan x ~ \
              & arcsin x ~ arctan x ~ \
              & e^x - 1 ~ ln(1+x) \
    x -> 0 => & 1-cos x ~ x^2/2 \
    x -> 0 => & (1+x)^alpha - 1 ~ alpha x
  $
]

#let discontinuities = [
  = Разрывы
  $
    crossmark_0 & <=> exists L: lim_(x->x_0) f = L != f(x_0) \
    crossmark_1 & <=> lim_(x->x_0^-) f != lim_(x->x_0^+) f \
    crossmark_2 & <=> exists.not lim_(x->x_0) f
  $
]

#let derivatives = [
  = Производные
  $
    (product_(i) f_i)' = sum_(j) f'_j product_(i != j) f_i \
    (f/g)' = (f' g - f g')/g^2 \
    (f(g(x)))' = f'(g(x)) dot g'(x ) \
    (f^(-1))'(f(x)) = 1/(f'(x)) \
    (f^g)' = f^g (g' ln f + g f'/f) \
    (cases(x=x(t), y=y(t)))' = y'/x'
  $
]

#let taylor = [
  = Формула Тейлора
  $
    f(x) = sum_(k=0)^n (f^((k))(x_0))/(k!) (x-x_0)^k + R_n (x) \
    e^x = sum_(k=0)^n x^k/(k!) + o(x^n) \
    sin x = sum_(k=0)^n (-1)^k x^(2k+1)/((2k+1)!) + o(x^(2n+1)) \
    cos x = sum_(k=0)^n (-1)^k x^(2k)/((2k)!) + o(x^(2n)) \
    (1+x)^alpha = sum_(k=0)^n (alpha! x^k)/((alpha-k)! k!) + o(x^n)
  $
]

#let limits = [
  = Пределы
  $
    lim f/g = [0/0] or [oo/oo] => lim f/g = lim (f')/(g') \
    f -> 0 and g -> oo => lim (1 + f)^g = e^(f g)
  $
]

#let tangent = [
  = Касательная
  $ dash(inter) y = f(x_0) + f'(x_0)(x - x_0) $
]

#let differential = [
  = Дифференциал
  $ dif^n f = f^((n))(x) (dif x)^n $
]

#let asymptotes = [
  = Асимптоты
  $
          x = a : & lim_(x->a) f = oo \
    y = k x + b : & lim_(x-> oo) cases(k = f/x, b = f - k x)
  $
]

#let extrema = [
  = Экстремумы и перегибы
  $
    f' > 0 => f arrow.tr, f' < 0 => f arrow.br; f'' > 0 => f union, f'' < 0 => f inter \
    x_0 min/max => f'(x_0) = 0 or exists.not f'(x_0); x_0 angzarr => f''(x_0) = 0 or exists.not f''(x_0) \
    f': -+ -> +- => x_0 min/max; f'': -+ -> +- => x_0 angzarr \
    f^((n))(x_0) != 0, forall k < n: f^((k))(x_0) = 0 => rest(n, 2) =
    cases(
      0 => min/max,
      1 => angzarr,
    )
  $
]

#let exploration = [
  = Исследование функции
  $
    1: & D(f), E(f)? \
    2: & +-f, T, f(0), 0 \
    3: & lim, x = a \
    4: & f(oo), y = b \
    5: & f' \
    6: & f'' \
    7: & k x + b \
    8: & x y arrow.r.wave \
  $
]
