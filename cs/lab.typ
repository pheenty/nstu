#import "/templates/gost.typ": *

#let lab(
  num,
  theme,
  group: [АИ-62],
  authors: ([Лукин Фёдор],),
  teach: [Копылова Оксана Андреевна],
  year: datetime.today().year(),
  code1: none,
  code2: none,
  body,
) = context {
  show: format.with(
    strict: true,
    numbering: none,
    structural: (),
    heading-weight: "regular",
  )

  show outline.entry: e => if e.element.level < 2 { e }
  show heading: h => if h.level > 1 {
    set block(inset: 0pt)
    align(center, h)
  } else {
    strong(h)
  }

  show raw.where(block: true): code => {
    let lang = code.lang
    block(code, fill: luma(246), inset: 1em, width: 100%)
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

  pagebreak(weak: true)
  bibliography(
    "literatype.yml",
    title: [Список литературы],
    style: "gost-r-705-2008-numeric",
  )

  if code1 != none {
    pagebreak(weak: true)
    heading[Приложение А. Исходный код программы]
    raw(block: true, lang: "cpp", code1)
  }

  if code2 != none {
    pagebreak(weak: true)
    heading[Приложение Б. Исходный код дополнительной программы]
    raw(block: true, lang: "cpp", code2)
  }
}
