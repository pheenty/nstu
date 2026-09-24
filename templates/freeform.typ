#let format(body) = {
  set page(
    paper: "a4",
    margin: (top: 20mm, outside: 15mm, rest: 25mm),
    footer: context {
      // "book" numbering
      let real_page = here().page()
      let outside = if calc.even(real_page) { left } else { right } // why is it not built in
      if real_page > 1 { align(outside)[#counter(page).get().first()] }
    },
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
