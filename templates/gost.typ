#let format(body) = {
  set page(
    paper: "a4",
    margin: (left: 30mm, right: 15mm, top: 20mm, bottom: 20mm),
    numbering: (..args) => { let page = args.at(0); if page > 1 { page } },
    number-align: center,
  )

  set text(
    font: "Liberation Serif",
    size: 14pt,
    lang: "ru"
  )

  set par(
    leading: 0.75em,
    spacing: 0.75em,
    justify: true,
    first-line-indent: (amount: 1.25cm, all: true),
  )

  set heading(numbering: "1.1.")
  show heading: it => {
    set text(weight: "bold", size: 14pt, hyphenate: false)
    set align(center)

    let unnumbered = ("Введение", "Заключение")
    let it = if unnumbered.contains(it.body.at("text", default: none) ) {
      counter(heading).update(n => n - 1) // roll the heading number back
      it.body
    } else {
      it
    }

    block(
      above: 1.5em,
      below: 1.5em,
      it
    )
  }

  body
}
