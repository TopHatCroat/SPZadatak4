#include<iostream>
using namespace std;

struct element{
	int oznaka;
	bool zastavica;
};
struct tbstablo{
	element polje[10000];
};

typedef int cvor;
typedef tbstablo* btree; 

void initB(int x, btree stablo){
 	for(int i=0;i < 1000; i++) stablo->polje[i].zastavica = false;
    stablo->polje[1].oznaka = x;
    stablo->polje[1].zastavica = true;
    cout << "Inicijalizirano stablo, korjen " << x << endl;
}

cvor parentB(cvor n, btree stablo){
	if(n==1) return -1;
	return n/2;
}
cvor leftchildB(cvor n, btree stablo){
	if(!stablo->polje[2*n].zastavica) return -1;
	else return 2*n;
}
cvor rightchildB(cvor n, btree stablo){
	if(!stablo->polje[2*n+1].zastavica) return -1;
	else return 2*n+1;
}
int labelB(cvor n, btree stablo){
	return stablo->polje[n].oznaka;
}
void changelabelB(int x, cvor n,btree stablo){
	stablo->polje[n].oznaka = x;
}
int rootB(btree stablo){
	return 1;
}
void createleftB(int x, cvor n, btree stablo){
	if(!stablo->polje[2*n].zastavica && stablo->polje[n].zastavica){
		stablo->polje[2*n].oznaka = x;
		stablo->polje[2*n].zastavica = true;
	}
	else cout<<"Ne postoji"<<endl;
}
void createrightB(int x,cvor n,btree stablo){
	if(!stablo->polje[2*n+1].zastavica && stablo->polje[n].zastavica){
		stablo->polje[2*n+1].oznaka = x;
		stablo->polje[2*n+1].zastavica = true;
	}
	else cout<<"Ne postoji"<<endl;
}
void deleteB(cvor n, btree stablo){
	if(leftchildB(n,stablo) != -1)
		deleteB(leftchildB(n,stablo), stablo);	
	if(rightchildB(n,stablo)!=-1)
		deleteB(rightchildB(n,stablo), stablo);
	stablo->polje[n].zastavica = false;	
}


