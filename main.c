#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"



void main(void){
	ToDo *head = NULL;
	int choice, id;
	char task[256];

	load_todo_items(&head, "todo.txt");

	while(1) {
		printf("1. Add To-Do Item\n");
		printf("2. Display To-Do items\n");
		printf("3. Mark To-Do item completed\n");
		printf("4. Delete To-Do item\n");
		printf("5. Save and exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		
		switch (choice) {
			case 1:
				printf("Enter task: ");
				scanf(" %[^\n]", task);
				id = (head == NULL) ? 1 : head->id + 1;
				add_todo_item(&head, id, task);
				break;
			case 2:
				display_todo_items(head);
				break;
			case 3:
				printf("Enter task ID to mark as completed: ");
				scanf("%d", &id);
				mark_todo_completed(head, id);
				break;
			case 4:
				printf("Enter task ID to delete: ");
				scanf("%d", &id);
				delete_todo(&head, id);
				break;
			case 5:
				save_todo(head, "todo.txt");
				return;
			default:
				printf("Invalid choice. Please try again.\n");
		}
	}
}
