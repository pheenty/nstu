#import "/templates/gost.typ": *

#let lab(
  num,
  theme,
  group: [АИ-62],
  authors: ([Лукин Фёдор],),
  teach: [Копылова Оксана Андреевна],
  year: datetime.today().year(),
  body,
) = context {
  show: format
  show heading: heading => align(right, heading)

  align(center)[
    #text(size: 12pt)[
      МИНИСТЕРСТВО НАУКИ И ВЫСШЕГО ОБРАЗОВАНИЯ РОССИЙСКОЙ ФЕДЕРАЦИИ \
      ФЕДЕРАЛЬНОЕ ГОСУДАРСТВЕННОЕ БЮДЖЕТНОЕ ОБРАЗОВАТЕЛЬНОЕ УЧРЕЖДЕНИЕ ВЫСШЕГО ОБРАЗОВАНИЯ \
      "НОВОСИБИРСКИЙ ГОСУДАРСТВЕННЫЙ ТЕХНИЧЕСКИЙ УНИВЕРСИТЕТ" \
      Кафедра вычислительной техники
    ]

    #v(1fr)

    *
    ОТЧЁТ ПО ЛАБОРАТОРНОЙ РАБОТЕ №#num \
    ПО ДИСЦИПЛИНЕ "ИНФОРМАТИКА" \
    "#theme"
    *

    #v(1fr)

    #align(left, grid(columns: (1fr, 1fr), inset: 1em, stroke: gray)[
      Факультет: АВТФ \
      Группа: #group \
      Студент(ы): #authors.join([, ])
    ][
      Преподаватель: #teach
    ])

    #v(2fr)

    Новосибирск, #year г.
  ]

  pagebreak()

  outline()

  body
  pagebreak(weak: true)
}
