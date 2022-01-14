/*

In this project I created an interactive menu with the help of a Singleton class,
which can print or add objects from any class.
The reading process is done by different files and its called in main().
The output will be displayed in only one file, "date.out".
I used a STL -vector for Angajat,
             -list for Piesa,
             -map for Service
             -set for Programari.

I used the inheritance concept in class Piesa by deriving class Cutie_viteze and class Angajat by deriving class Electrician(IS A - concept)
HAS A - concept can be seen in class Angajat, which has an object that has the type of another class: Service.
I build the interface Reducere and the abstract class Preturi, the scale being as follows:
Reducere -> Preturi -> Piesa -> Cutie_viteze
Pure virtual methods calc_red(in interface) and suma_totala(in abstract class) are overwritten in class Piesa


For class Piesa:
-constructor without parameters
-constructor with less parameters
-constructor with all the parameters of the class
-copy constructor
-destructor
-operator =
-operator<<
-operator>>
-operator++(pre+post)
-operator ==
-operator <
-operator +
-operator -
-operator cast (int)
-function :verificare_disponibilitate()


For class Service:
-constructor without parameters
-constructor with less parameters
-constructor with all the parameters of the class
-copy constructor
-destructor
-operator =
-operator<<
-operator>>
-operator++(pre+post)
-operator ==
-operator <
-operator +
-operator -
-operator cast (int)
-function: calcul_timp_pana_la_service()


For class Programare:
-constructor without parameters
-constructor with less parameters
-constructor with all the parameters of the class
-copy constructor
-destructor
-operator =
-operator<<
-operator>>
-operator++(pre+post)
-operator ==
-operator <
-operator +
-operator -
-operator cast (int)
-function: programeaza()


For class Angajat:
-constructor without parameters
-constructor with less parameters
-constructor with all the parameters of the class
-copy constructor
-destructor
-operator =
-operator<<
-operator>>
-operator++(pre+post)
-operator ==
-operator <
-operator +
-operator -
-operator cast (int)
-function: afiseaza_angajatul_lunii()
-setters + getters for any data type variables.

I ran tests on every class that are commented in main().
*/

//================================================================================================

/*
Romanian:
In acest proiect am creat un meni interactiv intr-o clasa Singleton, meniu in care se pot adauga / afisa obiecte
din orice clasa(chiar si din cele derivate);
Citirea se face din fisiere diferite pentru fiecare clasa si se face din main().
Afisarea se face intr-un singur fisier, "date.out".
Am creat utilizand STL un vector cu tipul de date Angajat, o lista cu tipul de date Piesa,
un map pentru Service-uri si un set pentru Programari.

Totodata, am mostenit clasa Piesa in clasa Cutie_viteze si clasa Angajat in clasa Electrician(conceptul IS A)
Conceptul HAS A este ilustrat in clasa Angajat, care are un obiect de tipul Service(in scopul de a spune la ce service lucreaza Angajatul x)
Am construit interfata Reducere si clasa abstracta Preturi, iar ierarhia este urmatoarea:
Reducere -> Preturi -> Piesa -> Cutie_viteze
Metodele virtuale pure calc_red(in interfata) si suma_totala(in clasa abstracta) sunt suprascrise ulterior in clasa Piesa


Pentru clasa Piesa:
-constructorul fara parametrii
-constructorul cu mai putini parametrii
-constructorul cu toti parametrii
-constructorul de copiere
-destructorul
-operatorul =
-operatorul<<
-operatorul>>
-operatorul++(pre+post)
-operatorul ==
-operatorul <
-operatorul +
-operatorul -
-operatorul cast (int)
-functionalitate:verificare_disponibilitate()


Pentru clasa Service:
-constructorul fara parametrii
-constructorul cu mai putini parametrii
-constructorul cu toti parametrii
-constructorul de copiere
-destructorul
-operatorul =
-operatorul<<
-operatorul>>
-operatorul++(pre+post)
-operatorul ==
-operatorul <
-operatorul +
-operatorul -
-operatorul cast (int)
-functionalitate: calcul_timp_pana_la_service()


Pentru clasa Programare:
-constructorul fara parametrii
-constructorul cu mai putini parametrii
-constructorul cu toti parametrii
-constructorul de copiere
-destructorul
-operatorul =
-operatorul<<
-operatorul>>
-operatorul++(pre+post)
-operatorul ==
-operatorul <
-operatorul +
-operatorul -
-operatorul cast (int)
-functionalitate: programeaza()


Pentru clasa Angajat:
-constructorul fara parametrii
-constructorul cu mai putini parametrii
-constructorul cu toti parametrii
-constructorul de copiere
-destructorul
-operatorul =
-operatorul<<
-operatorul>>
-operatorul++(pre+post)
-operatorul ==
-operatorul <
-operatorul +
-operatorul -
-operatorul cast (int)
-functionalitate: afiseaza_angajatul_lunii()
-setters + getters pentru variabilele de toate tipurile.

Am facut teste pe fiecare clasa, pe care le-am comentat in main().
*/

#include <iostream>
#include <string.h>
#include <fstream>
#include <iterator>
#include <vector>
#include <list>
#include <map>
#include <set>

using namespace std;

ifstream fin1("Angajati.in");
ifstream fin2("Piese.in");
ifstream fin3("Serviceuri.in");
ifstream fin4("Programari.in");
ofstream g("date.out");

bool caut_in_vct(string a, string* q)
{
    for (int i=0;i<10;i++)
        if(a == q[i])
            return true;
    return false;
}

int compara2caract(char a, char b)
{
    if(a==b)
        return 1;
    else return 0;
}

bool ind =1 ;

//interfata
class Reducere
{
    public:
    virtual void calc_red()=0;
};

//clasa abstracta
class Preturi:public Reducere
{
    protected:
        bool client_fidel;
        double pret_piesa;
        double manopera; //daca se achizitioneaza numai piese, manopera va fi egala cu 0.
    public:
        Preturi();
        Preturi(bool client_fidel, double pret_piesa, double manopera);
        Preturi(const Preturi& p);
        Preturi& operator=(const Preturi& p);
        ~Preturi(){}
        double getpret_piesa();
        virtual ostream& Afisare_virtuala(ostream& out)const;
        virtual istream& Citire_virtuala(istream& in);
        friend ifstream& operator>>(ifstream& in, Preturi& p);
        friend ofstream& operator<<(ofstream& out, const Preturi& p);
        friend istream& operator>>(istream& in, Preturi& p);
        friend ostream& operator<<(ostream& out, const Preturi& p);
        virtual void suma_totala()=0;
};

Preturi::Preturi()
{
    this->client_fidel=false;
    this->pret_piesa=-1;
    this->manopera=-1; //daca se achizitioneaza numai piese, manopera va fi egala cu 0.
}

Preturi::Preturi(bool client_fidel, double pret_piesa, double manopera)
{
    this->client_fidel=client_fidel;
    this->pret_piesa=pret_piesa;
    this->manopera= manopera;
}
Preturi::Preturi(const Preturi& p)
{
    this->client_fidel=p.client_fidel;
    this->pret_piesa=p.pret_piesa;
    this->manopera= p.manopera;
}

double Preturi::getpret_piesa()
{
    return this->pret_piesa;
}

ofstream& operator<<(ofstream& out, const Preturi& p)
{
    if(p.client_fidel==1)
        out<<"Clientul este fidel";
    else out<<"Clientul nu este fidel";
    out<<endl;
    out<<"Pretul pentru aceasta piesa este: "<<p.pret_piesa<<endl;
    if(p.manopera==0)
        out<<"Piesa cumparata nu a necesitat montaj, astfel ca manopera este egala cu 0";
    else out<<"Manopera pentru aceasta piesa este in valoare de: "<<p.manopera<<" lei."<<endl;
    return out;
}

ostream& Preturi::Afisare_virtuala(ostream& out)const
{
    if(this->client_fidel==1)
        out<<"Clientul este fidel";
    else out<<"Clientul nu este fidel";
    out<<endl;
    out<<"Pretul pentru aceasta piesa este: "<<this->pret_piesa<<endl;
    if(this->manopera==0)
        out<<"Piesa cumparata nu a necesitat montaj, astfel ca manopera este egala cu 0";
    else out<<"Manopera pentru aceasta piesa este in valoare de: "<<this->manopera<<" lei."<<endl;

    return out;
}
istream& Preturi::Citire_virtuala(istream& in)
{
    cout<<"Daca cumparatorul se afla in categoria CUMPARATOR-FIDEL introduceti 1, altfel 0: ";
    in>>this->client_fidel;
    cout<<endl;
    cout<<"Introduceti pretul piesei: ";
    in>>this->pret_piesa;
    cout<<endl;
    cout<<"Daca piesa cumparata va trebui si montata, introduceti pretul manoperei, altfel 0: ";
    in>>this->manopera;
    cout<<endl;
    return in;
}

ifstream& operator>>(ifstream& in, Preturi& p)
{
    in>>p.client_fidel;
    in>>p.pret_piesa;
    in>>p.manopera;
    return in;
}

istream& operator>>(istream& in, Preturi& p)
{
    return p.Citire_virtuala(in);
}
ostream& operator<<(ostream& out, const Preturi& p)
{
    return p.Afisare_virtuala(out);
}
Preturi& Preturi::operator=(const Preturi& p)
{
 if(this!=&p)
    {
    this->client_fidel=p.client_fidel;
    this->pret_piesa=p.pret_piesa;
    this->manopera= p.manopera;
    }
    return *this;
}

class Piesa:public Preturi
{
    protected:
        long nr_total_piese_de_acest_tip;
        bool in_stoc;  //interogarea unei piese pt a afla daca se afla in stoc sau nu
        string timp_estimat_pana_cand_ajunge_comanda; // daca nu e pe stoc
        char* nume_piesa;
        int numar_piese_cerute;
    public:
        Piesa();
        Piesa(char* nume_piesa, long nr_total_piese_de_acest_tip);
        Piesa(long nr_total_piese_de_acest_tip, bool in_stoc, string timp_estimat_pana_cand_ajunge_comanda, char* nume_piesa, int numar_piese_cerute, bool client_fidel, double pret_piesa, double manopera);
        Piesa(const Piesa& pie);
        ~Piesa();
        char* getnume_piesa();
        Piesa& operator=(const Piesa& pie);
        virtual ostream& Afisare_virtuala(ostream& out)const;
        virtual istream& Citire_virtuala(istream& in);
        friend ifstream& operator>>(ifstream& in, Piesa& pie);
        friend ofstream& operator<<(ofstream& out, Piesa& pie);
        const Piesa& operator++();
        const Piesa operator++(int);
        bool operator==(Piesa& pie);
        bool operator<(Piesa& pie);
        int operator+(int a);
        Piesa& operator-(Piesa pie);
        explicit operator int();
        void calc_red();
        void suma_totala();
        void verificare_disponibilitate(string nume_piesa1, int numar_piese_cerute);

};

char* Piesa::getnume_piesa()
{
    return this->nume_piesa;
}

Piesa::Piesa():Preturi()
{
    this->nr_total_piese_de_acest_tip = -1;
    this->in_stoc = 0;
    this->timp_estimat_pana_cand_ajunge_comanda = "niciodata";
    this->nume_piesa = new char[strlen("indisponibil") + 1];
    strcpy(this->nume_piesa,"indisponibil");
    this->numar_piese_cerute = -1;
}

Piesa::Piesa(char* nume_piesa, long nr_total_piese_de_acest_tip):Preturi()
{
    this->nr_total_piese_de_acest_tip = nr_total_piese_de_acest_tip;
    this->numar_piese_cerute = 1;
    this->timp_estimat_pana_cand_ajunge_comanda="3 zile";
    this->nume_piesa = new char[strlen(nume_piesa) + 1];
    strcpy(this->nume_piesa,nume_piesa);
}

Piesa::Piesa(long nr_total_piese_de_acest_tip, bool in_stoc, string timp_estimat_pana_cand_ajunge_comanda, char* nume_piesa, int numar_piese_cerute, bool client_fidel, double pret_piesa, double manopera):Preturi(client_fidel, pret_piesa, manopera)
{
    this->nr_total_piese_de_acest_tip = nr_total_piese_de_acest_tip;
    this->in_stoc = in_stoc;
    this->timp_estimat_pana_cand_ajunge_comanda = timp_estimat_pana_cand_ajunge_comanda;
    this->nume_piesa = new char[strlen(nume_piesa) + 1];
    strcpy(this->nume_piesa,nume_piesa);
    this->numar_piese_cerute = numar_piese_cerute;
}

Piesa::Piesa(const Piesa& pie):Preturi(pie)
{
    this->nr_total_piese_de_acest_tip = pie.nr_total_piese_de_acest_tip;
    this->in_stoc = pie.in_stoc;
    this->timp_estimat_pana_cand_ajunge_comanda = pie.timp_estimat_pana_cand_ajunge_comanda;
    this->nume_piesa = new char[strlen(pie.nume_piesa) + 1];
    strcpy(this->nume_piesa,pie.nume_piesa);
    this->numar_piese_cerute = pie.numar_piese_cerute;
}

Piesa::~Piesa()
{
    if(nume_piesa != NULL)
        delete[] this->nume_piesa;
}

Piesa& Piesa:: operator=(const Piesa& pie)
{
    if(this != &pie)
    {

        if(nume_piesa != NULL)
            delete[] this->nume_piesa;
        Preturi::operator=(pie);
        this->nr_total_piese_de_acest_tip = pie.nr_total_piese_de_acest_tip;
        this->in_stoc = pie.in_stoc;
        this->timp_estimat_pana_cand_ajunge_comanda = pie.timp_estimat_pana_cand_ajunge_comanda;
        this->nume_piesa = new char[strlen(pie.nume_piesa) + 1];
        strcpy(this->nume_piesa,pie.nume_piesa);
        this->numar_piese_cerute = pie.numar_piese_cerute;
    }
    return *this;
}
Piesa& Piesa::operator-(Piesa pie)
{
    Piesa* p= new Piesa(*this);
    if(p->nr_total_piese_de_acest_tip > pie.nr_total_piese_de_acest_tip)
        p->nr_total_piese_de_acest_tip -= pie.nr_total_piese_de_acest_tip;
    else
        p->nr_total_piese_de_acest_tip = pie.nr_total_piese_de_acest_tip - p->nr_total_piese_de_acest_tip;
    return *p;
}

Piesa::operator int ()
{
    return (int)this->numar_piese_cerute;
}

ostream& Piesa::Afisare_virtuala(ostream& out)const
{

    if(nr_total_piese_de_acest_tip != -1 && numar_piese_cerute == 1)
    {
    out<<"Piesa se numeste "<<nume_piesa<<" si ati cerut un numar de "<< numar_piese_cerute<<" piesa"<<endl;
    if(in_stoc == 1)
        out<<"Pe stoc se afla in acest moment "<< nr_total_piese_de_acest_tip<<" piese\n";
    else
        out<<nume_piesa<<" nu se afla pe stoc in acest moment si va ajunge in stoc intr-un timp estimat de: "<<timp_estimat_pana_cand_ajunge_comanda<<endl;
    }

    else if(nr_total_piese_de_acest_tip != -1)
    {
        out<<"Piesa se numeste "<<nume_piesa<<" si ati cerut un numar de "<< numar_piese_cerute<<" piese"<<endl;
        if(in_stoc == 1)
            out<<"Pe stoc se afla in acest moment "<< nr_total_piese_de_acest_tip<<" piese\n";
        else
            out<<nume_piesa<<" nu se afla pe stoc in acest moment si va ajunge in stoc intr-un timp estimat de: "<<timp_estimat_pana_cand_ajunge_comanda<<endl;
    }
    else
        out<<"Piesa nu exista. Ea nu se afla in stoc si nu are un timp estimat pentru cand va ajunge pe stoc. "<<endl;
        Preturi::Afisare_virtuala(out);
    return out;

}

istream& Piesa::Citire_virtuala(istream& in)
{
    cin.get();
    cout<<"Introduceti numele piesei: ";
    char aux[100];
    in.getline(aux, 99);
    if(nume_piesa != NULL)
        delete[] nume_piesa;
    nume_piesa = new char[strlen(aux)+1];
    strcpy(nume_piesa, aux);
    cout<<endl;
    cout<<"Introduceti numarul de piese de acest tip pe care doriti sa le comandati: ";
    in>>numar_piese_cerute;
    cout<<endl;
    cout<<"Daca piesa se afla pe stoc, introduceti 1, altfel 0 ";
    in>>in_stoc;
    cout<<endl;
    timp_estimat_pana_cand_ajunge_comanda = "3 zile";
    cout<<"Cate piese de acest tip exista pe stoc? ";
    in>>nr_total_piese_de_acest_tip;cout<<endl;
    Preturi::Citire_virtuala(in);

        return in;
}

ifstream& operator >>(ifstream& in, Piesa& pie)
{
    char aux[100];
    in.getline(aux, 99);
    if(pie.nume_piesa != NULL)
        delete[] pie.nume_piesa;
    pie.nume_piesa = new char[strlen(aux)+1];
    strcpy(pie.nume_piesa, aux);
    in>>pie.numar_piese_cerute;
    in>>pie.in_stoc;
    in>>pie.timp_estimat_pana_cand_ajunge_comanda;
    in>>pie.nr_total_piese_de_acest_tip;
    in>>(Preturi&)pie;
    return in;
}

ofstream& operator<<(ofstream& out, Piesa& pie)
{

    if(pie.nr_total_piese_de_acest_tip != -1 && pie.numar_piese_cerute == 1)
    {
    out<<"Piesa se numeste "<<pie.nume_piesa<<" si ati cerut un numar de "<< pie.numar_piese_cerute<<" piesa"<<endl;
    if(pie.in_stoc == 1)
        out<<"Pe stoc se afla in acest moment "<< pie.nr_total_piese_de_acest_tip<<" piese\n";
    else
        out<<pie.nume_piesa<<" nu se afla pe stoc in acest moment si va ajunge in stoc intr-un timp estimat de: "<<pie.timp_estimat_pana_cand_ajunge_comanda<<endl;
    }

    else if(pie.nr_total_piese_de_acest_tip != -1)
    {
        out<<"Piesa se numeste "<<pie.nume_piesa<<" si ati cerut un numar de "<< pie.numar_piese_cerute<<" piese"<<endl;
        if(pie.in_stoc == 1)
            out<<"Pe stoc se afla in acest moment "<< pie.nr_total_piese_de_acest_tip<<" piese\n";
        else
            out<<pie.nume_piesa<<" nu se afla pe stoc in acest moment si va ajunge in stoc intr-un timp estimat de: "<<pie.timp_estimat_pana_cand_ajunge_comanda<<endl;
    }
    else
        out<<"Piesa nu exista. Ea nu se afla in stoc si nu are un timp estimat pentru cand va ajunge pe stoc. "<<endl;
    out<<(Preturi&)pie;
    return out;

}

void Piesa::suma_totala()
{
    double pret_in_total=0;
    pret_in_total = this->numar_piese_cerute*this->pret_piesa;
    pret_in_total += this->manopera;
}

void Piesa::calc_red()
{
    double pret_final=0;
    double pret_initial=0;
    pret_initial = this->numar_piese_cerute*this->pret_piesa + this-> manopera;
    if(this->numar_piese_cerute >= 40){
        pret_final=pret_initial-(1/5)*pret_initial;}
    else
    {
        pret_final=pret_initial-pret_initial*this->numar_piese_cerute/200;
        if(this->client_fidel==1)
            pret_final -= pret_final*1/20;
    }
    cout<<"\nIn loc de "<<pret_initial<<" aveti de platit "<<pret_final<<" ceea ce inseamna o reducere de "<<pret_initial-pret_final<<" lei"<<endl;
}

void Piesa::verificare_disponibilitate(string nume_piesa1, int numar_piese_cerute)
{
    bool ok=0;
    string* q;
    q = new string[10];
    q[0] = "Bujie";
    q[1] = "Rulmenti";
    q[2] = "Racord";
    q[3] = "Catalizator";
    q[4] = "Baterie";
    q[5] = "Piston";
    q[6] = "Placute de frana";
    q[7] = "Cutie de viteza";
    q[8] = "Planetara";
    q[9] = "Ambreiaj";
    if(numar_piese_cerute <= this->nr_total_piese_de_acest_tip && caut_in_vct(nume_piesa1, q))
        ok = 1;
    if(ok)cout<<"Totul este in regula, puteti veni sa ridicati/montati piesa"<<endl;
    else cout<<"Piesa nu este pe stoc in cantitatea ceruta."<<endl;
}

const Piesa& Piesa::operator++()
{
    this-> nr_total_piese_de_acest_tip++;
    this->in_stoc = 1;
    this->numar_piese_cerute++;
    return *this;
}

const Piesa Piesa:: operator++(int)
{
    Piesa aux(*this);
    this-> nr_total_piese_de_acest_tip++;
    this->in_stoc = 1;
    this->numar_piese_cerute++;
    return aux;
}

bool Piesa::operator==(Piesa & pie)
{
    if(strcmp(this->nume_piesa, pie.nume_piesa)==0)
        return true;
    else return false;
}

bool Piesa::operator<(Piesa& pie)
{
    if(this->nr_total_piese_de_acest_tip < pie.nr_total_piese_de_acest_tip)
        return true;
    else return 0;
}

int Piesa::operator+(int a){ return this->numar_piese_cerute + a;}

class Service;

class Cutie_viteze:public Piesa
{
    private:
        bool hidramata;
        int nr_viteze;
        char* masina_compatibila;
        char pentru_benzina_diesel_sau_eletrica;
    public:
        Cutie_viteze():Piesa()
        {
            this->hidramata=0;
            this->nr_viteze=-1;
            this->masina_compatibila = new char[8];
            strcpy(this->masina_compatibila, "niciuna");
            this->pentru_benzina_diesel_sau_eletrica='q';
        }
        Cutie_viteze(char* nume_piesa, long nr_total_piese_de_acest_tip):Piesa(nume_piesa, nr_total_piese_de_acest_tip)
        {
            this->hidramata=0;
            this->nr_viteze=-1;
            this->masina_compatibila = new char[8];
            strcpy(this->masina_compatibila, "niciuna");
            this->pentru_benzina_diesel_sau_eletrica='q';
        }
        Cutie_viteze(long nr_total_piese_de_acest_tip, bool in_stoc, string timp_estimat_pana_cand_ajunge_comanda, char* nume_piesa, int numar_piese_cerute, bool hidramata, int nr_viteze, char* masina_compatibila, char pentru_benzina_diesel_sau_eletrica):Piesa(nr_total_piese_de_acest_tip, in_stoc, timp_estimat_pana_cand_ajunge_comanda, nume_piesa, numar_piese_cerute, client_fidel, pret_piesa, manopera)
        {
            this->hidramata = hidramata;
            this->nr_viteze = nr_viteze;
            this->masina_compatibila = new char[strlen(masina_compatibila)+1];
            strcpy(this->masina_compatibila, masina_compatibila);
            this->pentru_benzina_diesel_sau_eletrica = pentru_benzina_diesel_sau_eletrica;
        }
        Cutie_viteze(const Cutie_viteze& pie):Piesa(pie)
        {
            this->hidramata = pie.hidramata;
            this->nr_viteze = pie.nr_viteze;
            this->masina_compatibila = new char[strlen(pie.masina_compatibila)+1];
            strcpy(this->masina_compatibila, pie.masina_compatibila);
            this->pentru_benzina_diesel_sau_eletrica = pie.pentru_benzina_diesel_sau_eletrica;
        }

        virtual istream& Citire_virtuala(istream& in)
        {
            Piesa::Citire_virtuala(in);
            cout<<"Introduceti 1 daca cutia de viteze este hidramata, altfel 0: ";
            in>>hidramata;
            cout<<"Cate viteze are cutia? "<<endl;
            in>> nr_viteze;
            cout<<endl;
            cout<<"Introduceti b daca cutia este pentru masini care functioneaza pe benzina, d pentru masini diesel si e pentru masini electrice"<<endl;
            in>>pentru_benzina_diesel_sau_eletrica;
            cout<<"Cu ce marca de masina este compatibila cutia de viteze?\n";
            in>>masina_compatibila;
            return in;
        }
        friend ifstream& operator>>(ifstream& in, Cutie_viteze& pie)
        {
            in>>(Piesa&)pie;
            in>>pie.hidramata;
            in>> pie.nr_viteze;
            in>>pie.pentru_benzina_diesel_sau_eletrica;
            in>>pie.masina_compatibila;
            return in;
        }

        virtual ostream& Afisare_virtuala(ostream& out)const
        {
            Piesa::Afisare_virtuala(out);
            if(hidramata==1)
                out<<"Cutia de viteze este hidramata."<<endl;
            else
                out<<"Cutia de viteze nu este hidramata."<<endl;
            out<<"Cutia are: "<< nr_viteze<<" viteze."<<endl;
            if(pentru_benzina_diesel_sau_eletrica=='b')
                out<<"Cutia de viteze este facuta pentru masini care folosesc benzina ca si combustibil."<<endl;
            else if(pentru_benzina_diesel_sau_eletrica=='d')
                out<<"Cutia de viteze este facuta pentru masini cu motor diesel."<<endl;
            else if(pentru_benzina_diesel_sau_eletrica=='e')
                out<<"Cutia de viteze este facuta pentru masini eletrice."<<endl;
            out<<"Cutia de viteze este compatibila cu "<<masina_compatibila<<"."<<endl;
            return out;
        }

        friend ofstream& operator<<(ofstream& out, Cutie_viteze& pie)
        {
            out<<(Piesa&)pie;
            if(pie.hidramata==1)
                out<<"Cutia de viteze este hidramata."<<endl;
            else
                out<<"Cutia de viteze nu este hidramata."<<endl;
            out<<"Cutia are: "<< pie.nr_viteze<<" viteze."<<endl;
            if(pie.pentru_benzina_diesel_sau_eletrica=='b')
                out<<"Cutia de viteze este facuta pentru masini care folosesc benzina ca si combustibil."<<endl;
            else if(pie.pentru_benzina_diesel_sau_eletrica=='d')
                out<<"Cutia de viteze este facuta pentru masini cu motor diesel."<<endl;
            else if(pie.pentru_benzina_diesel_sau_eletrica=='e')
                out<<"Cutia de viteze este facuta pentru masini eletrice."<<endl;
            out<<"Cutia de viteze este compatibila cu "<<pie.masina_compatibila<<"."<<endl;
            return out;
        }
        Cutie_viteze& operator=(const Cutie_viteze& pie)
        {
            if(this != &pie)
            {
                if(pie.masina_compatibila != NULL)
                    delete this->masina_compatibila;
                Piesa::operator=(pie);
                this->hidramata=pie.hidramata;
                this->nr_viteze=pie.nr_viteze;
                this->masina_compatibila = new char[strlen(pie.masina_compatibila)+1];
                strcpy(this->masina_compatibila, pie.masina_compatibila);
                this->pentru_benzina_diesel_sau_eletrica=pie.pentru_benzina_diesel_sau_eletrica;
            }
            return *this;
        }
        ~Cutie_viteze()
        {
            if(this->masina_compatibila!= NULL)
                delete[] this->masina_compatibila;
        }
};


class Service
{
private:
    string strada;
    int numar_strada;
    string numar_telefon;
    char* program;
    string adresa_mail;
    bool client_nou;
public:
    Service();
    Service(string strada, int numar_strada, string numar_telefon, char* program);
    Service(string strada, int numar_strada, string numar_telefon, char* program, string adresa_mail, bool client_nou);
    Service(const Service& serv);
    ~Service();
    string getstrada();
    int getnumar_strada();
    Service& operator=(const Service& serv);
    friend istream& operator>>(istream& in, Service& serv);
    friend ostream& operator<<(ostream& out, const Service& serv);
    friend ofstream& operator<<(ofstream& out, const Service& serv);
    friend ifstream& operator>>(ifstream& in, Service& serv);
    const Service& operator++();
    const Service operator++(int);
    bool operator==(Service & serv);
    bool operator<(Service & serv);
    int operator+(int a);
    explicit operator int();
    Service& operator-(Service serv);
    void calcul_timp_pana_la_service(int ora, int minut, double distanta, int viteza_mers_pe_jos, int viteza_cu_masina);
};

string Service::getstrada()
{
    return this->strada;
}
int Service::getnumar_strada()
{
    return this->numar_strada;
}

Service::Service()
{
    this->strada = "Inexistenta ";
    this->numar_strada = -10;
    this->numar_telefon = "indisponibil ";
    this->program = new char[strlen("Nu exista program pentru acest service")+1];
    strcpy(this->program, "Nu exista program pentru acest service");
    this->adresa_mail = "indisponibila ";
    this->client_nou = 0;
}

Service::Service(string strada, int numar_strada,string numar_telefon, char* program)
{
    this->strada = strada;
    this->numar_strada = numar_strada;
    this->program = new char[strlen(program)+1];
    strcpy(this->program, program);
}

Service::Service(string strada, int numar_strada, string numar_telefon, char* program, string adresa_mail, bool client_nou)
{
    this->strada = strada;
    this->numar_strada = numar_strada;
    this->numar_telefon = numar_telefon;
    this->program = new char[strlen(program)+1];
    strcpy(this->program, program);
    this->adresa_mail = adresa_mail;
    this->client_nou = client_nou;
}

Service::Service(const Service& serv)
{
    this->strada = serv.strada;
    this->numar_strada = serv.numar_strada;
    this->numar_telefon = serv.numar_telefon;
    this->program = new char[strlen(serv.program)+1];
    strcpy(this->program, serv.program);
    this->adresa_mail = serv.adresa_mail;
    this->client_nou = serv.client_nou;
}

Service::~Service()
{
    if(this->program != NULL)
        delete[] this->program;
}

bool Service::operator==(Service & serv)
{
    if(this->adresa_mail==serv.adresa_mail && this->strada==serv.strada && this->numar_strada == serv.numar_strada && this->numar_telefon == serv.numar_telefon)
        return true;
    else return false;
}

bool Service::operator<(Service& serv)
{
    if(this->numar_strada < serv.numar_strada)
        return true;
    return false;
}

Service:: operator int(){
return (int)this->numar_strada;
}
//calcul_timp_pana_la_service este functionalitatea care arata ora la care veti ajunge la service
//in functie de distanta curenta la care sunteti de service si ora curenta
//calculeaza timpul daca mergeti pe jos/cu masina.
void Service::calcul_timp_pana_la_service(int ora, int minut, double distanta, int viteza_mers_pe_jos, int viteza_cu_masina)
{
    int ora_sosirii, minutul_sosirii;
    double timp;
    int timp_in_minute, contor_ore;
    int i=0;
    int contor_zile = 0;
    int ora_deschidere, ora_inchidere;

    while(i<2){
        ora_sosirii=0;
        minutul_sosirii=0;
        contor_ore=0;
        timp = distanta/viteza_mers_pe_jos;
        timp_in_minute = timp*60;

        while(timp_in_minute>=60){
            timp_in_minute-=60;
            contor_ore++;
        }
        ora_sosirii = ora_sosirii+ contor_ore;

        minutul_sosirii += timp_in_minute;
        ora_sosirii += ora;

        minutul_sosirii += minut;
        if(minutul_sosirii >= 60){
            minutul_sosirii -= 60;
            ora_sosirii ++;
        }
        contor_zile = 0;
        ora_deschidere = (this->program[0] - '0') * 10 + (this->program[1] - '0');
        ora_inchidere = (this->program[3] - '0') * 10 + (this->program[4]- '0');
        while (ora_sosirii >= 24){
            ora_sosirii -= 24;
            contor_zile++;
        }
        if (i == 0)
            if (contor_zile == 0)
                cout<<"Mergand pe jos pana la service ajungeti la ora "<<ora_sosirii<<":"<<minutul_sosirii;
            else
                cout<<"Mergand pe jos pana la service ajungeti peste "<<contor_zile<<" zile la ora "<<ora_sosirii<<":"<<minutul_sosirii;
        else
            if (contor_zile == 0)
                cout<<"Mergand cu masina pana la service ajungeti la ora "<<ora_sosirii<<":"<<minutul_sosirii;
            else
                cout<<"Mergand cu masina pana la service ajungeti peste "<<contor_zile<<" zile la ora "<<ora_sosirii<<":"<<minutul_sosirii;

        if(ora_deschidere < ora_sosirii && ora_sosirii < ora_inchidere)
            cout<<" si service-ul este deschis."<<endl;
        else if(ora_deschidere > ora_sosirii || ora_inchidere < ora_sosirii)
            cout<<" si service-ul este inchis."<<endl;
        else if (ora_deschidere == ora_sosirii)
            cout<<" si service-ul este deschis."<<endl;
        else if (ora_inchidere == ora_sosirii)
            if (minutul_sosirii > 0)
                cout<<" si service-ul este inchis."<<endl;
            else cout<<" si service-ul este deschis."<<endl;
        i++;
        viteza_mers_pe_jos = viteza_cu_masina;
    }
}

Service& Service::operator=(const Service& serv)
{
    if(this != &serv)
    {
        if(this->program != NULL)
            delete[] this->program;
        this->strada = serv.strada;
        this->numar_strada = serv.numar_strada;
        this->numar_telefon = serv.numar_telefon;
        this->program = new char[strlen(serv.program)+1];
        strcpy(this->program, serv.program);
        this->adresa_mail = serv.adresa_mail;
        this->client_nou = serv.client_nou;
    }
    return *this;
}

int Service::operator+(int a)
{
    return this->numar_strada + a;
}

ifstream& operator>>(ifstream& in, Service& serv)
{
    in>>serv.strada;
    in>>serv.numar_strada;
    in>>serv.client_nou;
    in>>serv.numar_telefon;
    in>>serv.adresa_mail;
    if(serv.program != NULL)
        delete[] serv.program;
    char aux[20];
    in>>aux;
    serv.program = new char[strlen(aux)+1];
    strcpy(serv.program, aux);
    return in;
}

ofstream& operator<<(ofstream& out, const Service& serv)
{
    out<<"Service-ul se afla pe strada "<<serv.strada<<", numarul "<<serv.numar_strada<<endl;
    out<<"Nr tel: "<<serv.numar_telefon<<endl;
    if(strcmp(serv.program, "Nu exista program pentru acest service") != 0)
    out<<"Programul este: "<<serv.program<<" de luni pana vineri"<<endl;
    else
        out<<"Nu exista program de afisat pentru acest service"<<endl;
    out<<"Adresa de email a acestui service este: "<<serv.adresa_mail<<endl;
    if(serv.client_nou == 1)
        out<<"Clientul este nou";
    else
        out<<"Clientul nu este nou";
    return out;
}

ostream& operator<<(ostream& out, const Service& serv)
{
    out<<"Service-ul se afla pe strada "<<serv.strada<<", numarul "<<serv.numar_strada<<endl;
    out<<"Nr tel: "<<serv.numar_telefon<<endl;
    if(strcmp(serv.program, "Nu exista program pentru acest service") != 0)
    out<<"Programul este: "<<serv.program<<" de luni pana vineri"<<endl;
    else
        out<<"Nu exista program de afisat pentru acest service"<<endl;
    out<<"Adresa de email a acestui service este: "<<serv.adresa_mail<<endl;
    if(serv.client_nou == 1)
        out<<"Clientul este nou";
    else
        out<<"Clientul nu este nou";
    return out;
}

istream& operator>>(istream& in, Service& serv)
{
    cout<<"Introduceti strada pe care se afla service-ul\n";
    cout<<" *Daca numele strazii este compus din mai multe cuvinte se va scrie ca in exemplu: 1_Decembrie_1918*\n";
    in>>serv.strada;
    cout<<endl;
    cout<<"La ce numar pe aceasta strada se afla service-ul? ";
    in>>serv.numar_strada;
    cout<<endl;
    cout<<"Daca sunteti client nou al acestui service introduceti 1, altfel 0 " ;
    in>>serv.client_nou;
    cout<<endl;
    cout<<"Ce numar de telefon are service-ul? ";
    in>>serv.numar_telefon;
    cout<<endl;
    cout<<"Ce adresa de mail are service-ul? ";
    in>>serv.adresa_mail;
    cout<<endl;
    if(serv.program != NULL)
        delete[] serv.program;
    cout<<"Introduceti programul service-ului de luni pana vineri sub forma 00-00 ";
    char aux[20];
    in>>aux;
    cout<<endl;
    serv.program = new char[strlen(aux)+1];
    strcpy(serv.program, aux);
    cout<<endl;
    return in;
}

const Service& Service::operator++()
{
    this-> numar_strada++;
    return *this;
}

const Service Service:: operator++(int)
{
    Service aux(*this);
    this->numar_strada++;
    return aux;
}

Service& Service::operator-(Service serv)
{
    Service* p = new Service(*this);
    p->numar_strada -= serv.numar_strada;
    return* p;
}

class Programare
{
    private:
        int numar_masini_pe_care_vrei_sa_programezi;
        bool disponibilitate; // care se ia in calcul pentru toate masinile la un loc. Ex: daca 1 din 10 nu se poate repara, atunci niciuna nu se va putea repara.
        char* la_ce_programezi; // t pt tinichigerie, e pt parte electrica si m pt parte mecanica
        string* marca_masinii; // pt a vedea daca se poate repara la service
        float* capacitatea_cilindrica_a_masinii; // in litri
        double* nr_kilometri_total;
        string* data_si_ora_programarii;
    public:
        Programare();
        Programare(int numar_masini_pe_care_vrei_sa_programezi, string* data_si_ora_programarii, char* la_ce_programezi, bool disponibilitate);
        Programare(int numar_masini_pe_care_vrei_sa_programezi, bool disponibilitate, char* la_ce_programezi, string* marca_masinii, float* capacitatea_cilindrica_a_masinii, double* nr_kilometri_total, string* data_si_ora_programarii);
        Programare(const Programare& prog);
        ~Programare();
        Programare &operator=(const Programare& prog);
        friend istream& operator>>(istream& in, Programare& prog);
        friend ostream& operator<<(ostream& out, const Programare& prog);
        friend ifstream& operator>>(ifstream& in, Programare& prog);
        friend ofstream& operator<<(ofstream& out, const Programare& prog);
        const Programare& operator++();
        const Programare operator++(int);
        bool operator==(Programare & prog);
        bool operator<(const Programare& prog)const;
        int operator +(int a);
        Programare& operator-(Programare prog);
        explicit operator int();
        void programeaza();
};

Programare::Programare()
{
        this->numar_masini_pe_care_vrei_sa_programezi = 0;
        this->disponibilitate = 0;
        this->la_ce_programezi = NULL;
        this->marca_masinii = NULL;
        this->capacitatea_cilindrica_a_masinii = NULL;
        this->nr_kilometri_total = NULL;
        this->data_si_ora_programarii = NULL;
}

Programare::Programare(int numar_masini_pe_care_vrei_sa_programezi, string* data_si_ora_programarii, char* la_ce_programezi, bool disponibilitate)
{
        this->numar_masini_pe_care_vrei_sa_programezi = numar_masini_pe_care_vrei_sa_programezi;
        this->disponibilitate = disponibilitate;
        this->la_ce_programezi = new char[strlen(la_ce_programezi)+1];
        strcpy(this->la_ce_programezi, la_ce_programezi);
        this->data_si_ora_programarii = new string[2];
        for(int i=0;i<2;i++)
            this->data_si_ora_programarii[i]=data_si_ora_programarii[i];
        this->marca_masinii = NULL;
        this->capacitatea_cilindrica_a_masinii = NULL;
        this->nr_kilometri_total = NULL;
}

Programare::Programare(int numar_masini_pe_care_vrei_sa_programezi, bool disponibilitate, char* la_ce_programezi, string* marca_masinii, float* capacitatea_cilindrica_a_masinii, double* nr_kilometri_total, string* data_si_ora_programarii)
{
        this->numar_masini_pe_care_vrei_sa_programezi = numar_masini_pe_care_vrei_sa_programezi;
        this->disponibilitate = disponibilitate;
        this->la_ce_programezi = new char[strlen(la_ce_programezi)+1];
        strcpy(this->la_ce_programezi, la_ce_programezi);
        this->data_si_ora_programarii = new string[numar_masini_pe_care_vrei_sa_programezi];
        for(int i=0;i<numar_masini_pe_care_vrei_sa_programezi;i++)
            this->data_si_ora_programarii=data_si_ora_programarii;
        this->marca_masinii = new string[numar_masini_pe_care_vrei_sa_programezi];
        for (int i=0;i<numar_masini_pe_care_vrei_sa_programezi;i++)
            this->marca_masinii[i]=marca_masinii[i];
        this->capacitatea_cilindrica_a_masinii = new float[numar_masini_pe_care_vrei_sa_programezi];
        for(int i=0;i<numar_masini_pe_care_vrei_sa_programezi;i++)
            this->capacitatea_cilindrica_a_masinii[i] = capacitatea_cilindrica_a_masinii[i];
        this->nr_kilometri_total = new double[numar_masini_pe_care_vrei_sa_programezi];
        for(int i=0;i<numar_masini_pe_care_vrei_sa_programezi;i++)
            this->nr_kilometri_total[i]=nr_kilometri_total[i];
}

Programare::Programare(const Programare& prog)
{
        this->numar_masini_pe_care_vrei_sa_programezi = prog.numar_masini_pe_care_vrei_sa_programezi;
        this->disponibilitate = prog.disponibilitate;
        this->la_ce_programezi = new char[strlen(prog.la_ce_programezi)+1];
        strcpy(this->la_ce_programezi, prog.la_ce_programezi);
        this->data_si_ora_programarii = new string[2];

        for(int i=0;i<2;i++)
            this->data_si_ora_programarii[i]=prog.data_si_ora_programarii[i];
        if(prog.marca_masinii != NULL && prog.capacitatea_cilindrica_a_masinii != NULL && prog.nr_kilometri_total != NULL){
            this->marca_masinii = new string[prog.numar_masini_pe_care_vrei_sa_programezi];

            for (int i=0;i<prog.numar_masini_pe_care_vrei_sa_programezi;i++)
                this->marca_masinii[i]=prog.marca_masinii[i];
            this->capacitatea_cilindrica_a_masinii = new float[prog.numar_masini_pe_care_vrei_sa_programezi];

            for(int i=0;i<prog.numar_masini_pe_care_vrei_sa_programezi;i++)
                this->capacitatea_cilindrica_a_masinii[i] = prog.capacitatea_cilindrica_a_masinii[i];
            this->nr_kilometri_total = new double[prog.numar_masini_pe_care_vrei_sa_programezi];

            for(int i=0;i<prog.numar_masini_pe_care_vrei_sa_programezi;i++)
                this->nr_kilometri_total[i]=prog.nr_kilometri_total[i]; }
        else
        {
            this->marca_masinii = NULL;
            this->capacitatea_cilindrica_a_masinii = NULL;
            this->nr_kilometri_total = NULL;
        }
}

int Programare::operator+(int a)
{
    return this->numar_masini_pe_care_vrei_sa_programezi + a;
}

bool Programare::operator==(Programare & prog)
{
    bool ok = 1;
    if(this->numar_masini_pe_care_vrei_sa_programezi == prog.numar_masini_pe_care_vrei_sa_programezi)
        {
            for (int i=0;i<this->numar_masini_pe_care_vrei_sa_programezi;i++)
                if(this->capacitatea_cilindrica_a_masinii[i] != prog.capacitatea_cilindrica_a_masinii[i] || this->marca_masinii[i] != prog.marca_masinii[i] || this->nr_kilometri_total[i]!=prog.nr_kilometri_total[i])
                    ok = 0;
                if(ok==0)
                    return false;
        }
    else return false;
    return true;
}

Programare::operator int()
{
    return (int)this->numar_masini_pe_care_vrei_sa_programezi;
}
bool Programare::operator<(const Programare& prog) const
{
    return this->numar_masini_pe_care_vrei_sa_programezi<prog.numar_masini_pe_care_vrei_sa_programezi;
}

Programare& Programare::operator-(Programare prog)
{
    Programare* p = new Programare(*this);
    p->numar_masini_pe_care_vrei_sa_programezi -= prog.numar_masini_pe_care_vrei_sa_programezi;
    return *p;
}

Programare::~Programare()
{
    if(this->capacitatea_cilindrica_a_masinii != NULL)
        delete[] this->capacitatea_cilindrica_a_masinii;
    if(this->data_si_ora_programarii != NULL)
        delete[] this->data_si_ora_programarii;
    if(this->la_ce_programezi != NULL)
        delete[] this->la_ce_programezi;
    if(this->marca_masinii != NULL)
        delete[] this->marca_masinii;
    if(this->nr_kilometri_total != NULL)
        delete[] this->nr_kilometri_total;
}

Programare& Programare::operator=(const Programare& prog)
{
    if(this != &prog)
    {
        if(this->capacitatea_cilindrica_a_masinii != NULL)
            delete[] this->capacitatea_cilindrica_a_masinii;
        if(this->data_si_ora_programarii != NULL)
            delete[] this->data_si_ora_programarii;
        if(this->la_ce_programezi != NULL)
            delete[] this->la_ce_programezi;
        if(this->marca_masinii != NULL)
            delete[] this->marca_masinii;
        if(this->nr_kilometri_total != NULL)
            delete[] this->nr_kilometri_total;
        this->numar_masini_pe_care_vrei_sa_programezi = prog.numar_masini_pe_care_vrei_sa_programezi;
        this->disponibilitate = prog.disponibilitate;
        this->la_ce_programezi = new char[strlen(prog.la_ce_programezi)+1];
        strcpy(this->la_ce_programezi, prog.la_ce_programezi);
        this->data_si_ora_programarii = new string[2];
        for(int i=0;i<2;i++)
        this->data_si_ora_programarii[i]=prog.data_si_ora_programarii[i];
        if(prog.marca_masinii != NULL && prog.capacitatea_cilindrica_a_masinii != NULL && prog.nr_kilometri_total != NULL){
            this->marca_masinii = new string[prog.numar_masini_pe_care_vrei_sa_programezi];
            for (int i=0;i<prog.numar_masini_pe_care_vrei_sa_programezi;i++)
                this->marca_masinii[i]=prog.marca_masinii[i];
            this->capacitatea_cilindrica_a_masinii = new float[prog.numar_masini_pe_care_vrei_sa_programezi];
            for(int i=0;i<prog.numar_masini_pe_care_vrei_sa_programezi;i++)
                this->capacitatea_cilindrica_a_masinii[i] = prog.capacitatea_cilindrica_a_masinii[i];
            this->nr_kilometri_total = new double[prog.numar_masini_pe_care_vrei_sa_programezi];
            for(int i=0;i<prog.numar_masini_pe_care_vrei_sa_programezi;i++)
                this->nr_kilometri_total[i]=prog.nr_kilometri_total[i];}
        else
        {
            this->marca_masinii = NULL;
            this->capacitatea_cilindrica_a_masinii = NULL;
            this->nr_kilometri_total = NULL;
        }
    }
    return *this;
}
istream& operator>>(istream& in, Programare& prog)
{
    if(prog.capacitatea_cilindrica_a_masinii != NULL)
        delete[] prog.capacitatea_cilindrica_a_masinii;
    if(prog.data_si_ora_programarii != NULL)
        delete[] prog.data_si_ora_programarii;
    if(prog.la_ce_programezi != NULL)
        delete[] prog.la_ce_programezi;
    if(prog.marca_masinii != NULL)
        delete[] prog.marca_masinii;
    if(prog.nr_kilometri_total != NULL)
        delete[] prog.nr_kilometri_total;
    cout<<"Introduceti numarul de masini pe care vreti sa le programati ";
    in>>prog.numar_masini_pe_care_vrei_sa_programezi;
    cout<<endl;
    cout<<"Introduceti data si ora la care vreti sa va programati dupa formatul: DD/MM/YYYY 00:00";
    cout<<endl;
    prog.data_si_ora_programarii = new string[2];
    in>>prog.data_si_ora_programarii[0]>>prog.data_si_ora_programarii[1];
    cout<<endl;
    if(prog.numar_masini_pe_care_vrei_sa_programezi>1)
        cout<<"Daca vreti sa programati masinile la tinichigerie, introduceti t, pentru partea mecanica m, iar pentru partea electrica e, ain ordine(dupa modelul 'eemt') ";
    if(prog.numar_masini_pe_care_vrei_sa_programezi==1)
        cout<<"Daca vreti sa programati masina la tinichigerie, introduceti t, pentru partea mecanica m, iar pentru partea electrica e ";
    char aux[100];
    in>>aux;
    prog.la_ce_programezi = new char[strlen(aux)+1];
    strcpy(prog.la_ce_programezi, aux);
    cout<<endl;
    if(prog.numar_masini_pe_care_vrei_sa_programezi>1)
        cout<<"Introduceti marcile celor "<<prog.numar_masini_pe_care_vrei_sa_programezi<<" masini despartite de cate un spatiu: ";
    if(prog.numar_masini_pe_care_vrei_sa_programezi==1)
        cout<<"Introduceti marca masinii ";
    prog.marca_masinii = new string[prog.numar_masini_pe_care_vrei_sa_programezi];
    for(int i=0;i<prog.numar_masini_pe_care_vrei_sa_programezi;i++)
        in>>prog.marca_masinii[i];
    if(prog.numar_masini_pe_care_vrei_sa_programezi>1)
        cout<<"Introduceti in ordine capacitatea cilindrica(in cmc) a celor "<<prog.numar_masini_pe_care_vrei_sa_programezi<<" masini, despartite de cate un spatiu: ";
    if(prog.numar_masini_pe_care_vrei_sa_programezi==1)
        cout<<"Introduceti capacitatea cilindrica a masinii(in cmc): ";
    prog.capacitatea_cilindrica_a_masinii = new float[prog.numar_masini_pe_care_vrei_sa_programezi];
    for(int i=0;i<prog.numar_masini_pe_care_vrei_sa_programezi; i++)
        in>>prog.capacitatea_cilindrica_a_masinii[i];
    if(prog.numar_masini_pe_care_vrei_sa_programezi>1)
        cout<<"Introduceti in ordine numarul de km al celor "<<prog.numar_masini_pe_care_vrei_sa_programezi<<" masini, despartite de cate un spatiu: ";
    if(prog.numar_masini_pe_care_vrei_sa_programezi==1)
        cout<<"Introduceti numarul de km al masinii: ";
    prog.nr_kilometri_total = new double[prog.numar_masini_pe_care_vrei_sa_programezi];
    for(int i=0;i<prog.numar_masini_pe_care_vrei_sa_programezi;i++)
        in>>prog.nr_kilometri_total[i];
    cout<<"Daca exista disponibilitate la acea data si ora introduceti 1 altfel 0: ";
    in>>prog.disponibilitate;
    cout<<endl;
    return in;
}

ifstream& operator>>(ifstream& in, Programare& prog)
{
    if(prog.capacitatea_cilindrica_a_masinii != NULL)
        delete[] prog.capacitatea_cilindrica_a_masinii;
    if(prog.data_si_ora_programarii != NULL)
        delete[] prog.data_si_ora_programarii;
    if(prog.la_ce_programezi != NULL)
        delete[] prog.la_ce_programezi;
    if(prog.marca_masinii != NULL)
        delete[] prog.marca_masinii;
    if(prog.nr_kilometri_total != NULL)
        delete[] prog.nr_kilometri_total;
    in>>prog.numar_masini_pe_care_vrei_sa_programezi;
    prog.data_si_ora_programarii = new string[2];
    in>>prog.data_si_ora_programarii[0]>>prog.data_si_ora_programarii[1];
    char aux[100];
    in>>aux;
    prog.la_ce_programezi = new char[strlen(aux)+1];
    strcpy(prog.la_ce_programezi, aux);
    prog.marca_masinii = new string[prog.numar_masini_pe_care_vrei_sa_programezi];
    for(int i=0;i<prog.numar_masini_pe_care_vrei_sa_programezi;i++)
        in>>prog.marca_masinii[i];
    prog.capacitatea_cilindrica_a_masinii = new float[prog.numar_masini_pe_care_vrei_sa_programezi];
    for(int i=0;i<prog.numar_masini_pe_care_vrei_sa_programezi; i++)
        in>>prog.capacitatea_cilindrica_a_masinii[i];
    prog.nr_kilometri_total = new double[prog.numar_masini_pe_care_vrei_sa_programezi];
    for(int i=0;i<prog.numar_masini_pe_care_vrei_sa_programezi;i++)
        in>>prog.nr_kilometri_total[i];
    in>>prog.disponibilitate;
    return in;
}

ostream& operator<<(ostream& out, const Programare& prog)
{

    if(prog.numar_masini_pe_care_vrei_sa_programezi<1)
    {
       out<<"Nu ati introdus niciuna dintre cerinte, astfel ca nu exista disponibilitate "<<endl;
    }
    else if(prog.numar_masini_pe_care_vrei_sa_programezi==1)
    {
        char aux='t';
        char aux2 = 'e';
        char aux1 = 'm';
        if(prog.marca_masinii != NULL){
            out<<"Masina pe care doriti sa o programati la service este marca "<<prog.marca_masinii[0]<<endl;
        }
        if(compara2caract(prog.la_ce_programezi[0], aux)==1)
            out<<"Vreti sa o programati la tinichigerie in data de "<<prog.data_si_ora_programarii[0]<<" la ora "<<prog.data_si_ora_programarii[1]<<endl;
        else if(compara2caract(prog.la_ce_programezi[0], aux1)==1)
            out<<"Vreti sa o programati pentru partea mecanica in data de "<<prog.data_si_ora_programarii[0]<<" la ora "<<prog.data_si_ora_programarii[1]<<endl;
        else if(compara2caract(prog.la_ce_programezi[0], aux2)==1)
            out<<"Vreti sa o programati pentru partea electrica in data de "<<prog.data_si_ora_programarii[0]<<" la ora "<<prog.data_si_ora_programarii[1]<<endl;
        if(prog.capacitatea_cilindrica_a_masinii != NULL) {
            out<<"Are "<< prog.capacitatea_cilindrica_a_masinii[0]<<" cmc "<<"si " << prog.nr_kilometri_total[0]<<" km rulati"<<endl; }
        if(prog.disponibilitate == 1)
            out<<"Masina a fost programata"<<endl;
        else
            out<<"Masina nu a putut fi programata deoarece nu exista disponibilitate pentru acea data"<<endl;
    }
    else if(prog.numar_masini_pe_care_vrei_sa_programezi>1)
    {

        if(prog.marca_masinii != NULL){
        out<<"Masinile pe care doriti sa le programati la service sunt marcile ";
        for (int i=0;i<prog.numar_masini_pe_care_vrei_sa_programezi;i++) {
        if(i < prog.numar_masini_pe_care_vrei_sa_programezi-1)
        out<<prog.marca_masinii[i]<<", ";
        if(i == prog.numar_masini_pe_care_vrei_sa_programezi-1)
            out<<prog.marca_masinii[i]<<".";}
        out<<endl;}
        char aux = 't';
        char aux1 = 'm';
        char aux2 = 'e';
    if(prog.marca_masinii != NULL){
        for (int i=0;i<prog.numar_masini_pe_care_vrei_sa_programezi;i++)
        {
        if(compara2caract(prog.la_ce_programezi[i], aux)==1)
            {out<<"Vreti sa programati " << prog.marca_masinii[i]<<" la tinichigerie in data de "<<prog.data_si_ora_programarii[0]<<" la ora "<<prog.data_si_ora_programarii[1]<<endl;;
            out<<endl;}

        else if(compara2caract(prog.la_ce_programezi[i], aux1)==1)
            {out<<"Vreti sa programati "<<prog.marca_masinii[i] <<" pentru partea mecanica in data de "<<prog.data_si_ora_programarii[0]<<" la ora "<<prog.data_si_ora_programarii[1]<<endl;;
            out<<endl;}

        else if(compara2caract(prog.la_ce_programezi[i], aux2)==1)
            {out<<"Vreti sa programati "<< prog.marca_masinii[i]<<" pentru partea electrica in data de "<<prog.data_si_ora_programarii[0]<<" la ora "<<prog.data_si_ora_programarii[1]<<endl;;
            out<<endl;}
        } }
        if(prog.marca_masinii != NULL && prog.capacitatea_cilindrica_a_masinii != NULL && prog.nr_kilometri_total != NULL){
        for (int i=0;i<prog.numar_masini_pe_care_vrei_sa_programezi;i++)
        out<<prog.marca_masinii[i] <<" are "<< prog.capacitatea_cilindrica_a_masinii[i]<<" cmc "<<"si are " << prog.nr_kilometri_total[i]<<" km"<<endl; }


        if(prog.disponibilitate == 1 && prog.marca_masinii != NULL && prog.capacitatea_cilindrica_a_masinii != NULL and prog.nr_kilometri_total != NULL)
            out<<endl<<"Masinile au fost programate"<<endl;
        else if(prog.disponibilitate != 1 && prog.marca_masinii != NULL && prog.capacitatea_cilindrica_a_masinii != NULL and prog.nr_kilometri_total != NULL)
            out<<endl<<"Masinile nu au putut fi programata deoarece nu exista disponibilitate pentru acea data"<<endl;

        if(prog.disponibilitate == 1 && prog.marca_masinii == NULL && prog.capacitatea_cilindrica_a_masinii == NULL and prog.nr_kilometri_total == NULL)
            out<<"Exista disponibilitate pentru acea data, insa trebuie sa mai introduceti niste informatii "<<endl;
        else if(prog.disponibilitate != 1 && prog.marca_masinii == NULL && prog.capacitatea_cilindrica_a_masinii == NULL and prog.nr_kilometri_total == NULL)
            out<<"Nu exista disponibilitate pentru acea data"<<endl;

    }
    return out;
}

ofstream& operator<<(ofstream& out, const Programare& prog)
{

    if(prog.numar_masini_pe_care_vrei_sa_programezi<1)
    {
       out<<"Nu ati introdus niciuna dintre cerinte, astfel ca nu exista disponibilitate "<<endl;
    }
    else if(prog.numar_masini_pe_care_vrei_sa_programezi==1)
    {
        char aux='t';
        char aux2 = 'e';
        char aux1 = 'm';
        if(prog.marca_masinii != NULL){
            out<<"Masina pe care doriti sa o programati la service este marca "<<prog.marca_masinii[0]<<endl;
        }
        if(compara2caract(prog.la_ce_programezi[0], aux)==1)
            out<<"Vreti sa o programati la tinichigerie in data de "<<prog.data_si_ora_programarii[0]<<" la ora "<<prog.data_si_ora_programarii[1]<<endl;
        else if(compara2caract(prog.la_ce_programezi[0], aux1)==1)
            out<<"Vreti sa o programati pentru partea mecanica in data de "<<prog.data_si_ora_programarii[0]<<" la ora "<<prog.data_si_ora_programarii[1]<<endl;
        else if(compara2caract(prog.la_ce_programezi[0], aux2)==1)
            out<<"Vreti sa o programati pentru partea electrica in data de "<<prog.data_si_ora_programarii[0]<<" la ora "<<prog.data_si_ora_programarii[1]<<endl;
        if(prog.capacitatea_cilindrica_a_masinii != NULL) {
            out<<"Are "<< prog.capacitatea_cilindrica_a_masinii[0]<<" cmc "<<"si " << prog.nr_kilometri_total[0]<<" km rulati"<<endl; }
        if(prog.disponibilitate == 1)
            out<<"Masina a fost programata"<<endl;
        else
            out<<"Masina nu a putut fi programata deoarece nu exista disponibilitate pentru acea data"<<endl;
    }
    else if(prog.numar_masini_pe_care_vrei_sa_programezi>1)
    {

        if(prog.marca_masinii != NULL){
        out<<"Masinile pe care doriti sa le programati la service sunt marcile ";
        for (int i=0;i<prog.numar_masini_pe_care_vrei_sa_programezi;i++) {
        if(i < prog.numar_masini_pe_care_vrei_sa_programezi-1)
        out<<prog.marca_masinii[i]<<", ";
        if(i == prog.numar_masini_pe_care_vrei_sa_programezi-1)
            out<<prog.marca_masinii[i]<<".";}
        out<<endl;}
        char aux = 't';
        char aux1 = 'm';
        char aux2 = 'e';
    if(prog.marca_masinii != NULL){
        for (int i=0;i<prog.numar_masini_pe_care_vrei_sa_programezi;i++)
        {
        if(compara2caract(prog.la_ce_programezi[i], aux)==1)
            {out<<"Vreti sa programati " << prog.marca_masinii[i]<<" la tinichigerie in data de "<<prog.data_si_ora_programarii[0]<<" la ora "<<prog.data_si_ora_programarii[1]<<endl;;
            out<<endl;}

        else if(compara2caract(prog.la_ce_programezi[i], aux1)==1)
            {out<<"Vreti sa programati "<<prog.marca_masinii[i] <<" pentru partea mecanica in data de "<<prog.data_si_ora_programarii[0]<<" la ora "<<prog.data_si_ora_programarii[1]<<endl;;
            out<<endl;}

        else if(compara2caract(prog.la_ce_programezi[i], aux2)==1)
            {out<<"Vreti sa programati "<< prog.marca_masinii[i]<<" pentru partea electrica in data de "<<prog.data_si_ora_programarii[0]<<" la ora "<<prog.data_si_ora_programarii[1]<<endl;;
            out<<endl;}
        } }
        if(prog.marca_masinii != NULL && prog.capacitatea_cilindrica_a_masinii != NULL && prog.nr_kilometri_total != NULL){
        for (int i=0;i<prog.numar_masini_pe_care_vrei_sa_programezi;i++)
        out<<prog.marca_masinii[i] <<" are "<< prog.capacitatea_cilindrica_a_masinii[i]<<" cmc "<<"si are " << prog.nr_kilometri_total[i]<<" km"<<endl; }


        if(prog.disponibilitate == 1 && prog.marca_masinii != NULL && prog.capacitatea_cilindrica_a_masinii != NULL and prog.nr_kilometri_total != NULL)
            out<<endl<<"Masinile au fost programate"<<endl;
        else if(prog.disponibilitate != 1 && prog.marca_masinii != NULL && prog.capacitatea_cilindrica_a_masinii != NULL and prog.nr_kilometri_total != NULL)
            out<<endl<<"Masinile nu au putut fi programata deoarece nu exista disponibilitate pentru acea data"<<endl;

        if(prog.disponibilitate == 1 && prog.marca_masinii == NULL && prog.capacitatea_cilindrica_a_masinii == NULL and prog.nr_kilometri_total == NULL)
            out<<"Exista disponibilitate pentru acea data, insa trebuie sa mai introduceti niste informatii "<<endl;
        else if(prog.disponibilitate != 1 && prog.marca_masinii == NULL && prog.capacitatea_cilindrica_a_masinii == NULL and prog.nr_kilometri_total == NULL)
            out<<"Nu exista disponibilitate pentru acea data"<<endl;

    }
    return out;
}



const Programare& Programare::operator++()
{
    this-> numar_masini_pe_care_vrei_sa_programezi++;
    return *this;
}
const Programare Programare:: operator++(int)
{
    Programare aux(*this);
    this->numar_masini_pe_care_vrei_sa_programezi++;
    return aux;
}
//programeaza este functionalitatea care verifica daca masinile se pot programa la service
void Programare::programeaza()
{
    string vect_masini[15];
    vect_masini[0] = "BMW";
    vect_masini[1] = "Audi";
    vect_masini[2] = "Mercedes-Benz";
    vect_masini[3] = "Lambo";
    vect_masini[4] = "Ferrari";
    vect_masini[5] = "Bugatii";
    vect_masini[6] = "Toyota";
    vect_masini[7] = "Porsche";
    vect_masini[8] = "Skoda";
    vect_masini[9] = "Dacia";
    vect_masini[10] = "Tesla";
    vect_masini[11] = "Honda";
    vect_masini[12] = "Renault";
    vect_masini[13] = "Mitsubishi";
    vect_masini[14] = "Volkswagen";
    bool ok=true;
        if(this->numar_masini_pe_care_vrei_sa_programezi>10){
            cout<<"Nu se pot programa mai mult de 10 masini la service!"<<endl;
            ok = false;
        }
        if(this->disponibilitate==0){
            cout<<"Nu exista disponibilitate pentru acea data, ne pare rau!"<<endl;
            ok = false;
        }
        for(int i=0;i<this->numar_masini_pe_care_vrei_sa_programezi;i++)
            if(caut_in_vct(this->marca_masinii[i], vect_masini) == 0){
                cout<<"Masina "<<this->marca_masinii[i]<<" nu se poate programa la service."<<endl;
                ok = false;
            }
        for(int i=0;i<this->numar_masini_pe_care_vrei_sa_programezi;i++)
            if(this->nr_kilometri_total[i] > 150000){
                cout<<"Masina "<<this->marca_masinii[i]<<" are prea multi km rulati pentru a se repara la acest service."<<endl;
                ok = false;
            }
        if(ok==true)
            cout<<"Ati fost programat cu succes in data de "<<this->data_si_ora_programarii[0]<<" la data "<<this->data_si_ora_programarii[1]<<endl;
}



class Angajat
{
    protected:
        const long long ID;
        bool functie_de_conducere;
        char departament; // t pt tinichigerie, e pt parte electrica si m pt parte mecanica
        char* Nume_Prenume;
        float ani_de_experienta;
        int* masini_reparate_in_ultimele_luni;
        float* Ore_lucrate_in_ultimele_luni;
        int nr_luni;
        string specializat_in; //marca masina
        string* ce_masini_poate_repara_angajatul;
        double salariu;
        int cate_masini_poate_repara;
        static int contorID;
        Service serv;
    public:

        Angajat();
        Angajat(char* Nume_Prenume, double salariu, Service serv);
        Angajat(bool functie_de_conducere, char departament, char* Nume_Prenume, float ani_de_experienta, int* masini_reparate_in_ultimele_luni, float* Ore_lucrate_in_ultimele_luni, int nr_luni, string specializat_in, string* ce_masini_poate_repara_angajatul, double salariu, int cate_masini_poate_repara, Service serv);
        Angajat(const Angajat& ang);
        ~Angajat();
        Angajat& operator=(const Angajat& ang);
        virtual ostream& Afisare_virtuala(ostream& out)const;
        virtual istream& Citire_virtuala(istream& in);
        friend ostream& operator<<(ostream& out, const Angajat& ang);
        friend istream& operator>>(istream& in, Angajat& ang);
        friend ofstream& operator<<(ofstream& out, const Angajat& ang);
        friend ifstream& operator>>(ifstream& in, Angajat& ang);

        const Angajat& operator++();
        const Angajat operator++(int);
        Angajat& operator-(Angajat ang);
        Angajat& operator+(int a);
        bool operator<(Angajat& ang);
        bool operator==(Angajat & ang);
        void setNume_Prenume(char* Nume_Prenume);
        void setFunctie_de_conducere(bool functie_de_conducere);
        void setdepartament(char departament);
        void setani_de_experienta(float ani_de_experienta);
        void setmasini_reparate_in_ultimele_luni(int* masini_reparate_in_ultimele_luni, int nr_luni);
        void setOre_lucrate_in_ultimele_luni(float* Ore_lucrate_in_ultimele_luni,int nr_luni);
        void setnr_luni(int nr_luni);
        void setspecializat_in(string specializat_in);
        void setce_masini_poate_repara_angajatul(string* ce_masini_poate_repara_angajatul, int cate_masini_poate_repara);
        void setsalariu(double salariu);

        long long getID();
        char* getNume_Prenume();
        bool getFunctie_de_conducere();
        char getdepartament();
        float getani_de_experienta();
        int* getmasini_reparate_in_ultimele_luni();
        float* getOre_lucrate_in_ultimele_luni();
        int getnr_luni();
        string getspecializat_in();
        string* getce_masini_poate_repara_angajatul();
        int getcate_masini_poate_repara();
        double getsalariu();
        float operator [](int index);
        explicit operator int();
        void afiseaza_angajatul_lunii(Angajat v[], int n);

};
int Angajat::contorID = 100;

Angajat::Angajat(bool functie_de_conducere, char departament, char* Nume_Prenume, float ani_de_experienta, int* masini_reparate_in_ultimele_luni, float* Ore_lucrate_in_ultimele_luni, int nr_luni, string specializat_in, string* ce_masini_poate_repara_angajatul, double salariu, int cate_masini_poate_repara, Service serv):ID(contorID++)
{
    this->functie_de_conducere = functie_de_conducere;
    this->departament = departament;
    this->Nume_Prenume = new char[strlen(Nume_Prenume)+1];
    strcpy(this->Nume_Prenume, Nume_Prenume);
    this->ani_de_experienta = ani_de_experienta;
    this->nr_luni = nr_luni;
    this->masini_reparate_in_ultimele_luni = new int[nr_luni];
    for (int i=0;i<nr_luni;i++)
        this->masini_reparate_in_ultimele_luni[i] = masini_reparate_in_ultimele_luni[i];
    this->Ore_lucrate_in_ultimele_luni = new float[nr_luni];
    for (int i=0;i<nr_luni;i++)
        this->Ore_lucrate_in_ultimele_luni[i] = Ore_lucrate_in_ultimele_luni[i];
    this->cate_masini_poate_repara = cate_masini_poate_repara;
    this->ce_masini_poate_repara_angajatul = new string[cate_masini_poate_repara];
    for(int i=0;i<cate_masini_poate_repara;i++)
        this->ce_masini_poate_repara_angajatul[i]=ce_masini_poate_repara_angajatul[i];
    this->salariu = salariu;
    this->specializat_in = specializat_in;
    this->serv=serv;
    //constructorul cu toti parametrii
}

Angajat::Angajat():ID(contorID++)
{
    this->functie_de_conducere = 0;
    this->departament = 'w';
    this->Nume_Prenume = new char[strlen("Neidentificat")+1];
    strcpy(this->Nume_Prenume, "Neidentificat");
    this->ani_de_experienta = 0;
    this->nr_luni = 0;
    this->masini_reparate_in_ultimele_luni = NULL;
    this->Ore_lucrate_in_ultimele_luni = NULL;
    this->cate_masini_poate_repara = 0;
    this->ce_masini_poate_repara_angajatul=NULL;
    this->salariu = -1000;
    this->specializat_in = "-";
}

Angajat::Angajat(char* Nume_Prenume, double salariu, Service serv):ID(contorID++)
{
    this->Nume_Prenume = new char[strlen(Nume_Prenume)+1];
    strcpy(this->Nume_Prenume, Nume_Prenume);
    this->salariu = salariu;
    this->functie_de_conducere = 0;
    this->departament = 'w';
    this->nr_luni = 0;
    this->ani_de_experienta = -1;
    this->masini_reparate_in_ultimele_luni = NULL;
    this->Ore_lucrate_in_ultimele_luni = NULL;
    this->cate_masini_poate_repara = 0;
    this->ce_masini_poate_repara_angajatul=NULL;
    this->specializat_in = "-";
    this->serv=serv;
}

Angajat::Angajat(const Angajat& ang):ID(ang.ID)
{

    this->functie_de_conducere = ang.functie_de_conducere;
    this->departament = ang.departament;
    this->Nume_Prenume = new char[strlen(ang.Nume_Prenume)+1];
    strcpy(this->Nume_Prenume, ang.Nume_Prenume);
    this->ani_de_experienta = ang.ani_de_experienta;
    this->nr_luni = ang.nr_luni;
    this->masini_reparate_in_ultimele_luni = new int[ang.nr_luni];

    for (int i=0;i<ang.nr_luni;i++)
        this->masini_reparate_in_ultimele_luni[i] = ang.masini_reparate_in_ultimele_luni[i];
    this->Ore_lucrate_in_ultimele_luni = new float[ang.nr_luni];
    for (int i=0;i<ang.nr_luni;i++)
        this->Ore_lucrate_in_ultimele_luni[i] = ang.Ore_lucrate_in_ultimele_luni[i];
    this->cate_masini_poate_repara = ang.cate_masini_poate_repara;
    this->ce_masini_poate_repara_angajatul = new string[ang.cate_masini_poate_repara];
    for(int i=0;i<ang.cate_masini_poate_repara;i++)
        this->ce_masini_poate_repara_angajatul[i]=ang.ce_masini_poate_repara_angajatul[i];
    this->salariu = ang.salariu;
    this->specializat_in = ang.specializat_in;
    this->serv=ang.serv;
}

Angajat::~Angajat()
{
    if(this->Nume_Prenume != NULL)
        delete[]this->Nume_Prenume;
    if(this->masini_reparate_in_ultimele_luni != NULL)
        delete[] this->masini_reparate_in_ultimele_luni;
    if(this->Ore_lucrate_in_ultimele_luni != NULL)
        delete[] this->Ore_lucrate_in_ultimele_luni;
    if(this->ce_masini_poate_repara_angajatul != NULL)
        delete[] this->ce_masini_poate_repara_angajatul;

}

Angajat& Angajat::operator-(Angajat ang)
{
    Angajat* p= new Angajat(*this);
    p->ani_de_experienta -= ang.ani_de_experienta;
    return *p;
}

 Angajat::operator int()
{
    return (int)this->cate_masini_poate_repara;
}

Angajat& Angajat::operator+(int a)
{
    Angajat* p= new Angajat(*this);
    p->salariu += a;
    return *p;
}

Angajat& Angajat::operator=(const Angajat& ang)
{
    if(this != &ang)
    {
        if(this->Nume_Prenume != NULL)
            delete[]this->Nume_Prenume;
        if(this->masini_reparate_in_ultimele_luni != NULL)
            delete[] this->masini_reparate_in_ultimele_luni;
        if(this->Ore_lucrate_in_ultimele_luni != NULL)
            delete[] this->Ore_lucrate_in_ultimele_luni;
        if(this->ce_masini_poate_repara_angajatul != NULL)
            delete[] this->ce_masini_poate_repara_angajatul;
        this->serv=ang.serv;
        this->functie_de_conducere = ang.functie_de_conducere;
        this->departament = ang.departament;
        this->Nume_Prenume = new char[strlen(ang.Nume_Prenume)+1];
        strcpy(this->Nume_Prenume, ang.Nume_Prenume);
        this->ani_de_experienta = ang.ani_de_experienta;
        this->nr_luni = ang.nr_luni;
        this->masini_reparate_in_ultimele_luni = new int[ang.nr_luni];
        for (int i=0;i<ang.nr_luni;i++)
            this->masini_reparate_in_ultimele_luni[i] = ang.masini_reparate_in_ultimele_luni[i];
        this->Ore_lucrate_in_ultimele_luni = new float[ang.nr_luni];
        for (int i=0;i<ang.nr_luni;i++)
            this->Ore_lucrate_in_ultimele_luni[i] = ang.Ore_lucrate_in_ultimele_luni[i];
        this->cate_masini_poate_repara = ang.cate_masini_poate_repara;
        this->ce_masini_poate_repara_angajatul = new string[ang.cate_masini_poate_repara];
        for(int i=0;i<ang.cate_masini_poate_repara;i++)
            this->ce_masini_poate_repara_angajatul[i]=ang.ce_masini_poate_repara_angajatul[i];
        this->salariu = ang.salariu;
        this->specializat_in = ang.specializat_in;
    }
    return *this;
}

bool Angajat::operator==(Angajat& ang)
{
    if(strcmp(this->Nume_Prenume, ang.Nume_Prenume)==0 && this->ani_de_experienta==ang.ani_de_experienta && this->salariu == ang.salariu)
        return true;
    else return false;
}

bool Angajat::operator<(Angajat& ang)
{
    if(this->salariu < ang.salariu)
        return true;
    return false;
}

ostream& Angajat::Afisare_virtuala(ostream& out)const
{
        out<<"Persoana are ID-ul "<< this->ID<<endl;
    if(this->functie_de_conducere == 1)
        out<<"Are functie de conducere";
    else
        out<<"Nu are functie de conducere";
    out<<endl;
    if(this->departament=='t')
        out<<"Angajatul lucreaza in tinichigerie"<<endl;
    if(this->departament=='e')
        out<<"Angajatul lucreaza pe partea electrica"<<endl;
    if(this->departament=='m')
        out<<"Angajatul lucreaza pe partea mecanica"<<endl;
    out<<"Nume Prenume: " <<this->Nume_Prenume<<endl;
    out<<"Ani de experienta: "<<this->ani_de_experienta<<endl;
    if (this->masini_reparate_in_ultimele_luni != NULL)
    {
        out<< "In ultimele "<<this->nr_luni<<" luni a reparat ";
        for(int i=0;i<this->nr_luni;i++)
            out<<this->masini_reparate_in_ultimele_luni[i]<<" masini ";
        out<<endl;
    }
    else out<<"Nu a reparat nicio masina in ultimele luni"<<endl;
    if(this->Ore_lucrate_in_ultimele_luni != NULL)
    {
        out<< "In ultimele "<<this->nr_luni<<" luni a lucrat ";
        for(int i=0;i<this->nr_luni;i++)
            out<<this->Ore_lucrate_in_ultimele_luni[i]<<" ore ";
        out<<endl;
    }
    else out<<"Nu a lucrat ore in ultimele luni"<<endl;
    if(this->cate_masini_poate_repara != -1)
    {
        out<<"Angajatul poate repara masinile:";
        for(int i=0;i<this->cate_masini_poate_repara;i++){
            if(i==this->cate_masini_poate_repara-1)
                out<<this->ce_masini_poate_repara_angajatul[i];
            else
                out<<this->ce_masini_poate_repara_angajatul[i]<<" ";}
        out<<", dar este specializat in "<<this->specializat_in<<endl;
    }
    else out<<"Angajatul nu poate repara nicio masina."<<endl;
    out<<"Are salariul "<<this->salariu<<" ron"<<endl;
    out<<"Angajatul lucreaza la service-ul cu urmatoarele date\n";
    out<<this->serv<<endl<<endl;
    return out;
}

ofstream& operator<<(ofstream& out, const Angajat& ang)
{
        out<<"Persoana are ID-ul "<< ang.ID<<endl;
    if(ang.functie_de_conducere == 1)
        out<<"Are functie de conducere";
    else
        out<<"Nu are functie de conducere";
    out<<endl;
    if(ang.departament=='t')
        out<<"Angajatul lucreaza in tinichigerie"<<endl;
    if(ang.departament=='e')
        out<<"Angajatul lucreaza pe partea electrica"<<endl;
    if(ang.departament=='m')
        out<<"Angajatul lucreaza pe partea mecanica"<<endl;
    out<<"Nume Prenume: " <<ang.Nume_Prenume<<endl;
    out<<"Ani de experienta: "<<ang.ani_de_experienta<<endl;
    if (ang.masini_reparate_in_ultimele_luni != NULL)
    {
        out<< "In ultimele "<<ang.nr_luni<<" luni a reparat ";
        for(int i=0;i<ang.nr_luni;i++)
            out<<ang.masini_reparate_in_ultimele_luni[i]<<" masini ";
        out<<endl;
    }
    else out<<"Nu a reparat nicio masina in ultimele luni"<<endl;
    if(ang.Ore_lucrate_in_ultimele_luni != NULL)
    {
        out<< "In ultimele "<<ang.nr_luni<<" luni a lucrat ";
        for(int i=0;i<ang.nr_luni;i++)
            out<<ang.Ore_lucrate_in_ultimele_luni[i]<<" ore ";
        out<<endl;
    }
    else out<<"Nu a lucrat ore in ultimele luni"<<endl;
    if(ang.cate_masini_poate_repara != -1)
    {
        out<<"Angajatul poate repara masinile:";
        for(int i=0;i<ang.cate_masini_poate_repara;i++){
            if(i==ang.cate_masini_poate_repara-1)
                out<<ang.ce_masini_poate_repara_angajatul[i];
            else
                out<<ang.ce_masini_poate_repara_angajatul[i]<<" ";}
        out<<", dar este specializat in "<<ang.specializat_in<<endl;
    }
    else out<<"Angajatul nu poate repara nicio masina."<<endl;
    out<<"Are salariul "<<ang.salariu<<" ron"<<endl;
    out<<"Angajatul lucreaza la service-ul cu urmatoarele date\n";
    out<<ang.serv;
    return out;
}

istream& Angajat::Citire_virtuala(istream& in)
{
    if(ind==1)
        cout<<"Apasati enter pentru a incepe.";
    cin.get();
    cout<<endl;
    cout<<"Introduceti numele si prenumele angajatului \n";
    char aux[100];
    in.get(aux,99);
    if(this->Nume_Prenume != NULL)
        delete[] this->Nume_Prenume;
    this->Nume_Prenume = new char[strlen(aux)+1];
    strcpy(this->Nume_Prenume, aux);
    cout<<endl;
    cout<<"Daca are functie de conducere introduceti 1, altfel 0 ";
    in>>this->functie_de_conducere;
    cout<<endl;
    cout<<"Introduceti departamentul in care lucreaza angajatul dupa urmatorul model:"<<endl;
    cout<<"t pentru tinichigerie"<<endl;
    cout<<"m pentru partea mecanica"<<endl;
    cout<<"e pentru partea electrica"<<endl;
    in>>this->departament;
    cout<<endl;
    cout<<"Introduceti anii de experienta pe care ii are angajatul ";
    in>>this->ani_de_experienta;
    cout<<endl;
    cout<<"Pe cate luni contorizam? ";
    in>>this->nr_luni;
    cout<<endl;
    cout<<"Introduceti cate masini a reparat angajatul in ultimele "<<this->nr_luni<<" luni, pentru fiecare luna ";
    if(this->masini_reparate_in_ultimele_luni != NULL)
        delete[] this->masini_reparate_in_ultimele_luni;
    this->masini_reparate_in_ultimele_luni = new int[this->nr_luni];
    for(int i=0;i<this->nr_luni;i++)
        in>>this->masini_reparate_in_ultimele_luni[i];
    cout<<endl;
    cout<<"Introduceti orele pe care le-a lucrat angajatul in ultimele "<<this->nr_luni<<" luni, pentru fiecare luna ";
    if(this->Ore_lucrate_in_ultimele_luni != NULL)
        delete[] this->Ore_lucrate_in_ultimele_luni;
    this->Ore_lucrate_in_ultimele_luni = new float[this->nr_luni];
    for(int i=0;i<this->nr_luni;i++)
        in>>this->Ore_lucrate_in_ultimele_luni[i];
    cout<<endl;
    cout<<"Cate tipuri de masini diferite stie sa repare angajatul? ";
    cout<<endl;
    in>>this->cate_masini_poate_repara;
    if(this->ce_masini_poate_repara_angajatul != NULL)
        delete[] this->ce_masini_poate_repara_angajatul;
    this->ce_masini_poate_repara_angajatul = new string[this->cate_masini_poate_repara];
    cout<<endl;
    cout<<"Introduceti cate o marca de masina pe care o poate repara angajatul ";
    cout<<endl;
    for(int i=0;i<this->cate_masini_poate_repara;i++)
        in>>this->ce_masini_poate_repara_angajatul[i];
    cout<<"In ce tipuri de masini este specializat angajatul?";
    cout<<endl;
    in>>this->specializat_in;
    cout<<endl;
    cout<<"Ce salariu are angajatul lunar?"<<endl;
    in>>this->salariu;
    cout<<"Acum introduceti datele despre service-ul in care lucreaza angajatul"<<endl;
    in>>this->serv;
    return in;
}

istream& operator>>(istream& in, Angajat& ang)
{
    return ang.Citire_virtuala(in);
}

ostream& operator<<(ostream& out, const Angajat& ang)
{
    return ang.Afisare_virtuala(out);
}

ifstream& operator>>(ifstream& in, Angajat& ang)
{
    char aux[100];
    in.get(aux,99);
    if(ang.Nume_Prenume != NULL)
        delete[] ang.Nume_Prenume;
    ang.Nume_Prenume = new char[strlen(aux)+1];
    strcpy(ang.Nume_Prenume, aux);
    in>>ang.functie_de_conducere;
    in>>ang.departament;
    in>>ang.ani_de_experienta;
    in>>ang.nr_luni;
    if(ang.masini_reparate_in_ultimele_luni != NULL)
        delete[] ang.masini_reparate_in_ultimele_luni;
    ang.masini_reparate_in_ultimele_luni = new int[ang.nr_luni];
    for(int i=0;i<ang.nr_luni;i++)
        in>>ang.masini_reparate_in_ultimele_luni[i];
    if(ang.Ore_lucrate_in_ultimele_luni != NULL)
        delete[] ang.Ore_lucrate_in_ultimele_luni;
    ang.Ore_lucrate_in_ultimele_luni = new float[ang.nr_luni];
    for(int i=0;i<ang.nr_luni;i++)
        in>>ang.Ore_lucrate_in_ultimele_luni[i];
    in>>ang.cate_masini_poate_repara;
    if(ang.ce_masini_poate_repara_angajatul != NULL)
        delete[] ang.ce_masini_poate_repara_angajatul;
    ang.ce_masini_poate_repara_angajatul = new string[ang.cate_masini_poate_repara];
    for(int i=0;i<ang.cate_masini_poate_repara;i++)
        in>>ang.ce_masini_poate_repara_angajatul[i];
    in>>ang.specializat_in;
    in>>ang.salariu;
    in>>ang.serv;
    return in;
}


float Angajat::operator [](int index)
{
    if(index > 0 && index<this->nr_luni)
        return this->Ore_lucrate_in_ultimele_luni[index];
    else return -1;
}

const Angajat& Angajat::operator++()
{
    this-> ani_de_experienta++;
    this->salariu++;
    return *this;
}

const Angajat Angajat::operator++(int)
{
    Angajat aux(*this);
    this->ani_de_experienta++;
    this->salariu++;
    return aux;
}

void Angajat::setNume_Prenume(char* Nume_Prenume)
{
    if (this->Nume_Prenume != NULL)
        delete[] this->Nume_Prenume;
    this->Nume_Prenume = new char[strlen(Nume_Prenume)+1];
    strcpy(this->Nume_Prenume, Nume_Prenume);
}

void Angajat::setFunctie_de_conducere(bool functie_de_conducere)
{
    this->functie_de_conducere = functie_de_conducere;
}

void Angajat::setdepartament(char departament)
{
    this -> departament = departament;
}

void Angajat::setani_de_experienta(float ani_de_experienta)
{
    this->ani_de_experienta = ani_de_experienta;
}

void Angajat::setmasini_reparate_in_ultimele_luni(int* masini_reparate_in_ultimele_luni, int nr_luni)
{
    this->nr_luni = nr_luni;
    if(this->masini_reparate_in_ultimele_luni != NULL)
        delete[] this->masini_reparate_in_ultimele_luni;
    this->masini_reparate_in_ultimele_luni = new int[this->nr_luni];
    for(int i=0;i<this->nr_luni;i++)
        this->masini_reparate_in_ultimele_luni[i]=masini_reparate_in_ultimele_luni[i];
}

void Angajat::setOre_lucrate_in_ultimele_luni(float* Ore_lucrate_in_ultimele_luni, int nr_luni)
{
    this->nr_luni = nr_luni;

    if(this->Ore_lucrate_in_ultimele_luni != NULL)
        delete[] this->Ore_lucrate_in_ultimele_luni;
    this->Ore_lucrate_in_ultimele_luni = new float[this->nr_luni];
    for(int i=0;i<this->nr_luni;i++)
        this->Ore_lucrate_in_ultimele_luni[i] = Ore_lucrate_in_ultimele_luni[i];
}

void Angajat::setnr_luni(int nr_luni)
{
    this->nr_luni = nr_luni;
}

void Angajat::setspecializat_in(string specializat_in)
{
    this->specializat_in = specializat_in;
}

void Angajat::setce_masini_poate_repara_angajatul(string* ce_masini_poate_repara_angajatul, int cate_masini_poate_repara)
{
    this->cate_masini_poate_repara = cate_masini_poate_repara;
    if (this->ce_masini_poate_repara_angajatul != NULL)
        delete[] this->ce_masini_poate_repara_angajatul;
    this->ce_masini_poate_repara_angajatul = new string[this->cate_masini_poate_repara];
    for (int i=0;i<this->cate_masini_poate_repara;i++)
        this->ce_masini_poate_repara_angajatul[i] = ce_masini_poate_repara_angajatul[i];
}

void Angajat::setsalariu(double salariu)
{
    this->salariu = salariu;
}

char* Angajat::getNume_Prenume()
{
    return this->Nume_Prenume;
}

bool Angajat::getFunctie_de_conducere()
{
    return this->functie_de_conducere;
}

char Angajat::getdepartament()
{
    return this->departament;
}

float Angajat::getani_de_experienta()
{
    return this->ani_de_experienta;
}

int* Angajat::getmasini_reparate_in_ultimele_luni()
{
    return this ->masini_reparate_in_ultimele_luni;
}

float* Angajat::getOre_lucrate_in_ultimele_luni()
{
    return this->Ore_lucrate_in_ultimele_luni;
}

int Angajat::getnr_luni()
{
    return this->nr_luni;
}

string Angajat::getspecializat_in()
{
    return this->specializat_in;
}

string* Angajat::getce_masini_poate_repara_angajatul()
{
    return this->ce_masini_poate_repara_angajatul;
}

double Angajat::getsalariu()
{
    return this->salariu;
}

long long Angajat::getID()
{
    return this->ID;
}

int Angajat::getcate_masini_poate_repara()
{
    return this->cate_masini_poate_repara;
}

//angajatul lunii este functionalitatea care indica angajatul care a lucrat cele mai multe ore in ultima luna
void Angajat::afiseaza_angajatul_lunii(Angajat v[], int n)
{
    Angajat maxx;
    for (int i=0;i<n;i++)
    {
        if(v[i][v[i].getnr_luni()-1] > maxx[maxx.getnr_luni()-1])
            maxx = v[i];
    }
    cout<<"Angajatul lunii: "<<endl;
    cout<<maxx;
    cout<<"A lucrat cel mai mult in ultima luna, mai exact "<<maxx[maxx.getnr_luni()-1] <<" ore.";
}

class Electrician:public Angajat
{
private:
    bool are_facultate;
    string* cu_ce_protectii_izolante_lucreaza;
    string* pe_ce_masini_poate_pune_testerul_computerizat;
    double rating_clienti;
    int cate_masini_tester_computerizat;
    int nr_protectii;
public:
    Electrician():Angajat()
    {
        this->are_facultate=0;
        this->cu_ce_protectii_izolante_lucreaza=NULL;
        this->pe_ce_masini_poate_pune_testerul_computerizat=NULL;
        this->rating_clienti=-1.0;
        this->cate_masini_tester_computerizat=0;
        this->nr_protectii=0;
    }

    Electrician(char* Nume_Prenume, double salariu, Service serv):Angajat(Nume_Prenume, salariu, serv)
    {
        this->are_facultate=0;
        this->cu_ce_protectii_izolante_lucreaza=NULL;
        this->pe_ce_masini_poate_pune_testerul_computerizat=NULL;
        this->rating_clienti=-1.0;
        this->cate_masini_tester_computerizat=0;
        this->nr_protectii=0;
    }

    Electrician(bool functie_de_conducere, char departament, char* Nume_Prenume, float ani_de_experienta, int* masini_reparate_in_ultimele_luni, float* Ore_lucrate_in_ultimele_luni, int nr_luni, string specializat_in, string* ce_masini_poate_repara_angajatul, double salariu, int cate_masini_poate_repara, Service serv):Angajat(functie_de_conducere, departament, Nume_Prenume, ani_de_experienta, masini_reparate_in_ultimele_luni, Ore_lucrate_in_ultimele_luni, nr_luni, specializat_in, ce_masini_poate_repara_angajatul, salariu, cate_masini_poate_repara, serv)
    {
        this->are_facultate=are_facultate;
        this->cate_masini_tester_computerizat=0;
        this->nr_protectii=0;
        for(int i=0;i<this->nr_protectii;i++)
            this->cu_ce_protectii_izolante_lucreaza[i]=cu_ce_protectii_izolante_lucreaza[i];
        for(int i=0;i<this->nr_protectii;i++)
        this->pe_ce_masini_poate_pune_testerul_computerizat[i]=pe_ce_masini_poate_pune_testerul_computerizat[i];
        this->rating_clienti=rating_clienti;
    }

    Electrician(const Electrician& ang):Angajat(ang)
    {
        this->are_facultate=ang.are_facultate;
        this->cu_ce_protectii_izolante_lucreaza=ang.cu_ce_protectii_izolante_lucreaza;
        this->cate_masini_tester_computerizat=ang.cate_masini_tester_computerizat;
        this->nr_protectii=ang.nr_protectii;
        for(int i=0;i<this->nr_protectii;i++)
            this->cu_ce_protectii_izolante_lucreaza[i]=ang.cu_ce_protectii_izolante_lucreaza[i];
        for(int i=0;i<this->nr_protectii;i++)
            this->pe_ce_masini_poate_pune_testerul_computerizat[i]=ang.pe_ce_masini_poate_pune_testerul_computerizat[i];
        this->rating_clienti=ang.rating_clienti;
    }


    Electrician& operator=(const Electrician& ang)
    {
        if(this!=&ang)
        {
            if(this->cu_ce_protectii_izolante_lucreaza!= NULL)
                delete[] this->cu_ce_protectii_izolante_lucreaza;
            if(this->pe_ce_masini_poate_pune_testerul_computerizat!= NULL)
                delete[] this->pe_ce_masini_poate_pune_testerul_computerizat;
                Angajat::operator=(ang);
                this->are_facultate=ang.are_facultate;
                this->nr_protectii=ang.nr_protectii;
                this->cu_ce_protectii_izolante_lucreaza = new string[this->nr_protectii];
                for(int i=0;i<this->nr_protectii;i++)
                    this->cu_ce_protectii_izolante_lucreaza[i]=ang.cu_ce_protectii_izolante_lucreaza[i];
                this->cate_masini_tester_computerizat = ang.cate_masini_tester_computerizat;
                this->pe_ce_masini_poate_pune_testerul_computerizat = new string[this->cate_masini_tester_computerizat];
                for(int i=0;i<this->cate_masini_tester_computerizat;i++)
                    this->pe_ce_masini_poate_pune_testerul_computerizat[i]=ang.pe_ce_masini_poate_pune_testerul_computerizat[i];
                this->rating_clienti=ang.rating_clienti;
        }
        return *this;
    }

    virtual ostream& Afisare_virtuala(ostream& out)const
    {
        Angajat::Afisare_virtuala(out);
        if(this->are_facultate == 1)
            out<<"Electricianul are facultate in domeniul in care lucreaza."<<endl;
        else
            out<<"Electricianul nu are facultate in domeniul in care lucreaza."<<endl;
        out<<"Electricianul nostru poarta protectie izolanta formata din: ";
        for(int i=0;i<this->nr_protectii;i++)
            out<<this->cu_ce_protectii_izolante_lucreaza[i]<<" ";
        out<<endl;
        out<<"Angajatul poate folosi testerul computerizat pe masinile: ";
        for(int i=0;i<this->cate_masini_tester_computerizat;i++)
            out<<this->pe_ce_masini_poate_pune_testerul_computerizat[i]<<" ";
        out<<endl;
        out<<"Angajatul a primit de la clientii sai rating-ul de: "<<this->rating_clienti<<"/10"<<endl;
        return out;
    }

    friend ofstream& operator<<(ofstream& out, const Electrician& ang)
    {
        out<<(Angajat&)ang;
        if(ang.are_facultate == 1)
            out<<"Electricianul are facultate in domeniul in care lucreaza."<<endl;
        else
            out<<"Electricianul nu are facultate in domeniul in care lucreaza."<<endl;
        out<<"Electricianul nostru poarta protectie izolanta formata din: ";
        for(int i=0;i<ang.nr_protectii;i++)
            out<<ang.cu_ce_protectii_izolante_lucreaza[i]<<" ";
        out<<endl;
        out<<"Angajatul poate folosi testerul computerizat pe masinile: ";
        for(int i=0;i<ang.cate_masini_tester_computerizat;i++)
            out<<ang.pe_ce_masini_poate_pune_testerul_computerizat[i]<<" ";
        out<<endl;
        out<<"Angajatul a primit de la clientii sai rating-ul de: "<<ang.rating_clienti<<"/10"<<endl;
        return out;
    }

    virtual istream& Citire_virtuala(istream& in)
    {
        Angajat::Citire_virtuala(in);
        cout<<"Introduceti 1 daca angajatul are facultate in domeniu, altfel 0: ";
        in>>this->are_facultate;
        cout<<endl;
        if(this->cu_ce_protectii_izolante_lucreaza!= NULL)
            delete[] this->cu_ce_protectii_izolante_lucreaza;
        cout<<"Introduceti numarul de protectii izolante pe care le poarta electricianul, apoi numele acestora(exemplu:manusi) "<<endl;
        in>>this->nr_protectii;
        this->cu_ce_protectii_izolante_lucreaza=new string[this->nr_protectii];
        for(int i=0;i<this->nr_protectii;i++)
            in>>this->cu_ce_protectii_izolante_lucreaza[i];
        cout<<endl;
        if(this->pe_ce_masini_poate_pune_testerul_computerizat!= NULL)
            delete[] this->pe_ce_masini_poate_pune_testerul_computerizat;
        cout<<"Introduceti numarul de marci diferite de masini pe care angajatul poate folosi testerul computerizat, iar mai apoi marca acestora"<<endl;
        in>>this->cate_masini_tester_computerizat;
        this->pe_ce_masini_poate_pune_testerul_computerizat=new string[this->cate_masini_tester_computerizat];
        for(int i=0;i<this->cate_masini_tester_computerizat;i++)
            in>>this->pe_ce_masini_poate_pune_testerul_computerizat[i];
        cout<<endl;
       cout<<"Introduceti rating-ul pe care il are angajatul primit de la clientii sai:" ;
       in>>this->rating_clienti;
       cout<<endl;
        return in;
    }

    friend istream& operator>>(istream& in, Electrician& ang)
    {
        return ang.Citire_virtuala(in);
    }

    friend ostream& operator<<(ostream& out, const Electrician& ang)
    {
        return ang.Afisare_virtuala(out);
    }

    friend ifstream& operator>>(ifstream& in, Electrician& ang)
    {
        in>>(Angajat&)ang;
        in>>ang.are_facultate;
        if(ang.cu_ce_protectii_izolante_lucreaza!= NULL)
            delete[] ang.cu_ce_protectii_izolante_lucreaza;
        in>>ang.nr_protectii;
        ang.cu_ce_protectii_izolante_lucreaza=new string[ang.nr_protectii];
        for(int i=0;i<ang.nr_protectii;i++)
            in>>ang.cu_ce_protectii_izolante_lucreaza[i];
        if(ang.pe_ce_masini_poate_pune_testerul_computerizat!= NULL)
            delete[] ang.pe_ce_masini_poate_pune_testerul_computerizat;
        in>>ang.cate_masini_tester_computerizat;
        ang.pe_ce_masini_poate_pune_testerul_computerizat=new string[ang.cate_masini_tester_computerizat];
        for(int i=0;i<ang.cate_masini_tester_computerizat;i++)
            in>>ang.pe_ce_masini_poate_pune_testerul_computerizat[i];
        in>>ang.rating_clienti;
        return in;
    }

    ~Electrician()
    {
        if(this->cu_ce_protectii_izolante_lucreaza!=NULL)
            delete[] this->cu_ce_protectii_izolante_lucreaza;
        if(this->pe_ce_masini_poate_pune_testerul_computerizat!=NULL)
            delete[] this->pe_ce_masini_poate_pune_testerul_computerizat;
    }
    //bool vedeti_daca_poate_testa_masina(Programare prog);
};

class MeniuInteractiv
{
private:
    static MeniuInteractiv *obiect;
    MeniuInteractiv(){

    }
public:
    static MeniuInteractiv* getInstance(){
        if(!obiect)
            obiect=new MeniuInteractiv();
        return obiect;
    }

    void meniu(){
    Piesa *p[100];
    Angajat* a[100];
    Service* s[100];
    Programare* pr[100];
    int k=1;
    int ip=0;
    int is=0;
    int ia=0;
    int ipr=0;
    while(k==1){
        cout<<"\n Apasati 1 pentru a introduce o piesa auto ";
        cout<<"\n Apasati 2 pentru a introduce un service auto ";
        cout<<"\n Apasati 3 pentru a introduce o programare la service ";
        cout<<"\n Apasati 4 pentru a introduce un angajat al service-ului ";
        cout<<"\n Apasati 5 pentru a afisa angajatii ";
        cout<<"\n Apasati 6 pentru a afisa piesele auto ";
        cout<<"\n Apasati 7 pentru a afisa preturile pieselor ";
        cout<<"\n Apasati 8 pentru a afisa datele programarii ";
        cout<<"\n Apasati 9 pentru a afisa datele unui service ";
        cout<<"\n Apasati 10 pentru a inchide meniul interactiv\n ";
        int comanda;
        cin>> comanda;
        switch(comanda){

            case 1:{

                cout<<"Daca piesa pe care doriti sa o introduceti este o cutie de viteze, apasati din nou 1, altfel 0\n";
                bool cmd;
                cin>>cmd;
                if(cmd==0)
                {
                    p[ip]= new Piesa();
                    cin>>*p[ip];
                }
                else
                {
                   p[ip] = new Cutie_viteze();
                   cin>>*p[ip];
                }
                ip++;
                break;
            }
            case 2:{
                s[is]= new Service();
                cin>>*s[is];
                is++;
                break;
            }
            case 3:{
                pr[ipr] = new Programare();
                cin>>*pr[ipr];
                ipr++;
                break;
            }

            case 4:{

            cout<<"Daca angajatul pe care doriti sa il introduceti este electrician auto introduceti 1, altfel 0\n ";
            bool cmda;
            cin>>cmda;
            if(cmda==0)
            {
                a[ia] = new Angajat();
                cin>>*a[ia];
            }
            else
            {
                a[ia] = new Electrician();
                cin>>*a[ia];
            }
            ia++;
            break;
            }
            case 5:{
                if(ia == 0)
                    cout<< "Nu exista angajati de afisat "<<endl;
                for(int j=0; j<ia;j++)
                    cout<<*a[j]<<endl;
                cout<<endl;
                break;
            }
            case 6:
            {
            if(ip==0)
                cout<<"Nu exista piese de afisat"<<endl;
            for(int j=0;j<ip;j++)
                cout<<*p[j]<<endl;
            cout<<endl;
            break;
            }

            case 7:{
            if(ip==0)
                cout<<"Nu exista preturi de afisat pentru piese "<<endl;
            else {
            cout<<"Piesele au urmatoarele preturi: ";
            for(int j=0;j<ip;j++){
                if(j==ip-1
                   )
                    cout<<p[j]->getpret_piesa()<<" lei. ";
                cout<<p[j]->getpret_piesa()<<" lei, ";}
            cout<<endl;
            }
            break;
            }
            case 8:
            {
                if(ipr == 0)
                    cout<<"Nu exista programari de afisat "<<endl;
                for(int j=0;j<ipr;j++)
                    cout<<*pr[j]<<endl;
                cout<<endl;
                break;
            }
            case 9:
                {
                if(is == 0)
                    cout<<"Nu exista service-uri de afisat "<<endl;
                for(int j=0;j<is;j++)
                    cout<<*s[j]<<endl;
                cout<<endl;
                break;
                }
            case 10:
                {
                    cout<<"Ati decis sa inchideti meniul "<<endl;
                    k=0;
                    break;
                }
    }
    }
}
};
MeniuInteractiv* MeniuInteractiv::obiect=0;


int main()
{
    MeniuInteractiv *meniulMeu=meniulMeu->getInstance();
    meniulMeu->meniu();
//cout<<"\n                          Pentru a incepe testele, decomentati main-ul pentru fiecare clasa\n"<<endl;

/* Aici teste toti setteri si toti getteri pentru obiectul c din clasa Angajat.

int* masini_reparate_in_ultimele_luni1;
masini_reparate_in_ultimele_luni1 = new int[3];
masini_reparate_in_ultimele_luni1[0] = 3;
masini_reparate_in_ultimele_luni1[1] = 4;
masini_reparate_in_ultimele_luni1[2] = 6;
float* Ore_lucrate_in_ultimele_luni1;
Ore_lucrate_in_ultimele_luni1 = new float[3];
Ore_lucrate_in_ultimele_luni1[0] = 67;
Ore_lucrate_in_ultimele_luni1[1] = 72;
Ore_lucrate_in_ultimele_luni1[2] = 88;
string* ce_masini_poate_repara_angajatul1;
ce_masini_poate_repara_angajatul1 = new string[3];
ce_masini_poate_repara_angajatul1[0] = "BMW";
ce_masini_poate_repara_angajatul1[1] = "Tesla";
ce_masini_poate_repara_angajatul1[2] = "Lambo";

Angajat c;

c.setNume_Prenume("Raducu Andrei");
c.setFunctie_de_conducere(1);
c.setdepartament('t');
c.setani_de_experienta(3.76);
c.setnr_luni(3);
c.setmasini_reparate_in_ultimele_luni(masini_reparate_in_ultimele_luni1, 3);
c.setOre_lucrate_in_ultimele_luni(Ore_lucrate_in_ultimele_luni1,3);
c.setspecializat_in("Tesla");
c.setce_masini_poate_repara_angajatul(ce_masini_poate_repara_angajatul1, 3);
c.setsalariu(7289.29);

cout<<"ID-ul angajatului este: "<<c.getID()<<endl;
cout<<"Numele si prenumele angajatului este: "<<c.getNume_Prenume()<<endl;
cout<<"Are functie de conducere? "<<c.getFunctie_de_conducere()<<endl;
cout<<"Lucreaza in departamentul "<<c.getdepartament()<<endl;
cout<<"Ani de experienta: "<<c.getani_de_experienta()<<endl;
cout<<"Angajatul a reparat in ultimele 3 luni: ";
for(int i=0;i<c.getnr_luni();i++)
    cout<<c.getmasini_reparate_in_ultimele_luni()[i]<< " masini ";
cout<<endl;
cout<<"Angajatul a lucrat in ultimele 3 luni: ";
for(int i=0;i<c.getnr_luni();i++)
    cout<<c.getOre_lucrate_in_ultimele_luni()[i]<<" ore ";
cout<<endl;
cout<<"Angajatul poate repara "<<c.getcate_masini_poate_repara()<<" masini: ";
for(int i=0;i<c.getnr_luni();i++)
    cout<<c.getce_masini_poate_repara_angajatul()[i]<<", ";
cout<<"dar este specializat in reparatia autoturismelor: "<<c.getspecializat_in();
cout<<endl;
cout<<"Salariul angajatului este de: "<<c.getsalariu()<<" lei"<<endl;
*/


//Aici testez clasa Angajat:
/*
int* masini_reparate_in_ultimele_luni1;
masini_reparate_in_ultimele_luni1 = new int[3];
masini_reparate_in_ultimele_luni1[0] = 3;
masini_reparate_in_ultimele_luni1[1] = 4;
masini_reparate_in_ultimele_luni1[2] = 6;
float* Ore_lucrate_in_ultimele_luni1;
Ore_lucrate_in_ultimele_luni1 = new float[3];
Ore_lucrate_in_ultimele_luni1[0] = 67;
Ore_lucrate_in_ultimele_luni1[1] = 72;
Ore_lucrate_in_ultimele_luni1[2] = 88;
string* ce_masini_poate_repara_angajatul1;
ce_masini_poate_repara_angajatul1 = new string[3];
ce_masini_poate_repara_angajatul1[0] = "BMW";
ce_masini_poate_repara_angajatul1[1] = "Tesla";
ce_masini_poate_repara_angajatul1[2] = "Lambo";


Angajat A(1, 'e', "Raducanu Andrei", 2.5, masini_reparate_in_ultimele_luni1, Ore_lucrate_in_ultimele_luni1, 3, "Audi", ce_masini_poate_repara_angajatul1, 3000.78, 3);
//constructorul cu toti parametrii
cout<<A<<endl;

Angajat F;
cin>>F; // operatorul de citire(istream) ">>";
Angajat v[2]; //creez vectorul pentru a apela functionalitatea clase Angajat
v[0]=A;
v[1]=F;
cout<<v[0];
cout<<endl<<v[1];
//apelez functionalitatea clasei angajat
F.afiseaza_angajatul_lunii(v, 2);
*/
/*
Angajat B("Raducanu Andrei-Cosmin", 46.32);
//constructorul cu mai putini parametri
cout<<B<<endl;

Angajat C; // constructorul fara parametrii
//cout<<C<<endl;

//Angajat D = A; // constructorul de copiere
//cout<<D<<endl;

Angajat E;
E = B; // operatorul =
cout<<E;
*/

//Aici verific clasa Piesa
/*
Piesa P;
cout<<P<<endl; // constructorul fara parametrii

Piesa P1("Bujie", 15);// constructorul cu mai putini parametrii
cout<<P1<<endl;

Piesa P2(400, 1, "Nu", "Cilindru", 20); // constructorul cu toti parametrii
cout<<P2<<endl;

Piesa P3 = P1; // constructorul de copiere
cout<<P3<<endl;

Piesa P4;
P4 = P2; // operatorul =
cout<<P4<<endl;

Piesa P5;
cin>>P5;
cout<<P5<<endl;
*/

// Functia Verificare_disponibilitate verifica daca o cantitate dintr-o anumita piesa se afla pe stoc in acest moment.
//Ce se afla pe stoc este reprezentat in vectorul de string-uri q, iar pentru a da numarul de piese de acel tip este necesara
//utilizarea constructoriilor (chiar si cel cu mai putini parametri are ca parametru nr_total_piese_de_acest_tip).
/*
Piesa PP("Bujie", 8);
PP.verificare_disponibilitate("Bujie", 8);
*/
/*
//Aici verific clasa Service
Service S; // constructorul fara parametrii
cout<<S<<endl;

Service S1("Giurgiului", 118, "0777700770", "9:00 - 18:00"); // constructorul cu mai putini parametrii
cout<<S1<<endl;

Service S2("Giurgiului", 122, "0777700770", "10:00 - 19:00","ServicePOO@yahoomail.com", 0); // constructorul cu toti parametrii
cout<<S2<<endl;

Service S3 = S1; // constructorul de copiere
cout<<S3<<endl;

Service S4;
S4 = S2; // operatorul de atribuire
cout<<S4<<endl;
*/

//Service S5("Giurgiului", 122, "077777788", "08-20");
//S5.calcul_timp_pana_la_service(18, 30, 70, 5, 35);

/*
Programare P; // constructorul fara parametri
cout<<P<<endl;
*/
/*
string* a;
a= new string[2];
 a[0]= "31.05.2021";
 a[1]= "12:30";

 string* m;
 m = new string[2];
 m[0]="BMW";
 m[1]="Mercedes-Benz";

 double* nrkm;
 nrkm = new double[2];
 nrkm[0] = 160726.28;
 nrkm[1] = 96218.7;

 float* cc;
 cc = new float[2];
 cc[0] = 3000.0;
 cc[1] = 2700.0;

Programare P1(2, a, "te", 1);
cout<<P1; // constructorul cu putini parametrii

Programare P2(2, 1, "te", m, cc, nrkm, a); // constructorul cu toti parametrii
cout<<P2;

P2.programeaza();//verific daca se poate programa.

Programare P3 = P2; // constructorul cu toti parametrii
cout<<P3<<endl;

Programare P4; // operatorul =
P4 = P1;
cout<<P4;
*/
/*
Cutie_viteze p,q;
cin>>p;
Cutie_viteze e=p;
cout<<endl<<e;
q=e;
cout<<endl<<q;*/

/*
Angajat e,p;
cin>>e;
p=e;cout<<p;
*/
/*
Preturi* preturi[3];
preturi[0] = new Piesa;
preturi[1] = new Piesa;
preturi[2] = new Cutie_viteze;

cin>>static_cast<Piesa&>(*(preturi[0]));
cin>>static_cast<Piesa&>(*(preturi[1]));
cin>>static_cast<Cutie_viteze&>(*(preturi[2]));


for(int i=0;i<3;i++)
{
    if(typeid(*(preturi[i]))==typeid(Piesa))
        cout<<static_cast<Piesa&>(*(preturi[i]));
    else
        cout<<static_cast<Cutie_viteze&>(*(preturi[i]));
}
*/

vector <Angajat> vectorAngajati;
Angajat angajat1, angajat2, angajat3, angajat4;

fin1>>angajat1;
fin1>>angajat2;
fin1>>angajat3;
fin1>>angajat4;

vectorAngajati.push_back(angajat1);
vectorAngajati.push_back(angajat4);
vectorAngajati.push_back(angajat3);
vectorAngajati.push_back(angajat2);

for(auto ir=vectorAngajati.begin();ir!=vectorAngajati.end();ir++)
{
    g<<(*ir)<<endl<<endl;
}

list <Piesa> listaPiese;
Piesa piesa1, piesa2;
Cutie_viteze cutie1, cutie2;

fin2>>piesa1;
fin2>>piesa2;
fin2>>cutie1;
fin2>>cutie2;

listaPiese.push_back(piesa1);
listaPiese.push_back(piesa2);
listaPiese.push_front(cutie2);
listaPiese.push_back(cutie1);

list <Piesa>::iterator it;
for(it=listaPiese.begin();it!=listaPiese.end();it++)
{
    g<<*it<<endl;
}

map <int, Service> mapServiceuri;
Service service1, service2, service3;
fin3>>service1;
fin3>>service2;
fin3>>service3;
mapServiceuri.insert(pair<int, Service>(1, service1));
mapServiceuri[2]=service2;
mapServiceuri[3]=service3;

map<int, Service>::iterator itr;
for(itr=mapServiceuri.begin();itr!=mapServiceuri.end();itr++)
{
    g<< '\t' << itr->first<< '\t' << itr->second << '\n';
}

set<Programare> setProgramari;
Programare programare1, programare2, programare3, programare4;
fin4>>programare1;
fin4>>programare2;
programare3=programare1;
programare4=programare2;

setProgramari.insert(programare1);
setProgramari.insert(programare2);
setProgramari.insert(programare3);
setProgramari.insert(programare4);

set<Programare>::iterator itrr;
g<<endl<<endl;
for(auto itrr=setProgramari.begin();itrr!=setProgramari.end();itrr++)
{
    g<<*itrr<<endl;
}

    fin1.close();
    fin2.close();
    fin3.close();
    fin4.close();
    g.close();
    return 0;
}
