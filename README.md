# Kalkulator Dla Elektroników/Informatyków

Autor: Hubert Gąsior

## Spis treści
1. [Wstęp](#wstęp)
2. [Wymagania systemowe](#wymagania-systemowe)
3. [Funkcjonalność](#funkcjonalność)
4. [Analiza problemu](#analiza-problemu)
5. [Projekt techniczny](#projekt-techniczny)
6. [Opis realizacji](#opis-realizacji)
7. [Opis wykonanych testów](#opis-wykonanych-testów)
8. [Podręcznik użytkownika](#podręcznik-użytkownika)
9. [Bibliografia](#bibliografia)

## Wstęp
Niniejszy dokument dotyczy projektu kalkulatora przeznaczonego dla elektroników i informatyków. Program oferuje funkcje wykonywania podstawowych operacji matematycznych, takich jak dodawanie, odejmowanie, mnożenie, dzielenie, oraz konwersję liczb między systemami liczbowymi: dziesiętnym, binarnym, ósemkowym i szesnastkowym. Kalkulator obsługuje hierarchię działań oraz nawiasy.

## Wymagania systemowe
- System operacyjny Windows
- Środowisko Qt lub Visual Studio 2022 wraz z biblioteką MFC

## Funkcjonalność
1. Wyświetlanie wyników: Wyniki są prezentowane w odpowiednich systemach liczbowych (Float, Bin, Oct, Hex).
2. Wybór systemu liczbowego: Użytkownik może wprowadzać wyrażenia w wybranym formacie liczbowym.
3. Wprowadzenie oraz obliczanie wyrażenia: Użytkownik może wprowadzić wyrażenie matematyczne i obliczyć je za pomocą przycisku "Compute".

## Analiza problemu
Algorytm "Shunting Yard" konwertuje wyrażenie z postaci infiksowej na RPN, co umożliwia wykonywanie obliczeń zgodnie z priorytetem działań. Proces obliczania wyrażenia w RPN obejmuje umieszczanie liczb i operatorów na stosie, zdejmowanie liczb i operatorów, wykonywanie działań oraz odkładanie wyników na stos.

## Projekt techniczny
1. Hierarchia klas: Główna klasa `Calculator` zawiera metody umożliwiające obliczanie wyrażeń oraz konwersję między systemami liczbowymi.
2. Metody klas `Bin`, `Oct`, `Hex`: Konwersje liczb zmiennoprzecinkowych na różne systemy liczbowe oraz konwersje wyrażeń między systemami.

## Opis realizacji
1. Klasa `Calculator`:
    - `applyOperation`: Wykonuje działanie matematyczne.
    - `precedence`: Zwraca priorytet operatora.
    - `Compute`: Oblicza wyrażenie matematyczne, konwertując je na RPN.
2. Klasy `Bin`, `Oct`, `Hex`:
    - `FloatToBin`, `FloatToOct`, `FloatToHex`: Konwersje liczb na odpowiednie systemy liczbowe.
    - `ExpBinToDec`, `ExpOctToDec`, `ExpHexToDec`: Konwersje wyrażeń z systemów liczbowych na system dziesiętny.

## Opis wykonanych testów
Przeprowadzono testy jednostkowe z wykorzystaniem biblioteki GTest, obejmujące:
- Metody konwersji liczb i wyrażeń w klasach `Bin`, `Oct`, `Hex`.
- Metody `applyOperation`, `precedence`, `Compute` w klasie `Calculator`.

## Podręcznik użytkownika
### Budowanie aplikacji z MFC
1. Utwórz folder `build` w katalogu projektu.
2. W wierszu poleceń (CMD) przejdź do katalogu `build`.
3. Wykonaj polecenie `cmake ..` w celu wygenerowania pliku `Calculator.sln`.
4. Otwórz plik `Calculator.sln` w Visual Studio.
5. Uruchom kompilację projektu w Visual Studio.
6. Po zakończeniu kompilacji powstanie plik wykonywalny `Calculator.exe`.

### Budowanie aplikacji z Qt
1. Utwórz folder `build` w katalogu projektu.
2. W wierszu poleceń (CMD) przejdź do katalogu `build`.
3. Wykonaj polecenie `cmake -G "MinGW Makefiles" ..`.
4. Wykonaj polecenie `mingw32-make` w celu skompilowania pliku `Calculator.exe`.

## Bibliografia
- "Introduction to Programming with C++ for Engineers" by Bogusław Cyganek
- [Qt Documentation](https://doc.qt.io/qt-6/cmake-get-started.html#building-a-c-gui-application)
- [Wikipedia: Shunting Yard Algorithm](https://en.wikipedia.org/wiki/Shunting_yard_algorithm)
- [Wikipedia: Reverse Polish Notation](https://en.wikipedia.org/wiki/Reverse_Polish_notation)
