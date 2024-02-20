/*
Themen:  Vererbung, Delegation von Konstruktoren und Methoden


Ihre Aufgabe:

Für eine Bibliotheksanwendung benötigen Sie verschiedene Benutzergruppen, 
Dozenten (Klasse 'Lecturer') und Studenten (Klasse 'Student'). 
Diese sollen von einer gemeinsamen Basisklasse 'Person' erben. 
Die Ausleihdauer soll für Dozenten 90 Tage und für Studenten 30 Tage betragen. 
Ergänzen Sie die Vererbungshierarchie und implementieren Sie die angegebenen Methoden. 
Verwenden Sie Delegation, um den Konstruktor der Basisklasse aufzurufen und nutzen 
Sie in den print()-Methoden von Dozent und Student die print()-Methode der Basisklasse.

Das angegebene Hauptprogramm soll folgende Ausgabe erzeugen:

Ausgabe:

smith, Matrikelnummer 12345678
Ausleihdauer: 30 Tage(e)
miller, Prüfernummer 98
Ausleihdauer: 90 Tage(e)

********************************************************************************************************************************/


#include <string>
#include <iostream>
using namespace std;

class Person {
	string _name;
	int _check_out_duration;
public:
	Person(string , int );
	int get_check_out_duration() const;
	void print() const;
};

Person::Person(string name, int check_out_duration = 0)
:_name(name), _check_out_duration(check_out_duration){}
//Inizialisierungsliste damit der aufruf über die Delegation
//erfolgen kann 

int Person::get_check_out_duration() const
{
	return _check_out_duration;
}

void Person::print() const
{
	cout << _name <<", ";
}

// Implmentierung des Konstruktors und der Methoden
//----------------------------------------------------------------------------------
class Lecturer : public Person
{
	int _examiner_id;
public:
	Lecturer(string , int );
	void print() const;
};

Lecturer::Lecturer(string name, int examiner_id)
	:Person(name, 90) 
{
	_examiner_id = examiner_id;
}

void Lecturer::print() const
{
	Person::print();
	cout <<"Prüfernummer "<<_examiner_id<<endl;
}
// Implmentierung des Konstruktors und der Methoden
//-----------------------------------------------------------------------------------
class Student : public Person
{
	int _matriculation_number;

public:
	Student(string name, int matriculation_number);
	void print() const;
};

Student::Student(string name, int matriculation_number)
	:Person(name, 30) //Delegation an Person 
	//es werden ihre Methoden zur belegung der Attribute genutzt
{
	//Belegen der einen Attribute
	_matriculation_number = matriculation_number;
}

void Student::print() const
{
	//Aufruf der Methode von Person als Student
	Person::print();
	//Ausgabe Matrikelnummer 
	cout << "Matrikelnummer " << _matriculation_number << endl;
}
// Implmentierung des Konstruktors und der Methoden

int main(int argc, char* argv[]) {
	Student smith = Student("smith", 12345678);
	Lecturer miller = Lecturer("miller", 98);
	smith.print();
	cout << "Ausleihdauer: " << smith.get_check_out_duration() << " Tage(e)" << endl;
	miller.print();
	cout << "Ausleihdauer: " << miller.get_check_out_duration() << " Tage(e)" << endl;
}


