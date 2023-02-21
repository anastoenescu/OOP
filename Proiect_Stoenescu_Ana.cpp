#include<iostream>
#include<string>
using namespace std;


enum Locul { dreaptasus, dreaptajos, stangasus, stangajos };


class Profil {
    int nrClickS;
    int nrClickD;
    Locul locul;
    const int nrSesiuni;
    static int vitezaDeRulare;
    char* durataSesiuni;
    string* modNavigare;
public:
    static string getNumeTip(Locul locul) {
        if (locul == dreaptajos)
            return "dreapta jos";
        if (locul == dreaptasus)
            return "dreapta sus";
        if (locul == stangasus)
            return "stanga sus";
        if (locul == stangajos)
            return "stanga jos";
    }
    Profil() : nrSesiuni(5) {
        this->durataSesiuni = new char[3];
        this->durataSesiuni[0] = 2;
        this->durataSesiuni[1] = 3;
        this->durataSesiuni[2] = 4;
        this->nrClickD = 5;
        this->nrClickS = 5;
        this->modNavigare = NULL;
        this->locul = dreaptajos;
    }
    Profil(int nrSesiuni, int nrClickS, int nrClickD, Locul locul, const char* durataSesiuni, string* modNavigare) : nrSesiuni(nrSesiuni) {
        this->durataSesiuni = new char[strlen(durataSesiuni) + 1];
        strcpy(this->durataSesiuni, durataSesiuni);
        this->nrClickD = nrClickD;
        this->nrClickS = nrClickS;
        this->locul = locul;
        if (modNavigare != NULL) {
            this->modNavigare = new string[this->nrClickD];
            for (int i = 0; i < nrClickD; i++) {
                this->modNavigare[i] = modNavigare[i];
            }

        }
    }

    Profil(const Profil& p) :nrSesiuni(5) {
        vitezaDeRulare++;
        this->durataSesiuni = new char[strlen(p.durataSesiuni) + 1];
        strcpy(this->durataSesiuni, "durataSesiuni");
        this->nrClickD = p.nrClickD;
        this->nrClickS = p.nrClickS;
        this->locul = locul;
        if (modNavigare != NULL) {
            this->modNavigare = new string[this->nrClickD];
            for (int i = 0; i < p.nrClickD; i++) {
                this->modNavigare[i] = p.modNavigare[i];
            }
        }
    }
    ifstream Profil("profil.txt", ios::in);
    Profil profil1, profil2;
    if (profil.1 is_open)){
    profil1 >> profil2 >> profil3;
    profil1.close();
}
    else {
        cout << "Fisierul cautat nu exista: !" << endl;
    }
    int getnrClickD() {
        return this->nrClickD;
    }

    void setnrClickD(int nrClickD) {
        if (nrClickD > 0) {
            this->nrClickD = nrClickD;
        }
    }

    int getnrClickS() {
        return this->nrClickS;
    }

    void setnrClickS(int nrClickS) {
        if (nrClickS > 0) {
            this->nrClickS = nrClickS;
        }
    }

    char* getdurataSesiuni() {
        return this->durataSesiuni;
    }

    void setdurataSesiuni(char* durataSesiuni) {
        if (this->durataSesiuni != nullptr) {
            delete[]this->durataSesiuni;
        }
        this->durataSesiuni = new char[strlen(durataSesiuni) + 1];
        strcpy(this->durataSesiuni, durataSesiuni);
    }

    string* getmodNavigare() {
        return this->modNavigare;

    }

    void setmodNavigare(string* modNavigare) {
        if (modNavigare->length() > 1) {
            this->modNavigare = modNavigare;
        }
    }
    friend ostream& operator<<(ostream& out, const Profil& p) {
        out << "Numarul de click-uri efectuate in partea stanga este:  " << p.nrClickS;
        out << "Nr de click-uri efectuate in partea dreapta este: " << p.nrClickD;

        for (int i = 0; i < strlen(p.durataSesiuni); i++) {
            out << p.durataSesiuni[i] << " ";
        }
        return out;
    }
    Profil& operator=(const Profil& p) {
        if (this != &p) {
            this->durataSesiuni = new char[strlen(p.durataSesiuni) + 1];
            strcpy(this->durataSesiuni, "durataSesiuni");
            this->nrClickD = p.nrClickD;
            this->nrClickS = p.nrClickS;
            if (modNavigare != NULL) {
                this->modNavigare = new string[this->nrClickD];
                for (int i = 0; i < p.nrClickD; i++) {
                    this->modNavigare[i] = p.modNavigare[i];
                }

            }
            return *this;
        }
    }

    Profil operator+(int x) {

        Profil p = *this;
        nrClickD += x;
        return p;
    }

    Profil operator-(int x) {

        if (x < this->nrClickD) {
            Profil p = *this;
            p.nrClickD -= x;
            return p;
        }
    }


    Profil operator+=(int nrClickD) {
        this->nrClickD += nrClickD;
        return *this;;
    }

    bool operator<=(const Profil& p) {
        if (this->nrClickD <= p.nrClickS)
            return true;
        else {
            return false;
        }
    }
    bool operator==(Profil p) {
        return(this->locul == p.locul) &&
            (this->durataSesiuni == p.durataSesiuni);
    }
    Profil& operator++() {
        this->durataSesiuni++;
        return*this;
    }
    Profil operator++(int) {
        Profil p = *this;
        this->nrClickD++;
        return p;
    }
    

};
class Utilizator {

    string nume;
    string prenume;
    float nrSesiuni;
    int id;
    const int loculNasterii;
    static int dataNasterii;
    string* parola;
public:
    Utilizator() :loculNasterii() {
        this->nume = "Popescu";
        this->nrSesiuni = 3;
        this->id = 002;
        this->prenume = "Ion";
        this->parola = new string[3];
        this->parola[0] = "asmsj";
        this->parola[1] = "Ana";
        this->parola[2] = "pop";
    }
    Utilizator(string nume, string prenume, float nrSesiuni, int id, string* parola) :loculNasterii() {
        this->nume = nume;
        this->prenume = prenume;
        this->nrSesiuni = nrSesiuni;
        this->id = id;
        this->parola = new string[this->id];
        for (int i = 0; i < this->id; i++) {
            this->parola[i] = parola[i];
        }
    }
    Utilizator(const Utilizator& u) :loculNasterii()
    {
        this->nume = u.nume;
        this->prenume = u.prenume;
        this->nrSesiuni = u.nrSesiuni;
        this->id = u.id;
        this->parola = new string[this->id];
        for (int i = 0; i < this->id; i++) {
            this->parola[i] = u.parola[i];
        }
    }

    string getnume() {
        return this->nume;
    }
    void setnume(string nume) {
        this->nume = nume;
    }
    string getprenume() {
        return this->prenume;
    }
    void setprenume(string prenume) {
        this->prenume = prenume;
    }
    float getid() {
        return this->id;
    }
    void setid(float id) {
        this->id = id;
    }
    string* getparola() {
        return this->parola;
    }
    void setparola(string* parola) {
        if (parola > 0) {
            this->parola = parola;
        }
    }

    Utilizator& operator=(const Utilizator& u) {
        if (this != &u) {
            this->nume = u.nume;
            this->prenume = u.prenume;
            this->nrSesiuni = u.nrSesiuni;
            this->id = u.id;

            if (u.parola != NULL) {
                for (int i = 0; i < 10; i++) {
                    this->parola[i] = u.parola[i];
                }
            }

        }
        return*this;
    }

    friend ostream& operator<<(ostream& out, Utilizator& u) {
        out << "Numele utilizatorului este: " << endl;
        out << "Parola utilizatorului este: " << endl;
        out << "Numarul sesiunilor este: " << endl;
        for (int i = 0; i < u.nrSesiuni; i++)
        {
            out << u.parola[i] << " ," << endl;
        }
        return out;
    }
    friend istream& operator>>(istream& in, Utilizator& u) {
        delete[]u.parola;
        u.parola = new string[u.id];
        for (int i = 0; i < u.id; i++) {
            in >> u.parola[i];
        }
    }

    Utilizator& operator++() {
        this->parola++;
        return*this;
    }
    Utilizator& operator++(int) {
        this->parola++;
        return*this;
    }
    Utilizator& operator--() {
        if (id >= 1 && id <= 10) {
            this->id--;

        }
        return*this;
    }
    const string operator[](int id)const {
        return this->parola[id - 1];
    }

    Utilizator operator+(float x) {
        Utilizator u = *this;
        u.dataNasterii = this->dataNasterii + x;
        return u;
    }

    bool operator==(Utilizator u) {
        return(this->parola == u.parola) &&
            (this->id == u.id) &&
            (this->nrSesiuni == u.nrSesiuni);
    }
    bool operator>=(Utilizator u) {
        return this->dataNasterii >= u.dataNasterii;
    }


};
class UtilizatorSuspect : public Utilizator {
    int nrMatricol;
    string nume;
    string prenume;
    static int CNP;
    const int serieBuletin;
    char* username;

    UtilizatorSuspect() :serieBuletin(3), Utilizator() {
        this->CNP = 23;
        this->nrMatricol = 999;
        this->nume = "Ana";
        this->prenume = "Maria";
        this->username = new char[strlen(username) + 1];
        strcpy_s(this->username, strlen(username) + 1, username);

    }
    UtilizatorSuspect(int nrMatricol, string nume, string prenume, float nrSesiuni, int id, string* parola) : serieBuletin(), Utilizator() {
        this->CNP = CNP;
        this->nrMatricol = nrMatricol;
        this->nume = nume;
        this->prenume = prenume;
        this->username = new char[strlen(username) + 1];
        strcpy_s(this->username, strlen(username) + 1, username);

    }
    UtilizatorSuspect(const UtilizatorSuspect& u) : serieBuletin(3), Utilizator(u) {
        this->nume = u.nume;
        this->prenume = u.prenume;
        this->username = new char[strlen(u.username) + 1];
        strcpy_s(this->username, strlen(u.username) + 1, u.username);
        this->CNP = u.CNP;
        this->nrMatricol = u.nrMatricol;
    }


    int getnrMatricol() {
        return this->nrMatricol;
    }
    void setnrMatricol(int nrMatricol) {
        this->nrMatricol = nrMatricol;
    }
    string getnume() {
        return this->nume;
    }
    void setnume(string nume) {
        {
            this->nume = nume;
        }
    }
    char* getusername() {
        return this->username;
    }
    void setusername(char* username) {
        if (this->username != nullptr) {
            delete[]this->username;
        }
        this->username = new char[strlen(username) + 1];
        strcpy(this->username, username);
    }
   
    UtilizatorSuspect& operator= (const UtilizatorSuspect& u) {
        Utilizator::operator=(u);
        if (this != &u) {
            delete[] this->username;
            this->nume = u.nume;
            this->prenume = u.prenume;
            this->username = new char[strlen(u.username) + 1];
            strcpy_s(this->username, strlen(u.username) + 1, u.username);
            this->CNP = u.CNP;
            this->nrMatricol = u.nrMatricol;
        }
        return *this;
    }
    friend ostream& operator<<(ostream& out, UtilizatorSuspect& u) {
        out << (Utilizator&)u << endl;
        out << "Numele utilizatorului este: " << endl;
        out << "Parola utilizatorului este: " << endl;
        out <<"Numarul matricol al utilizatorului suspect este: " << endl;
        for (int i = 0; i < u.nrMatricol; i++)
        {
            out << u.username[i] << " ," << endl;
        }
        return out;
    }
    friend istream& operator>>(istream& in, UtilizatorSuspect& u) {
        in >> (Utilizator&)u;
        in.ignore();

        delete[]u.username;
        return in;
    }
    UtilizatorSuspect& operator++() {
        this->nrMatricol++;
        return *this;
    }
    UtilizatorSuspect& operator++(int) {
        this->nrMatricol++;
        return *this;
    }
    UtilizatorSuspect& operator--() {
        this->nrMatricol--;
        return *this;
    }
    UtilizatorSuspect& operator--(int) {
        this->nrMatricol--;
        return *this;
    }
    bool operator>=(UtilizatorSuspect u) {
        return this->nrMatricol >= u.nrMatricol;
    }
    
};


int UtilizatorSuspect::CNP = 0;
int Profil::vitezaDeRulare = 0;
int Utilizator::dataNasterii = 0;



int main() {
   // Profil p2(5,6,7,"xyz")
    Profil p1;
    Profil p2(5, 6, 3, dreaptasus, "3", new string[3]{ "sus", "jos", "parola" });
    char linie[100];
    cout << u1.getnrClickD();
    cout << u1.getnrClickS();
    cout << u1.getdurataSesiuni();
    cout << u1.getmodNavigare();
    u1.setnrClickD();
    u1.setnrClickS();
    u1.setdurataSesiuni();
    u1.setmodNavigare();
    ifstream p;
    //Profil p3(p2);
    ////u1 = u2;
    //cout << p3;
    //p1 = p2 + 2;
    ////cin>>p1;
    //cout << endl;
    ////p1 = 2 + p2;
    //cout << p1;
    //
    Utilizator;
    ////string nume, string prenume,  float nrSesiuni, int id,string*parola
    //Utilizator u2("Ana", "Maria", 3, 005, "proiectpoo");
    //Utilizator u3(u2);
    //cout << u3;
    cout << u2.getnume();
    cout << u2.getprenume();
    cout << u2.getnrSesiuni();
    cout << u2.getparola();
    cout << u2.getid();
    u2.setnume();
    u2.setprenume();
    u2.setnrSesiuni();
    u2.setparola();
    u2.setid();
    UtilizatorSuspect;
    //UtilizatorSuspectu3(u2);
    return 0;
} 