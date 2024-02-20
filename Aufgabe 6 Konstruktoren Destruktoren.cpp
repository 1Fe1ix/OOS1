/* Aufgabe 6 Konstruktoren Destruktoren.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.

Themen:

Initialisierung von Objekten, Konstruktoren, Destruktoren
Ihre Aufgabe:

Schreiben Sie eine Klasse 'Student' mit den Attributen '_name' und '_first_name' vom Typ String.    
Schützen Sie die Attribute gegen Zugriff von außen. 
Die folgenden Methoden implementieren sie außerhalb der Klasse: 
Die Klasse soll einen parametrisierten Konstruktor haben, 
der Name und Vorname entgegennimmt und die beiden Attribute '_name' und '_first_name' entsprechend belegt. 
Verwenden Sie hierzu keine Initialisierungsliste. Schreiben sie get-Methoden für beide Attribute und einen Destruktor. 
Schreiben Sie zwei print-Methoden, beide ohne Rückgabewert. Eine der beiden Methoden nimmt eine boolsche Variable entgegen, 
mit der gesteuert werden kann, ob am Ende der Zeile ein Zeilenumbruch erfolgen soll oder nicht. 
In der anderen Methode erfolgt immer ein Zeilenumbruch.
----------------------------------------------------------------------------------------------------------------------------------------------------------


Schreiben Sie eine Klasse 'Employee', ebenfalls mit den Attributen '_name' und '_first_name' vom Typ String. 
Schützen Sie auch diese Attribute gegen einen Zugriff von außen. Die folgenden Methoden implementieren sie innerhalb der Klasse: 
Die Klasse soll einen parametrisierten Konstruktor haben, 
der Name und Vorname entgegennimmt und die beiden Attribute '_name' und '_first_name' entsprechend belegt. 
Verwenden Sie hierzu die Initialisierungsliste. Die Klasse soll einen Standardkonstruktor haben, 
die den Konstruktoraufruf an den parametrisierten Konstruktor delegiert. 
Nutzen Sie auch hier die Initialisierungsliste und setzen sie die Werte 'Mustermann' für Name und 'Erika' für Vorname. 

Schreiben Sie zusätzlich einen Konvertierkonstruktor, 
der einen Studenten entgegenimmt und die enthaltenen Daten zur Initialisierung von Name und Vorname verwendet. 
Schreiben sie einen Destruktor. Schreiben Sie auch für diese Klasse zwei print-Methoden, ebenfalls beide ohne Rückgabewert. 
Eine der beiden Methoden nimmt eine boolsche Variable entgegen, mit der gesteuert werden kann, 
ob am Ende der Zeile ein Zeilenumbruch erfolgen soll oder nicht. In der anderen Methode erfolgt immer ein Zeilenumbruch.

Die Methoden der beiden Klassen sollen jeweils eine Ausgabe enthalten, die zur Ausgabe der vorgegebenen main-Methode passt. 

Die Ausgabe ist unten angegeben.


Ausgabe:

Parametrisierter Konstruktor Student: Max Mustermann
Konvertierungskonstruktor Employee: Max Mustermann
Parametrisierter Konstruktor Employee: Erika Mustermann
Standardkonstruktor Employee: Erika Mustermann
print() ohne Parameter; Student: Max Mustermann
print() mit Parameter; Student: Max Mustermann
print() ohne Parameter; Mitarbeiter: Max Mustermann
print() ohne Parameter; Mitarbeiter: Erika Mustermann
Block wird betreten
Parametrisierter Konstruktor Student: Markus Mustermann
print() mit Parameter; Student: Markus Mustermann
Block wurde verlassen
Destruktor Student: Markus Mustermann
Destruktor Employee: Erika Mustermann
Destruktor Employee: Max Mustermann
Destruktor Student: Max Mustermann
*****************************************************************************************************************************************************************/

#include <string>
#include <iostream>
using namespace std;

// Klasse Student

class Student
{ 
    string _name;
    string _first_name; 
public:
    Student(string, string);
    string get_name();
    string get_first_name();
    void print();
    void print(bool);
    ~Student() {cout << "Destruktor Student: "<<_first_name<< " " << _name<< endl;}
};

//Legt Objekt Student an 
Student::Student(string name, string first_name)
{
    _name = name;
    _first_name = first_name;
    cout << "Parametrisierter Konstruktor Student: " << _first_name << " " << _name << endl;
}
// Übergeben die Var an Employee Konvertierkonstruktor
string Student::get_name(){
    return _name;
}
string Student::get_first_name(){
    return _first_name;
}
void Student::print()
{
    cout << "print() ohne Parameter; Student: " << _first_name << " " << _name <<endl;
}
void Student::print(bool Zeilenumbruch)
{
    if (Zeilenumbruch == true)
    cout << "print() mit Parameter; Student: " << _first_name << " " << _name << endl;
    else
    cout << "print() mit Parameter; Student: " << _first_name << " " << _name;
}

class Employee
{
    // Class Member / Attribute
    string _name;
    string _first_name;
public:

    //Konvertierkonstruktor mit call by ref. auf objekt Student 
    Employee(Student& stud_mustermann)
    {
        //Übergabe von name auf name
        _name=stud_mustermann.get_name();
        _first_name =stud_mustermann.get_first_name();
        std::cout << "Konvertierungskonstruktor Employee: " << _first_name <<" "<< _name << endl;
    }

    //Std. Konstruktor mit delegation an Pram. Konstruktor
    Employee()
    : Employee("Erika","Mustermann") {
        std::cout << "Standardkonstruktor Employee: " << _first_name << " " << _name << endl;
    }

    //Pramkonstruktor der Werte in Var mit Initialisierungsliste 
    Employee(string first_name, string name )
        :_name(name),_first_name(first_name){
        std::cout << "Parametrisierter Konstruktor Employee: " << _first_name << " " << _name << endl;
    }



    void print()
    {
        std::cout << "print() ohne Parameter; Mitarbeiter: "<< _first_name << " " << _name << std::endl;
    }
    void print(bool Zeilenumbruch)
    {
        if (Zeilenumbruch == true)
            std::cout << "print() mit Parameter; Mitarbeiter: " << _first_name << " " << _name << endl;
        else
            std::cout << "print() mit Parameter; Mitarbeiter: " << _first_name << " " << _name;
    }
    ~Employee() { cout << "Destruktor Employee: "<< _first_name<< " " << _name << endl; }
};

int main(int argc, char* argv[])
{
    //Student stud_mustermann deklariert ein Objekt
    //Student(...) inizialisiert diese Objekt 
    Student stud_mustermann = Student("Mustermann", "Max");
    //Deklaration Employee
    //Employee(...) bekommt objekt stud_mustermann und Konvertiert dieses in string
    //belegt die zwei Atribute in Employee dann mit den 
    //selben werten wie die Atribute in student 
    Employee empl_mustermann = Employee(stud_mustermann);
    //Deklaration neues Objekt mit_default inizialisierung
    //std. Employee Erika Mustermann
    Employee mit_default = Employee();
    //aufrufe für prints 
    stud_mustermann.print();       //Max M. standart Print
    stud_mustermann.print(true);   //Max M. mit bool
    empl_mustermann.print();       //Max M. Empl
    mit_default.print();           //Erika M.
    
    
    //Anker für Liste
    Student* p_stud_mustermann = nullptr;
    cout << "Block wird betreten" << endl;
    {
        p_stud_mustermann = new Student("Mustermann", "Markus");
        p_stud_mustermann->print(true);
    }
    cout << "Block wurde verlassen" << endl;
    delete p_stud_mustermann;
    return 0;
}