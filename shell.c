#include <stdlib.h>
#include <string.h>
#include <stdio.h>


#define MAX_LINE 80
#define MAX_ARGS 50

typedef struct command_type{
    char *data;
    char **args;
} Command;

Command *createCommand(char **args, int argc){
    Command *new_command = (Command *) malloc(sizeof(Command));
    if(new_command){
        if(argc > 0 && strlen(args[0])<MAX_LINE/2 + 1)
        new_command->data = args[0];
        new_command->args = args;
    }
    else{
        printf("Error allocating memory for type 'Command'\n");
    }

    return new_command;
}

int convertStrList(char *str, char **list){
    int auxList = 0, auxStr = 0, cursor;

    for(cursor=0; cursor<strlen(str); cursor++){
        char current = str[cursor];
        if(current != ' '){
            list[auxList][auxStr] = current;
            auxStr++;
        }
        else{
            auxList++;
            auxStr = 0;
        }
    }

    return auxList+1;
}

void main(void){
    char **list = (char **) malloc(sizeof(char *) * MAX_ARGS);
    int cursor;
    for(cursor=0; cursor<MAX_ARGS; cursor++){
        list[cursor] = (char *) malloc(sizeof(char) * (MAX_LINE/2 + 1));
    }

    int result = convertStrList("ls -al -br", list);
    printf("%s\n", list[0]);
    printf("%s\n", list[1]);
    printf("%s\n", list[2]);
    printf("%d\n", result);
}