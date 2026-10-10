#let format(
  body,
  strict: false,
  numbering: "1.1.",
  structural: (
    "введение",
    "заключение",
    "источники",
    "список литературы",
  ),
  heading-weight: "bold",
) = {
  set page(
    paper: "a4",
    margin: (left: 30mm, right: 15mm, rest: 20mm),
    numbering: (page, ..args) => {
      if page > 1 { page }
    },
  )

  set text(
    font: ("Times New Roman", "Liberation Serif"),
    size: 14pt,
    lang: "ru",
  )

  show raw: set text(font: ("Courier New", "Liberation Mono"))

  let indent = 1.25cm
  set par(
    leading: 0.75em,
    spacing: 0.75em,
    justify: true,
    first-line-indent: (amount: indent, all: true),
  )

  show heading: title => {
    set text(weight: heading-weight, size: 14pt, hyphenate: false)

    if lower(title.at("body", default: ``).at("text", default: "")).contains(
      "вступление",
    ) {
      panic("Введение блядь")
    }

    block(
      above: 1.2em,
      below: 0.9em,
      width: 100%,
      breakable: false,
      sticky: true,
      {
        set block(inset: 0pt)
        title
      },
    )
  }

  set heading(numbering: numbering)

  set heading(bookmarked: false) // used as a marker for processed headings
  show heading.where(
    numbering: numbering,
    bookmarked: false,
    outlined: true,
  ): title => {
    set heading(bookmarked: auto)
    // roll the heading number back
    if title.numbering != none {
      counter(heading).update((..n) => {
        let v = n.pos()
        v.at(-1) -= 1
        v
      })
    }

    let body = title.body
    if structural.contains(lower(body.at("text", default: none))) {
      set align(center)
      heading(
        level: title.level,
        numbering: none,
        outlined: title.outlined,
        body,
      )
    } else {
      set align(if strict { left } else { center })
      set block(inset: (left: if strict { indent } else { 0pt }))
      heading(level: title.level, outlined: title.outlined, body)
    }
  }

  set outline(title: if strict [СОДЕРЖАНИЕ] else [Содержание])
  show outline.entry: entry => {
    if entry.element.bookmarked == auto {
      entry
    }
  }

  // why can't you just search by content bruh
  show sym.space + sym.dash.em: [~---]

  body
}

#let init(
  theme,
  authors: ([Лукин Фёдор Петрович],),
  reviewer,
  group: [АИ-62],
  uni: [ Федеральное государственное бюджетное образовательное учреждение \ высшего образования \ "Новосибирский государственный технический университет" ],
  city: [Новосибирск #datetime.today().year()],
  authors_fmt: (authors, group) => {
    if authors.len() > 1 [Выполнили студенты] else [Выполнил студент]
    [группы #group \ ]
    authors.join[,\ ]
  },
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
  city
  pagebreak()
}
