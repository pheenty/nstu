#let format(body) = {
  let end = <end> // shitty but better than counter(page).final().first()
  let total_pages() = query(end).first().location().page()
  let real_page() = here().page()

  set page(
    paper: "a4",
    // margin:
    footer: context if real_page() > 1 and total_pages() > 2 {
      align(center)[#counter(page).get().first()]
    },
  )

  set text(
    font: "DejaVu Serif",
    size: 13pt,
    lang: "ru",
  )

  show raw: set text(font: "DejaVu Sans Mono")

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
