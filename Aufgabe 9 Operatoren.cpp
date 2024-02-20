/*
Themen:                 Operatoren


Ihre Aufgabe:

Implementieren Sie den Konstruktor und die Operatoren, die für die Klasse Datum angegeben sind. 
Sie können zur Vereinfachung davon ausgehen, dass ein Jahr 360 Tage und jeder Monat 30 Tage hat.

Das angegebene Hauptprogramm soll folgende Ausgabe erzeugen:

Ausgabe:

Die Aufgabe beginnt am 13.4.2023
Die Aufgabe endet am 20.4.2023
Ein Jahr und ein Monat nach Aufgabenbeginn ist der 13.5.2024
Drei Jahre und 5 Monate nach Aufgabenbeginn ist der 13.9.2026


***********************************************************************************************************************************/


#include<iostream>
using namespace std;

class Date {

    int _day, _month, _year;

public:
    Date(int = 0, int = 0, int = 0);
    Date operator+(int days);
    friend ostream& operator<<(ostream&, const Date&);
};

//Inizialisierung
Date::Date(int day, int month, int year)
{
        _day = day;
        _month = month;
        _year = year;
}

Date Date::operator+(int days)
{  

    int Tag = days + _day;
    int Jahr =0;
    int monat = 0;

    if (Tag > 30)
    {
        monat = Tag / 30;
        Tag = Tag% 30;
        
        Jahr = monat/12;

        if (Jahr >= 1)
        {            
            monat = monat-(12*Jahr);
        }
    }

    //Neue Variablen sonst wird erster reverenzwert überschrieben 
     int neu_day = Tag;
     int neu_month = _month + monat;
     int neu_year = _year + Jahr;

    //Rückgabe eines neuen Datums
    return Date(neu_day, neu_month, neu_year);
}




ostream& operator<<(ostream& os, const Date& Date)
{
    //Gibt Das datum als dd.mm.YYYY aus 
    return os << Date._day<<"."<< Date._month<<"."<< Date._year;
}



int main(int argc, char* argv[])
{
    Date begin_task = Date(13, 04, 2023);
    cout << "Die Aufgabe beginnt am " << begin_task << endl;
    Date end_task = begin_task + 7;
    cout << "Die Aufgabe endet am " << end_task << endl;
    Date one_year_and_one_month_later = begin_task + 390;
    cout << "Ein Jahr und ein Monat nach Aufgabenbeginn ist der " << one_year_and_one_month_later << endl;
    Date three_years_and_five_months_later = begin_task + 1230;
    cout << "Drei Jahre und 5 Monate nach Aufgabenbeginn ist der " << three_years_and_five_months_later << endl;
}