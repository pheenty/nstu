#import "@preview/touying:0.8.0": meanwhile

#let img(path, src, caption) = {
  meanwhile
  align(
    center + bottom,
    link(src, image("assets/" + path, height: 40%) + caption),
  )
}
