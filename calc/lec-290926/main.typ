#import "/templates/freeform.typ": format
#import "/templates/title.typ": title

#show: format
#title[
  = Математический анализ
  Лекция 29.09.2026
]

#v(1em)

== Производные сложных функций
$
  (f(x) g(x)) prime = f prime(x) * g(x) + f(x) * g prime(x) \
  (f(x) / g(x)) prime = (f prime(x) * g(x) - f(x) * g prime(x)) / (g(x))^2 \
  (f(g(x))) prime = f prime(g(x)) * g prime(x) \
  f prime(x) = 1 / ((f^(-1))prime(x) * f(x)) \
  f(x) = cases(x = x(t), y = y(t)) => f prime(x) = cases(x = x prime(t), y = y prime(t))
$

== Таблица простых производных
$
  C prime = 0 \
  (x^alpha) prime = alpha x^(alpha - 1) \
  (e^x) prime = e^x <=> (a^x) prime = a^x ln a \
  (ln x) prime = 1 / x <=> (log_a x) prime = 1 / (x ln a) \
  (sin x) prime = cos x \
  (cos x) prime = - sin x \
  (tg x) prime = 1 / (cos x)^2 \
  (ctg x) prime = (-1) / (sin x)^2 \
  (arcsin x) prime = 1 / sqrt(1 - x^2) \
  (arccos x) prime = (-1) / sqrt(1 - x^2) \
  ("arctg" x) prime = 1 / (1 + x^2) \
  ("arcctg" x) prime = (-1) / (1 + x^2) \
$
