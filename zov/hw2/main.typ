#import "/templates/informal.typ": format
#import "@preview/griddle:0.2.1": *

#show: format

#set page(footer: align(end)[Подготовили: А. Потапов, А. Садков, Ф. Лукин])
#title[Гойда гойда зов кроссворд]

#v(1fr)

#let cw = load-crossword(yaml("crossword.yml"))
#align(center, show-schema(cw.schema, cell-size: (2.5em, 2.5em)))

#v(1fr)
#columns[
  = По горизонтали
  #show-definitions(cw.definitions.across)

  #colbreak()

  = По вертикали
  #show-definitions(cw.definitions.down)
]

#v(1fr)
