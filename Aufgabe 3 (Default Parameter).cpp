/*  Aufgabe 3 (Default Parameter).cpp
    Ergänzen Sie das Programmgerippe um eine Funktion print_rectangle, die zwei Parameter entgegennimmt und ein Rechteck auf der Konsole ausgibt. 
    Die Kantenlängen des Rechtecks entsprechen den jeweils übergebenen Parametern. 
    Wird nur ein Parameter übergeben, so soll ein Quadrat ausgegeben werden, dessen Kantenlängen dem übergebenen Parameter entspricht.

    Nutzen sie kein Überladen. Verwenden Sie für die Lösung geeignete Defaultwerte für Parameter.

    Der Aufruf der print_rectangle funtion mit den Werten 2 und 5 führt z.B. zu folgender Ausgabe:

    X X
    X X 
    X X
    X X 
    X X

    Der Aufruf der print_rectangle funtion mit dem Wert 4 führt z.B. zu folgender Ausgabe:

    X X X X
    X X X X
    X X X X
    X X X X

*****************************************************************************************************************************************************/ 
#include <iostream>






void print_rectangle(int x, int y = 0)  //Überlegung warum sollte man eine Seitenlänge von 0 haben es würde keine fläche existieren? 
{
    if (y == 0)
    {
        for (int i = 0;i < x;i++)//Saule
        {
            for (int j = 0;j < x;j++)//Reihe
            {
                std::cout <<"X ";//Print für Reihe
            }
            std::cout << std::endl;//Absatz für Zeile
        }
    }
    else
    {
        for (int i = 0; i < y; i++)//Saule
        {
            for (int j = 0; j < x; j++)//Reihe
            {
                std::cout << "X ";
            }
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;// Absatz für abstand zum nächsten Quadrat
}


int main(int argc, char* argv[])
{
    std::cout << "x = 2, y = 5: " << std::endl;
    print_rectangle(2, 5);

    std::cout << "x = 3, y = 3: " << std::endl;
    print_rectangle(3, 3);

    std::cout << "x = 4: " << std::endl;
    print_rectangle(4);

    return 0;
};



