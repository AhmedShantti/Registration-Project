#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<process.h>
#define main_tab 
#define admin_tab 
//------------------------------------------------------------------------------------------------------------
int login_choice,admin_choice,student_choice,i,view_choice,size=0;
void add_student();
void view_student();
void update_student();
void main_menu();
void admin_menu();
void students_page();
void exit();
char a[][20]={""};
char b[][20]={""};
//************************************ Add Student Function.***************************************************
void add_student(){
	system("cls");
	printf("Enter the first Name : \n");
	scanf("%s", &a[size]);
	printf("Enter the last Name : ");
	scanf("%s", &b[size]);
	++size;
	admin_menu();	
}
//************************************ View Student Function.*************************************************
void view_student(){
	
	system("cls");
	printf("\n\t\t\t\t\t |Student Records|\n");
	printf("\n\n---------------------------------------------------------------------------------------------\n");
	printf("Number \t\t  Name\n");
	for (i = 0; i < size ; i++){
		printf("%d\t\t%s%s\n",i+1,a[i],b[i]);
	}
	printf("\n\n---------------------------------------------------------------------------------------------\n");
	printf("1. Back to Admin Menu\n");
	printf("2. Exit\n");
	scanf("%d", &view_choice);
	switch(view_choice){
		case 1 : admin_menu();
		break;
		case 2 : exit();
		break;
	} }
	//************************************ Update Student Function.******************************************
void update_student(){
	system("cls");
	int num;
	printf("enter the number you want to update: ");
	scanf("%d", &num);
	if(num < 0 || num > size){
		printf("Invalid number! [press any number to close it ]");
	}
	else{
		printf("enter the first name: ");
		scanf("%s",&a[num-1]);
		printf("enter the last name: ");
		scanf("%s",&b[num-1]);
		admin_menu();
	}	}
//************************************ Delete Student Function.**********************************************
void delete_student(){
	system("cls");
	int pos;
	printf("Enter the Number of student: ");
	scanf("%d",&pos);
	if(pos < 0 || pos > size){
		printf("Invalid number!");
	}
	else{
		for(i=pos-1 ; i<size-1 ; i++)
		{
			strcpy(a[i], a[i+1]);
			strcpy(b[i], b[i+1]);
		}
		size--;
		admin_menu();
	}
	}
//************************************ Main Menu Function.***************************************************
void main_menu(){
	do{
		system("cls");
	printf("\n\n\n\n\t\t\t\t\t Login As :\n");
	printf("\n\n\t\t\t\t\t 1. Admin\n ");
	printf("\n\t\t\t\t\t 2. Student\n ");
	printf("\n\t\t\t\t\t 3. Exit\n");
	printf("\n\n\t\t\t\t\t Enter your choice :");
	scanf("%d", &login_choice);
	}
	while(!(login_choice>=1 && login_choice<=3));
	switch (login_choice){
		case 1 : system("cls");
		admin_menu();
				break;
		case 2 : system("cls");
		students_page();
				break;
		case 3 : system("cls");
		exit();
				break;
		default : system("cls");
		main_menu();
		break;	
	}	
	}
//************************************ Admin menu Function.***************************************************	
void admin_menu(){
	do{
	system("cls");
	printf("\n\n\n\t\t\t\t\t | Logged In as Admin |\n");
	printf("\n\n\n\t\t\t\t\t 1. Add Student Record");
	printf("\n\n\n\t\t\t\t\t 2. View All Student Records");
	printf("\n\n\n\t\t\t\t\t 3. Update Student Record");
	printf("\n\n\n\t\t\t\t\t 4. Delete Student Record");
	printf("\n\n\n\t\t\t\t\t 5. Main Menu");
	printf("\n\n\n\t\t\t\t\t 6. Exit\n");
	printf("\n\n\n\t\t\t\t\t  Enter Choice :");
	scanf("%d", &admin_choice);
	}
	while(!(admin_choice>=1 && admin_choice<=6));
	switch (admin_choice){
		case 5 : system("cls");
		main_menu();
		break;
		case 6 : system("cls");
		exit();
		break;
		case 1 : system("cls");
		add_student();
		break;
		case 2 : system("cls");
		view_student();
		break;
		case 3 : system("cls");
		update_student();
		break;
		case 4 : system("cls");
		delete_student();
		break;	
	}
}
//************************************ Students Page Function.************************************************
void students_page(){
	do{
		system("cls");
	printf("\n\n\n\t\t\t\t\t | Students Page |\n");
	printf("\n\n\n\t\t\t\t\t Welcome as Student\n\n\n ");
	printf("\n\n\n\t\t\t\t\t 1. Back to Main Menu");
	printf("\n\n\n\t\t\t\t\t 2. Exit\n");
	printf("\n\n\n\t\t\t\t\t Enter choice : ");
	scanf("%d",&student_choice);
	}
	while(!(student_choice >= 1 && student_choice <= 2));
		switch(student_choice){
			case 1:
			main_menu();
			break;
			case 2:
			exit();
			break;
		}	
}
//************************************ Exit Function.*********************************************************
void exit(){
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n%sQuitting the program");
	exit(0);
}

int main(){
	main_menu();
}
