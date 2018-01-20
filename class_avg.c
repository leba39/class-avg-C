/*
	CLASS_AVG 
*/
//PREPROCESSOR
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

//CONSTANTS
#define STR_MAX 255

//STRUCTS
struct student{

	char first_name[STR_MAX];
	char last_name[STR_MAX];
	double grade;

};



//FUNCTION DECLARATION
FILE* openFile(void);
struct* student readFile(FILE* fp);


//M A I N 
int main(void){

	FILE* file_data;
	struct* students_data;


	//READING
	file_data      = openFile();
	students_data  = readFile(file_data);

	//PRINTING


	exit(EXIT_SUCCESS);
}

FILE* openFile(void){

	//VARS
	char file_name[STR_MAX];
	FILE *fp;

	do{
		fprintf(stdout,"Enter name of DATAFILE:\t");
		fscanf(stdin,"%s",file_name);
		fp =fopen(filename,"r");
		if (fp == NULL){
			fprintf(stderr,"Error opening file: %d\n",errno);
			perror("Description:");
		}

	}while(fp == NULL);

	return fp;
}

struct* student readFile(FILE* fp){

	//var
	int count = 0;
	int end;

	do{

		//var
		
		char first[NAMES];
		char last[NAMES];
		double grade;

		end = fscanf(fp,"%s %s %lf",last,first,&grade);
		if (end != EOF){
			count++;
			struct* student data = (struct*)realloc(data,sizeof(struct student)*count);
			//updates dyn mem

			data[count-1].first_name = first;
			data[count-1].last_name  = last;
			data[count-1].grade      = grade;
		}	

	}while(end != EOF);
	fclose(fp);	//CLOSE FILE!


	return data;

}


