/*
Themen:

Verkettete Liste, Pointer
Ihre Aufgabe:

Ergänzen Sie die Implementierung der Einfach verketteten Liste um die Implementierung der Funktionen: 
void add_new_tail_element(int id) void print_list()

Die Ausgabe des Hauptprogramms soll folgendermaßen aussehen:

1
2
9
10
1
9
10


****************************************************************************************************************************************************************/


#include <string>
#include <iostream>
using namespace std;


void print_list();

struct ListElement
{
    int id;
    ListElement* p_next;
};

ListElement* p_root = nullptr;

void add_new_head_element(int id)
{
    ListElement* p_new_element = new ListElement();
    p_new_element->id = id;
    //Das element vor dem Element das erzeugt wurde ist
    //der Anker 
    p_new_element->p_next = p_root;
    //Neues Element wird zu Anker 
    p_root = p_new_element;
}

void add_new_tail_element(int id)
{
    // HIER programmieren:
    // Neues listenElement erzeugen.
    // Ans Ende der Liste navigieren und neues listenElement anhängen.

    //Anlegen eines neuen Elements
    ListElement* new_tail_element = new ListElement();
    new_tail_element->id = id;
    new_tail_element->p_next= nullptr;


    //Wenn der Anker auf nullptr 
    //zeigt wird das new_tail zum Anker
    if (p_root == nullptr)
    {
        p_root = new_tail_element;
    }
    //Wenn nicht dann wird die Liste so lange durchlaufen 
    //bis das ende gefunden wurde und das letzet mit
    //Daten befüllte element ist new_tail
    else
    {
        //Kopie
        ListElement* current = p_root;

        //Durchlauf
        while (current->p_next != nullptr)
        {
            current = current->p_next;
        }

        //new_tail wird letztes Element
        current->p_next = new_tail_element;
    }
  
}

void delete_element(int id)
{
    ListElement* p_tmp = p_root;
    ListElement* p_predecessor = nullptr;

    while (p_tmp != nullptr && p_tmp->id != id)
    {
        //p_predecessor speichert element vor p_tmp
        //damit die Liste beim löschen nicht verloren geht
        p_predecessor = p_tmp;
        p_tmp = p_tmp->p_next;
    }
    //Wenn zu löschendes Element = nullptr dann 
    //ist nichts zu beachten
    if (p_tmp != nullptr)
    {
        if (p_tmp == p_root)
        {
            //Wenn zu löschendes Element = Anker 
            //dann wird einfach nur um eins verschoben 
            p_root = p_tmp->p_next;
        }
        else
        {
            //Das nechste Element von p_predecessor
            //wird das vor p_tmp so wird die 2 übersprungen 
            p_predecessor->p_next = p_tmp->p_next;
        }
    }

    //Element wird gelöscht
    delete p_tmp;
}

void print_list()
{
    // Hier programmieren:
    // Die Liste durchlaufen und jeweils die id des listenElements ausgeben. 


    //Anker ünergabe an Temporären Pointer
    //Weil Liste auf NULL läuft wenn nicht in tmp
    ListElement* current = p_root;

    //Schleife die von Anker (p_root) bis NULL
    //die Linked-List durchläuft
    while(current != nullptr)
    {
        cout << current->id<<"\n";
        current = current->p_next;
    }
}

int main(int argc, char* argv[])
{
    add_new_tail_element(9);
    add_new_head_element(2);
    add_new_head_element(1);
    add_new_tail_element(10);
    print_list();
    delete_element(2);
    print_list();

    return 0;
};

