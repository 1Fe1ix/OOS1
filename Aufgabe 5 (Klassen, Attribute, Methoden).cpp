/* Aufgabe 5 (Klassen, Attribute, Methoden).cpp : Diese Datei enthält die Funktion "main".Hier beginnt und endet die Ausführung des Programms.

Themen:

Klassen, Attribute, Methoden
Ihre Aufgabe:

Ergänzen Sie das Programmgerippe um die Klasse Punkt mit den Koordinaten x und y vom Typ double. 
Schreiben sie für die Klasse Punkt die Methode print() sowie getter- und setter-Methoden für die Koordinaten x und y, 
sodass das Hauptprogramm folgende Ausgabe erzeugt:

print-Methode:
X = 1
Y = 10
X ohne print(): 5
Y ohne print(): 10


!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Funktioniert VS macht nur Probleme!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
****************************************************************************************************************************************************/
#include<iostream>
using namespace std;

// hier die Klasse Punkt implementieren
class Point {
    //Definitionen der Var in Priv.
    double X;
    double Y;


public:
    
    // zugehörige Funtionen zu Var in Priv.

    //set weist var werte zu 
    //get gibt werte an fragende zurück
    //print gibt werte aus 
        void print()
        {
            cout << "print-Methode:" << endl;
            cout << "X = " << get_x() << endl;
            cout << "Y = " << get_y() << endl;
        }

        double get_x()
        {
            return X;
        }
        double get_y()
        {
            return Y;
        }
        void set_x(int var)
        {
             X = var;
           
        }
    
        void set_y(int var)
        {
            Y = var;
        }
};

int main(int argc, char* argv[]) {
    Point p;

    //Aufruf classe wird erstellt wert in set zu x gewiesen
    p.set_x(1);
    //Aufruf classe wird erstellt wert in set zu y gewiesen
    p.set_y(10);
    //funktion print aufgerufen 
    p.print();
    //Erneuter Aufruf classe wird erstellt wert in set zu x gewiesen
    p.set_x(5);
    cout << "X ohne print(): " << p.get_x() << endl;
    cout << "Y ohne print(): " << p.get_y() << endl;
    return 0;
}

