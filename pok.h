//implementacija pomocu pokazivaca
#include <iostream>
using namespace std;

struct t_zivotinja { 
    int sifra,dan,mjesec,godina;
    char naziv[40];
    char vrsta[40];
    float cijena;
    };

struct t_sve_zivotinje { 
    t_zivotinja*element;
    t_sve_zivotinje*sljedeci;
    };

t_sve_zivotinje*novi; 

t_zivotinja* FirstL(t_sve_zivotinje*lista) { 
    return lista->sljedeci->element;
    }

int EndL(t_sve_zivotinje*lista) { 
    return 0;
    }

t_sve_zivotinje*NextL(int p, t_sve_zivotinje*lista) { 
    t_sve_zivotinje*zadnji=lista;
    int brojac=0;
    while(brojac<p&&zadnji!=NULL) {
        zadnji=zadnji->sljedeci;
        brojac++;
        }
    if(zadnji==NULL)return NULL; 
    else
        return zadnji->sljedeci; 
    }

t_sve_zivotinje*PreviousL(int p, t_sve_zivotinje*lista) { 
    t_sve_zivotinje*zadnji=lista; 
    int brojac=0;
    p-=2;
    while(brojac<p&&zadnji!=NULL) { 
        zadnji=zadnji->sljedeci;
        brojac++;
        }
    if(zadnji==NULL)return NULL;
    else
        return zadnji->sljedeci;
    }

t_sve_zivotinje*LocateL(int n,t_sve_zivotinje*lista) { 
    t_sve_zivotinje*zadnji=lista->sljedeci;
    while(zadnji!=NULL) { 
        if(zadnji->element->sifra==n) {
            cout<<"PRONADJENO!\n";
            return zadnji;
            }
        else zadnji=zadnji->sljedeci;
        }
    cout<<"NIJE PRONADJENO!\n";
    return NULL;
    }

void InsertL(t_zivotinja*novi, int p, t_sve_zivotinje*lista) { 
    t_sve_zivotinje*zadnji = lista; 
    t_sve_zivotinje*novi3=new t_sve_zivotinje; 
    novi3->element=novi; 
    novi3->sljedeci=NULL; 
    int brojac=0;
    while(brojac<p&&zadnji!=NULL) {
        zadnji=zadnji->sljedeci;
        brojac++;
        }
    if(brojac<p) { 
        cout<<"Ne mogu dodati na to mjesto!\n";
        return;
        }
    if(zadnji->sljedeci!=NULL) { 
        novi3->sljedeci=zadnji->sljedeci; 
        zadnji->sljedeci=novi3; 
        }
    else zadnji->sljedeci=novi3; 
    }

int DeleteL(int p, t_sve_zivotinje*lista) { 
    t_sve_zivotinje*zadnji=lista; 
    bool pogresan=false;
    int brojac=0;
    while(brojac<p-1) {
        zadnji=zadnji->sljedeci; 
        if(!zadnji->sljedeci) {
            pogresan=true;
            break; 
            }
        brojac++; //
        }
    if(pogresan==true)cout<<"Taj element ne postoji!\n";
    if(!pogresan) {
        t_sve_zivotinje*brisani_element=zadnji->sljedeci;
        zadnji->sljedeci=zadnji->sljedeci->sljedeci;
        delete brisani_element; 
        }
    return 0;
    }

t_zivotinja * RetrieveL(int p,t_sve_zivotinje*lista) {
    t_sve_zivotinje*zadnji=lista;
    int brojac=0;
    while(brojac<p&&zadnji!=NULL) {
        zadnji=zadnji->sljedeci;
        brojac++;
        }
    return zadnji->element;
    }

t_sve_zivotinje* InitL(t_sve_zivotinje*lista) { 
    lista= new t_sve_zivotinje; 
    lista->sljedeci=NULL; 
    return lista;
    }

void DeleteAll(t_sve_zivotinje*lista) { 
    t_sve_zivotinje*zadnji=lista->sljedeci;
    while(zadnji->sljedeci) {
        novi=zadnji->sljedeci;
        delete zadnji;
        zadnji=novi;
        }
    delete zadnji;
    lista->sljedeci=NULL;
    }

int NumberL(t_sve_zivotinje*lista) { 
    t_sve_zivotinje*zadnji=lista;
    int brojac=0;
    while(zadnji->sljedeci) {
        zadnji=zadnji->sljedeci;
        brojac++;
        }
    return brojac;
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
    while(novi->dan<1||novi->dan>31);
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
