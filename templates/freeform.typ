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

#let Size = (
  "Big": 0, // title on its own page and outline on the new one
  "Medium": 1, // title and outline on one page
  "Small": 2, // embedded title
)

#let start(title, size: Size.Small) = {
  if size == Size.Big {
    v(5fr)
    start(title, size: Size.Small) // yes
    v(8fr)
    pagebreak()
    outline()
    pagebreak()
  } else if size == Size.Medium {
    v(5fr)
    start(title, size: Size.Small)
    v(8fr)
    outline()
    v(3fr)
    pagebreak()
  } else if size == Size.Small {
    align(center, title)
  } else {
    panic("invalid size")
  }
}
