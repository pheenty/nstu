#let title(body, with_outline: false) = {
  set heading(numbering: none, outlined: false)
  set text(hyphenate: false)

  if with_outline {
    v(5fr)
    title(body) // yes
    v(8fr)
    outline()
    v(3fr)
    pagebreak()
  } else {
    align(center, body)
  }
}

#let uni_title(
  theme,
  authors: ([Лукин Фёдор],),
  checker,
  group: [АИ-62],
  uni: [ Федеральное государственное бюджетное образовательное учреждение \ высшего образования \ "Новосибирский государственный технический университет" ],
  city: [Новосибирск],
  authors_fmt: (authors, group) => [
    #if authors.len() > 1 [Выполнили студенты] else [Выполнил студент] группы #group \
    #authors.join[,\ ]
  ],
  checker_fmt: checker => [ Проверил #checker ],
  year: datetime.today().year(),
) = {
  title[
    #uni
    #v(3fr)
    #theme
    #v(2fr)
    #align(right)[
      #authors_fmt(authors, group)
      #v(1fr)
      #checker_fmt(checker)
    ]
    #v(2fr)
    #city #year
  ]
  pagebreak()
}
