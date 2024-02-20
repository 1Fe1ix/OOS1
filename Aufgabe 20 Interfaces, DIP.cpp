/* Afg 20 Interfaces, DIP.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.

Themen:
Interfaces, Dependency Inversion Principle


Ihre Aufgabe:

Setzen Sie das Dependency Inversion Principle um.

Implementieren Sie eine Klasse "AuthenticationResult" mit den konstanten Attributen "_authenticated" von Typ bool und "_username" vom typ string, einem parametrisierten Kontruktor,
der die Attribute initialisiert sowie getter-Methoden um die jeweilingen Werte auszulesen.
Der Parameter für den Usernamen soll den default-Wert "unauthenticated_user" enthalten.

Schreiben Sie ein Interface "IAuthenticationMethod", das die rein virtuelle Methode "authenticate" mit dem Rückgabewert "AuthenticationResult" enthält.

Schreiben Sie eine Klasse "Client" mit dem Attribut "_authentication_method" vom Typ Pointer auf "IAuthenticationMethod".
Die Methode "set_authentication_method" nimmt einen Pointer auf "IAuthenticationMethod" entgegen und setzt das Attribut "_authentication_method" entsprechend.


Die methode "execute" nimmt keine Parameter entgegen und führt die folgende Logik aus:
Es führt zunächst auf dem "_authentication_method"-Attribut die Methode "authenticate" aus und weist das Ergebnis einer konstanten vom Typ "AuthenticationResult" zu.


Weist das "AuthenticationResult" ein positives Ergebnis aus, so wird auf der Konsole folgendes ausgegeben:

Das Programm wird ausgeführt für [user].


War die Authentifizierung nicht erfolgreich so wird folgendes ausgegeben:

Das Programm konnte nicht ausgeführt werden.

Schreiben Sie drei verschiedene Implementierungen des Interfaces "IAuthenticationMethod": "MockAuth", "UsernamePassword" und "Certificate".

Die Klasse "MockAuth" gibt in jedem Fall ein positives "AuthenticationResult" für den Username "Default" zurück.

Die Klasse "UsernamePassword" liest nacheinander zunächst den Usernamen und das Passwort ein. Dazu wird der Anwender jeweils über die Konsole zur Eingabe aufgefordert:

Username:

bzw.

Password:

Sind Username und Passwort identisch, so gibt die Klasse ein positives "AuthenticationResult" für den entsprechenden Username zurück.
Andernfalls wird ein negatives "AuthenticationResult" zurückgegeben.
Die Klasse "Certificate" liest den Zertifikatsaussteller von der Konsole ein. Der Anwender wird hierzu folgendermaßen aufgefordert:

Zertifikatsaussteller:

Ist der Zertifikatsaussteller "hs-esslingen" so gibt die Klasse ein positives "AuthenticationResult" zurück mit dem Usernamen "certificate.owner".
Andernfalls wird ein negatives "AuthenticationResult" zurückgegeben.



Für die Eingaben:

Username:
Maier
Passwort:
Maier

Zertifikatsaussteller:
hs-esslingen

erzeugt das Programm die folgende (Ein-)Ausgabe:

Authentifizierung über MockAuth
Das Programm wird ausgeführt für Default.
Authentifizierung über UsernamePassword
Username:
Maier
Password:
Maier

Das Programm wird ausgeführt für Maier.
Authentifizierung über Zertifikat
Zertifikatsaussteller:
hs-eslingen
Das Programm wird ausgeführt für certificate.owner.

************************************************************************************************************************************************************************************/
#include <iostream>
#include <string>
using namespace std;



//-----------------------------Auth. Result----------------------------------------

class AuthenticationResult {

    const bool _authenticated;
    string _username;

public:

    AuthenticationResult(bool authenticated, string username = "unauthenticated_user");
    bool get_authenticated();
    string get_username();
};

//Param. Konstruktor für Authent.
AuthenticationResult::AuthenticationResult(bool authenticated, string username)
    : _authenticated(authenticated), _username(username) {}

bool AuthenticationResult::get_authenticated()
{
    return _authenticated;
}

string AuthenticationResult::get_username()
{
    return _username;
}

//--------------------Interface------------------------------------

//Interface für AuthenticationResult
class IAuthenticationMethod
{

public:

    virtual AuthenticationResult authenticate() = 0;

};

//--------------------------Client------------------------------

class Client
{
    IAuthenticationMethod* _authentication_method = nullptr;
    AuthenticationResult eine_Variable = AuthenticationResult(false, "unauthenticated_user");

public:

    void set_authentication_method(IAuthenticationMethod* authentication_method);
    void execute();

};

void Client::set_authentication_method(IAuthenticationMethod* authentication_method)
{

    //Jection dieser Zeiger schafft die dependencys
    _authentication_method = authentication_method;
}


void Client::execute()
{
    AuthenticationResult eine_Variable = _authentication_method->authenticate();

    if (eine_Variable.get_authenticated()) //Warum mit Punktoperator?
    {
        cout << "Das Programm wird ausgeführt für " << eine_Variable.get_username()<<"." << endl;  //WTF? warum alles mit dem Punkt?? wegen Interfaces???
    }
    else
    {
        cout << "Das Programm konnte nicht ausgeführt werden." << endl;
    }
}

//----------------------------MockAuth----------------------------------------------------

//Erbt von Interface IAuthenticationMethod weil es eine eigenschaft ist 


class MockAuthentication :public IAuthenticationMethod
{
public:
    AuthenticationResult authenticate();
};

AuthenticationResult MockAuthentication::authenticate()
{
    //Legt User Default mit _authenticated = wahr an 
    return AuthenticationResult(true, "Default");
}

//----------------------------UsernamePassword--------------------------------------------

class UsernamePassword : public IAuthenticationMethod
{
    string _Username;
    string _Password;
public:

    AuthenticationResult authenticate();


};


AuthenticationResult UsernamePassword::authenticate()
{
    //Print für Username
    cout << "Username:" << endl;
    cin >> _Username;
    //Print für passwort
    cout << "Password:" << endl;
    cin >> _Password;
    

    if (_Username == _Password)
    {
        return AuthenticationResult(true, _Username);
    }
    else
    {
        return AuthenticationResult(false, _Username);
    }
}

//----------------------------Certificate-------------------------------------------------

class Certificate : public IAuthenticationMethod
{
    string certificate;

public:

    void set_certificate(); //Warum da weil ztu erst in einzelne methoden dann aber gesehen das alles in eine muss upsi nicht gelöscht
    AuthenticationResult authenticate();
};


AuthenticationResult Certificate::authenticate()
{
    cout << "Zertifikatsaussteller: " << endl;
    cin >> certificate;
    

    if (certificate == "hs-esslingen")
    {
        return AuthenticationResult(true, "certificate.owner");
    }
    else
    {
        return AuthenticationResult(false);
    }
}

int main(int argc, char* argv[]) {
    Client client;

    cout << "Authentifizierung über die Authentifizierungsmethode Mock Authentication" << endl;
    IAuthenticationMethod* mock_authentication = new MockAuthentication();
    client.set_authentication_method(mock_authentication);
    client.execute();

    cout << "Authentifizierung über die Authentifizierungsmethode Username Password" << endl;
    IAuthenticationMethod* username_password = new UsernamePassword();
    client.set_authentication_method(username_password);
    client.execute();

    cout << "Authentifizierung über die Authentifizierungsmethode Zertifikat" << endl;
    IAuthenticationMethod* certificate = new Certificate();
    client.set_authentication_method(certificate);
    client.execute();
    return 0;
}



