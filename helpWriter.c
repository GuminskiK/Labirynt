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
	printf("./analyzer -f <nazwa pliku zpreprocesowanego>\n");
	printf("Możliwe jest także wyświetlenie pomocy, poprzez użycie flagi -h podczas uruchamiania,\n");
	printf("czyli wpisanie komendy:\n");
	printf("./analyzer -h\n");


	printf("--------------Jaki format pliku jest przyjmowany?----------------------------------------------------------\n");
	printf("Analizator:\n");
	printf("	!!! ANALIZATOR PRZYJMUJE JEDYNIE PREPROCESOWANY PLIK !!!\n");
	printf("Preprocesor:\n");
	printf("	a) Plik tekstowy:\n");
	printf("		- Labirynt jest przedstawiony w postaci, gdzie:\n");
	printf("			- P - punkt wejścia do labiryntu\n");
	printf("			- K - punkt wyjścia z labiryntu\n");
	printf("			- X - ściana\n");
	printf("			- spacja - ścieżka\n");
	printf("		- Labirynt jest prostokątem\n");
	printf("	b) Plik binarny:\n");
	printf("		- Zawiera nagłówek pliku:\n");
	printf("			- FILE Id w 32 bitach\n");
	printf("			- Escape w 8 bitach\n");
	printf("			- Liczbę kolumn labiryntu w 16 bitach\n");
	printf("			- Liczbę wierszy labiryntu w 16 bitach\n");
	printf("			- Współrzędne wejścia do labiryntu (X w 16 bitach i Y w 16 bitach)\n");
	printf("			- Współrzędne wyjścia z labiryntu (X w 16 bitach i Y w 16 bitach)\n");
	printf("			- 96 bitów zarezerwowanych do przyszłego wykorzystania\n");
	printf("			- Liczbę słów kodowych w 32 bitach\n");
	printf("			- Offset w pliku do sekcji zawierającej rozwiązanie w 32 bitach\n");
	printf("			- Separator w 8 bitach (oznacza początek słowa kodowego)\n");
	printf("			- Ściana w 8 bitach (słowo definiujące ścianę labiryntu)\n");
	printf("			- Path w 8 bitach (słowo definiujące pole, po którym można się poruszać)\n");
	printf("		- Słowa kodowe będace odzwierciedleniem jak wygląda labirynt:\n");
	printf("			- Separator - 8 bitów\n");
	printf("			- Wartość słowa kodowego - 8 bitów\n");
	printf("			- Liczba wystąpień (gdzie 0 oznacza jedno wystąpienie)- 8 bitów\n");

	
	printf("--------------Wyjście, czym jest?--------------------------------------------------------------------------\n");
	
	printf("Jest to lista kroków jakie należy wykonać by przejść przez labirynt i wygląda np. tak:\n");
	printf("	START\n");
	printf("	FORWARD 1\n");
	printf("	TURNLEFT\n");
	printf("	FORWARD 4\n");
	printf("	TURNRIGHT\n");
	printf("	FORWARD 3\n");
	printf("	STOP\n");

	printf("--------------Autorzy:-------------------------------------------------------------------------------------\n");
	printf("Praca została wykonana przez Krzysztofa Gumińskiego i Macieja Bankiewicza.");
	
	
	
}
