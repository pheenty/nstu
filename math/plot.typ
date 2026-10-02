#import "@preview/cetz:0.5.2": canvas, draw
#import "@preview/cetz-plot:0.1.4": plot
#import draw: *

#let plot_fn(
  // todo: rewrite for dicts
  labels,
  fns,
  xs: (-5, 5),
  ys: (-1, 9),
  trig: false,
  polar: false,
) = align(center, canvas({
  plot.plot(
    size: (11, 11),
    axis-style: if polar { none } else { "school-book" },
    x-tick-step: if trig { calc.pi / 2 } else { 1 },
    x-format: if trig { plot.formats.multiple-of } else {
      plot.formats.decimal
    },
    y-tick-step: 1,
    y-min: ys.at(0),
    y-max: ys.at(1),
    legend-style: (padding: .3),
    {
      for (num, (fn, label)) in fns.zip(labels).enumerate() {
        let style = if calc.rem(num, 2) != 0 {
          (stroke: (dash: "dashed"))
        } else { (:) } // default
        plot.add(fn, domain: xs, label: label, samples: 333, style: style)
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

#let plot_points(
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
