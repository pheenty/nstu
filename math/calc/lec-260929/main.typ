#import "/templates/default.typ": *
#import "../../math_utils.typ": *

#show: format
#set align(center + horizon)

#init[
  = Техника дифференцирования
  Математический анализ, 29.09.2026
]
#v(2fr)

= Правила дифференцирования
#table(
  columns: 2,
  align: left,

  $ (f(x) + g(x))' = f'(x) + g'(x) $, [Производная суммы],

  $ (f(x) * g(x))' = f'(x) * g(x) + f(x) * g'(x) $, [Производная произведения],

  $ (f(x) / g(x))' = (f'(x) * g(x) - f(x) * g'(x)) / (g(x))^2 $,
  [Производная частного],

  $ (f(g(x)))' = f'(g(x)) * g'(x) $, [Производная сложной],

  $ (f^(-1))'(x) = 1 / (f'(f^(-1)(x))) $, [Производная обратной],

  $ f(x) = cases(y = y(t), x = x(t)) => f'(x) = (y') / (x') $,
  [Производная параметрической],
)

#v(1fr)
= Таблица простых производных
#table(
  columns: 2,
  align: horizon,

  $ C' = 0 $, $ (x^alpha)' = alpha x^(alpha - 1) $,
  $ (e^x)' = e^x <=> (a^x)' = a^x ln a $,
  $ (ln x)' = 1 / x <=> (log_a x)' = 1 / (x ln a) $,

  $ (sin x)' = cos x $, $ (cos x)' = - sin x $,
  $ (tg x)' = 1 / (cos x)^2 $, $ (ctg x)' = (-1) / (sin x)^2 $,
  $ (arcsin x)' = 1 / sqrt(1 - x^2) $, $ (arccos x)' = (-1) / sqrt(1 - x^2) $,

  $ (arctg x)' = 1 / (1 + x^2) $, $ (arcctg x)' = (-1) / (1 + x^2) $,
)

#v(2fr)
