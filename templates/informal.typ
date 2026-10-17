#let format(body) = {
  let end = <end> // shitty but better than counter(page).final().first()
  let total_pages() = query(end).first().location().page()
  let real_page() = here().page()

  set page(
    paper: "a4",
    margin: (rest: 20mm),
    footer: context if real_page() > 1 and total_pages() > 2 {
      align(center)[#counter(page).get().first()]
    },
  )

  set text(
    font: "DejaVu Serif",
    size: 12pt,
    lang: "ru",
  )

  show raw: set text(font: "DejaVu Sans Mono")
  show math.equation: set text(font: "DejaVu Math TeX Gyre")

  let title_fmt(title, above, below) = {
    set text(hyphenate: false, font: "DejaVu Sans")
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

  body

  [#metadata(none)#end] // bruh
}
