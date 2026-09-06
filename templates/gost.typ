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
    justify: true,
    first-line-indent: 1.25cm,
  )

  body
}
