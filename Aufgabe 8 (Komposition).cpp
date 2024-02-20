/*
Themen:

Komposition
Ihre Aufgabe:

Das Programm, das sie entwickeln werden, kann grafische Objekte (Punkte, Kreise, ...) als Objekte von Klassen darstellen. 
Sie können sich die Objekte als Datenrepräsentationen von grafischen Objekten in einem Zeichenprogramm vorstellen. 
Die grafischen Objekte sind definiert über Koordinaten und könnten (später) Eigenschaften haben wie z.B. eine Strichstärke und -art.

Sie sollen zwei Klassen definieren: Point und Circle.

(a) Die Klasse Point repräsentiert das geometrische Objekt Punkt.

(b) Die Klasse hat die Instanzvariablen '_x' und '_y' vom Typ double. 
Diese beiden Instanzvariablen repräsentieren die x- und y-Koordinaten eines Punktes.

(c) Die Klasse Circle repräsentiert einen Kreis.

(d) Sie hat die Instanzvariablen '_centre' vom Typ 'Point' und '_radius' vom Typ double. 
    Die Variable '_centre' steht also für den Mittelpunkt des Kreises.

(e) In beiden Klassen sollen die Instanzvariablen vor Zugriff von außerhalb der Klasse geschützt sein.

(f) Schreiben Sie für beide Klassen Konstruktoren mit geeigneten Defaultparametern.

(g) Schreiben sie get- und set-Methoden für alle Instanzvariablen.

(h) Die Instanzfunktion 'move(double dx, double dy)' verschiebt einen Punkt bzw. 
    einen Kreis um die Werte 'dx' und 'dy' in x- bzw. y-Richtung.

(i) Beide Klassen sollen eine Funktion 'print' besitzen, welche die Koordinaten eines Punktes bzw. 
    die Koordinaten des Mittelpunktes und den Radius eines Kreises auf dem Bildschirm ausgibt. 
    Die Funktion 'print' besitzt einen Parameter vom Typ 'bool', der steuert, 
    ob nach der Ausgabe ein Zeilenvorschub (endl) durchgeführt wird oder nicht. 
    Der Defaultwert für diesen Parameter soll 'true' sein. Die Ausgabe des gegebenen Hauptprogrammes ist unten angegeben:

    Ausgabe:

    Ausgabe 1:
    (0, 0)
    [(0, 0), 1]

    Ausgabe 2:
    (1.1, 2.2) == (1.1, 2.2)
    [(1.1, 2.2), 3.3]

    Ausgabe 3:
    (2.1, 3.2)
    [(3.1, 4.2), 3.3]
***********************************************************************************************************************************************/ 
#include <iostream>
using namespace std;

// Klasse Point und Circle implementieren
class Point
{
	double _x;
	double _y;
public:

	Point(double x = 0, double y = 0) 
	{
		_x = x;
		_y = y;
	}

	void set_x(double x);

	void set_y(double y);

	double get_x();
	
	double get_y();

	void move(double dx, double dy)
	{
		_x += dx;
		_y += dy;
	}


	void print(bool x = true)
	{
		if (x == true)
		{
			cout << "(" << _x << ", "<< _y <<")"<<endl;
		}
		else
		{
			cout << "(" << _x << ", " << _y << ")";
		}
	}
};


double Point::get_x()
{
	return _x;
}

double Point::get_y()
{
	return _y;
}

void Point::set_x(double x)
{
	_x = x;
}

void Point::set_y(double y)
{
	_y = y;
}


	class Circle
	{
		Point _centre;
		double _radius ;
	public:

		Circle(Point p,double radius = 1)
		{
			_centre = p;
			_radius = radius;
		}

		void set_centre(Point p)
		{
			_centre = p;
		}

		void set_radius(double radius)
		{
			_radius = radius;
		}

		void move(double dx, double dy)
		{

			//mit _center.get_x() wird der x wert der des objekts
			// von der typ point aufgerufen und übergeben 
			double x =_centre.get_x();
			double y = _centre.get_y();
			
			//Rechnung 
			double x_neu = x + dx;
			double y_neu = y + dy;


			//Mit _center.set_x(x_neu) wird der neue Wert
			// vom onjekt center mit der klasse Circle 
			//vom typ Point zurückgegeben 
			_centre.set_x(x_neu);
			_centre.set_y(y_neu);
		}

		void print(bool x = true )
		{
			if (x == true)
			{
				cout << "[(" <<_centre.get_x()<< ", "<< _centre.get_y()<<"), "<< _radius <<"]"<<endl;
			}
			else
			{
				cout << "[(" << _centre.get_x() << ", " << _centre.get_y() << "), " << _radius << "]";
			}
		}
	};




// Hauptprogramm
int main(int argc, char* argv[])
{
    // Erstellt objekt p von der Klasse Point
	Point p;
	// Erstellt objekt c von klasse circle
	Circle c(p);
	cout << "Ausgabe 1:" << endl;
	p.print();
	c.print();
	p.set_x(1.1);
	p.set_y(2.2);
	c.set_centre(p);
	c.set_radius(3.3);
	cout << "Ausgabe 2:" << endl;
	p.print(false);
	cout << " == (" << p.get_x() << ", " << p.get_y() << ")"
		<< endl;
	c.print();
	//Einfach weil zugriff direkt auf das objekt mit
	//basis datentyp
	p.move(1.0, 1.0);
	//Schwieriger weil zugriff auf objekt mit anderer 
	//Klasse als Datentyp
	c.move(2.0, 2.0);
	cout << "Ausgabe 3:" << endl;
	p.print();
	c.print();
	return 0;
}
