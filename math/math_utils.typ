#let lb = math.op("lb")
#let rest = math.op("rest")
#let arctg = math.op("arctg")
#let arcctg = math.op("arcctg")
#let cbrt(x) = math.root($3$, x)

#let abs(xs) = {
  let sum = xs.map(x => calc.pow(x, 2)).sum()
  let approx = calc.sqrt(sum)

  let factor = 10000
  calc.round(approx * factor) / factor
}

#let det(..args) = math.mat(delim: "|", ..args)

#let trig(abs, arg) = $#abs (cos #arg + i sin #arg)$
#let canon(abs, arg) = $#abs e^(i #arg)$

#let complex_roots(labels, abs, first_arg) = {
  let step = 360deg / labels.len()
  labels
    .enumerate()
    .map(il => {
      let (i, label) = il
      let arg = first_arg + i * step
      let point = (calc.cos(arg), calc.sin(arg)).map(dir => dir * abs)
      (label, point)
    })
}

#let quarter_signs(quarter) = {
  let angle = 45deg + quarter * 90deg
  (calc.cos(angle), calc.sin(angle)).map(t => t > 0)
}
