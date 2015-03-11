//implementacija pomocu polja
#include <iostream>
using namespace std;

struct t_zivotinja {  // struktura za pojedinacnu zivotinju
    int sifra,dan,mjesec,godina;
    char naziv[40];
    char vrsta[40];
    float cijena;
    };

struct t_sve_zivotinje { //elementi upisani u polje od 1000 elemenata
    t_zivotinja*element[1000];
    int kursor;
    };

int FirstL(t_sve_zivotinje*lista) {
    return 0;
    }

int EndL(t_sve_zivotinje*lista) {
    return lista->kursor;
    }

int NextL(int k,t_sve_zivotinje*lista) {
    return k+1;
    }

int PreviousL(int k,t_sve_zivotinje*lista) {
    return k-1;
    }

int LocateL(int n,t_sve_zivotinje*lista) {
    for(int i=0; i<lista->kursor; i++) {
        if(n==lista->element[i]->sifra)return i;
        }
    return lista->kursor; //endL
    }
void InsertL(t_zivotinja*novi, int k, t_sve_zivotinje*lista) {
    if(k>EndL(lista))
        cout<<"Prevelika pozicija!\n";

    else {//<=endl
        for (int i = EndL(lista); i > k; i--) {
            lista->element[i] = lista->element[i-1]; //prebacuje elem za jedan dalje
            }
        lista->element[k] = novi; // zamjenjuje stari elem. na novi
        lista->kursor = lista->kursor + 1; //mice kursor za jedan jer smo dodali elem
        }
    }
int DeleteL(int k, t_sve_zivotinje*lista) {
    k-=1;// ako kazemo da treba obrisati prvi element, zapravo treba obrisati nulti element , ako kazemo da treba 15 onda zapravo treba 14
    if(k>EndL(lista))//ako nasa lista ima samo npr. 10 elemenata a mi smo rekli da treba izbrisati stoti onda je k sigurno veci od endl i nemoze obrisati
        cout<<"Taj element ne postoji!\n";
    else {
        for(int i=k; i<EndL(lista); i++) {
            lista->element[i]=lista->element[i+1];//premjestaj se s elementa na element ( element s vece pozicije prebaci na manji )
            }
        lista->kursor=lista->kursor-1;//smanji kursor za jedan jer si izbrisao jedan element
        return 0;
        }
    }
    
void DeleteAll(t_sve_zivotinje*lista) {
    lista->kursor=0;
    }
    
int NumberL(t_sve_zivotinje*lista) {
    int k=lista->kursor;
    return k;
    }
    
t_zivotinja*RetrieveL(int k,t_sve_zivotinje*lista) {
    return lista->element[k-1];
    }
    
t_sve_zivotinje*InitL(t_sve_zivotinje*lista) {
    t_sve_zivotinje*novi=new t_sve_zivotinje;
    novi->kursor=0;
    return novi;
    }
    
t_zivotinja*UnosL(t_zivotinja*novi) {
    cout<<"Sifra= ";
    cin>>novi->sifra;
    cout<<"Vrsta= ";
    cin>>novi->vrsta;
    cout<<"Naziv= ";
    cin>>novi->naziv;
    cout<<"Cijena= ";
    cin>>novi->cijena;
    do {
        cout<<"Dan dostave= ";
        cin>>novi->dan;
        }
    while(novi->dan<1||novi->dan>32);
    do {
        cout<<"Mjesec dostave= ";
        cin>>novi->mjesec;
        }
    while(novi->mjesec<1||novi->mjesec>12);
    cout<<"Godina dostave= ";
    cin>>novi->godina;
    }

t_zivotinja*IspisL(t_zivotinja*novi) {
    cout<<"=====================\n";
    cout<<"Zivotinja\n";
    cout<<"---------------------\n";
    cout<<"Sifra= "<<novi->sifra<<endl;
    cout<<"Vrsta= "<<novi->vrsta<<endl;
    cout<<"Naziv= "<<novi->naziv<<endl;
    cout<<"Datum= "<<novi->dan<<"."<<novi->mjesec<<"."<<novi->godina<<endl;
    cout<<"Cijena= "<<novi->cijena<<endl;
    }
