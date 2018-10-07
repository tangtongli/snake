#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <dos.h>

#define N 20

#include "tcs.h"

struct snake{
	int x,y;
	struct snake *prior;
	struct snake *next;
};
struct snake *head,*tail;

int **snake_init(){
	int i,j,k=1;
	int **p;
	p=(int**)calloc(N,sizeof(int*));
	for(i=0;i<N;i++)
	p[i]=(int*)calloc(N,sizeof(int));
	for(i=0;i<N;i++)
	for(j=0;j<N;j++)
	{
     if(i>0&&i<19){
		if(j==0||j==19)
		p[i][j]=1;
		else
		p[i][j]=0;
	}
	else
	p[i][j]=1;
}
  return p; 
}

void add_head(int a,int b){
	struct snake *p=NULL;
	p=(struct snake*)malloc(sizeof(struct snake));
	if(p==NULL)
	return ;
	p->prior=NULL;
	p->y=a;
	p->x=b;
	if(head==NULL){
		head=tail=p;
		p->next=NULL;
	}
	else{
		head->prior=p;
		p->next=head;
		head=p;
	}
	return ;
}

void delete_tail(){
	struct snake *q=NULL;
	q=tail;
	tail=q->prior;
	tail->next=NULL;
	free(q);
	return ;
	
}

void move(char ah,int **p){
	 if(ah=='a'){
    	right_move(p);
	}
    if(ah=='s'){
    	down_move(p);
	}
    if(ah=='d'){
    	left_move(p);
	}
    if(ah=='w'){
    	up_move(p);
	}
	return ;
}

int *food_get(int **q){
	int a,b;
	int *n;
	struct snake *p;
	srand(time(0));
	a=rand()%18+1;
	b=rand()%18+1;
	p=head;
	while(1){
		if(a==p->y&&b==p->x){
			n=food_get(q);
			return n;
		}
		if(p->next==NULL){
			break;
		}
		p=p->next;
	}
	n=&q[a][b];
	return n;
	
}


void right_move(int **q){
	if(q[head->y][head->x-1]==1){
		add_head(head->y,(head->x-1));
	}
	else{
	add_head(head->y,(head->x-1));
	delete_tail();
}
  return ;
}

void left_move(int **q){
	if(q[head->y][head->x+1]==1){
		add_head(head->y,(head->x+1));
	}
	else{
	add_head(head->y,head->x+1);
	delete_tail();
}
   return ;
}

void up_move(int **q){
	if(q[head->y-1][head->x]==1){
		add_head(head->y-1,head->x);
	}
	else{
	add_head(head->y-1,head->x);
    delete_tail();
}
   return ;
}

void down_move(int **q){
	if(q[head->y+1][head->x]==1){
		add_head(head->y+1,head->x);
	}
	else{
	add_head(head->y+1,head->x);
	delete_tail();
}
  return ;
}

void ouput(int **p,int *k){
	int i,j;
	struct snake *q=NULL;
	/*for(i=0;i<N;i++)
    for(j=0;j<N;j++)
    printf("%d ",p[i][j]);*/
    for(i=1;i<N-1;i++)
    for(j=1;j<N-1;j++){
    	p[i][j]=0;
	}
    *k=1;
    q=head;
    while(1){
    	p[q->y][q->x]=1;
    	q=q->next;
    	if(q->next==NULL){
    		p[q->y][q->x]=1;
    		break;
		}
	}
   for(i=0;i<N;i++)
  {
  printf("                     ");
   for(j=0;j<N;j++){
   	if(j==19)
   	printf("* \n");
   	else{
   		if(p[i][j]==1)
   		printf("* ");
   		else
   		printf("  ");
	   }
   }
}
   
}

int st(){
	int a=0;
	struct snake *p;
	p=head;
	while(1){
		a++;
		p=p->next;
		if(p->next==NULL)
		break;
	}
	return a;
}

void die(){
	char ch;
	struct snake *p;
	p=head->next;
	while(1){
		if(head->x==p->x&&head->y==p->y){
			system("cls");
			printf("\n\n\n\n\n\n                               ÓÎÏ·Ê§°Ü£¡£¡£¡£¡");
			printf("\n                               3ÃëºóÓÎÏ·¼ÌÐø£¡");
			Sleep(3000); 
			run();
		}
		if(p->next==NULL)
		break;
		p=p->next;
	}
	if(head->x==0||head->x==19){
		system("cls");
		printf("\n\n\n\n\n\n                                ÓÎÏ·Ê§°Ü£¡£¡£¡£¡");
		printf("\n                               3ÃëºóÓÎÏ·¼ÌÐø£¡"); 
		Sleep(3000);
	run();
	}
	if(head->y==0||head->y==19){
		system("cls");
		printf("\n\n\n\n\n\n                               ÓÎÏ·Ê§°Ü£¡£¡£¡£¡");
		printf("\n                               3ÃëºóÓÎÏ·¼ÌÐø£¡"); 
			Sleep(3000);
		    run();
	}
	return ;
}

void run(){
	head=NULL;
	tail=NULL;
	int **q,*n=NULL;
    int i,j,k,h,y=150;
    char ch,hh;
    q=snake_init();
    add_head(2,6);
    add_head(3,6);
    add_head(4,6);
    hh=ch='s';
    i=1;  
    while(1){
    h=get_num();
    system("color 60");
    system("title Ì°³ÔÉß");	
    k=st();
    if(n==NULL)
    n=food_get(q);
    move(ch,q);
    ouput(q,n);
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
			j=st();
			if(j!=k){
				n=NULL;
			}	
			int x=0;
	struct snake *p;
	p=head;
	while(1){
		x++;
		p=p->next;
		if(p->next==NULL)
		break;
	}
   if(x>h){
   	if(y==20){
   		Sleep(y);
	   }
	   else{
   	y=y-5;
   	Sleep(y);
   }
   }
   else
   Sleep(y);
		system("cls");
}
}

int get_num(){
	int x=0;
	struct snake *p;
	p=head;
	while(1){
		x++;
		p=p->next;
		if(p->next==NULL)
		break;
	}
	return x;
}
