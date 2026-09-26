#import "../templates/gost.typ"
#import "../templates/title.typ": *

#let abstract(
  theme,
  seminary: none,
  authors: ([Лукин Фёдор],),
  group: [АИ-62],
  year: datetime.today().year(),
  body,
) = context {
  show: gost.format
  uni_title(
    [
      Доклад по дисциплине "История России" \
      #seminary
      #v(2fr)
      Тема: #theme
    ],
    authors: authors,
    [старший преподаватель \ Пономарев Илья Игоревич ],
    authors_fmt: (
      authors,
      _,
    ) => [ Доклад #if authors.len() > 1 [подготовили студенты] else [подготовил студент] \
      #authors.sorted(key: (content => content.text)).join[,\ ] \
      группы #group
    ],
  )

  body
  pagebreak()

  // biblography shit
  layout(size => {
    // i don't fucking know why 10 but it doesn't work if it's less
    let exists(bib) = measure(bib, width: page.width).height > 10pt

    // still need to have them in the document for measuring them, so can't just assign the title directly
    set bibliography(style: "ponomarev.csl", title: none)
    let sources = bibliography("sources.yml")
    let literature = bibliography("literature.yml")
    let bibs = (
      {
        if exists(sources) [ = Источники ]
        sources
      },
      {
        if exists(literature) [ = Список литературы ]
        literature
      },
    )

    // cursed but works
    if measure(width: size.width, bibs.sum()).height > page.height {
      bibs = bibs.intersperse(colbreak(weak: true))
    }

    bibs.sum()
  })
}
