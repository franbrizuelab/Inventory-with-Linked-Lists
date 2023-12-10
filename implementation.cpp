#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "1.2decla.h"
const int name_lenght = 25;
const int max_parts = 100;

 struct part{
	int number;
	char name[name_lenght + 1];
	int on_hand;
	struct part* next;
}part;
 struct part* head = NULL;

//Helps get the correct input when entering the name of a part
void read_line(char* str, int n) {
	char ch;
	int i = 0;
	while (isspace(ch = getchar()));
	while (ch != '\n' && ch != EOF) {
		if (i < n)
			str[i++] = ch;
		ch = getchar();
	}
	str[i] = '\0';
}

//Helps returning the position in the array of a certain part, or returning a negative number if it does not exist in the list
struct part* find_part(int number) {
	for (struct part* p = head; p->next != NULL && p->number > number; p = p->next)
		if (p != NULL && p->number == number) {
			printf("encontrao!\n");
			return p;
		}
	printf("Not found, sorry :(\n");
	return NULL;

}

void insert() {
	struct part* newnode, *prev, *cur;
	
	newnode = (struct part*)malloc(sizeof(struct part));
	printf("insert number of the piece: ");
	scanf("%d", &newnode->number);
	if (head != NULL) {
		for (prev = NULL, cur = head;
			cur != NULL && newnode->number > cur->number;
			prev = cur, cur = cur->next);
		if (cur != NULL && newnode->number == cur->number) {
			printf("Part already exists.\n");
			free(newnode);
			return;
		}
		printf("insert name of the piece: ");
		read_line(newnode->name, name_lenght);
		printf("Enter quantity on hand: ");
		scanf("%d", &newnode->on_hand);
		newnode->next = cur;
		if (prev == NULL)
			head = newnode;
		else
			prev->next = newnode;
	}
	else {
		newnode->next = head;
		head = newnode;
		printf("insert name of the piece: ");
		read_line(newnode->name, name_lenght);
		printf("Enter quantity on hand: ");
		scanf("%d", &newnode->on_hand);
	}
}

void search() {
	struct part* rpart;			//requested part
	int temp;
	printf("Enter the number of a part to search: ");
	scanf("%d", &temp);
	rpart = find_part(temp);
	if (rpart == NULL) {
		printf("We don't have that, sorry :c\n");
		return;
	}
	printf("Name of part: %s \nQuantity in stock: %d\n", rpart->name, rpart->on_hand);
}

void update() {
	struct part* rpart;			//requested part
	int temp, change;
	printf("Enter the number of a part to update: ");
	scanf("%d", &temp);
	rpart = find_part(temp);
	if (rpart == NULL) {
		printf("We don't have that, sorry :(\n");
		return;
	}
	printf("Enter change in quantity on hand: ");
	scanf("%d", &change);
	rpart->on_hand += change;
}
void display() {
	printf("Part Number      Part Name               Quantity on hand\n");
	for (struct part* p = head; p != NULL; p = p->next) {
		printf("%7d           %-25s %-9d\n", p->number, p->name, p->on_hand);
	}

}
