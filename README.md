# Tegn og Mal

## Begreber

- Abstraktion
- Generalisering vha. parametrisering
- [Nedarvning](https://programmering.systime.dk/?id=176) og polymorfisme
- [Typer og Bindinger](https://programmering.systime.dk/?id=177)
- [Generiske funktioner](https://programmering.systime.dk/?id=245) vha. overload
- [Træer](https://programmering.systime.dk/?id=240) og [rekursion](https://programmering.systime.dk/?id=242)

### Abstraktion

> I datalogi er abstraktion en mekanisme eller metode til at mindske eller skjule detaljer således, at man kan koncentrere sig om nogle få koncepter ad gangen.
> -- wiki

### Generalisering vha. parametrisering

En funktion kan generaliseres ved at lave færre og færre antagelser om input. Man kunne fx forestille sig en funktion der starter med at tegne en firkant med en bestemt farve, bredde, højde og position. Denne funktion kan generaliseres trinvis ved at acceptere farve som funktionsparameter, bredde osv. Hermed gås fra en meget specifik/snæver funktion til en mere generel funktion.

---

## Vejledning og logbog

Løbende vejledning og stikord til logbog på repo wiki.

- [Intro til SFML og øvelser i parametrisering](../../wiki/Home).

---

## Dokumentation

- [SFML Classes](https://www.sfml-dev.org/documentation/2.5.1/annotated.php)
- [SFML Tutorials](https://www.sfml-dev.org/tutorials/2.5/)

---

## Opsætning af SFML

### Code::blocks

Dette repo indeholder et build og opsat projekt i CB med et basis eksempel.

Kræver compiler: MinGW (x86_64-8.1.0-posix-seh-rt_v6-rev0)

Alternativt kan man følge [tutorial til opsætning](https://www.sfml-dev.org/tutorials/2.5/start-cb.php).

### CMake

1. [Hent SFML build](https://www.sfml-dev.org/download/sfml/2.5.1/) der passer til din compiler.

2. Brug evt. [CMakeLists.txt](/CMakeLists.txt) i dette repo som udgangspunkt til opsætning. Husk at ændre stien til SFML hvor det er angivet.
