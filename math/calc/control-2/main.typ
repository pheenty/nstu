#import "definitions.typ": *
#import "../../math_utils.typ": *

#show: shorthands
#show heading: []
#set text(size: 8pt)
#set align(center + horizon)
#set page(margin: (rest: 12mm))

#let thing(..which) = (
  range(5)
    .map(_ => grid(columns: (
        1fr,
        1fr,
        1fr,
      ), stroke: 0.5pt, inset: 0.5em, ..which))
    .join(v(1fr))
)

#thing(
  (equivalents + discontinuities),
  derivatives,
  taylor,
)

#thing(
  limits,
  (tangent + differential),
  asymptotes,
  grid.cell(colspan: 2, extrema),
  exploration,
)
