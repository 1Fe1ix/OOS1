/* Aufgabe 4 (Überladen von Funktionen).cpp : Diese Datei enthält die Funktion "main".Hier beginnt und endet die Ausführung des Programms.

Themen:

Überladen (von Funktionen)
Ihre Aufgabe:

Analysieren Sie das Programm und kommentieren Sie dann die minimale Anzahl von Funktionsdefinitionen aus, 
so dass Sie das Programm erfolgreich kompilieren können. Kommentieren Sie keine Zeile im Hauptprogramm aus. 
Sind mehrere Funktionen gleichwertig, so verwenden sie die erste Funktion und kommentieren die weiteren aus. 
Nennen Sie die Funktionen, die im Hauptprogramm aufgerufen werden, und erklären Sie Ihre Überlegungen.


Erst wenn Sie sich Gedanken gemacht haben, verifizieren Sie Ihre Überlegungen durch einen Programmdurchlauf.


WICHTIG: Lassen Sie nicht den Compiler die Arbeit machen, sondern überlegen Sie selbst, was auszukommentieren ist. 
In der Prüfung können Sie auch keinen Compiler nutzen!
*****************************************************************************************************************************************************/
#include <iostream>
using namespace std;


int function(int i_1) 
{
    cout << "Funktion  1: i_1=" << i_1 << endl;
    return 0;
}
/*void function(int i_1)
{
    cout << "Funktion  2: i_1=" << i_1 << endl;
}*/
//Würde auch gehen ist aber nicht die erste Funktion
/*char function(int i_1) Sele Fk. wie 1. aber rückgabe Char
{
    cout << "Funktion  3: i_1=" << i_1 << endl;
    return 'a';
}*/

/*int function(int& i_1)
{
    cout << "Funktion  4: i_1=" << i_1 << endl;
    return 1;
}*/

//rest hier
int function(int i_1, int i_2)
{
    cout << "Funktion  5: i_1=" << i_1 << " i_2=" << i_2 << endl;
    return 1;
}


//weil für function(c, i)
int function(char c_1, int i_1)
{
    cout << "Funktion  6: c_1=" << c_1 << " i_1=" << i_1 << endl;
    return 1;
}
// verwechslung mit Fkt 1 deshalb löschung 
/*int function(int i_1, int i_2 = 0)
{
    cout << "Funktion  7: i_1=" << i_1 << " i_2=" << i_2 << endl;
    return 1;
}*/


int function(double d_1, int i_1, char c_1 = 'a')
{
    cout << "Funktion  8: d_1=" << d_1 << " i_1=" << i_1 << " c_1=" << c_1 << endl;
    return 1;
}

int function(double d_1, double d_2 = 1.1, int i_1 = 0)
{
    cout << "Funktion  9: d_1=" << d_1 << " d_2=" << d_2 << " i_1=" << i_1 << endl;
    return 1;
}

/*
int function(double d_1, double d_2 = 1.1, char c_1)
{
    cout << "Funktion 10: d_1=" << d_1 << " d_2=" << d_2 << " c_1=" << c_1 << endl;
    return 1;
}*/

int function(char c_1, char c_2, int i_1 = 2, char c_3 = 'c')
{
    cout << "Funktion 11: c_1=" << c_1 << " c_2=" << c_2 << " i_1=" << i_1 << " c_3=" << c_3 << endl;
    return 1;
}
int main(int argc, char* argv[])
{
    int i = 1;
    char c = 'a';
    
    // Fkt. 1 müssen alle in einen Prototyp passen 
    // sonst mehrfach aufruf mgl. weil verwechslungsgefahr
    // char passt in int und umgekehrt 
    function(1);
    function(c);
    function(i);
    c = function('a');
    c = 'a';
    //Fkt. 4
    function(1, 2);
    //Fkt.5
    function(c, i);
    //Fkt.4
    function(1.0, 2.0);
    //Fkt. 10
    function(1.0, 2.0, 1);
    //Fkt. 9
    function(1.0, 1, 'a');
    //Fkt.5 beide
    function(1.0, 1);
    function(1.0, static_cast<double>(i));
    //Funktion 8
    function(c, c, i);
    //Fkt. 6/11
    function(c, i);
    return 0;
}

