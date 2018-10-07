#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define N 20

#include "tcs.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
 
  run();
   /*int **q,*n=NULL;
    int i,j,k;
    char ch,hh;
    q=snake_init();
    add_head(2,6);
    add_head(3,6);
    add_head(4,6);
    hh=ch='s';
    i=1;
    
    while(1){
    k=st();
    if(n==NULL)
    n=food_get(q);
    move(ch,q);
   while(kbhit()!=0){  	        
    	   hh=getch();
    		if(hh=='a'||hh=='w'||hh=='d'||hh=='s'){
    		if(hh=='a'||hh=='d'){
    			if(i==1){
    				ch=hh;
    				i=0;
				}
			}
			else{
				if(i==0){
					ch=hh;
					i=1;
				}
			}
    	}
			}
			die();
			ouput(q,n);
			j=st();
			if(j!=k){
				n=NULL;
			}			 
		Sleep(250);
		system("cls");
		}
    /*for(i=0;i<N;i++)
    for(j=0;j<N;j++)
    printf("%d ",q[i][j]);*/
    
	return 0;
}
