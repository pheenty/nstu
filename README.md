# Typst-CICD

A ready-to-use template repo for writing uni abstracts (or any text work, really) using [Typst](https://github.com/typst/typst)
which are then automatically compiled and deployed to GitHub Pages using the pre-configured CI/CD.
See [this file](subject/abstract1/main.typ)? It was automatically compiled and
deployed at the [web](https://pheenty.github.io/typst-cicd/subject/abstract1.pdf) by me merely pushing to master.

# How this works

1. Use this template to create your repo.
2. Setup `git lfs`.
3. Optionally, you can check `.github/workflows/typst.yml` for extra settings you might want.
4. Enable GitHub Pages in the repo settings and set them to be sourced from actions.
5. Write your normal typst docs. They can be anywhere in this repo, BUT the document root must be named `main.typ`.
6. Once you push them to `master`, GitHub actions will automatically build and deploy them. Main file at `subject/abstract1/main.typ` gets `yourname.github.io/yourrepo/subject/abstract1.pdf` adress.

# License

Copyright (C) 2026 Theodore Lukin

This program is free software: you can redistribute it and/or modify
it under the terms of the Do What the Fuck You Want to Public License as
published by Sam Hocevar, either version 2 of the
License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
Do What the Fuck You Want to Public License for more details.

You should have received a [copy](LICENSE) of the Do What the Fuck You Want to Public License
along with this program. If not, [kill yourself](https://www.wtfpl.net/about/).
