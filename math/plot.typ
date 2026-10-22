#import "@preview/cetz:0.5.2": canvas, draw
#import "@preview/cetz-plot:0.1.4": plot
#import draw: *

#let plot_fn(
  functions, // (("name", F,)
  xs: (-5, 5),
  ys: (-1, 9), // optional third arg for name
  x-tick-step: 1,
  y-tick-step: 1,
  trig: false,
  polar: false,
  log: false,
  size: (11, 11),
) = align(center, canvas({
  plot.plot(
    size: size,
    axis-style: if polar { none } else { "school-book" },
    x-tick-step: x-tick-step * if trig { calc.pi / 2 } else { 1 },
    x-format: if trig { plot.formats.multiple-of } else {
      plot.formats.decimal
    },
    y-tick-step: y-tick-step,
    x-label: xs.at(2, default: auto),
    y-label: ys.at(2, default: auto),
    y-min: ys.at(0),
    y-max: ys.at(1),
    y-mode: if log { "log" },
    legend-style: (padding: .3),
    {
      for (num, (label, fn)) in functions.enumerate() {
        let styles = (
          (stroke: (paint: black)),
          (stroke: (dash: "dashed", paint: black)),
          (stroke: (paint: gray)),
          (stroke: (dash: "dotted", paint: black)),
          (stroke: (dash: "dashed", paint: gray)),
          (stroke: (dash: "dotted", paint: gray)),
        )
        let style = styles.at(calc.rem(num, styles.len()))
        plot.add(fn, domain: xs, label: label, samples: 200, style: style)
      }
    },
  )

  if polar {
    floating({
      // holy fucking shit
      // todo unhardcode
      let offset = (5.3, 6.6)
      let circles = 7

      for r in range(1, circles) {
        circle(offset, radius: r, stroke: (dash: "dotted"))
      }
      for angle in range(0, 360, step: 45) {
        let r = angle * calc.pi / 180
        line(
          offset,
          (
            offset.at(0) + circles * calc.cos(r),
            offset.at(1) + circles * calc.sin(r),
          ),
          stroke: (dash: "dotted"),
        )
      }
    })
  }
}))

#let plot_pts(
  points, // (("name", (x, y)),)
  xs: (-8, 8),
  ys: (-8, 8),
  trig: false,
  offset: (0.02, 0.02),
) = align(center, canvas(
  plot.plot(
    size: (13, 13),
    axis-style: "school-book",
    x-tick-step: if trig { calc.pi / 2 } else { 1 },
    x-format: if trig { plot.formats.multiple-of } else {
      plot.formats.decimal
    },
    y-tick-step: 1,
    x-min: xs.at(0),
    x-max: xs.at(1),
    y-min: ys.at(0),
    y-max: ys.at(1),
    for (label, pt) in points {
      plot.add(
        (pt,),
        mark: "o", // holy goida
        mark-style: (fill: black, stroke: black),
        mark-size: 0.1,
      )

      plot.annotate(
        content(
          (
            pt.at(0) + xs.map(calc.abs).sum() * offset.at(0),
            pt.at(1) + ys.map(calc.abs).sum() * offset.at(1),
          ),
          label,
        ),
      )
    },
  ),
))
