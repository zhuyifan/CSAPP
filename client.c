#include "csapp.h"
#include "stdio.h"

int main(){
	int clientfd = open_clientfd("elnux1.cs.umass.edu", 5250);
	if(clientfd < 0){
		printf("%s\n", "connection failed");
	}
	else{
		printf("%s\n", "Connected to server");
		FILE* file = Fdopen(clientfd, "a+");
		printf("%s\n", "Sending Spire ID 29939634");
		fprintf(file, "29939634");
		char *line = NULL;
		int count;
		getline(&line, &count, file);
		printf("%s", "Receiving problem: ");
		printf("%s\n", line);
	}
	return 0;
}