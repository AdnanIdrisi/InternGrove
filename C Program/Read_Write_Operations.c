#include <stdio.h>
#include <stdlib.h>

void writeToFile(char *filename) {
    FILE *file;
    char data[1000];

    file = fopen(filename, "w");
    if(file == NULL){
        printf("Error opening file for writing!\n");
        exit(1);
    }

    printf("\nEnter the text you want to write: ");
    getchar();
    fgets(data, sizeof(data), stdin);
    fputs(data, file);
    fclose(file);
    printf("\nData written to %s successfully.\n", filename);
}

void readFromFile(char *filename) {
    FILE *file;
    char ch;

    file = fopen(filename, "r");
    if(file == NULL){
        printf("Error opening file for reading! Make sure the file exists.\n");
        exit(1);
    }

    printf("\nContents of %s are:\n", filename);
    while((ch = fgetc(file)) != EOF){
		putchar(ch);
    }
    fclose(file);
}

int main(){
    char filename[100];
    int choice;

    printf("Enter the filename: ");
    scanf("%s", filename);

    while(1){
        printf("\nMenu:\n");
        printf("1. Write in file: %s\n",filename);
        printf("2. Read from file: %s\n",filename);
        printf("3. Change selected file\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                writeToFile(filename);
                break;
            case 2:
                readFromFile(filename);
                break;
            case 3:
            	printf("Enter the filename: ");
    			scanf("%s", filename);
    			break;
            case 4:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

