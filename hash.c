/*******************************************************************************************************************************
A program created to manage a list of students, using an hash function to store them in an array

It includes some other functions that can be used in other type of programs [read a menu option, validate text and numbers, etc.] 
*******************************************************************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_NUM 8
#define SIZE_NAME 50
#define SIZE_COURSE 10

#define SIZE_HASH 50
#define EMPTY_REG "0"
#define DELETE_REG "-1"
#define ZERO 48 /* VALUE OF THE NUMBER ZERO */


typedef struct {
	char num[SIZE_NUM];
	char name[SIZE_NAME];
	char course[SIZE_COURSE];
	int year;
} Student; 


/* MENUS */
void MainMenu() {
	system("clear");
	printf("\n1.Insert");
	printf("\n2.Delete");
	printf("\n3.Edit");
	printf("\n4.Search");
	printf("\n5.List");
	printf("\n\n0.Quit\n");
}

void EditMenu() {
	printf("\n1.Name");
	printf("\n2.Course");
	printf("\n3.Year");
	printf("\n\n0.Back\n");	
}

/* VALIDATIONS */
int NumberValidation(char *num) {
	int i = 0, flag = 0;
		
	/* '\n' remotion */
	num[strlen(num) - 1] = '\0';
	
	/* Checks if nothing was written (user just pressed enter, for example) */
	if(strlen(num) == 0) {
		flag = 1;
	}
	
	/* Checks if only numbers were written */
	else {
		while(num[i] != '\0') {
			if(!(num[i] >= 48 && num[i] <= 57)) {
				flag = 1;
			}
			i++;	
		}
	}
		
	return flag;
}

int TextValidation(char *txt) {
	int i = 0, flag = 0;
	
	/* '\n' remotion */
	txt[strlen(txt) - 1] = '\0';
	
	/* Checks if nothing was written (user just pressed enter, for example) */
	if(strlen(txt) == 0) {
		flag = 1;
	}

	/* Checks if only letters, spaces and hifens were written */
	else {
		while(txt[i] != '\0') {
			if(!((txt[i] >= 97 && txt[i] <= 122) || (txt[i] >= 65 && txt[i] <= 90) || txt[i] == 32 || txt[i] == 45)) {
				flag = 1;
			}
			i++;	
		}
	}
	
	return flag;
}

int StudentNumberValidation(char *num) {
	int i = 1, flag = 0;
	
	/* '\n' remotion */
	num[strlen(num) - 1] = '\0';
	
	if(strlen(num) == 0) {
		flag = 1;
	}
	else if(num[0] != '8') {
		flag = 1;
	}
	else {
		while(num[i] != '\0') {
			if(!(num[i] >= 48 && num[i] <= 57)) {
				flag = 1;
			}
			i++;	
		}
		if(i != (SIZE_NUM - 1))
			flag = 1;
	}
	
	return flag;
}



/* INPUT / OUTPUT */
int readOption(int min, int max) {
	int opc = -1;
	char temp[5];
	
	do {
		fseek(stdin, 0, SEEK_END);
		printf ("\nOption: ");
		fgets(temp, sizeof(temp), stdin);
		if((strlen(temp) <= 2) && (temp[0] >= (min + '0') && temp[0] <= (max + '0')))
			sscanf (temp, "%d", &opc);
		else
			printf("\nInvalid Option!\n");
	} while((opc < min) || (opc > max));
	
	return opc;	
}

void readStudentNumber(char *num) {
	int validation;
	char temp[10];
	
	system("clear");
	
	do {
		fseek(stdin, 0, SEEK_END);
		printf("\n - Student Number[8xxxxxx]: ");
		fgets(temp, sizeof(temp), stdin);
		
		validation = StudentNumberValidation(temp);
		
		if(validation != 0)
			printf(" - Invalid Student Number! Try Again!\n");
		else
			strcpy(num, temp);
		
	} while(validation != 0);
}

void readName(char *name) {
	int validation;

	do {
		fseek(stdin, 0, SEEK_END);
		printf("\n - Name: ");
		fgets(name, sizeof(name), stdin);
		
		validation = TextValidation(name);
		
		if(validation != 0)
			printf(" - Invalid Name! Try Again\n");
		
	} while (validation != 0);
}

void readCourse(char *course) {
	int validation;
	
	do {
		fseek(stdin, 0, SEEK_END);
		printf("\n - Course: ");
		fgets(course, sizeof(course), stdin);
		
		validation = TextValidation(course);
		
		if(validation != 0)
			printf(" - Invalid Course Name! Try Again!\n");
		
	} while (validation != 0);
}

int readYear() {
	int validation, year;
	char temp[10];
	
	do {
		fseek(stdin, 0, SEEK_END);
		printf("\n - Year: ");
		fgets(temp, sizeof(temp), stdin);
		
		validation = NumberValidation(temp);
		
		if(validation != 0)
			printf(" - Invalid Year! Try Again!\n");
		else {
			sscanf(temp, "%d", &year);
			if((year <= 0) || (year > 3))
				printf(" - Invalid Year! Try Again!\n");
		}
	} while ((validation != 0) || (year <= 0) || (year > 3));
	
	return year;
}

Student readStudentData(char *numE) {
	Student s;
	
	strcpy(s.num, numE);
	
	system("clear");
	
	printf("\n- Student Number: %s\n", numE);

	readName(s.name);

	readCourse(s.course);
	
	s.year = readYear();
	
	return s;
}

void printStudentData(Student s) {
	printf("\n - Student N: %s", s.num);
	printf("\n  - Name: %s", s.name);
	printf("\n  - Course: %s", s.course);
	printf("\n  - Year: %d\n", s.year);
}



/* HASH RELATED FUNCTIONS */
int hash(char *num) {
	int pos;
	
	pos = (num[2] - ZERO) * 1000 + (num[4] - ZERO) * 100 + (num[5] - ZERO) * 10 + (num[6] - ZERO);
		
	return (pos % SIZE_HASH);
}

void HashInicialization(Student *s) {
	int i;
	
	for(i = 0; i < SIZE_HASH; i++)
		strcpy(s[i].num, EMPTY_REG);
}

/* HASH COLLISION TREATMENT */
int HashSearch(Student *s, char *num) {
	int posE, cont = 0, posI, flag = 0;
		
	posE = hash(num);
	
	while((strcmp(s[posE].num, EMPTY_REG) != 0) && (strcmp(s[posE].num, num) != 0) && (posE < SIZE_HASH)) {
		
		if((strcmp(s[posE].num, DELETE_REG) == 0) && (flag == 0)) {
			posI = posE;
			flag = 1;	
		}
		posE = (posE + 1) % SIZE_HASH;			
		cont++;
	}
	
	if(cont == SIZE_HASH)
		return -1; //FULL ARRAY
	else if((strcmp(s[posE].num, EMPTY_REG) == 0) && (flag == 1))
		return posI; //STUDENT DOES NOT EXIST BUT THERE IS A SPACE OF A DELETED STUDENT THAT CAN BE FILLED WITH THE NEW STUDENT
	else
		return posE; //STUDENT MAY EXIST OR IT'S INSERTION POSITION IT'S EMPTY
	
}


/* MAIN FUNCTIONS */
void insertStudent(Student *s) {
	int pos;
	char num[SIZE_NUM];
	
	readStudentNumber(num);
	
	pos = HashSearch(s, num);
	
	if(pos == -1)
		printf("\n - The Array is Full!\n");
	else if (strcmp(s[pos].num, num) == 0)
		printf("\n - Student Already Exists!\n");
	else {
		s[pos] = readStudentData(num);
		printf("\n - Student Inserted!\n");	
	}
}

void deleteStudent(Student *s) {
	int pos;
	char num[SIZE_NUM];
	
	readStudentNumber(num);
	
	pos = HashSearch(s, num);
	
	if ((pos != -1 ) && (strcmp(s[pos].num, num) == 0)) {
		strcpy(s[pos].num, DELETE_REG);
		printf("\n - Student Deleted!\n");	
	}
	else {
		printf("\n - Student Does Not Exist!\n");
	}
}

void editStudent(Student *s) {
	int pos, opc = -1;
	char num[SIZE_NUM];
	
	readStudentNumber(num);
	
	pos = HashSearch(s, num);
	
	if ((pos != -1) && (strcmp(s[pos].num, num) == 0)) {	
		do {
			system("clear");
			printf("\n - Student N: %s\n", num);
			
			EditMenu();
			opc = readOption(0,3);
			
			switch(opc) {
				case 1: {
					system("clear");
					printf("\n - Student N: %s\n", num);
					
					readName(s[pos].name);
					printf(" - Student Name Changed!\n");
					
					getchar();
					system("clear");
					break;
				}
				case 2: {
					system("clear");
					printf("\n - Student N: %s\n", num);

					readCourse(s[pos].course);
					printf("\n - Student Course Changed!\n");
					
					getchar();
					system("clear");
					break;
				}
				case 3: {
					system("clear");
					printf("\n - Student N: %s\n", num);

					readYear(s[pos].year);
					printf("\n - Student Year Changed!\n");
					
					getchar();
					system("clear");
					break;
				}
			}
		} while(opc != 0);
	}
	else {
		printf("\n - Student Does Not Exist!\n");	
		getchar();
	}
}

void searchStudent(Student *s) {
	int pos;
	char num[SIZE_NUM];
	
	readStudentNumber(num);
	
	pos = HashSearch(s, num);
	
	if ((pos != -1 )&& (strcmp(s[pos].num, num) == 0))
		printStudentData(s[pos]);
	else
		printf("\n - Student Does Not Exist!\n");	
}

void listStudents(Student *s) {
	int i;
	
	system("clear");
	
	for(i = 0; i < SIZE_HASH; i++) {
		if((strcmp(s[i].num, EMPTY_REG) != 0) && (strcmp(s[i].num, DELETE_REG) != 0))
			printStudentData(s[i]);
	}
}



int main() {
	int opc = -1;
	Student Students[SIZE_HASH];
	
	HashInicialization(Students);

	do {
		MainMenu();
		opc = readOption(0,5);
		
		switch(opc) {
			case 1: {
				insertStudent(Students);
				getchar();
				break;
			}
			case 2: {
				deleteStudent(Students); 
				getchar();  
				break;
			}
			case 3: {
				editStudent(Students);
				break;
			}
			case 4: {
				searchStudent(Students);
				getchar();
				break;
			}
			case 5: {
				listStudents(Students);
				getchar();
				break;
			}
		}
	} while(opc != 0);
	
	return 0;
}
