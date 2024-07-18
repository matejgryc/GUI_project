typedef struct ToDo {
       int id;
       char task[256];
       int completed;
	struct ToDo *next;
} ToDo;

void add_todo_item(ToDo **head, int id, const char *task);
void display_todo_items(ToDo *head);
void mark_todo_completed(ToDo *head, int id);
void delete_todo(ToDo **head, int id);
void save_todo(ToDo *head, const char *filename);
void load_todo_items(ToDo **head, const char *filename);
