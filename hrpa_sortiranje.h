#include <iostream>

using namespace std;
typedef int tip;

void Podesi(int a[], int n, int i){
    int j,t;
     
    j = 2 * i + 1;
    t = a[i];
     
    while(j<n){
    	if(j < (n-1) && a[j] < a[j+1])j++;
    	if(t >= a[j])break;
     
    	a[i] = a[j];
    	i = j;
    	j = 2*j+1;
    }
     
    a[i] = t;
}
    
void StvoriGomilu(int a[], int n){
    int i;
    for(i= (n - 2)/2; i >= 0; i--) Podesi(a, n, i);
}

void HeapSort(int a[], int n){
    int i,t;
     
    StvoriGomilu(a,n);
    for(i = n; i >= 2; i--) {
   		t = a[i-1];
    	a[i-1] = a[0];
    	a[0] = t;
     
    	Podesi(a,i-1,0);
    }
}
