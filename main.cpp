#include <iostream>
#include "polja.h"
//#include "pok.h"
#include <string.h>
using namespace std;
t_zivotinja*provjera=new t_zivotinja;
t_sve_zivotinje*zadnji2=new t_sve_zivotinje;
int br=0;

bool dodaj(t_sve_zivotinje*glava) {
    int brojac=NumberL(glava);
    bool uspjesno=false;
    t_zivotinja*novi=new t_zivotinja;
    UnosL(novi);
    while(brojac>=0) {
        if(brojac==0) { 
            InsertL(novi,0,glava);
            uspjesno=true;
            br=1;
            break;
            }//if
        provjera=RetrieveL(brojac,glava);
        if(novi->sifra>provjera->sifra) {
            InsertL(novi,brojac,glava); 
            uspjesno=true;
            br=brojac+1;
            break;
            }//if
        else
            brojac--;
        }//while
    if(!uspjesno)return 0;
    return 1;
    }//dodaj

void ispis(t_sve_zivotinje*glava) {
    t_zivotinja*trenutno;
    int brojac= NumberL(glava);
    if(br==0)return;
    for(int i=br; i<=brojac; i++) {
        trenutno=RetrieveL(i,glava);
        IspisL(trenutno);
        }//for
    }//ispis

void pretraga(t_sve_zivotinje*glava) {
    int brojac=NumberL(glava);
    t_zivotinja*trenutno;
    int brojac2=0;
    for(int i=1; i<=brojac; i++) {
        trenutno=RetrieveL(i,glava);
        if(trenutno->godina>2012) {
            IspisL(trenutno);
            brojac2++;
            }
        else if(trenutno->godina==2012&&trenutno->mjesec>9) {
            IspisL(trenutno);
            brojac2++;
            }
        else if(trenutno->godina==2012&&trenutno->mjesec==9&&trenutno->dan>23) {
            IspisL(trenutno);
            brojac2++;
            }
        }//for
    cout<<"Ukupan broj zivotinja dostavljenih nakon 23. rujna 2012 je: "<<brojac2<<endl;
    }//pretraga

bool brisi(t_sve_zivotinje*glava) {
    bool obrisano=0;
    cout<<"Naziv zivotinje: ";
    char naziv[40];
    cin.ignore();
    cin.getline(naziv,40);
    int brojac=NumberL(glava);
    t_zivotinja*trenutni;
    for(int i=1; i<=brojac; i++) {
        trenutni=RetrieveL(i,glava);
        if(strcmp(trenutni->naziv,naziv)==0) {
            DeleteL(i,glava);
            obrisano=1;
            }
        }
    return obrisano;
    }

bool brisi_sve(t_sve_zivotinje*glava) {
    bool obrisano=0;
    cout<<"Naziv vrste: ";
    char naziv[40];
    cin.ignore();
    cin.getline(naziv,40);
    int brojac=NumberL(glava);
    t_zivotinja*trenutni;
    for(int i=1; i<=brojac; i++) {
        trenutni=RetrieveL(i,glava);
        if(!strcmp(trenutni->vrsta,naziv)) { 
            DeleteL(i,glava);
            brojac=NumberL(glava);
            i=1;
            obrisano=1;
            }
        }
    return obrisano;
    }

void merge(t_zivotinja *a[],int low,int pivot,int high) {
    int h,i,j,k;
    t_zivotinja*b[500]; 
    h=low; 
    i=low;  
    j=pivot+1;  

    j=pivot+1;  

    while((h<=pivot)&&(j<=high)) { 
        if(a[h]->cijena>=a[j]->cijena) { 
            b[i]=a[h];    
            h++;
            }  
        else { 
            b[i]=a[j];
            j++;  
            }  
        i++;  
        }
    if(h>pivot) {
        for(k=j; k<=high; k++) { 
            b[i]=a[k];  
            i++;  
            }
        }
    else { 
        for(k=h; k<=pivot; k++ ) { 
            b[i]=a[k];  
            i++;  
            }
        }
    for(k=low; k<=high; k++) a[k]=b[k];  
    }
void mergesort(t_zivotinja *a[], int low,int high) {
    int pivot;
    if(low<high) {
        pivot=(low+high)/2;  
        mergesort(a,low,pivot);
        mergesort(a,pivot+1,high);
        merge(a,low,pivot,high);
        }
    }

void sortiraj(t_sve_zivotinje*glava) {
    int brojac=NumberL(glava);
    t_zivotinja*novi[brojac];
    for(int i=1; i<=brojac; i++)
        novi[i-1]=RetrieveL(i,glava);
    cout<<"ISPIS ELEMENATA (UZLAZNO)\n";
    for(int i=0; i<brojac; i++)
        IspisL(novi[i]);
    mergesort(novi,0,brojac-1);
    cout<<"SORTIRANI ELEMENTI SILAZNO\n===============================\n";
    for(int i=0; i<brojac; i++) {
        IspisL(novi[i]);
        }
    }

int main() {
    t_sve_zivotinje*glava;
    glava=InitL(glava);
    int izbor;
    do {
        system("cls");
        cout<<"1. Dodavanje novog zapisa u listu prema rastucoj sifri zivotinje\n";
        cout<<"2. Ispis sadrzaja liste pocevsi od sifre zivotinje koja je posljednja dodana\n";
        cout<<"3. Pretraga liste te ispis svih zivotinja koje su dostavljene nakon\n   23.rujna 2012. godine te njihov broj\n";
        cout<<"4. Brisanje pojedinacnih unosa prema nazivu zivotinje\n";
        cout<<"5. Brisanje svih zivotinja odabrane vrste\n";
        cout<<"6. Silazno sortiranje zivotinja prema cijeni i nazivu\n";
        cout<<"9. Izlaz\n";
        cout<<endl;
        cout<<"Vas izbor?: ";
        cin>>izbor;
        system("cls");
        switch(izbor) {
            case 1:
                if(dodaj(glava)==1)cout<<"Zapis uspjesno dodan\n";
                else cout<<"Zapis nije uspjesno dodan!\n";
                break;
            case 2:
                ispis(glava);
                break;
            case 3:
                pretraga(glava);
                break;
            case 4:
                if(brisi(glava)==1)cout<<"Uspjesno obrisano\n";
                else cout<<"Nije uspjesno obrisano\n";
                break;
            case 5:
                if(brisi_sve(glava)==1)cout<<"Uspjesno obrisano!\n";
                else cout<<"Nije uspjesno obrisano\n";
                break;
            case 6:
                sortiraj(glava);
            } //switch
        system("pause");
        }//do
    while(izbor!=9);
    return 0;
    }
