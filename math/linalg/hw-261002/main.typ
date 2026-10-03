#import "/templates/freeform.typ": *
#import "../../plot.typ": plot_pts
#import "../../math_utils.typ": *
#import "@preview/auto-div:0.1.0": poly-div

#show: format
#set grid(columns: (1fr, 1fr))

#normal_title[
  = Индивидуальное домашнее задание
  $ "Вариант" = 12 => k = 3; m = 1 $
]

+ Решить систему линейных уравнений методом Крамера:
  $
    cases(
      (2 + m i) x + (1 - i) y = 2 - m,
      (3 - k i) x + (m + i) y = 2m + k + 5i
    )
  $

  $
    cases(
      (2 + i) x + (1 - i) y = 1,
      (3 - 3i) x + (1 + i) y = 5 + 5i
    )
  $

  $
    Delta = det(
      2 + i, 1 - i;
      3 - 3i, 1 + i;
    ) = (2 + i)(1 + i) - (1 - i)(3 - 3i) = 1 + 9i
  $

  $
    Delta_x = det(
      1, 1 - i;
      5 + 5i, 1 + i;
    ) = 1(1 + i) - (1 - i)(5 + 5i) = -9 + i
  $

  $
    Delta_y = det(
      2 + i, 1;
      3 - 3i, 5 + 5i;
    ) = (2 + i)(5 + 5i) - (3 - 3i) = 2 + 18i
  $

  $ x = (-9 + i) / (1 + 9i) = i $
  $ y = (2 + 18i) / (1 + 9i) = 2 $


+ Изобразить комплексные числа на комплексной плоскости, найти их модули, аргументы, представить их в показательной и тригонометрической формах:
  $
    z_1 = (-1)^k * (m + 1) + (-1)^m * (m + 1)sqrt(3)i; \
    z_2 = (-1)^(m+1) * (k + 1)sqrt(3) + (-1)^(k+1) * (k + 1)i; \
    z_3 = (-1)^(k+1) * (7 - m) + (-1)^m * (7 - m)i.
  $

  $
    z_1 = -2 - 2sqrt(3)i; \
    z_2 = 4sqrt(3) + 4i; \
    z_3 = 6 - 6i.
  $

  #let zs = (
    (-2, -2 * calc.sqrt(3)),
    (4 * calc.sqrt(3), 4),
    (6, -6),
  )

  #let abses = ($4$, $8$, $6 sqrt(2)$)
  #let args = ($(4pi) / 3$, $pi / 6$, $(7pi) / 4$)

  #plot_pts(
    zs.enumerate().map(zi => ($z_#(zi.at(0) + 1)$, zi.at(1))),
  )

  $ #for i in range(zs.len()) [ $|z_#(i + 1)| = #abses.at(i)$ \ ] $
  $ #for i in range(zs.len()) [ $arg(z_#(i + 1)) = #args.at(i)$ \ ] $
  $
    #for i in range(zs.len()) {
      let abs = abses.at(i)
      let arg = args.at(i)
      $z_#(i + 1) = #trig(abs, arg) = #canon(abs, arg)$
      linebreak()
    }
  $

+ Найти и записать в показательной, тригонометрической и алгебраической формах числа:
  #grid(
    [а) $z_1^(7+k)$;],
    [б) $z_2^(12+m)$.],
  )
  #grid(
    [а) $z_1^10$;],
    [б) $z_2^13$.],
  )

  $
    z_1^10 = #canon($#abses.at(0)^10$, $#args.at(0)*10$) = #canon($2^20$, $5pi/3$) = #trig($2^20$, $5pi/3$) = 2^19 - 2^19sqrt(3)i
  $
  $
    z_2^13 = #canon($#abses.at(1)^13$, $#args.at(1)*13$) = #canon($2^53$, $pi/6$) = #trig($2^53$, $pi/6$) = 2^52sqrt(3) + 2^52i
  $

+ Изобразить корни на комплексной плоскости, записать их в алгебраической форме:
  #grid(
    [а) $cbrt((-1)^(m+1) k^3i)$;],
    [б) $root(6, (-1)^k * m^6)$.],
  )
  #grid(
    [а) $cbrt(9i)$;],
    [б) $root(6, -1)$.],
  )

  #{
    let roots = (
      $(cbrt(9) sqrt(3)) / 2 + cbrt(9) / 2 i$,
      $(- cbrt(9) sqrt(3)) / 2 + cbrt(9) / 2 i$,
      $cbrt(-9) i$,
    )
    $ cbrt(9i) = cases(..roots) $
    plot_pts(
      complex_roots(roots, calc.root(3, 9), 30deg),
      xs: (-3, 3),
      ys: (-3, 3),
      offset: (0.065, 0.015),
    )
  }

  #{
    let roots = (
      $sqrt(2)/2 + sqrt(2)/2 i$,
      $i$,
      $-sqrt(2)/2 + sqrt(2)/2 i$,
      $-sqrt(2)/2 - sqrt(2)/2 i$,
      $-i$,
      $sqrt(2)/2 - sqrt(2)/2 i$,
    )
    $ root(6, -1) = cases(..roots) $
    plot_pts(
      complex_roots(roots, 1, 30deg),
      xs: (-1.5, 1.5),
      ys: (-1.5, 1.5),
      offset: (0.02, 0.03),
    )
  }

+ Разложить многочлен над полем вещественных и комплексных чисел:
  #grid(
    [а) $x^3 + (m - k)x^2 + (7 - k m)x - 7k$;],
    [б) $x^4 + m^4$.],
  )
  #grid(
    [а) $x^3 - 2x^2 + 4x - 21$;],
    [б) $x^4 + 1$.],
  )

  $ x^3 - 2x^2 + 4x - 21 $
  Подберём корень. $x^3 - 2*3^2 + 4*3 - 21 = 27 - 18 + 12 - 21 = 0$.
  Делим на $(x - 3)$.
  #let division = poly-div((1, -2, 4, -21), (1, -3)) // we do a little trolling
  $ #division.working $
  Получившийся квадратный многочлен над вещественными числами не раскладывается ($D = -27$). Итоговое разложение:
  $ (#division.divisor)(#division.quotient) $
  Теперь переходим в числа комплексные. Решим $#division.quotient = 0$.
  #let (x1, x2) = ($(-1 + 3i sqrt(3)) / 2$, $(-1 - 3i sqrt(3)) / 2$)
  $
    x_1 = (-1 + sqrt(-27)) / 2 = #x1 \
    x_2 = (-1 - sqrt(-27)) / 2 = #x2
  $
  Следовательно, полное разложение:
  $ (#division.divisor)(x - #x1)(x - #x2) $

  $x^4 + 1$ над полем вещественных раскладываться должен на два нераскладываемых квадратных многочлена, но я не знаю, как.
  Над полем комплексных же имеем просто $x^4 = -1$ и следовательно разложение на:
  $
    #range(4).map(q => {
      let (x, y) = quarter_signs(q)
      $#if not x { $-$ } sqrt(2)/2 #if y { $+$ } else { $-$ } sqrt(2)/2i$
    }).map(x => $(x-(#x))$).sum()
  $
