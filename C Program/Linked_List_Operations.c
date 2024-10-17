#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtBeginning(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
    printf("%d inserted at the beginning.\n", new_data);
}

void deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref;
    struct Node* prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        printf("%d deleted from the list.\n", key);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("%d not found in the list.\n", key);
        return;
    }
    else{
	    prev->next = temp->next;
    	free(temp);
    	printf("%d deleted from the list.\n", key);
	}
}

void searchItem(struct Node* head, int key) {
    struct Node* current = head;
    int i=0;

    while (current != NULL) {
    	i++;
        if (current->data == key) {
            printf("%d found in the list at index %d.\n", key,i);
            return;
        }
        current = current->next;
    }
    printf("%d not found in the list.\n", key);
}


void displayList(struct Node* node) {
    if (node == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("The list contains: ");
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}


int main() {
    struct Node* head = NULL;
    int choice, value;

    while(1){
        printf("\nMenu:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Delete an item\n");
        printf("3. Search for an item\n");
        printf("4. Display the list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insertAtBeginning(&head, value);
                break;
            case 2:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;
            case 3:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                searchItem(head, value);
                break;
            case 4:
                displayList(head);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

