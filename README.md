# Analzator labiryntu
## Do czego służy?

Nasz program, służy do znalezienia rozwiązania labiryntu, czyli drogi od wejścia
do labiryntu, aż do wyjścia z niego. Składa się on z dwóch części: preprocesora (preprocessor) i analizatora (analyzer). Przyjmuje on na wejściu pliki w dwóch formatach binarnym i tekstowym.

## Jak uruchomić?

Preprocesor uruchamiamy za pomocą komendy:
```
./preprocessor <nazwa pliku wejściowego>
```
Analizator uruchamiamy za pomocą komendy:
```
./analyzer -f <nazwa pliku zpreprocesowanego>
```
Możliwe jest także wyświetlenie pomocy, poprzez użycie flagi -h podczas
uruchamiania, czyli wpisanie komendy:
```
./analyzer -h
```

## Jaki format pliku jest przyjmowany?

### Analizator:
!!! ANALIZATOR PRZYJMUJE JEDYNIE PREPROCESOWANY PLIK !!!

### Preprocesor:

#### a) Plik tekstowy:
- Labirynt jest przedstawiony w postaci, gdzie:
   - P - punkt wejścia do labiryntu
   - K - punkt wyjścia z labiryntu
   - X - ściana
   - spacja - ścieżka  
- Labirynt jest prostokątem

#### b) Plik binarny:
- Zawiera nagłówek pliku:
  - FILE Id w 32 bitach
  - Escape w 8 bitach
  - Liczbę kolumn labiryntu w 16 bitach
  - Liczbę wierszy labiryntu w 16 bitach
  - Współrzędne wejścia do labiryntu (X w 16 bitach i Y w 16 bitach)
  - Współrzędne wyjścia z labiryntu (X w 16 bitach i Y w 16 bitach)
  - 96 bitów zarezerwowanych do przyszłego wykorzystania
  - Liczbę słów kodowych w 32 bitach
  - Offset w pliku do sekcji zawierającej rozwiązanie (nie używamy, ale jest) w 32 bitach
  - Separator w 8 bitach (oznacza początek słowa kodowego)
  - Ściana w 8 bitach (słowo definiujące ścianę labiryntu)
  - Path w 8 bitach (słowo definiujące pole, po którym można się poruszać)
- Słowa kodowe będace odzwierciedleniem jak wygląda labirynt:
  - Separator - 8 bitów
  - Wartość słowa kodowego - 8 bitów
  - Liczba wystąpień (gdzie 0 oznacza jedno wystąpienie)- 8 bitów

## Wyjście, czym jest?
Jest to lista kroków jakie należy wykonać by przejść przez labirynt i wygląda np. tak:
```
START
FORWARD 1
TURNLEFT
FORWARD 4
TURNRIGHT
FORWARD 3
STOP
```
## Autorzy:
Praca została wykonana przez Krzysztofa Gumińskiego i Macieja Bankiewicza.
