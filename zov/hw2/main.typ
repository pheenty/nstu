#import "/templates/informal.typ": format
#import "@preview/griddle:0.2.1": *

#show: format
#set page(footer: align(end)[Подготовили: А. Потапов, А. Садков, Ф. Лукин])
#set enum(numbering: num => strong(numbering("1.", num)))

#let cw_data = yaml("crossword.yml")
#let cw = {
  // https://github.com/micheledusi/Griddle/pull/2/changes
  let data = {
    let to-clair(str) = {
      // https://www.consultant.ru/document/cons_doc_LAW_116298/6535874516fa34e7995e5716a162922bab41c9dd/
      let table = (
        "а": "a",
        "б": "b",
        "в": "v",
        "г": "g",
        "д": "d",
        "е": "e",
        "ё": "2",
        "ж": "j",
        "з": "z",
        "и": "i",
        "й": "q",
        "к": "k",
        "л": "l",
        "м": "m",
        "н": "n",
        "о": "o",
        "п": "p",
        "р": "r",
        "с": "s",
        "т": "t",
        "у": "u",
        "ф": "f",
        "х": "h",
        "ц": "c",
        "ч": "3",
        "ш": "4",
        "щ": "w",
        "ъ": "x",
        "ы": "y",
        "ь": "9",
        "э": "6",
        "ю": "7",
        "я": "8",
      )
      lower(str).clusters().map(ch => table.at(ch, default: ch)).join()
    }
    cw_data.map(dir => dir.map(entry => entry + (word: to-clair(entry.word))))
  }
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
  #for entry in cw_data.across { enum.item(entry.number, entry.definition) }

  #colbreak()

  = По вертикали
  #for entry in cw_data.down { enum.item(entry.number, entry.definition) }
]

#pagebreak()
= Ответы
#for ans in cw_data.values().flatten().map(entry => entry.word) [+ #ans]
