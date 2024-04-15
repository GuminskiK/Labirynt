#include <stdio.h>
#include "helpWriter.h"

void writeHelp( void )
{
	printf("-------------------------------------------Analizator Labiryntu-------------------------------------------\n");
	printf("--------------Do czego służy?-----------------------------------------------------------------------------\n");
	printf("Nasz program, służy do znalezienia rozwiązania labiryntu, czyli drogi od wejścia do labiryntu,\n");
	printf("aż do wyjścia z niego. Składa się on z dwóch części: preprocesora (preprocessor) i analizatora (analyzer).");
	printf("Przyjmuje on na wejściu pliki w dwóch formatach binarnym i tekstowym.\n");

	printf("--------------Jak uruchomić?------------------------------------------------------------------------------\n");
	printf("Preprocesor uruchamiamy za pomocą komendy:\n");
	printf("./preprocessor <nazwa pliku wejściowego>\n");
	printf("Analizator uruchamiamy za pomocą komendy:\n");
	printf("./analyzer <nazwa pliku zpreprocesowanego>\n");
	printf("Możliwe jest także wyświetlenie pomocy, poprzez użycie flagi -h podczas uruchamiania,\n");
	printf("czyli wpisanie komendy:\n");
	printf("./analyzer -h\n");


	printf("--------------Jaki format pliku jest przyjmowany?----------------------------------------------------------\n");
	printf("Analizator:\n");
	pritnf("	!!! ANALIZATOR PRZYJMUJE JEDYNIE PREPROCESOWANY PLIK !!!\n");
	pritnf("Preprocesor:\n");
	pritnf("	a) Plik tekstowy:\n");
	pritnf("		- Labirynt jest przedstawiony w postaci, gdzie:\n");
	pritnf("			- P - punkt wejścia do labiryntu\n");
	pritnf("			- K - punkt wyjścia z labiryntu\n");
	pritnf("			- X - ściana\n");
	pritnf("			- spacja - ścieżka\n");
	pritnf("		- Labirynt jest prostokątem\n");
	pritnf("	b) Plik binarny:\n");
	pritnf("		- Zawiera nagłówek pliku:\n");
	pritnf("			- FILE Id w 32 bitach\n");
	pritnf("			- Escape w 8 bitach\n");
	pritnf("			- Liczbę kolumn labiryntu w 16 bitach\n");
	pritnf("			- Liczbę wierszy labiryntu w 16 bitach\n");
	pritnf("			- Współrzędne wejścia do labiryntu (X w 16 bitach i Y w 16 bitach)\n");
	pritnf("			- Współrzędne wyjścia z labiryntu (X w 16 bitach i Y w 16 bitach)\n");
	pritnf("			- 96 bitów zarezerwowanych do przyszłego wykorzystania\n");
	pritnf("			- Liczbę słów kodowych w 32 bitach\n");
	pritnf("			- Offset w pliku do sekcji zawierającej rozwiązanie w 32 bitach\n");
	pritnf("			- Separator w 8 bitach (oznacza początek słowa kodowego)\n");
	pritnf("			- Ściana w 8 bitach (słowo definiujące ścianę labiryntu)\n");
	pritnf("			- Path w 8 bitach (słowo definiujące pole, po którym można się poruszać)\n");
	pritnf("		- Słowa kodowe będace odzwierciedleniem jak wygląda labirynt:\n");
	pritnf("			- Separator - 8 bitów\n");
	pritnf("			- Wartość słowa kodowego - 8 bitów\n");
	pritnf("			- Liczba wystąpień (gdzie 0 oznacza jedno wystąpienie)- 8 bitów\n");

	
	printf("--------------Wyjście, czym jest?--------------------------------------------------------------------------\n");
	
	pritnf("Jest to lista kroków jakie należy wykonać by przejść przez labirynt i wygląda np. tak:\n");
	pritnf("	START\n");
	pritnf("	FORWARD 1\n");
	pritnf("	TURNLEFT\n");
	pritnf("	FORWARD 4\n");
	pritnf("	TURNRIGHT\n");
	pritnf("	FORWARD 3\n");
	printf("	STOP\n");

	printf("--------------Autorzy:-------------------------------------------------------------------------------------\n");
	printf("Praca została wykonana przez Krzysztofa Gumińskiego i Macieja Bankiewicza.");
	
	
	
}
