#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

/* ############################################## Declaration of Structure and Linked list #################################### */

struct patient_details
{
	int id;
	int discharge;
	char disease[10], doctor[20], gen;
	struct
	{
		char first_name[20];
		char surname[20];
	} patient_name;
	int age;
	struct
	{
		int month_no;
		int day;
		int year;
	} date_of_entry;
	int room_no;
	struct
	{
		int date;
		int month_no;
		int year;
	} date_of_birth;
};
struct node
{
	struct patient_details patient;
	struct node *next;
};

/* ############################################## Declaration of Global Variable #################################### */

int ID = 1000, room[9];
struct node *start = NULL;
struct node *insert_details(struct node *start);
struct node *change_details(struct node *start);
struct node *display_details(struct node *start);
void display_list(struct node *start);
void display(struct node *start);
int sort_by_month(struct node *start);
void sort_by_name(struct node *start);
void sort_by_id(struct node *start);
void swap_data(struct node *ptr1, struct node *ptr2);
void WelcomeScreen(void);
void Title(void);
void LoginScreen(void);


/* ############################################## Main function #################################### */
int main()
{   
	system("color 03");
	WelcomeScreen();
	LoginScreen();
	Title();
	int choice, i;
	for (i = 0; i < 10; i++)
		room[i] = -1;

	do
	{
		printf("\n\n\n1.Make a new entry of a patient.\n2. Display details of a patient.\n3. Change details of a patient\n4. Exit\nEnter your choice:\n ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			start = insert_details(start);
			break;
		case 2:
			start = display_details(start);
			break;
		case 3:
			start = change_details(start);
			break;
		case 4:
			printf("\n******* Closing application,Thank You for using. ******* \n");
			break;
		default:
			printf("\nPlease enter valid option ");
		}
	} while (choice != 4);

	return 0;
}

/* ############################################## Login Function #################################### */
void LoginScreen(void)//function for login screen
{

int e=0	;
char Username[15];
char Password[15];
char original_Username[25]="abcd";
char original_Password[15]="1234";

do
{
	printf("\n\n\n\n\t\t\t\tEnter your Username and Password :)");
	printf("\n\n\n\t\t\t\t\tUSERNAME:");
	scanf("%s",&Username);
	
	printf("\n\n\t\t\t\t\tPASSWORD:");
	scanf("%s",&Password);
	
	if (strcmp(Username,original_Username)==0 && strcmp(Password,original_Password)==0)
	{
		printf("\n\n\n\t\t\t\t\t...Login Successfull...");
		
		
		getch();
		return;
		break;
	}
	else
	{
		printf("\n\t\t\tPassword in incorrect:( Try Again :)");
		e++;
		getch();
	}

}
while(e<=2);
	
 
system("cls");
}


/* ############################################## Welcome screen #################################### */

void WelcomeScreen(void) //function for welcome screen
{

	printf("\n\n\n\n\n\n\n\t\t\t\t#########################################");
	printf("\n\t\t\t\t#\t\tWELCOME TO\t\t#");
	printf("\n\t\t\t\t#  QUARANTINE WARD MANAGEMENT SYSTEM    #");
	printf("\n\t\t\t\t#########################################");
	printf("\n\n\n\n\n Press any key to continue......\n");
	getch();
	system("cls");
}

/* ############################################## Title screen #################################### */

void Title(void) //function for title screen
{
	printf("\n\n\t\t----------------------------------------------------------------------------------");
	printf("\n\t\t\t\t       NAGPUR QUARANTINE WARD        ");
	printf("\n\t\t----------------------------------------------------------------------------------");
}

/* ############################################## Insert Details #################################### */

struct node *insert_details(struct node *start)
{
	struct node *new_node, *ptr;
	int d, m, yr, ag, yrb, mb, db, flag = 0, i = 0, roomno = 0;
	char gend, f_name[20], l_name[20], dis[20], doct[20];
	new_node = (struct node *)malloc(sizeof(struct node));
	while (i < 10)
	{
		if (room[i] == -1)
		{
			printf("Room number %d is empty.\n", i + 1);
			flag = 1;
		}
		i++;
	}
	if (flag != 1)
		printf("\nSorry,there are no Rooms available at this time.\n");
	else
	{
		printf("\nEnter day of entry:\n ");
		scanf("%d", &d);
		printf("\nEnter month of entry:\n ");
		scanf("%d", &m);
		printf("\nEnter year of entry:\n ");
		scanf("%d", &yr);
		printf("\nEnter Patient's First name:\n ");
		scanf("%s", f_name);
		printf("\nEnter Patient's Last name:\n ");
		scanf("%s", l_name);
		printf("\nEnter Patient's age:\n ");
		scanf("%d", &ag);
		printf("\nEnter Patient's Gender(only initial):\n ");
		scanf(" %c", &gend);
		printf("\nEnter Patient's date of birth:\n ");
		scanf("%d", &db);
		printf("\nEnter Patient's month number of birth:\n ");
		scanf("%d", &mb);
		printf("\nEnter Patient's year of birth:\n ");
		scanf("%d", &yrb);
		printf("\nEnter Symptoms:\n ");
		scanf("%s", dis);
		printf("\nEnter In-charge Doctor name:\n ");
		scanf("%s", doct);
		printf("Patient's Generated ID: %d\n", ID);
		do
		{
			printf("\nEnter the Room Number for the patient:\n ");
			scanf("%d", &roomno);
			if (roomno > 0 && roomno < 11)
			{
				if (room[roomno - 1] != -1)
				{
					printf("\nThe Room is occupied.Please select from the given Room Number(s) only\n");
					i = 1;
				}
				else
				{
					new_node->patient.room_no = roomno;
					room[roomno - 1] = new_node->patient.id;
					i = 0;
				}
			}
			else
			{
				printf("\n**** Invalid Room Number. Please select again. ****\n");
				i = 1;
			}
		} while (i);
		new_node->patient.id = ID;
		strcpy(new_node->patient.patient_name.first_name, f_name);
		strcpy(new_node->patient.patient_name.surname, l_name);
		new_node->patient.date_of_entry.month_no = m;
		new_node->patient.date_of_entry.day = d;
		new_node->patient.date_of_entry.year = yr;
		new_node->patient.age = ag;
		new_node->patient.gen = gend;
		new_node->patient.discharge = 0;
		new_node->patient.date_of_birth.date = db;
		new_node->patient.date_of_birth.month_no = mb;
		new_node->patient.date_of_birth.year = yrb;
		strcpy(new_node->patient.disease, dis);
		strcpy(new_node->patient.doctor, doct);
		if (start == NULL)
		{
			new_node->next = NULL;
			start = new_node;
			ID++;
		}
		else
		{
			new_node->next = NULL;
			ptr = start;
			while (ptr->next != NULL)
			{
				ptr = ptr->next;
			}
			ptr->next = new_node;
			ID++;
		}
	}
	system("cls");
	return start;
}

/* ############################################## Modify Details #################################### */

struct node *change_details(struct node *start)
{
	struct node *ptr;
	int change_id, option, status, roomno, i = 0, flag = 0;
	char f_name[20], m_name[20], l_name[20], dis[20], doct[20];
	ptr = (struct node *)malloc(sizeof(struct node));
	ptr = start;
	if (ptr == NULL)
	{
		printf("***** No details available!! Please make an entry. *****\n");
		return NULL;
	}
	else
	{
		printf("Which patient's detail is to be changed? Please enter the patient's Id: ");
		scanf("%d", &change_id);
		while (ptr != NULL && ptr->patient.id != change_id)
		{
			ptr = ptr->next;
		}
		if (ptr == NULL)
		{
			printf("There is no patient with such id.\n");
			free(ptr);
			return start;
		}
		else
		{
			do
			{
				printf("Which detail is to be changed?\n1.Status of the patient\n2.Name\n.Room Number\n.Doctor Assigned\n5.Symptoms acquired\n6.Exit\nEnter your option: \t");
				scanf("%d", &option);
				switch (option)
				{
				case 1:
					printf("Is the patient\n1.Admitted\n2.Discharged ? ");
					scanf("%d", &status);
					if (status == 1)
						ptr->patient.discharge = 0;
					else
					{
						ptr->patient.discharge = 1;
						roomno = ptr->patient.room_no;
						room[roomno - 1] = -1;
					}
					break;
				case 2:
					printf("Enter Patient's First name: ");
					scanf("%s", f_name);
					;
					printf("Enter Patient's Last name: ");
					scanf("%s", l_name);
					strcpy(ptr->patient.patient_name.first_name, f_name);
					strcpy(ptr->patient.patient_name.surname, l_name);
					break;
				case 3:
					while (i < 10)
					{
						if (room[i] == -1)
						{
							printf("Room number %d is empty.\n", i + 1);
							flag = 1;
						}
						i++;
					}
					if (flag != 1)
						printf("There are no rooms empty at this time.Please try again later.\n");
					else
					{
						do
						{
							printf("Enter new Room Number for the patient:");
							scanf("%d", &roomno);
							if (room[roomno - 1] != -1)
							{
								printf("The room is occupied.Please select from the given room no.s\n");
								i = 1;
							}
							else
							{
								room[ptr->patient.room_no - 1] = -1;
								ptr->patient.room_no = roomno;
								room[roomno - 1] = ptr->patient.id;
								i = 0;
							}
						} while (i);
					}
					break;
				case 4:
					printf("Enter In-charge Doctor name: ");
					scanf("%s", doct);
					strcpy(ptr->patient.doctor, doct);
					break;
				case 5:
					printf("Enter Disease name: ");
					scanf("%s", dis);
					strcpy(ptr->patient.disease, dis);
					break;
				case 6:
					printf("\n******* Returning to Main Menu ******* \n");
					break;
				default:
					printf("Wrong choice\n");
				}
				return start;
			} while (option != 6);
		}
	}
	system("cls");
}

/* ############################################## Display Details #################################### */

struct node *display_details(struct node *start)
{
	int choice, i = 0, m;
	char n[15];
	struct node *ptr;
	ptr = start;
	if (start == NULL)
	{
		printf("***** Patient database empty! *****\n");
		return NULL;
	}
	else
	{
		while (choice != 5)
		{
			ptr = start;
			printf("\n1.Display by name \n2.Display by ID \n3.Display for a specific month.\n4.Search patient by first name\n5.Exit\n");
			printf("\nEnter a choice: ");
			scanf("%d", &choice);
			switch (choice)
			{
			case 1:
				sort_by_name(start);
				printf("ID\t\tName\t\t\t\tDisease\t\t\t\tDoctor\t\t\t\tRoom No.\t\t\tStatus\n");
				while (ptr != NULL)
				{
					display_list(ptr);
					ptr = ptr->next;
				}
				break;
			case 2:
				sort_by_id(start);
				printf("ID\t\tName\t\t\t\tDisease\t\t\t\tDoctor\t\t\t\tRoom No.\t\t\tStatus\n");
				while (ptr != NULL)
				{
					display_list(ptr);
					ptr = ptr->next;
				}
				break;
			case 3:
				m = sort_by_month(start);
				if (m == 0)
					printf("\nNo Entry available for this month\n ");
				else
					printf("ID\t\tName\t\t\t\tDisease\t\t\t\tDoctor\t\t\t\tRoom No.\t\t\tStatus\n");
				while (ptr != NULL)
				{
					if (ptr->patient.date_of_entry.month_no == m)
						display_list(ptr);
					ptr = ptr->next;
				}
				break;
			case 4:
				printf("Enter patient name: ");
				scanf("%s", n);
				while (ptr != NULL)
				{
					if (!(strcmp(n, ptr->patient.patient_name.first_name)))
					{
						display(ptr);
						i++;
					}
					ptr = ptr->next;
				}
				if (i == 0)
					printf("Name not found.");
				break;
			case 5:
				printf("\n******* Returning to Main Menu ******* ");
				break;
			default:
				printf("Invalid choice. Please enter again.");
			}
		}
	}
	sort_by_id(start);
	
	return start;
}

void display(struct node *start)
{
	char Discharge[15];
	if (start->patient.discharge == 0)
		strcpy(Discharge, "Quarantined");
	else
		strcpy(Discharge, "Discharged");
	printf("\nID: %d\n", start->patient.id);
	printf("Patient Name [FIRST MIDDLE LAST] : %s  %s\n", start->patient.patient_name.first_name, start->patient.patient_name.surname);
	printf("Gender: %c\n", start->patient.gen);
	printf("Date of Birth: %d/%d/%d\n", start->patient.date_of_birth.date, start->patient.date_of_birth.month_no, start->patient.date_of_birth.year);
	printf("Age: %d years\n", start->patient.age);
	printf("Date of entry: %d/%d/%d\n", start->patient.date_of_entry.day, start->patient.date_of_entry.month_no, start->patient.date_of_entry.year);
	printf("Room Number: %d\n", start->patient.room_no);
	printf("Disease: %s\tDoctor: Dr. %s\n", start->patient.disease, start->patient.doctor);
	printf("Status: %s\n", Discharge);
	
}

void display_list(struct node *start)
{
	char Discharged[15];
	if (start->patient.discharge == 0)
		strcpy(Discharged, "Quarantined");
	else
		strcpy(Discharged, "Discharged");
	printf("%d\t\t%s %s\t\t\t%s\t\t\t\t%s\t\t\t%d\t\t\t%s\n", start->patient.id, start->patient.patient_name.first_name, start->patient.patient_name.surname, start->patient.disease, start->patient.doctor, start->patient.room_no, Discharged);
    
}

/* ############################################## Sort By Month #################################### */
int sort_by_month(struct node *start)
{
	struct node *pt1, *pt2;
	int m, flag = 1;
	long int d1, d2;
	printf("\nEnter Month number for which you want all patient details: ");
	scanf("%d", &m);
	pt1 = start;
	while (pt1 != NULL)
	{
		if (pt1->patient.date_of_entry.month_no == m)
		{
			flag = 0;
			break;
		}
		pt1 = pt1->next;
	}
	pt2 = pt1;
	if (flag)
		return 0;
	while (pt1->next != NULL)
	{
		while (pt1->patient.date_of_entry.month_no != m)
			pt1 = pt1->next;

		d1 = pt1->patient.date_of_entry.month_no * 50 + pt1->patient.date_of_entry.day + pt1->patient.date_of_entry.year * 1000;
		while (pt2 != NULL)
		{
			if (pt2->patient.date_of_entry.month_no == m && pt1 != pt2)
			{
				d2 = pt2->patient.date_of_entry.month_no * 50 + pt2->patient.date_of_entry.day + pt2->patient.date_of_entry.year * 1000;
				if ((d1 > d2) && (pt2->patient.date_of_entry.month_no == m))
					swap_data(pt1, pt2);
			}
			pt2 = pt2->next;
		}
		pt1 = pt1->next;
	}
	return m;
}

/* ############################################## Sort By ID #################################### */

void sort_by_id(struct node *start)
{
	struct node *pt1, *pt2;
	pt1 = start;
	while (pt1->next != NULL)
	{
		pt2 = pt1->next;
		while (pt2 != NULL)
		{
			if (pt1->patient.id > pt2->patient.id)
				swap_data(pt1, pt2);
			pt2 = pt2->next;
		}
		pt1 = pt1->next;
	}
}

/* ############################################## Sort By Name #################################### */
void sort_by_name(struct node *start)
{
	struct node *pt1, *pt2;
	pt1 = start;
	while (pt1->next != NULL)
	{

		pt2 = pt1->next;
		while (pt2 != NULL)
		{
			if (strcmp(pt1->patient.patient_name.first_name, pt2->patient.patient_name.first_name) > 0)
				swap_data(pt1, pt2);
			pt2 = pt2->next;
		}
		pt1 = pt1->next;
	}
}


void swap_data(struct node *ptr1, struct node *ptr2)
{
	struct patient_details temp;
	temp = ptr1->patient;
	ptr1->patient = ptr2->patient;
	ptr2->patient = temp;
}
