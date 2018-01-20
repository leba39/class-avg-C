/*
	CLASS_AVG 
*/
//PREPROCESSOR
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

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
struct student* readFile(FILE* fp,size_t* num_students);


//M A I N 
int main(void){

	FILE* file_data;
	struct student* students_data;
	size_t num_students;

	//READING MAIN FILE
	file_data      = openFile();
	students_data  = readFile(file_data,&num_students);

	//READING EACH STUDENT

	//PRINTING
	for (int i=0;i<num_students;i++){
		
		char proof;
		proof = students_data[i].MI;

		printf("Prueba:\t%c\n",proof);

	}

	free(students_data);

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

struct student* readFile(FILE* fp,size_t* num_students){

	//var
	int count = 0;
	int end;
	struct student* data;

	do{

		//var
		
		char* first;
		char* last;
		char MI;

		end = fscanf(fp,"%s %s %c",last,first,&MI); //WE READ 3 LOTS OF DATA.
		if (end != EOF){
		//I pretend to add && end == 3 to make sure we read the data.
		//It is currently reading 0 and program breaks up at #100.

			count++;

			data = (struct student*)realloc(data,sizeof(struct student)*count);
			//updates dyn mem

			data[count-1].first_name = first;
			data[count-1].last_name  = last;
			data[count-1].MI     	 = MI;
		}	

	}while(end != EOF);
	fclose(fp);	//CLOSE FILE!

	//WE UPDATE size_students with the students read and RETURN the address of the struct
	*num_students = count;
	return data;

}


