#let format(body) = {
  set page(
    paper: "a4",
    margin: (left: 30mm, right: 15mm, rest: 20mm),
    numbering: (page, ..args) => {
      if page > 1 { page }
    },
  )

  set text(
    font: "Liberation Serif", // technically should be Times New Roman but who gives a fuck
    size: 14pt,
    lang: "ru",
  )

  show raw: set text(font: "Liberation Mono")

  set par(
    leading: 0.75em,
    spacing: 0.75em,
    justify: true,
    first-line-indent: (amount: 1.25cm, all: true),
  )

  set heading(numbering: "1.1.")
  show heading: title => {
    set text(weight: "bold", size: 14pt, hyphenate: false)
    set align(center)

    let unnumbered = (
      "Введение",
      "Заключение",
      "Источники",
      "Список литературы",
    )

    let title = if unnumbered.contains(title.body.at("text", default: none)) {
      counter(heading).update(n => n - 1) // roll the heading number back
      title.body
    } else {
      title
    }

    block(
      above: 1.5em,
      below: 1.5em,
      width: 100%,
      breakable: false,
      title,
    )
  }

  // why can't you just search by content bruh
  show sym.space + sym.dash.em: [~---]

  body
}

#let uni_title(
  theme,
  authors: ([Лукин Фёдор Петрович],),
  reviewer,
  group: [АИ-62],
  uni: [ Федеральное государственное бюджетное образовательное учреждение \ высшего образования \ "Новосибирский государственный технический университет" ],
  city: [Новосибирск],
  authors_fmt: (authors, group) => [
    #if authors.len() > 1 [Выполнили студенты] else [Выполнил студент] группы #group \
    #authors.join[,\ ]
  ],
  year: datetime.today().year(),
) = {
  set align(center)
  uni
  v(3fr)
  theme.intersperse(v(2fr)).sum()
  v(2fr)
  align(right)[
    #authors_fmt(authors, group)
    #v(1fr)
    #reviewer
  ]
  v(2fr)
  [#city #year]
  pagebreak()
}
