#include <iostream>
using namespace std;
struct telepre{
	int broj;
	telepre *lDijete, *dDijete;
};

void addElement(telepre *stablo, int broj){
  telepre *zadnji, *novi;
  int dalje = 1;
	zadnji = stablo;
	do{
		if (broj > zadnji->broj){
			if (zadnji->dDijete != NULL){
				zadnji = zadnji->dDijete;
			}else{ 
				novi = new telepre;
				zadnji->dDijete=novi;
				novi->lDijete = NULL;
				novi->dDijete = NULL;
				novi->broj = broj;
				dalje=0;
			}
		}
		else{
			if (zadnji->lDijete != NULL){
				zadnji = zadnji -> lDijete;
			} else { 
				novi = new telepre;
				zadnji->lDijete=novi;
				novi->lDijete=NULL;
				novi->dDijete=NULL;
				novi->broj=broj;
				dalje=0;
			}
		}
	}while (dalje == 1);
};

void sortAsc(telepre *stablo){
  static telepre *korijen = stablo;
	if (stablo == NULL) return;
		sortAsc(stablo->lDijete);
	if (stablo != korijen) cout << stablo->broj << ", ";
		sortAsc(stablo->dDijete);
};

telepre *search(telepre *stablo, int broj){
  telepre *tekuci=stablo;
  while (tekuci){
    if ((tekuci->broj == broj) && (tekuci != stablo))break;
    if (broj > tekuci -> broj)
      tekuci = tekuci -> dDijete;
    else
      tekuci = tekuci->lDijete;
  };
  return tekuci;
};


