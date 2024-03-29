/*
Themen:
Komposition, Vektoren

Ihre Aufgabe:
Implementieren Sie die Klassen Point und Polygonline (Polygonlinie, Linienzug). 
Die Objekte der Klasse Polygonline repräsentiert einen Linienzug. 
Ein Linienzug ist durch eine Folge von Punkten defininiert. 
Die Folge von Punkten wird in Polygonline als ein vector von Punkten realisiert, 
da wir nicht wissen, wieviele Punkte die Linie haben wird. 
Implementieren Sie die vorgegebenen Konstruktoren und Methoden.

Die Ausgabe des Hauptprogrammes soll folgendermaßen aussehen:

Ausgabe 1:
||
|(3, 3)|
Ausgabe 2:
|(1, 1) - (2, 2)|
|(3, 3) - (4, 4) - (5, 5)|
Ausgabe 3:
(2.5, 2.5)
|(1, 1) - (2, 2)|
|(3, 3) - (4, 4) - (5, 5)|
Ausgabe 4:
|(1, 1) - (2, 2) - (3, 3) - (4, 4) - (5, 5)|
|(3, 3) - (4, 4) - (5, 5)|
Ausgabe 5:
|(1, 1.5) - (2, 2.5) - (3, 3.5) - (4, 4.5) - (5, 5.5)|
|(3, 3) - (4, 4) - (5, 5)|
****************************************************************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Point
{
	double _x;
	double _y;
public:
	// Konstruktor mit Parametern
	Point(double x = 0.0, double y = 0.0);
	// Verschiebt einen Punkt
	void move(double dx, double dy);
	// gibt den Punkt auf der Konsole aus
	void print(bool nl = true);
};

// Implementierung Konstruktor
Point::Point(double x , double y) :_x(x), _y(y){}


// Implementierung Methoden
void Point :: move(double dx, double dy) 
{
	 _x += dx;
	 _y += dy;
}

void Point::print(bool nl )
{
		cout << "(" << _x << ", " << _y << ")";
		if (nl)  { cout << endl; }		
}


class Polygonline {
	vector<Point> _points;
public:
	// Konstruktor
	Polygonline();
	// Konstruktor mit Parameter
	Polygonline(Point& p);
	// gibt die Elemente des Polygons auf der Konsole aus
	void print(bool nl = true);
	// Hängt einen Punkt hinten an
	Polygonline& add_point(Point p);
	// Hängt einen zusätzlichen Polygon hinten an
	void append_polygonline(Polygonline& pl);
	// Verschiebt den gesamten Polygon
	void move(double dx, double dy);
};


// Implementierung Konstruktor
Polygonline::Polygonline() {}
Polygonline::Polygonline(Point& p) : _points({p}) {}
// Implementierung Methoden

//Plygonline& = Rückgabetyp -> DurcReferenz wird vermieden dass, das Obj. kopiert wird nur Refernz wird übergeben 
Polygonline& Polygonline :: add_point(Point p)
{
	 _points.push_back(p);
	 return *this;
}

void Polygonline::append_polygonline(Polygonline& pl)
{
	for (Point punkt : pl._points)
	{
		_points.push_back(punkt);
	}

}

void Polygonline::move(double dx, double dy)
{
	Point p;

	for (Point& p : _points) 
	{
		p.move(dx, dy);
	}
}




void Polygonline::print(bool nl) {
	cout << "|";

	for (vector<Point>::size_type i = 0; i < _points.size(); ++i) {
		_points[i].print(false);
		if (i < _points.size() - 1)
		{
			cout << " - ";
		}
	}

	cout << "|";

	if (nl)
	{
		cout << endl;
	}
}



int main(int argc, char* argv[])
{
	Point p1(1, 1), p2(2, 2), p3(3, 3), p4(4, 4), p5(5, 5);
	Polygonline l1;
	Polygonline l2(p3);
	cout << "Ausgabe 1:" << endl;
	l1.print();
	l2.print();
	l1.add_point(p1).add_point(p2);
	l2.add_point(p4).add_point(p5);
	cout << "Ausgabe 2:" << endl;
	l1.print();
	l2.print();
	p2.move(0.5, 0.5);
	cout << "Ausgabe 3:" << endl;
	p2.print();
	l1.print();
	l2.print();
	l1.append_polygonline(l2);
	cout << "Ausgabe 4:" << endl;
	l1.print();
	l2.print();
	l1.move(0, 0.5);
	cout << "Ausgabe 5:" << endl;
	l1.print();
	l2.print();
	return 0;
}
































