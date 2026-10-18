#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;
int main(){

	// 1. Get all env variable
	for(int i=0;environ[i]!=NULL;i++){
		printf("%s\n",environ[i]);
	}
	
	// 2. Request the environment variable
    	char *env_pointer = getenv("PATH");

  	if (env_pointer == NULL) {
        	printf("The environment variable 'PATH' was not found.\n");
        	return EXIT_FAILURE;
    	}

    	// 3. Make a local copy to safely manipulate or store the data
    	char *my_path = strdup(env_pointer);
    
    	if (my_path != NULL) {
        	printf("Current PATH: %s\n", my_path);
        
        	// Always free dynamically allocated copies when done
        	free(my_path); 
    	}

    	return EXIT_SUCCESS;
}
