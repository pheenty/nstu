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
  title[
    Федеральное государственное бюджетное образовательное учреждение \ высшего образования \
    "Новосибирский государственный технический университет"

    #v(3fr)

    Доклад по дисциплине "История России" \
    #seminary

    #v(2fr)

    Тема: #theme

    #v(2fr)

    #align(right)[
      Доклад #if authors.len() > 1 [подготовили студенты] else [подготовил студент] \
      #authors.sorted(key: (content => content.text)).join[,\ ] \
      группы #group

      #v(1fr)

      Проверил: старший преподаватель \
      Пономарев Илья Игоревич
    ]

    #v(2fr)

    Новосибирск #year
  ]

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
