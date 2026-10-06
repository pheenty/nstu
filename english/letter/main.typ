#import "@preview/letterloom:3.0.2": letterloom
#show: letterloom.with(
  from-name: "Theodore Lukin",
  from-address: [
    Room 7-401 of NSTU \
    Novosibirsk, Russia \
  ],
  to-name: "John Friend",
  to-address: [
    221B Baker Street \
    London, UK \
  ],
  date: [October 5#super[th], 2026],
  salutation: "Dear John,",
  subject: smallcaps([= Regarding our higher education]),
  closing: "Sincerely yours,",
  signatures: (
    name: "Theodore Lukin",
    signature: image("assets/signature.svg", width: 20%),
  ),
  main-font: "New Computer Modern Mono",
  main-font-size: 10pt,
)

#set par(justify: true)
#show raw: set text(size: 1.25em, font: "New Computer Modern Mono")

Thank you very much for your previous formal correspondence regarding the status of my professional development.
I am writing this official notification to update you on my recent successful enrollment in an accredited program of higher education, pursuant to all applicable institutional regulations.

In strict accordance with your previous inquiry regarding my ongoing academic pursuits, I am pleased to inform you that I have officially gained admission to Novosibirsk State Technical University.
Specifically, upon completion of the requisite registration procedures, I have been matriculated into the Faculty of Automation and Computer Engineering, designated under local administrative classification as AVTF.
Currently, under the direct supervision of Departmental Faculty, we are acquiring theoretical and practical expertise in a modern, state-of-the-art programming language known as COBOL.
Pursuant to course requirements, I have successfully developed my initial software, presented below for your administrative evaluation:

#align(center, block(fill: luma(246), inset: 1em, stroke: luma(0))[
  ```
  000100 IDENTIFICATION DIVISION.
  000200 PROGRAM-ID. HELLO-WORLD.
  000300 PROCEDURE DIVISION.
  000400     DISPLAY "HELLO, WORLD!"
  000500     STOP RUN.
  ```
])

Regarding your own prospects in higher education, kindly submit clarification detailing which specific field of study you intend to select.
Furthermore, please specify what exact professional qualifications and official state certification you will be granted upon final graduation from your designated tertiary institution.
Lastly, clarify whether it possesses suitable, fully certified laboratory facilities for operational research.

I must formally conclude this letter now due to scheduled domestic responsibilities requiring my personal oversight.
However, I look forward to receiving your official written reply in due course.
