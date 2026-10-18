#import "/templates/informal.typ": format
#import "clair.typ": to-clair
#import "@preview/griddle:0.2.1": *

#show: format
#set page(footer: align(end)[Подготовили: А. Потапов, А. Садков, Ф. Лукин])
#set enum(numbering: num => strong(numbering("1.", num)))

#let cw_data = yaml("crossword.yml")
#let cw = {
  // https://github.com/micheledusi/Griddle/pull/2/changes
  let data = cw_data.map(dir => dir.map(entry => (
    entry + (word: to-clair(entry.word))
  )))
  load-crossword(data)
}

#title[Кроссворд]

#v(1fr)
#align(center, show-schema(cw.schema))
#v(2fr)

#pagebreak()
#columns[
  = По горизонтали
  // original show-definitions is really shitty
  #cw_data.across.map(entry => enum.item(entry.number, entry.definition)).sum()

  #colbreak()

  = По вертикали
  #cw_data.down.map(entry => enum.item(entry.number, entry.definition)).sum()
]

#pagebreak()
= Ответы
#(
  cw_data
    .values()
    .flatten()
    .sorted(key: entry => entry.number)
    .map(entry => enum.item(entry.word))
    .sum()
)
