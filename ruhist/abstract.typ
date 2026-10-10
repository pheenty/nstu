#import "/templates/gost.typ": *

#let abstract(
  theme,
  seminary: none,
  authors: ([Лукин Фёдор], [Садков Артём], [Потапов Артём]),
  group: [АИ-62],
  year: datetime.today().year(),
  body,
) = context {
  show: format
  show heading: heading => align(center, heading)
  set enum(numbering: "1)")

  show list: _ => panic(
    "НЕНУМЕРОВАННЫЙ СПИСОК НАРУШАЕТ ЛИТЕРАТУРНУЮ ЧИСТОТУ РЕФЕРАТА.",
  )
  show regex(`\s-|-\s`.text): _ => panic(
    "ОБНАРУЖЕНО НЕПОЛНОЦЕННОЕ ТИРЕ ВОЗЛЕ СВЯЩЕННОГО ПРОБЕЛА.",
  )

  init(
    (
      [ Доклад по дисциплине "История России" \ #seminary ],
      [ Тема: #theme ],
    ),
    authors: authors,
    [ Проверил: кандидат исторических наук, \ старший преподаватель \ Пономарев Илья Игоревич ],
    authors_fmt: (
      authors,
      _,
    ) => [ Доклад #if authors.len() > 1 [подготовили студенты] else [подготовил студент] \
      #authors.sorted(key: (content => content.text)).join[,\ ] \
      группы #group
    ],
  )

  body
  pagebreak(weak: true)

  // biblography shit
  layout(size => {
    // i don't fucking know why but it's 9.17pt if it doesn't exist
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
