/*
	CLASS_AVG 
*/
//PREPROCESSOR
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>

//CONSTANTS
#define FILE_MAX 255

//STRUCTS
struct student{

	char* first_name;
	char* last_name;
	char MI;
	double* grades;
	double grade_avg;

};



//FUNCTION DECLARATION
FILE* openFile(void);
size_t readFile(FILE* fp,struct student **data);


//M A I N 
int main(void){

	//VARs
	FILE* file_data;
	size_t num_students;
	struct student *arr_data = malloc(sizeof(struct student));
		//does void* from malloc promotes to struct student* ??

	//READING MAIN FILE
	file_data      = openFile();
	num_students   = readFile(file_data,&arr_data);

	//READING EACH STUDENT

	//PRINTING
	for (int i=0;i<num_students;i++){
		
		char proof;
		proof = arr_data[i].MI;

		printf("Prueba:\t%c\n",proof);

	}

	free(arr_data);

	exit(EXIT_SUCCESS);
}

FILE* openFile(void){

	//VARS
	char filename[FILE_MAX];
	FILE *fp;

	do{
		fprintf(stdout,"Enter name of DATAFILE:\t");
		fscanf(stdin,"%s",filename);
		fp =fopen(filename,"r");
		if (fp == NULL){
			fprintf(stderr,"Error opening file: %d\n",errno);
			perror("Description:");
		}

	}while(fp == NULL);

	return fp;
}

size_t readFile(FILE* fp,struct student **data){

	//var
	int count = 0;
	int end;
	char* first = NULL;
	char* last  = NULL;
	char MI;

	do{

		end = fscanf(stdin,"%*s %*s %c",&MI); //WE READ 3 LOTS OF DATA.
		//stdin will be fp and last first the first two args of fscanf.
		//If if use %ms would I need to free(first), free(last)???		

		if (end != EOF){
		//I pretend to add && end == 3 to make sure we read the data.
		//It is currently reading 0 and program breaks up at #100.

			count++;

			*data = realloc(*data,sizeof(struct student)*count);
			//updates dyn mem

			//breaks at second iteration asigment. First works fine tho'.
			//it denies access to data[1]->MI so it can't assign.


			/*data[count-1]->first_name = first;
			data[count-1]->last_name  = last;*/
			data[count-1]->MI     	 = MI;
		}	

	}while(end != EOF);
	fclose(fp);	//CLOSE FILE!

	//WE RETURN COUNT
	return count;

}


