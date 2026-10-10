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
  show: format.with(
    strict: true,
    numbering: none,
    structural: (),
    heading-weight: "regular",
  )

  show outline.entry: e => { if e.element.level < 2 { e } }
  show heading: h => if h.level > 1 {
    set block(inset: 0pt)
    align(center, h)
  } else {
    strong(h)
  }

  init(
    uni: [
      #text(size: 12pt)[
        МИНИСТЕРСТВО НАУКИ И ВЫСШЕГО ОБРАЗОВАНИЯ РОССИЙСКОЙ ФЕДЕРАЦИИ \
        ФЕДЕРАЛЬНОЕ ГОСУДАРСТВЕННОЕ БЮДЖЕТНОЕ ОБРАЗОВАТЕЛЬНОЕ \
        УЧРЕЖДЕНИЕ ВЫСШЕГО ОБРАЗОВАНИЯ \
        "НОВОСИБИРСКИЙ ГОСУДАРСТВЕННЫЙ ТЕХНИЧЕСКИЙ УНИВЕРСИТЕТ" \
      ]
      Кафедра вычислительной техники
    ],
    (
      strong[
        ОТЧЁТ ПО ЛАБОРАТОРНОЙ РАБОТЕ №#num \
        ПО ДИСЦИПЛИНЕ "ИНФОРМАТИКА" \
        "#theme"
      ],

      align(left + horizon, grid(columns: (1fr, 1fr), inset: 1em, stroke: gray)[
        Факультет: АВТФ \
        Группа: #group \
        Студент(ы): #authors.join([, ])
      ][
        Преподаватель: \ #teach
      ]),
    ),
    none,
    authors_fmt: (_, _) => none,
    city: [Новосибирск, #year г.],
  )

  outline(title: [Содержание])
  pagebreak()

  body
}
