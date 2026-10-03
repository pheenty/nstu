#let outside(page) = if calc.even(page) { left } else { right } // why is it not built in

#let format(body, author: [Лукин Фёдор, АИ-62]) = {
  set page(
    paper: "a4",
    margin: (top: 20mm, outside: 15mm, rest: 25mm),
    footer: context {
      // "book" numbering
      let real_page = here().page()
      if real_page > 1 and counter(page).final().first() > 2 {
        align(outside(real_page))[#counter(page).get().first()]
      }
    },
    header: context {
      // "book" numbering
      let real_page = here().page()
      if real_page > 1 or counter(page).final().first() == 1 {
        align(outside(real_page), author)
      }
    },
  )

  set text(
    font: "New Computer Modern",
    size: 12pt,
    lang: "ru",
  )

  set par(justify: true)

  show heading: title => {
    set text(hyphenate: false)
    set align(center)

    block(
      above: 1em,
      below: 1em,
      width: 100%,
      breakable: false,
      title,
    )
  }

  show title: title => {
    block(
      above: 2em,
      below: 2em,
      width: 100%,
      breakable: false,
      title,
    )
  }

  body
}

#let normal_title(body, with_outline: false) = {
  set heading(numbering: none, outlined: false)
  set text(hyphenate: false)

  if with_outline {
    v(5fr)
    normal_title(body) // yes
    v(8fr)
    outline()
    v(3fr)
    pagebreak()
  } else {
    align(center, title(body))
  }
}
