#let title(body, with_outline: false) = {
  set heading(outlined: false)
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
