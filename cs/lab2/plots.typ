#import "/math/plot.typ": plot_fn

#let actual(x) = 1 / calc.sqrt(1 + x)
#let next_member(x, prev, n) = prev * (-x) * (2 * n - 1) / (2 * n)
#let partial_sum_at(x, max_n) = {
  let approx = 0
  let nth = 1
  let n = 1
  for n in range(max_n + 1) {
    approx += nth
    nth = next_member(x, nth, n + 1)
  }
  approx
}
#let n_for(x, precision) = {
  let actual = actual(x)
  let approx = 0
  let nth = 1
  let n = 1
  while calc.abs(actual - approx) > precision {
    approx += nth
    nth = next_member(x, nth, n)
    n += 1
  }
}

#let plot_difference(n) = plot_fn(
  (
    ($ 1 / sqrt(1 + x) $, actual),
    ([Приближение $n = #n$], x => partial_sum_at(x, n)),
  ),
  xs: (0, 1),
  ys: (0, 1),
)

#let plot_n(precision) = plot_fn(
  (
    ([$n$, требуемое для точности #precision], x => n_for(x, precision)),
  ),
  xs: (0, 1),
  ys: (1, 100),
)
