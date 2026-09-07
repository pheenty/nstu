#let title_page(
  theme,
  seminary: none,
  authors: ("Фёдор Лукин",),
) = {
  set text(hyphenate: false)
  align(center)[

    Федеральное государственное бюджетное образовательное учреждение высшего образования \
    "Новосибирский государственный технический университет" \

    #v(3fr)

    Доклад по дисциплине "История России" \

    #seminary \

    #v(2fr)

    Тема: #theme \

    #v(2fr)
  ]

  align(right)[
    Доклад
    #if authors.len() > 1 { "подготовили студенты" } else { "подготовил студент" } \
    #authors.sorted().join(linebreak()) \
    группы АИ-62 \

    #v(1fr)

    Проверил: старший преподаватель \
    Пономарев Илья Игоревич \
  ]

  v(2fr)

  align(center)[
    Новосибирск
    #datetime.today().year()
  ]

  pagebreak()
}
