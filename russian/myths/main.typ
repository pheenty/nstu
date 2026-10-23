#import "/templates/default.typ": *
#show: format

#init[Мифологемы]

#for entry in yaml("data.yml") [
  + #block(breakable: false)[
      *#entry.name* \
      _Значение_: #entry.meaning \
      _Происхождение_: #entry.origin \
      _Пример использования_: #entry.example
    ]
]
