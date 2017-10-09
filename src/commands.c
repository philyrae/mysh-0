#include <string.h>
#include <unistd.h>
#include <stdio.h>

#include "commands.h"

int do_cd(int argc, char** argv) {
  if (!validate_cd_argv(argc, argv))
    return -1;

  // TODO: Fill it!
  int result;
  result = chdir(argv[1]);
  
  if(result == 0){
  	
  }
  else if(result == -1){
  	printf("No such file or direcroty\n");
  }
  

  return 0;
}

int do_pwd(int argc, char** argv) {
  if (!validate_pwd_argv(argc, argv))
    return -1;

  // TODO: Fill it!
  char buf[2048];

	getcwd(buf, 2048);
	printf("%s\n", buf);

  return 0;
}

int validate_cd_argv(int argc, char** argv) {
  // TODO: Fill it!
  int i;
  
  if(argc == 1){
  	printf("there is not a specific argv.\n");
  	for(i = 0; i < argc; i++){
  		printf("%s ", argv[i]);
  	}
  	printf("\n");
  	return 0;
  }
  else if(argc == 2){
  	if(strcmp(argv[0], "cd")){
  		printf("Wrong command.\n");
  		for(i = 0; i < argc; i++){
  			printf("%s ", argv[i]);
  		}
  		printf("\n");
  		return 0;
  	}
  	else{
  		printf("validation pass\n");
  		return 1;
  	}
  }
  else{
  	printf("there are too many argv.\n");
  	for(i = 0; i < argc; i++){
  		printf("%s ", argv[i]);
  	}
  	printf("\n");
  	return 0;
  }
}

int validate_pwd_argv(int argc, char** argv) {
  // TODO: Fill it!
  int i;
  
  if(argc == 1){
  	if(strcmp(argv[0], "pwd")){
  		printf("Wrong command.\n");
  		for(i = 0; i < argc; i++){
  			printf("%s ", argv[i]);
  		}
  		printf("\n");
  		return 0;
  	}
  	else{
  		printf("validation pass\n");
  	 	return 1;
  	}
  }
  else{
  	printf("there are too many argv.\n");
  	for(i = 0; i < argc; i++){
  		printf("%s ", argv[i]);
  	}
  	printf("\n");
  	return 0;
  }
}
