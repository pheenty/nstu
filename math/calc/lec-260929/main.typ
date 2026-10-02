#import "/templates/freeform.typ": format
#import "../../utils.typ": *

#show: format
#set align(center + horizon)

= Математический анализ
Лекция 29.09.2026

#v(1fr)
== Правила дифференцирования
#table(
  columns: 2,
  align: left,

  $ (f(x) + g(x)) prime = f prime(x) + g prime(x) $, [Производная суммы],

  $ (f(x) * g(x)) prime = f prime(x) * g(x) + f(x) * g prime(x) $,
  [Производная произведения],

  $ (f(x) / g(x)) prime = (f prime(x) * g(x) - f(x) * g prime(x)) / (g(x))^2 $,
  [Производная частного],

  $ (f(g(x))) prime = f prime(g(x)) * g prime(x) $, [Производная сложной],

  $ (f^(-1))prime(x) = 1 / (f prime(f^(-1)(x))) $, [Производная обратной],

  $ f(x) = cases(y = y(t), x = x(t)) => f prime(x) = (y prime) / (x prime) $,
  [Производная параметрической],
)

#v(1fr)
== Таблица простых производных
#table(
  columns: 2,
  align: horizon,

  $ C prime = 0 $, $ (x^alpha) prime = alpha x^(alpha - 1) $,
  $ (e^x) prime = e^x <=> (a^x) prime = a^x ln a $,
  $ (ln x) prime = 1 / x <=> (log_a x) prime = 1 / (x ln a) $,

  $ (sin x) prime = cos x $, $ (cos x) prime = - sin x $,
  $ (tg x) prime = 1 / (cos x)^2 $, $ (ctg x) prime = (-1) / (sin x)^2 $,
  $ (arcsin x) prime = 1 / sqrt(1 - x^2) $,
  $ (arccos x) prime = (-1) / sqrt(1 - x^2) $,

  $ (arctg x) prime = 1 / (1 + x^2) $, $ (arcctg x) prime = (-1) / (1 + x^2) $,
)

#v(2fr)
