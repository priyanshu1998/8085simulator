#include "core.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int perLineExec = 0;


int main(int argc, char **argv){
	printf("\n8085 Emulator\n");
	if(argc != 2) printf("Parameter Error!");
	State8085 *state;
	

	int opt;

	while(1){
		printf("\nSelect an option :\n");
		printf("1.Load program\n");
		printf("2.Write to Memory/Input\n");
		printf("3.Read for Memory/Output\n");
		printf("4.Execute\n");
		printf("5.Toggle per line execution.(current status : %d)\n",perLineExec);
		printf("6.Exit\n\n");
		

		scanf("%d",&opt);

		switch (opt)
		{

		case 1:
			state = Init8085();
			LoadProgram(state,argv[1],0);
			break;

		case 2:
			mem_write(state);
			break;

		case 3:
			mem_read(state);
			break;

		case 4:
			ExecuteProgram(state);
			break;

		case 5:
			perLineExec ^= 1;
			break;

		case 6:
			free_allocated_mem(state);
			return 0;

		

		default:
			printf("Invalid option\n");
			break;
		}
	}
	free_allocated_mem(state);
	return 0;
}