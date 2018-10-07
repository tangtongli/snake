#ifndef __TCS_H__
#define __TCS_H__

struct snake;

int **snake_init();

void run();

void add_head(int a,int b);

int *food_get(int **q);

void right_move(int **q);

void left_move(int **q);

void up_move(int **q);

void down_move(int **q);

void move(char ah,int **p);

void delete_tail();

int st();

void die();

void ouput(int **p,int *k);


int get_num();

#endif
