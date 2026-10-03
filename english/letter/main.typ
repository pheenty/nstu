#import "@preview/letterloom:3.0.2": letterloom
#show: letterloom.with(
  from-name: "Theodore Lukin",
  from-address: [
    Room 7-402 of NSTU \
    Novosibirsk, Russia \
  ],
  to-name: "John Friend",
  to-address: [
    221B Baker Street \
    London, UK \
  ],
  date: datetime
    .today()
    .display("[day padding:zero] [month repr:long] [year repr:full]"),
  salutation: "Dear John,",
  subject: title(smallcaps("Regarding our higher education")),
  closing: "Sincerely yours,",
  signatures: (
    (
      name: "Theodore Lukin",
      signature: image("assets/signature.svg", width: 20%),
    ),
  ),
  main-font: "New Computer Modern Mono",
)

#set par(justify: true)

Thank you very much for your previous correspondence.
I am writing to update you on my recent enrollment in a program of higher education.

In accordance with your previous query regarding my academic pursuits, I am pleased to inform you that I have successfully gained admission to Novosibirsk State Technical University.
Specifically, I have matriculated into the Faculty of Automation and Computer Engineering, commonly referred to as AVTF.
Currently we are getting expertise in a modern programming language known as COBOL, and I have programmed my first application recently:

#align(center, block(fill: luma(240), inset: 1em, stroke: luma(0))[
  #show raw: set text(size: 1.25em, font: "New Computer Modern Mono")
  ```
  000100    IDENTIFICATION DIVISION.
  000200        PROGRAM-ID. HELLO-WORLD.
  000300        PROCEDURE DIVISION.
  000400            DISPLAY "HELLO, WORLD!".
  000500            GOBACK.
  ```
])

Regarding your own higher education prospects, could you please clarify which field of study you intend to select?
Furthermore, does your chosen institution possess suitable laboratory facilities?
Lastly, what specific qualifications will you be granted upon graduation?

I must conclude this letter now due to scheduled domestic responsibilities.
However, I look forward to receiving your official written reply.
