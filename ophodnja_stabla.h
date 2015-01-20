#include<iostream>
using namespace std;

void Preorder(int tekuci, tstablo* stablo){
   	cout<<tekuci<<" "; 
	if(firstchildT(tekuci,stablo) !=-1) 
		Preorder(firstchildT(tekuci,stablo),stablo);
	if(nextsiblingT(tekuci,stablo) !=-1) 
				Preorder(nextsiblingT(tekuci,stablo),stablo);
}
void Inorder(int tekuci,tstablo* stablo){
    if(firstchildT(tekuci,stablo)!=-1)  
    	Inorder(firstchildT(tekuci,stablo),stablo);
    cout<<tekuci<<" "; 
    if(firstchildT(tekuci,stablo)!=-1){ 
    	tekuci=firstchildT(tekuci,stablo);
    	while(nextsiblingT(tekuci,stablo)!=-1){
    		tekuci=nextsiblingT(tekuci,stablo);
    		Inorder(tekuci,stablo);
    	}
    }
}

void Postorder(int tekuci,tstablo* stablo){
	if(firstchildT(tekuci,stablo)!=-1)  
    	Postorder(firstchildT(tekuci,stablo),stablo);
     int tekuci2=tekuci; 
     if(firstchildT(tekuci2,stablo)!=-1){   
    	tekuci2=firstchildT(tekuci2,stablo);
    	while(nextsiblingT(tekuci2,stablo)!=-1){
    		tekuci2=nextsiblingT(tekuci2,stablo);
    		Postorder(tekuci2,stablo);
    	}
    }
    cout<<tekuci<<" ";
}

