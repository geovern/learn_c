#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	
	// get file data
	// get window size ws
	// get the last ws lines of file data
	// sum it up and divide by ws
	
	int ws = 0; //window size

	if(argc == 1) {
		printf("Usage: ./future <filename> [--window N (default: 50)]");
		return 0;
	} else if (argc == 2) {
		ws = 50;
	} else if (argc > 3) { 
		if (strcmp(argv[2], "--window") == 0) {
			ws = atoi(argv[3]);
		} else {
			//error
		}
	} else {
		//error
	}

	FILE * fd = fopen(argv[1], "r"); // argv = dow_jones.txt
	if (!fd) 
		return 1;

	if (ws == 0) {
		perror("Window too small!");
		return 1;
	}
	printf("Window Size: %d\n", ws);
	
	//get last lines of file data
	float *buffer = malloc(ws * sizeof(float)); // float * means an array of floats?
	if (!buffer) {
		perror("GG's, failed data alocation");
		fclose(fd);
		return 1;
	}

	int count = 0; //number of lines read
	int index = 0; //resets every ws lines, used in buffer
	float value;

	while (fscanf(fd, "%f", &value) == 1) {
		buffer[index] = value; // basically saves last ws values in the buffer
		index = (index + 1) % ws; // every ws lines reset the buffer index
		count++;
	}

	if (count < ws) {
		perror("Window too large!");
		return 1;
	}
	
	double sum = 0.0;
	
	for (int i = 0; i < ws; ++i) {
		sum += buffer[i];
	}
	free(buffer);

	double SMA;

	if (argc == 2) 
		SMA = sum / 50;
	else 
		SMA = sum / ws;
	
	printf("SMA: %.2f\n", SMA);


	fclose(fd);
	return 0;
}
