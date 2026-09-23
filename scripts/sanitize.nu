#!/usr/bin/env nu

def main [file] {
    open --raw $file
    | str replace --all "\t" ' '
    | str replace --all '–' '--'
    | str replace --all '—' '---'
    | str replace --all '«' '"'
    | str replace --all '»' '"'
    | save --force $file

    ^typstyle -i $file
}
