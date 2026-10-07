#let format(body, author: [Лукин Фёдор, АИ-62]) = {
  let outside(page) = if calc.even(page) { left } else { right } // why is it not built in

  let end = <end> // shitty but better than counter(page).final().first()
  let total_pages() = query(end).first().location().page()
  let real_page() = here().page()

  set page(
    paper: "a4",
    // margin:
    footer: context if real_page() > 1 and total_pages() > 2 {
      align(outside(real_page()))[#counter(page).get().first()]
    },
    header: context if real_page() > 1 or total_pages() == 1 {
      align(outside(real_page()), author)
    },
  )

  set text(
    font: "New Computer Modern",
    size: 12pt,
    lang: "ru",
  )

  show raw: set text(font: "New Computer Modern Mono")

  set par(justify: true)

  let title_fmt(title, above, below) = {
    set text(hyphenate: false, font: "New Computer Modern Sans")
    set align(center)

    block(
      above: above,
      below: below,
      width: 100%,
      breakable: false,
      sticky: true,
      title,
    )
  }

  show title: title => smallcaps(title_fmt(title, 1.8em, 1.2em))
  show heading: heading => title_fmt(heading, 1.2em, 0.8em)

  // https://github.com/typst/typst/issues/5182
  context if total_pages() > 2 {
    set page(margin: (top: 20mm, outside: 15mm, rest: 25mm))
    body
  } else {
    set page(margin: (bottom: 25mm, rest: 20mm))
    body
  }

  [#metadata(none)#end] // bruh
}

#let init(body, with_outline: false) = {
  set heading(numbering: none, outlined: false)
  set text(hyphenate: false)

  if with_outline {
    v(5fr)
    init(body) // yes
    v(8fr)
    outline()
    v(3fr)
    pagebreak()
  } else {
    align(center, title(body))
  }
}
