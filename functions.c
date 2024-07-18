#include "functions.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void add_todo_item(ToDo **head, int id, const char *task){
	ToDo *new_item = (ToDo *)malloc(sizeof(ToDo));
	new_item->id = id;
	strncpy(new_item->task, task, 256);
	new_item->completed = 0;
	new_item->next = *head;
	*head = new_item;
}

void display_todo_items(ToDo *head){
	ToDo *current = head;
	while (current != NULL){
		printf("ID: %d\nTask: %s\nCompleted: %s\n\n", current->id, current->task, current->completed ? "Yes" : "No");
		current = current->next;
	}
}

void mark_todo_completed(ToDo *head, int id){
	ToDo *current = head;
	while (current != NULL){
		if (current->id == id){
			current->completed = 1;
			return;
		}
		current = current->next;
	}
	printf("To-Do item with ID %d not found\n", id);
}

void delete_todo(ToDo **head, int id){
	ToDo *current = *head;
	ToDo *previous = NULL;

	while (current != NULL && current->id != id){
		previous = current;
		current = current->next;
	}
	
	if (current == NULL){
		printf("To-Do itme with %d ID not found\n", id);
		return;
	}
}

void save_todo(ToDo *head, const char *filename){
	FILE *file = fopen(filename, "a");
	if (file == NULL) {
		perror("Error opening file");
		return;
	}

	ToDo *current = head;
	while (current != NULL) {
		fprintf(file, "%d,%s,%d\n", current->id, current->task, current->completed);
		current = current->next;
	}
	
	fclose(file);
}

void load_todo_items(ToDo **head, const char *filename) {
	FILE *file = fopen(filename, "a");
	if (file == NULL) {
		perror("Error opening file");
		return;
	}
	
	char line[512];
	while (fgets(line, sizeof(line), file)) {
		int id;
		char task[256];
		int completed;

		sscanf(line,"%d,%255[^,],%d", &id, task, &completed);
		add_todo_item(head, id, task);
		if (completed) {
			mark_todo_completed(*head, id);
		}
	}

	fclose(file);
}
