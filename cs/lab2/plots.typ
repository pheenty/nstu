#import "/math/plot.typ": plot_fn

#let actual(x) = 1 / calc.sqrt(1 + x)
#let next_member(x, prev, n) = prev * (-x) * (2 * n - 1) / (2 * n)
#let partial_sum_at(x, n) = {
  let approx = 0
  let nth = 1
  for n in range(n + 1) {
    approx += nth
    nth = next_member(x, nth, n + 1)
  }
  approx
}
#let n_for(x, precision) = {
  let actual = actual(x)

  let approx = 0
  let n = 0
  let nth = 1
  while calc.abs(actual - approx) > precision {
    n += 1
    approx += nth
    nth = next_member(x, nth, n)
  }

  n
}

#let plot_difference(..ns) = {
  let fns = ns
    .pos()
    .map(n => ([Приближение, $n = #n$], x => partial_sum_at(x, n)))
  fns.push(($ 1 / sqrt(1 + x) $, actual))
  plot_fn(
    fns,
    xs: (0, 1),
    ys: (0.5, 1, $f(x)$),
    x-tick-step: 0.1,
    y-tick-step: 0.1,
  )
}

#let plot_n(..precisions) = plot_fn(
  precisions
    .pos()
    .map(precision => (
      [Точность #precision],
      x => n_for(x, precision),
    )),
  xs: (0.075, 0.925),
  ys: (1, 100, $n$),
  x-tick-step: 0.1,
  log: true,
)
