/*
a) Leiten Sie von der Standardexceptionklasse exception eine eigene Klasse MyException ab.

Schreiben Sie einen parametrisierten Konstruktor, 
der in seperaten Parametern den Dateinamen und die Zeilennummer entegegennimmt, in der eine Ausnahme (Exception) auftritt. 
Zusätzlich soll ein dritter Parameter übergeben werden können, der den Namen bzw. eine Beschreibung der Ausnahme enthält. 
(Um die Zeile und den Dateinamen zu ermitteln sollen die Präprozessormakros LINE und FILE im Aufruf des Konstruktors genutzt werden.)

Überschreiben sie zusätzlich die Methode what() der Standardexception, 
die eine Beschreibung des Fehlers - bestehend aus der Angabe der Datei, der Zeile und des Namens des Fehlers - zurückgibt.

b) Ergänzen Sie den Programmcode an den gekennzeichneten Stellen (//HIER).
**********************************************************************************************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <exception>

using namespace std;
// Eigene Exceptionklasse "MyException"
// abgeleitet von Exception
//------------Es existiert eine Standard Klasse "exception"-------------
class MyException : public exception // HIER 
{
    // HIER
    
public:
    string Dateiname;
    int Zeilennummer;
    string Ausnahme_Name;

    MyException(string Datei, int Zeile, string Ausnahme) :Dateiname(Datei), Zeilennummer(Zeile), Ausnahme_Name(Ausnahme) {}

    virtual const char* what() const noexcept
    {
        return Ausnahme_Name.c_str();
    }
};

// Eigene Exceptionklasse "ElefantMeetsMouse"
// abgeleitet von MyException
class ElefantMeetsMouse : public MyException // HIER 
{
    // HIER
public:

    ElefantMeetsMouse (string Datei,int Zeile,string Ausnahme) 
    : MyException(Datei, Zeile, Ausnahme) {}
};

// Klasse der Tiere
class Animal
{
    // Name des Tiers
    string _name;

public:
    
    
    // Konstruktor
    Animal()
    {
        //Wird hier der name des Tiers eingegeben um dann wieder an ein unterprogramm weitergegeben zu werden ?
        cout << "Bitte Namen des Tieres eingeben: ";
        cin >> _name;
    };
    // virtuelle print-Funktion
    void print(bool nl) const
    {
        cout << _name;
        if (nl)
        {
            cout << endl;
        }
    }
    virtual Animal* clone() const = 0;   //Virtuelle Methode
};

// Klasse "Elefant"
// abgeleitet von Animal
class Elefant : public Animal// HIER 
{
public:
    // HIER
    //Allociert speicherplatz für Objekt Elefant
    
    Elefant() : Animal()
    {

    }

    Elefant* clone() const
    {
        return  new Elefant(*this);
    }

    //Konstruktor
    
};

// Klasse "Tiger"
// abgeleitet von Animal
class Tiger : public Animal // HIER 
{
public:
    // HIER
    Tiger* clone() const
    {
        return  new Tiger(*this);
    }

    //Konstruktor
    Tiger() : Animal() {}
};

// Klasse "Mouse"
// abgeleitet von Animal
class Mouse : public Animal // HIER 
{
public:
    // HIER
    Mouse* clone() const
    {
        return  new Mouse(*this);
    }

    //Konstruktor
    Mouse() : Animal() {}
};

class Zoo
{
    // Name des Zoos
    string _name;
    // Die Tiere werden in einem Vektor gespeichert
    vector<Animal*> animals;

public:
    // Konstruktor
    Zoo()
    {   // Name zuweisen


        cout << "Bitte Name des Zoos eingeben: ";
        cin >> _name;


        // Wenn der String kuerzer als 4 Zeichen ist,

        if (_name.size() < 4)
        {





            throw MyException(__FILE__,__LINE__, "Fehler 'Zooname zu kurz' ");
        }
        else 
        {
            // dann MyException werfen
            // Nutzen Sie die Praeprozessormakros __LINE__ und __FILE__
            // HIER
            // Ansonsten, den 5. Buchstaben des Namens gross machen
            _name.at(4) = toupper(_name.at(4));
        }
    }

    // Ein Tier dem Zoo hinzufuegen
    void add_animal(const Animal& animal)
    {
        // Wenn ein Elefant nach einer Maus eingefuegt wird, oder anders herum dann Ausnahme werfen
        // Nutzen Sie die Praeprozessormakros __LINE__ und __FILE__
        if (animals.size() > 0) {
            if ((typeid(*animals[animals.size() - 1]) == typeid(Elefant) && typeid(animal) == typeid(Mouse)) || (typeid(*animals[animals.size() - 1]) == typeid(Mouse) && typeid(animal) == typeid(Elefant))) 
            { throw ElefantMeetsMouse(__FILE__, __LINE__, "Fehler 'Elefant trifft auf Maus' ");
            }
        }
        animals.push_back(animal.clone());




        // sonst Tier hinzufuegen
        // HIER
    }
    // Alle Zootiere ausgeben
    void print() const
    {
        // HIER
        for (const auto& animal : animals)        //for (string animal : animals)
        {
            animal->print(true);          
        }
    }
};

int main(int argc, char* argv[])
{
    char choice;
    string name;

    // Ausnahmepruefung aktivieren
    // HIER
    
    
    try 
    {
        Zoo zoo;
    do
    {
        
            cout << endl<< "Bitte Tierart auswaehlen:" << endl;
            cout << "1 = Elefant" << endl;
            cout << "2 = Tiger" << endl;
            cout << "3 = Maus" << endl;
            cout << "e = Ende mit Eingabe" << endl;
            cout << "Eingabe: ";
            cin >> choice;
            switch (choice)
            {
            case '1':
            {
                Elefant elefant = Elefant();   //legt Objekt vom Typ Elefant an 
                zoo.add_animal(elefant);       //zoo->add_animal
                break;
            }
            case '2':
            {
                Tiger tiger = Tiger();
                zoo.add_animal(tiger);
                break;
            }
            case '3':
            {
                Mouse mouse = Mouse();
                zoo.add_animal(mouse);
                break;
            }
            case 'e':
                break;
            default:
                // Einen String als Ausnahme werfen
                // HIER
                
                throw string("Fehlerhafte Eingabe!");
            }

            cout << endl;
            zoo.print();
        } while (choice != 'e');
    }
    // Ausnahmen auffangen
    // Speziellste Ausnahme auffangen und ausgeben
    catch (ElefantMeetsMouse& e)
    {
        cout << e.what() << "aufgetreten in Datei " << e.Dateiname << ", Zeile: " << e.Zeilennummer << "." << endl;
    }
    
    // MyException auffangen und ausgeben
    // HIER
    catch (MyException& e)
    {
        cout << e.what() << "aufgetreten in Datei " << e.Dateiname << ", Zeile: " << e.Zeilennummer << "." << endl;
    }

    // Alle anderen Standardausnahmen auffangen und ausgeben
    // HIER
    catch (exception& e)
    {
        cout <<"Standardausnahme: " << e.what() ;
    }

    // Alle Strings auffangen und ausgeben
    // HIER
    catch (string &e)
    { 
        cout << e;
    }

    // Alle anderen Ausnahmen auffangen
    // HIER
    catch (...)
    {
        cout <<"Alles andere";
    }

return 0;
}

