#!/usr/bin/env nu

let pdfs = mkdir --verbose $env.PDFS | first | get path
let oldest = (date now) - ($env.MAX_AGE | into duration)

ls **/main.typ
| get name
| where {
    # only compile fresh dirs.
    # we also want to include documents whose assets were changed,
    # but we do not want to compile everything if a template was changed.
    let dir = $in | path dirname
    let changed_at = ^git log --max-count=1 --format=%ci $dir | into datetime
    $changed_at > $oldest
}
| par-each {
    let dir = $in | path dirname | path parse

    let path = $dir | get parent
    let name = $dir | get stem

    let out = mkdir --verbose ($pdfs | path join $path)
    | first
    | get path
    | path join $'($name).pdf'

    ^typst compile --jobs=1 --root=. $in $out
}
