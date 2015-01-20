#include <iostream>
#include <cstdlib>
#include <ctime>
#include "hrpa_sortiranje.h"
#include "binarno_pretrazivanje.h"
#include "prvo_dijete-sljedeci_brat.h"
#include "ophodnja_stabla.h"
//#include "binarno_polje.h" 
#include "binarno_pokazivac.h"

using namespace std;

void a1(){
	tstablo *stablo= new tstablo;
	initT(10,stablo);	
	createT(8,10,stablo);  
	createT(12,10,stablo); 
	cout << "Dodana djeca korjenu..." << endl;
	createT(15,8,stablo);
	createT(3,8,stablo);
	cout << "Dodana djeca prvom djetetu korjena..." << endl;
	cout << "Vrijednost prvog djeteta korjena: " << firstchildT(10, stablo) << endl;
	cout << "Vrijednost brata djeteta korjena: " << nextsiblingT(8, stablo)<<endl;
	cout<<"Vrijednost korijena: "<<labelT(10, stablo) << endl;
	cout << "Roditelj cvora 3: " << parentT(3, stablo) << endl;
	cout<<"Mijenjam oznaku korijena iz 10 u 5..."<<endl;
	changelabelT(5, 10, stablo);
	cout << "Vrijednost korjena je: " << labelT(10, stablo) << endl;
	cout << "Provjeravam da li cvor 8 ima brata: " << nextsiblingT(8,stablo)<<endl;
	cout << "Brisem stablo"<<endl;
	deleteT(5,stablo);
	system("pause");
}
void a2(){
	tstablo *stablo=new tstablo;
	int izbor;
	initT(1,stablo);
	createT(5,1,stablo);
	createT(10,1,stablo);
	createT(2,5,stablo); 
    createT(3,5,stablo); 
	createT(50,10,stablo); 
    createT(60,10,stablo);
    createT(11,2,stablo); 
    createT(12,2,stablo); 
    cout << "Kreirano stablo: \n\t\t1\n\t   5        10\n\t2    3   50    60\n      11 12\n";
	cout << endl << "Preorder: "; Preorder(rootT(stablo),stablo); 
	cout << endl << "Postorder: "; Postorder(rootT(stablo),stablo); 
	cout << endl << "Inorder: "; Inorder(rootT(stablo),stablo);
	cout << endl;
    delete stablo;
    system("pause");
}
void a3(){
     telepre *S= new telepre;
     int ulaz;
     S->lDijete = NULL;
	 S->dDijete = NULL;
	 for(int i=0; i<10; i++){
         cout<<"Unesite element "<< i+1 << "/10: ";
         cin >> ulaz;
         addElement(S,ulaz);
	 }
     sortAsc(S);
     cout<<endl;
     cout<<"Broj za trazenje: ";
     cin >> ulaz;

     telepre *found = search(S, ulaz);
     if(found == NULL)
                     cout<<"Uneseni broj ne postoji u stablu"<<endl<<endl;
     else
         cout << found->broj <<" je pronaden na adresi: "<< found << endl;
     delete S;
     system("pause");
     system("cls");
}

void a4(){
	btree stablo=new tbstablo;
	initB(100,stablo);
	cout << "Adresa korijena:" << rootB(stablo) << endl;
	cout << "Vrijednost korijena:" << labelB(rootB(stablo),stablo) << endl;
	cvor k = rootB(stablo);
	createleftB(90, k, stablo);
	createrightB(150, k, stablo);
	cout << "Korjenu dodani cvorovi 90 i 150" << endl;
	cvor lk = leftchildB(k, stablo);
	cvor dk = rightchildB(k, stablo);
	cout<<"Lijevo dijete korjena dobija cvorove 20 i 60..."<<endl;
	createleftB(20,lk,stablo);
	createrightB(60,lk,stablo);
	cvor dd = rightchildB( lk ,stablo);
	cout<<"Desno dijete korjena dobija cvorove 100 i 300..."<<endl;
	createleftB(100, dk, stablo);
	createrightB(300, dk, stablo);
	cout<<"Cvor s vrijednosti 5 dobija desno dijete 25..."<<endl;
	createrightB(25, dd, stablo);
	cout<<"Vrijednost lijevog dijeteta korijena: "<<labelB(leftchildB(rootB(stablo),stablo),stablo) << endl;
	cout<<"Mjenjam vrijednost korjena u 150: "<<endl;
	changelabelB(150,rootB(stablo),stablo);
	cout << "Vrijednost korijena:" << labelB(rootB(stablo),stablo) << endl;
	
	cout<<"Adresa roditelja cvora s oznakom 90: " << parentB(lk,stablo) << endl;
	cout<<"Lijevo dijete cvora 90 je na adresi: "<<leftchildB(lk,stablo)<<endl;
	cout<<"Desno dijete cvora 90 je na adresi : "<<rightchildB(lk,stablo)<<endl;
	cout<<"Stablo obrisano"<<endl;
	deleteB(leftchildB(k,stablo),stablo);
	system("pause");
}
void a5(){
     int polje[10];
     for(int i=0; i<10; i++){
             cout<<"Unesite element "<< i << " ";
             cin >> polje[i];
     }

	 cout << "Sortiram..." << endl;
     HeapSort(polje,5);
     cout << "Sortirano polje "<<endl;
     for(int i=0; i < 10; i++){
             cout<<polje[i]<<" ";
     }
     cout << endl;
     system("pause");
}

int main(){
	int izbor;
	do{
		system("cls");
		cout<<"(1) Prvo dijete - sljedeci brat\n(2) Ophodnja stabla\n(3) Pretrazivanje binarnog stabla\n(4) Binarno stablo\n(5) Sortiranje hrpom"<<endl;
		cin>>izbor;
		switch(izbor)
		{
			case 1:
				a1();
				break;
			case 2:
				a2();
				break;
			case 3:
				a3();
				break;
			case 4:
            	a4();
            	break;
            case 5:
            	a5();
            	break;
		}
		
	}while(izbor!=9);
	system("pause");
}

