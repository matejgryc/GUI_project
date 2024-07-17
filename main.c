#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ToDo {
       int id;
       char task[256];
       int completed;
} ToDo;

void add_todo_item(ToDo head, int id, const char *task);
void display_todo_items(ToDo *head);
void mark_todo_completed(ToDo *head, int id);
void delete_todo(ToDo *head, int id);
void save_todo(Todo *head, const char *filename);


void main(void){
	while(1) {
	
	}
}

