/* Afg 19 Polymorph, abstract class.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
*
* Themen:

Polymorphismus, abstract classes
Ihre Aufgabe:

Schreiben Sie die abstrakte Basisklasse 'Meal' mit den Methoden 'add_topping' und 'prepare'.
Implementieren sie die Klassen Pizza und Burger,
sodass das vorhandene Programmfragment kompiliert werden und mittels der Zeile *[1] folgendes auf der Konsole ausgegeben werden kann:

Pizza Mista. Pizzaboden, belegt mit:
- Salami
- Pilzen
Pizza Hawaii. Pizzaboden, belegt mit:
- Schinken
- Ananas
Hamburger. Brötchen mit:
- Hackfleisch
Cheesburger. Brötchen mit:
- Hackfleisch
- Käse

Nutzen Sie die Vererbung von Instanzvariablen und Instanzmethoden entsprechend.
*************************************************************************************************************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <array>
using namespace std;




class Meal
{
protected:
    vector <string> topping;
    string Meal_Name;


public:

    //Konstruktor
    Meal(string Name) : Meal_Name(Name) {}


    virtual void add_topping(string top)
    {   //Vector mit werten füllen 
        topping.push_back(top);
    }
    //
    virtual void prepare() = 0;
    string getName() { return Meal_Name; }

};





class Pizza : public Meal
{

public:
    Pizza(string Name) :Meal(Name) {}

    void add_topping(string top)
    {
        Meal::add_topping(top);    //
    }

    void prepare()
    {
        cout << "Pizza " << Meal::getName() << "." << " Pizzaboden, belegt mit:" << endl;

        for (string top : topping) {
            cout << "- " << top << endl;
        }   
    }
};



class Burger : public Meal
{

public:
    Burger(string Name) :Meal(Name) {}

    //von Main zutat anadd_top in Burger übergeben
    void add_topping(string top)
    {
        //Zutat an Basisklasse add_topping
        Meal::add_topping(top);
    }
    void prepare()
    {
        cout << Meal::getName() << "." << " Brötchen mit:" << endl;

        for (string top : topping)
        {
            cout << "- " << top << endl;
        }

    }
};










int main(int argc, char* argv[])
{
    Pizza* mista = new Pizza("Mista");
    mista->add_topping("Salami");
    mista->add_topping("Pilzen");
    Meal* hawaii = new Pizza("Hawaii");
    hawaii->add_topping("Schinken");
    hawaii->add_topping("Ananas");
    Burger* hamburger = new Burger("Hamburger");
    hamburger->add_topping("Hackfleisch");
    Meal* cheesburger = new Burger("Cheesburger");
    cheesburger->add_topping("Hackfleisch");
    cheesburger->add_topping("Käse");
    array<Meal*, 4> menu = { mista, hawaii, hamburger, cheesburger };
    for (Meal* g : menu)
    {
        g->prepare(); //*[1]
    }
    return 0;



}


