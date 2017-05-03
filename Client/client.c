#include "csapp.h"
#include <stdio.h>

int MUL(int x, int y){
	return x * y;
}

int main(){
	int clientfd = open_clientfd("elnux1.cs.umass.edu", 5250);
	if(clientfd < 0){
		printf("%s\n", "connection failed");
	}
	else{
		printf("%s\n", "Connected to server");
		FILE* file = Fdopen(clientfd, "a+");
		//send Spire ID
		printf("%s\n", "Sending Spire ID 29939634");
		fprintf(file, "29939634");
		// recieve question
		char *line = NULL;
		int count;
		getline(&line, &count, file);
		printf("%s", "Receiving problem: ");
		printf("%s\n", line);
		//answer question
		char str[50];
		int num1;
		int num2;
		int result;
		sscanf(line, "%s %d %d", str, &num1, &num2);
		result = MUL(num1, num2);
		free(line);
		line = NULL;
		count =0;
		printf("Sending solution: %d\n", result);
		dprintf(clientfd, "%d", result);
		getline(&line, &count, file);
		printf("%s", line);
		free(line);
		line = NULL;

		//answer bonus question
		printf("Sending bonus: 42\n");
		dprintf(clientfd, "%s", "42");
		fflush(file);
		getline(&line, &count, file);
		printf("%s", line);
		free(line);
		line = NULL;
		//close file
		fclose(file);
		close(clientfd);
	}
	return 0;
}