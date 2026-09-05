#{
  set page(
    paper: "a4",
    margin: (left: 30mm, right: 15mm, top: 20mm, bottom: 20mm),
    numbering: "1",
    number-align: center,
  )

  set text(
    font: "Liberation Serif",
    size: 14pt,
  )

  set par(
    leading: 0.8em,
    justify: true,
    first-line-indent: 1.25cm,
  )

  show heading: it => {
    set text(font: "Liberation Serif", weight: "bold", size: 14pt)
    block(above: 1.5em, below: 1em, it.body)
  }
}

Hello, world!

#image("assets/typst.png")
