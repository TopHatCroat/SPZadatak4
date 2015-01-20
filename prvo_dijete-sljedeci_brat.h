#include<iostream>
using namespace std;

struct telement{
	int oznaka,dijete,brat;
};
struct tstablo{
	telement polje[10000];
	int korijen;
};

void initT(int x, tstablo* stablo){
	for(int i=0;i < 10000; i++){
		stablo->polje[i].oznaka = 0;
		stablo->polje[i].dijete = -1;
		stablo->polje[i].brat = -1;
	}
	stablo->polje[x].oznaka = 1;
	stablo->korijen = x;
}

int parentT(int n, tstablo* stablo){
	if(n==stablo->korijen) {
		cout<<"Korjen je Batman"<<endl;
		return -1;
	}
	for(int i=0; i<10000; i++){
		if(stablo->polje[i].dijete == n) return i;
		if(stablo->polje[i].brat == n) return parentT(i,stablo); 
	}

}
int firstchildT(int n, tstablo* stablo){
	return stablo->polje[n].dijete;
}

int nextsiblingT(int n, tstablo* stablo){
	return stablo->polje[n].brat;
}

int labelT(int n, tstablo* stablo ){
	return stablo->polje[n].oznaka;
}

int rootT(tstablo* stablo){
	return stablo->korijen;
}

void createT(int x, int n, tstablo* stablo){
	if(!stablo->polje[n].oznaka){
		cout<<"Cvor ne postoji"<<endl;
		return;
	}
	if(stablo->polje[n].dijete == -1) {
		stablo->polje[n].dijete = x;
	}
	else{ 
			n=stablo->polje[n].dijete; 	
			while(stablo->polje[n].brat != -1) n = stablo->polje[n].brat;
			stablo->polje[n].brat = x;			
	} 
	stablo->polje[x].brat =- 1;
	stablo->polje[x].dijete = -1;
	stablo->polje[x].oznaka = x * 5;
}

void changelabelT(int x,int n, tstablo* stablo){
	stablo->polje[n].oznaka = x;
}

void deleteT(int n,tstablo* stablo){
	if(firstchildT(n, stablo) != -1) deleteT(stablo->polje[n].dijete, stablo); 
	if(nextsiblingT(n, stablo) != -1) deleteT(stablo->polje[n].brat, stablo);
	stablo->polje[n].brat = -1;
	stablo->polje[n].dijete = -1;
	changelabelT(0, n, stablo);	
}

