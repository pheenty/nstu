#import "/templates/default.typ": *
#show: format

#set text(10pt)
#align(center + horizon, table(
  columns: (1fr, 1fr, 1fr, 1fr),
  table.header([Значение], [Древнегреческий], [Латынь], [Примеры]),
  ..yaml("data.yml")
    .map(entry => (
      table.cell(rowspan: 2, entry.meaning),
      table.cell(rowspan: 2, entry.greek),
      table.cell(rowspan: 2, entry.latin),
      entry.examples.at(0),
      entry.examples.at(1),
    ))
    .flatten(),
  inset: 0.5em,
))
