/* Aufgabe 1; Ein - und Ausgabe, Aufzählungstypen, Schleifen, bedingte Abfragen, Casts


Ihre Aufgabe:

Das Spiel Schere-Stein-Papier, kann auch am Computer gespielt werden.
Schreiben Sie ein Programm, so dass Sie mit dem Computer Stein-Schere- Papier spielen können.
Nutzen Sie das bereitgestellte Programmgerippe.


Die Ausgabe des Programms soll folgendermaßen aussehen:

Der Computer hat seine Wahl getroffen.
Name des Spielers:
[Eingabe: z.B. Max]
Bitte Objektwahl eingeben (1 = Stein, 2 = Schere, 3 = Papier):
[Eingabe: z.b. 1]
Computer hat das Objekt Schere gewaehlt.
Max hat das Objekt Stein gewaehlt.
Max hat gewonnen!

*************************************************************************************************************************************************************/

#include <string>
#include <ctime>
#include <iostream>

#define PC_GEWINNT 0//"PLAYER_ONE_WINS"
#define SPIELER_GEWINNT 1//"PLAYER_TWO_WINS"
#define UNENTSCHIEDEN 2//"DRAW"

using namespace std;

// Aufzählungstyp für wählbare Objekte
// STEIN - 0, SCHERE - 1, PAPIER - 2
enum class Object
{
    ROCK,
    SCISSORS,
    PAPER
};

// Aufzählungstyp für mögliche Spielausgänge
enum class Result
{
    PLAYER_ONE_WINS,
    PLAYER_TWO_WINS,
    DRAW
};

// Struktur für einen Spieler bestehend aus Name und Wahl des Spielers
struct Player
{
    string name;
    Object choice;
};

// Name des Spielers eingeben
string insert_name()
{
        // HIER programmieren:
        // Den Namen des Spielers von der Konsole einlesen und zurückgeben
        // Tip: für das Einlesen eines Strings gibt es eine bestimmte Funktion, 
        //siehe auch Vorlesung Folie "Eine Zeile als String einlesen"

        //Deklariert String
    string Name;

    //Print der Ausgabe
    cout << "Name des Spielers: ";

    //Liest die Eingabe
    cin >> Name;

    //Gibt die Variable zurück so das sie in den Struct 
    //aufgenommen wird(in Main)
    return Name;

}


//Frage???????
Object determine_choice(string choice)
{
    if (choice.compare("CoderunnerTestValueROCK") == 0)
    {
        return Object::ROCK;
    }
    else if (choice.compare("CoderunnerTestValueSCISSORS") == 0)
    {
        return Object::SCISSORS;
    }
    else if (choice.compare("CoderunnerTestValuePAPER") == 0)
    {
        return Object::PAPER;
    }
    else
    {
        // Den Computer zufällig waehlen lassen.
        // HIER beantworten Sie folgende Fragen:
        

        // Wie funktioniert die funktion rand?
        // rand generiert "Zufallszahl" zw. 0 und
        // RAND_MAX, die auf dem Seed von srand basiert 
        
        // Was bewirkt die funktion srand?
        // srand() initialisiert Seed = Startwert 
        // für den rand() Zufallsgenerator
        
        // Warum wird hier die Zeit (time) als Eingabe für die Funktion srand verwendet?
        // time(); nimmt aktuelle systemzeit, 
        // praktisch da die zeit immer voranschreitet 
        // und so die wiederholungsgefahr vermieden wird
         
       
        // Warum wird hier modulo 3 verwendet?
        // Weil rand() % 3 durch die teilung 
        // nur die Rest-Ergebnise 0/1/2 ermöglicht
        // Egal wie groß die Zahl wird da rand() nur 
        // Positive Ganzzahlen generiert
        // a%b = a-b*(a/b) bei div. wird rest abgeschnitten
        // so brechnet sich das erg. von Modulo

        srand(static_cast<int>(time(nullptr)));
        int choice = rand() % 3;
        return static_cast<Object>(choice);
    }
}

// Die Wahl von Stein etc. als String zurückgeben lassen
string get_name(Object object)
{

    // HIER programmieren:
    // Abhängig vom vorliegenden Object einen entsprechenden String zurückgeben.
    // z.B: Wenn Object dem Wert Object::ROCK entspricht, dann String "Stein" zurückgeben
    string choice;

    //Switch case das je nach übergebener classe
    //ROCK/PAPER/SCISSORS einen String zurückgibt
    switch (object)
    {
     //ist object = Object::ROCK so 
     //springt in diese case
     //return string an Aufruf
    case Object::ROCK: 
        return "Stein";
        break;

    case Object::SCISSORS:
        return "Schere";
        break;
    case Object::PAPER:
        return "Papier";
        break;
    }

    //Damit keine fehler von Moodle Compiler
    //nicht notwendig da immer eines der drei
    //cases ausgewählt wird keine mgl. für fehler
    return choice;
}

// Einen Text mit dem Namen des Spielers und seiner Wahl ausgeben
void print_choice(Player player)
{

    // HIER programmieren:
    // Auf der Konsole ausgeben, für welches Object sich der Spieler entschieden hat.
    // z.B.: "Computer hat das Object Schere gewählt"
    // TIP: Nutzen sie hierzu die Funktion get_name
    
    
    //if für zwei unterschiedliche Aufrufe in einer Fkt.
    if (player.name == "Compter")
    {
        //Print von Player1
        cout << "Computer hat das Objekt " << get_name(player.choice) << " gewählt\n";
    }
    else
    {
        //Print von Player2
        cout << "" << player.name << " hat das Objekt " << get_name(player.choice) << " gewählt\n";

    }
}

// Die Wahl des Spielers abfragen
Object chose()
{

    // HIER programmieren:
    // Die Wahl des Spielers von der Konsole einlesen und zurückgeben
    int Wahl = 0;
    do
    {
        cout << "Bitte Objektwahl eingeben (1 = Stein, 2 = Schere, 3 = Papier): ";
        cin >> Wahl;
    }
    // Stellen sie sicher, dass es sich um eine gültige Wahl handelt!
    //Fragt solange nach bis gültige wahl getroffen wird und wahl eine der drei
    //mgl. ist
    while (Wahl != 1 && Wahl != 2 && Wahl != 3);


    //Übergabe der mgl. der classes an Aufruf
    //je nach wahl des Spielers
    if (Wahl == 1)
    {
        return Object::ROCK;
    }
    else if (Wahl == 2)
    {
        return Object::SCISSORS;
    }
    else
    {
        return Object::PAPER;
    }
    // TIP: Nutzen Sie dazu eine geeignete Schleife. Siehe auch Vorlesung Folie "Annehmende Schleifenanweisungen – Do"

}

Result determine_result(Player player_1, Player player_2)
{
    // HIER programmieren:
    // Vergleichen Sie die gewählten Objekte, ermitteln sie das Spielergebnis und geben sie es zurück.
    // player_1 TIP: Wenn Sie für den Vergleich mit ganzene Zahlen _rechnen_ wollen, dann nutzen sie den static_cast, siehe auch Vorlesung Folie "Casts in C++: Static_cast"
    //Stein 0
    //Schere 1
    //Papier 2

    //Var Gewinner sortiert nach cases
    int Gewinner = static_cast<int>(player_1.choice) + static_cast<int>(player_2.choice);

    //Wenn die Wahl = ist direkt rückgabe von DRAW
    if (static_cast<int>(player_1.choice) == static_cast<int>(player_2.choice))
        return Result::DRAW;



    //Gewinner wird in cases sortiert class zurückgegeben
    switch (Gewinner)
    {
    case 1:
        if (static_cast<int>(player_1.choice) == 0)//= 0 so wird sortiert welcher spieler welches Objekt gewählt hat
        {
            return Result::PLAYER_ONE_WINS;
        }
        else
        {
            return Result::PLAYER_TWO_WINS;
        }
        break;

    case 3:
        if (static_cast<int>(player_1.choice) == 1)//= 1 so wird sortiert welcher spieler welches Objekt gewählt hat
        {
            return Result::PLAYER_ONE_WINS;
        }
        else
        {
            return Result::PLAYER_TWO_WINS;
        }
        break;

    case 2:
        if (static_cast<int>(player_1.choice) == 2)//= 2 so wird sortiert welcher spieler welches Objekt gewählt hat
        {
            return Result::PLAYER_ONE_WINS;
        }
        else
        {
            return Result::PLAYER_TWO_WINS;
        }
        break;

        // kein default kann zu problemen mit dem Compieler führen 
        //in VS aber nicht
        //es besteht keine mgl. das dieser Fall eintritt
        default:
        return Result::DRAW;
    }


}

void print_result(Player player_1, Player player_2)
{

    // HIER programmieren:
    // Ermitteln Sie zunächst das Spielergebnis. Nutzen sie dazu die Funktion determine_result.
    // Geben Sie anschließend auf der Konsole aus, wer gewonnen hat.
    // z.B: "Spieler Computer hat gewonnen" oder "Unentschieden"

    //Bekommt eine class Player1/Player2 gewinnt oder Unentschieden
    //wandelt sie in int Var um
    int Gewinner = static_cast<int>(determine_result(player_1, player_2));
    

    //Gewinner wird in cases überprüft 
    //und je nach Fall printbefehl
    switch (Gewinner)
    {
    case PC_GEWINNT:
        cout << "Spieler Computer hat gewonnen.\n";
        break;

    case SPIELER_GEWINNT:
        cout << "Spieler " << player_2.name << " hat gewonnen.\n";
        break;

    case UNENTSCHIEDEN:
        cout << "Unentschieden\n";
        break;


    }

}

int main(int argc, char* argv[])
{
    Player player_1, player_2;
    player_1.name = "Computer";
    player_2.name = insert_name();
    player_1.choice = determine_choice(player_2.name);
    cout << "Der Computer hat seine Wahl getroffen." << endl;
    player_2.choice = chose();
    print_choice(player_1);
    print_choice(player_2);
    print_result(player_1, player_2);

    return 0;
}

