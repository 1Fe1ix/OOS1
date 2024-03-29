/*
Themen:

Templates, Bubble Sort

Ihre Aufgabe:

Implementieren Sie eine generische Sortierfunktion auf Basis des Bubble-Sort Algorithmus. 
Die Funktion soll dabei ein Array als Eingabeparameter enthalten und das sortierte Array zurückgeben.

Der Bubble-Sort Algorithmus durchläuft ein Feld / Array in einer Schleife und vergleicht zwei benachbarte Elemente. 
Sind diese falsch angeordnet, so werden sie vertauscht. Ist man am Ende des Feldes / des Arrays angelangt, 
so beginnt man wieder von vorne. Dieser Vorgang wird so lange wiederholt bis das Feld / Array ein Mal durchlaufen wird, 
ohne dabei ein einzelnes Element auszutauschen.
**********************************************************************************************************************************/
#include <array>
#include <iostream>
using namespace std;

const unsigned int length = 10;

// hier die Funktion 'sort' implementieren

template<typename T>
T sort(T int_container)
{
    
    for (int n = length ; n > 1; --n) 
    {
        for (int i = 0; i < n - 1; ++i) 
        {
            if (int_container[i] > int_container[i + 1]) 
            {
                int tmp = 0;
                tmp =int_container[i];
                int_container[i] = int_container[i+1];
                int_container[i+1] = tmp;
            } 
        } 
    }

    return int_container;
}

int main(int argc, char* argv[])
{
    array<int, length> int_container = { 10, 2, 7, 5, 8, 3, 4, 1, 9, 6 };
    array<int, length> sorted_int_container = sort(int_container);

  
    for (size_t i = 0; i < sorted_int_container.size(); i++) {
        cout << i << ": " << sorted_int_container[i] << endl;
    }

    array<char, length> char_container = { 'j', 'm', 'e', 't', 'k', 'o', 'p', 's', 'a', 'f' };
    array<char, length> sorted_char_container = sort(char_container);

    for (size_t i = 0; i < sorted_char_container.size(); i++) {
        cout << i << ": " << sorted_char_container[i] << endl;
    }
}

