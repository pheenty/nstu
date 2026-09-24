#import "shared.typ": Size

#let format(body) = {
  set page(
    paper: "a4",
    margin: (left: 20mm, right: 20mm, top: 20mm, bottom: 25mm),
    numbering: (page, ..args) => {
      if page > 1 { page }
    },
    number-align: center,
  )

  set text(
    font: "New Computer Modern",
    size: 12pt,
    lang: "ru",
  )

  set par(justify: true)

  show heading: it => {
    set text(hyphenate: false)
    set align(center)

    block(
      above: 1em,
      below: 1em,
      it,
    )
  }

  body
}
