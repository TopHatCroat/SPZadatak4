#include <iostream>
using namespace std;

struct tbstablo{
	int oznaka;
	tbstablo *lijevo,*desno;
};

typedef tbstablo* cvor;
typedef cvor btree;

void initB(int x, btree stablo){
    stablo->lijevo = NULL;
    stablo->desno = NULL;
    stablo->oznaka = x;
    cout << "Inicijalizirano stablo, korjen " << x << endl;
    }
    
cvor parentB(cvor n, btree stablo){
	cvor lRoditelj = NULL, dRoditelj = NULL;
      if (stablo->lijevo == n || stablo->desno == n) 
         return stablo;
      if (stablo->lijevo)  
         lRoditelj = parentB(n, stablo->lijevo);
      if (stablo->desno) 
         dRoditelj = parentB(n, stablo->desno);
      if (lRoditelj) 
         return lRoditelj;
      if (dRoditelj) 
         return dRoditelj;
      return NULL;   		     
}

cvor leftchildB(cvor n, btree stablo){
	return n->lijevo;
}

cvor rightchildB(cvor n, btree stablo){
	return n->desno;	
}

int labelB(cvor n, btree stablo){
	return n->oznaka;
}

void changelabelB(int x, cvor n, btree stablo){
	n->oznaka=x;
}

cvor rootB(btree stablo){
	return stablo;
}

void createleftB(int x,cvor n,btree stablo){
	if(n->lijevo)
		cout<<"Cvor postoji!"<<endl;	
	else{
	cvor novi=new tbstablo;
	n->lijevo=novi;
	novi->lijevo=NULL;
	novi->desno=NULL;
	novi->oznaka=x;
	}
}

void createrightB(int x,cvor n,btree stablo){
	if(n->desno)
		cout<<"Cvor postoji!"<<endl;	
	else{
	cvor novi=new tbstablo;
	n->desno=novi;
	novi->lijevo=NULL;
	novi->desno=NULL;
	novi->oznaka=x;
	}
}

void deleteB (cvor n, btree stablo) {
      if (n->lijevo)
         deleteB(n->lijevo, stablo);
      if (n->desno)
         deleteB(n->desno, stablo);
      if (n != rootB(stablo) && leftchildB(parentB(n, stablo),stablo)==n)
         parentB(n, stablo)->lijevo = NULL;
      else if (n != rootB(stablo))
           parentB(n, stablo)->desno = NULL;
      delete n;    
}

