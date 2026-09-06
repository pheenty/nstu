#import "../abstract.typ": title_page
#import "../../templates/gost.typ": format

#show: format
#title_page("Связь истории России с историей других стран",
  authors: ("Фёдор Лукин", "Артём Садков", "Артём Потапов"),
  seminary: "Семинар 1. Общие вопросы курса."
)

= Введение

#lorem(200) согласно @orlov2018 @kirillov2016 @vorobjeva2019

#pagebreak()

= Основная часть

#lorem(300)

#pagebreak()

= Вывод

#lorem(100)

#pagebreak()

#bibliography("../sources.bib", title: [Список литературы], style: "gost-r-705-2008-numeric")
