#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <getopt.h>

char random()
{
	return rand()%100;
}

int main(int argc, char* argv[])
{
	const int TWO_LEN = 20;
	int opt,two_numbers = 0;

	// linux staff
	while ((opt = getopt(argc, argv, "n:")) != -1)
	{
		switch (opt)
		{
			case 'n':
				two_numbers = atoi(optarg);
				break;
			default: 
				fprintf(stderr, "Usage: %s [-n] two_numbers\n", argv[0]);
				exit(EXIT_FAILURE);
				break;
		}
	}

	if (two_numbers == 0) two_numbers = TWO_LEN;

	// init the random
	srand (time(0));

	for (int i=0; i<two_numbers; i++)
	{
		int a = random();
		printf("%02d ", a);
	}
	
	printf("\n");
	
	exit(EXIT_SUCCESS);
}
