/*
 * StructureTry.c
 *
 *  Created on: 27-Jul-2017
 *      Author: Sys-5304
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _person {
	char* first_name;
	int age;
};

typedef struct details {
	char* last_name;
	char* place;
	int rank;
} Student;

typedef union {
	int units;
	float kgs;
} amount;

typedef struct {
	char selling[15];
	float unitprice;
	int unittype;
	amount howmuch;
} product;

struct List {
	int Contact;
	char Name[100];
} Directory[50];

int main() {

#ifdef NORMAL
	Student _student;
	struct _person PERSON;

	PERSON.age = 5;
	PERSON.first_name = (char*)malloc(strlen("Priyadarshini")+1);
	_student.last_name = (char*)malloc(strlen("Singh")+1);
	_student.place = (char*)malloc(strlen("Rajasthan")+1);
	strcpy(PERSON.first_name,"Priyadarshini");
	strcpy(_student.last_name,"Singh");
	strcpy(_student.place,"Rajasthan");
	_student.rank = 1;
	printf("%s %s of age %d from %s ranked no.%d\n", PERSON->first_name,
			_student->last_name, PERSON->age, _student->place,
			_student->rank);
#endif

#ifdef POINTER

	Student *_ptrstudent;
	_ptrstudent = (Student*) malloc(sizeof(Student));

	struct _person *ptrPERSON;
	ptrPERSON = (struct _person*) malloc(sizeof(struct _person));

	ptrPERSON->first_name = (char*) malloc(strlen("Priyadarshini") + 1);
	_ptrstudent->last_name = (char*) malloc(strlen("Singh") + 1);
	_ptrstudent->place = (char*) malloc(strlen("Rajasthan") + 1);

	strcpy(_ptrstudent->last_name, "Singh");
	strcpy(_ptrstudent->place, "Rajasthan");
	_ptrstudent->rank = 2;

	ptrPERSON->age = 10;
	strcpy(ptrPERSON->first_name, "Priya");
	printf("%s %s of age %d from %s ranked no.%d\n", ptrPERSON->first_name,
			_ptrstudent->last_name, ptrPERSON->age, _ptrstudent->place,
			_ptrstudent->rank);
#endif

#ifdef unionInsideStruct
	product dieselmotorbike;
	product apples;
	product * myebaystore[2];

	int nitems = 2;
	int i;

	strcpy(dieselmotorbike.selling, "A Diesel Motor Cycle");
	dieselmotorbike.unitprice = 5488.00;
	dieselmotorbike.unittype = 1;
	dieselmotorbike.howmuch.units = 4;

	strcpy(apples.selling, "Granny duBois");
	apples.unitprice = 0.78;
	apples.unittype = 2;
	apples.howmuch.kgs = 0.5;

	myebaystore[0] = &dieselmotorbike;
	myebaystore[1] = &apples;

	for (i = 0; i < nitems; i++) {
		printf("\n%s\n", myebaystore[i]->selling);
		switch (myebaystore[i]->unittype) {
			case 1:
			printf("We have %d units for sale\n",
					myebaystore[i]->howmuch.units);
			break;
			case 2:
			printf("We have %f kgs for sale\n", myebaystore[i]->howmuch.kgs);
			break;
		}
	}
#endif

	int n, x;
	FILE *fp1;
	printf("Enter number of contacts You want to save:");
	printf("main menu :\n1.add\n2.delete\n3.display\n4.exit\n");
	fflush(stdout);

	scanf("%d\n", &n);
	scanf("%d", &x);
	switch (x) {
	case 1:
		for (int i = 0; i < n; i++) {
			fp1 = fopen("File.txt", "a");
			if (fp1 == NULL) {
				printf("Unable to save in File");
				exit(1);
			}
			printf("Enter Name\n");
			fflush(stdout);
			scanf("%99s", Directory[i].Name);

			printf("Enter Contact Number\n");
			fflush(stdout);
			scanf("%d", &Directory[i].Contact);

			fprintf(fp1, "# %s - ", Directory[i].Name);
			char temp[11];
			sprintf(temp,"%d",Directory[i].Contact);
			fprintf(fp1, "%s\n", temp);
			fclose(fp1);
		}

		break;
	case 2:

		break;
	case 3:
		fp1 = fopen("File.txt", "r");

		while (!feof(fp1)) {
			printf("%c", fgetc(fp1));
		}
		break;
	case 4:
		return 0;
	default:
		printf("wrong choice");
		break;

	}

	return 0;
}
