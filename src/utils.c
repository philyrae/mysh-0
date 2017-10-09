#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "utils.h"

void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
  // TODO: Fill this!
  char key[] = {'\n'};
  char* check;
  char buffer[8096] = "";
  char* parser[1024];
  char* token;
  int i, flag, pos_null, numOfNull, pos_command;
  *argc = 0;
  flag = 0;
  numOfNull = 0;
  pos_command = 0;
  
  for(i = 0; i < 1024; i++){
		parser[i] = malloc(1024);
  }
  
  check = strpbrk(command, key);
  
  while(check != NULL){
  	numOfNull++;
  	pos_null = (int)(check - command);
  	check = strpbrk(check+1, key);
  }
  
  if(numOfNull == 0){
  	strncpy(buffer, command, strlen(command));
  }
  else{  	
  	if(numOfNull == 1 && pos_null == strlen(command)-1){
  		strncpy(buffer, command, strlen(command)-1);
  	}
  	else{
  		strncpy(buffer, command, strlen(command));
  	}
  }
  
  token = strtok(buffer, " ");
  
  while(token != NULL){
  	if(flag == 0){
	  	pos_command++;
	  }
  	if((!(strcmp(token, "pwd")) || !(strcmp(token, "cd")))){
  		flag = 1;
  	}
  	strcpy(parser[*argc], token);
  	(*argc)++;
  	
  	token = strtok(NULL, " ");
  }
  
  printf("pos_com: %d\n", pos_command);
  printf("(*argc): %d\n", (*argc));
  
  if(flag == 1){
  	pos_command -= 1;
  }
  
  (*argc) -= pos_command;
  
  printf("(*argc): %d\n", (*argc));
  
  *argv = (char **)malloc(sizeof(char **) * (*argc));
  if(*argc == 0){
  	(*argv)[0] = (char *)malloc(strlen("") * sizeof(char*));
  	strcpy((*argv)[0], "");
  	(*argc)++;
  }
  else{
  	for(i = 0; i < *argc; i++){
  		(*argv)[i] = (char *)malloc(strlen(parser[pos_command]) * sizeof(char*));
  		strcpy((*argv)[i], parser[pos_command]);
  		pos_command++;
  	}
  }
  
  for(i = 0; i < 1024; i++){
		free(parser[i]);
  }  
  
}
