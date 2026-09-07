// might want to make this generic for future math stuff but for now it's in linalg/0lec
// todo: combine kinds of math into one dir? idk

#let plot(
  labels,
  fns,
  xs: (-5, 5),
  ys: (-1, 9),
  trig: false,
  polar: false,
) = {
  import "@preview/cetz:0.5.2": canvas, draw
  import draw: *
  import "@preview/cetz-plot:0.1.4": plot

  canvas({
    plot.plot(
      size: (11, 11),
      axis-style: if polar { none } else { "school-book" },
      x-tick-step: if trig { calc.pi/2 } else { 1 },
      x-format: if trig { plot.formats.multiple-of } else { plot.formats.decimal },
      y-tick-step: 1, y-min: ys.at(0), y-max: ys.at(1),
      legend-style: (padding: .3,),
      {
        for (num, (fn, label)) in fns.zip(labels).enumerate() {
          let style = if calc.rem(num, 2) != 0 {(stroke: (dash: "dashed"))} else {(:)} // default
          plot.add(fn, domain: xs, label: label, samples: 333, style: style )
        }
      }
    )

    if polar {
      floating({
        // holy fucking shit
        // todo unhardcode
        let offset = (5.3, 6.6)
        let circles = 5

        for r in range(1, circles) {
          circle(offset, radius: r, stroke: (dash: "dotted"))
        }
        for angle in range(0, 360, step: 45) {
          let r = angle * calc.pi / 180
          line(offset, (offset.at(0) + circles * calc.cos(r), offset.at(1) + circles * calc.sin(r)), stroke: (dash: "dotted"))
        }
      })
    }
  })
}
