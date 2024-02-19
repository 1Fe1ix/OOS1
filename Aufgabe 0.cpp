/*
Thema:
Ein-/Ausgabe, Schleifen, Arrays

Ihre Aufgabe:

Schreiben Sie ein Programm, das den Nutzer fragt, wie viele ganze Zahlen eingelesen werden sollen (maximal 10). 
Lesen Sie dann die gewünschte Anzahl von ganzen Zahlen in ein Array ein. Geben Sie alle Zahlen im Array sowie deren Durchschnitt aus.
Wenn 3 Zahlen eingegeben werden sollen und die Zahlen 1, 3 und 6 eingegeben werden, muss die Ausgabe folgendermaßen aussehen:

Anzahl eingeben:
Zahl eingeben:
Zahl eingeben:
Zahl eingeben:
Zahl[0]: 1
Zahl[1]: 3
Zahl[2]: 6
Durchschnitt: 3.33333

************************************************************************************************************************************************************/
#include <iostream>
#include <array>

int main()
{

    //Array Deklariert 
    std::array<int,10>arr;

    //Variablen Deklariert & Inizialisiert
    int Max = 0;
    int Gesamtzahl = 0;
    float Durchschnitt = 0;


    // Befehl zur eingbe wie viele Indexplätze des Arrays benötigt werden
    std::cout << "Anzahl eingeben:\n";
    std::cin >> Max;

    //Einlesen der Zahlen, Begrenzt auf vorherige angabe oder Max. 10
    //danach Fehler weil überlauf
    for (int z = 0; z < Max ;z++)
    {
        std::cout << "Zahl eingeben:\n";
        std::cin >> arr[z];
    }

    //Zusmmenrechnen der Zahlen im Array
    for (int z = 0; z < Max; z++)
    {
        Gesamtzahl += arr[z];
    }

    //Berechnun des Durchschnitts sich ergebende Gesamtzahl
    //aus der Addition der einzelen Werte aus dem Array 
    //Geteilt durch die anzahl der INdex/Speicherplätze
    Durchschnitt = static_cast <float> (Gesamtzahl) / static_cast <float> (Max);

    //Ausgabe des jeweiligen Platz im Array 
    //und Wert der darin gespeicherten Variable
    for (int z = 0; z < Max; z++)
    {
       std::cout <<"Zahl["<<z<<"]: " << arr[z]<<"\n";
    }
    
    //Ausgabe des Durchschnitts
    std::cout << "Durchschnitt: "  << Durchschnitt <<"\n";

    return 0;
}

