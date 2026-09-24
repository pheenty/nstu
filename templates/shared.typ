#let Size = (
  "Big": 0, // title on its own page (add outline yourself on the new one if needed)
  "Medium": 1, // title and outline on one page
  "Small": 2, // embedded title
)

#let start(body, size: Size.Small) = {
  set heading(outlined: false)
  set text(hyphenate: false)
  if size == Size.Big {
    v(5fr)
    start(body, size: Size.Small) // yes
    v(8fr)
    pagebreak()
  } else if size == Size.Medium {
    v(5fr)
    start(body, size: Size.Small)
    v(8fr)
    outline()
    v(3fr)
    pagebreak()
  } else if size == Size.Small {
    align(center, [#body])
  } else {
    panic("invalid size")
  }
}
