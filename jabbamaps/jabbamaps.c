#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 256
#define MAX_CITY_LENGTH 100

struct path {
	char city1[64];
	char city2[64];
	int distance;
};

int main(int argc, char * argv[]) {
	//blah blah errors
	
	FILE *file = fopen(argv[1], "r");
	if (file == NULL) {
        	perror("Error opening file");
        	return 1;
	}

	char line[MAX_LINE_LENGTH];
	char city1[MAX_CITY_LENGTH], city2[MAX_CITY_LENGTH];
	int distance;

	while (fgets(line, sizeof(line), file)) {
        // Remove newline character if it exists
		line[strcspn(line, "\n")] = '\0';

        // Parse using sscanf
		if (sscanf(line, " %[^-]-%[^:]: %d", city1, city2, &distance) == 3) {
			printf("City 1: %s\n", city1);
			printf("City 2: %s\n", city2);
			printf("Distance: %d\n", distance);
			printf("-------------------\n");
		} else {
			printf("Invalid line format: %s\n", line);
		}
	}
	
	

	fclose(file);
	return 0;
}
