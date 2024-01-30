//including header files
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//defining global variables
int i,j,choose;

//declaring functions
void menu();
void new_entry();
void view_everything();
void student_data();
void view_room();
void closer();

//defining structures
struct
{
    char name[60];
    char city[60];
    char room_no[8];
    char hostel_name[6];
    char roll_no[10];
} add,upd,check,rem,sort;

//--------------------------------------------------------------------------------------------------------------------
//main function
int main()
{
    int a = pass();
    if(a==1)
    {
        printf("  \n\n\n\t\t       WELCOME TO THE SYSTEM   \n\n\n\n");
        system("PAUSE");
        menu();
    }
    else
    {
        system("cls");
        printf("\n\n\n\t\t\tAUTHENTICATION ERROR\n\n\n\n");
    }
    return 0;
}
//Login form
int pass(void)
{
    int cnt=0;
    char uname[10];
    char pword[10];
    char sq[15];
    char user[10]="username";
    char pass[10]="password";
    char security_ques[15]="security";
    do
    {
        system("CLS");

        printf("\n  ---------------------- AUTHENTICATION----------------------\n");
        printf(" \n\t ENTER ");
        printf(" \n\t\t USERNAME: ");
        scanf("%s", &uname);
        printf("\n\t\t PASSWORD: ");
        scanf("%s", &pword);
        if(strcmpi(uname,user)==0 && strcmp(pword,pass)==0)
        {
            return 1;
            break;
        }
        else
        {
            printf("\n        Warning! No Match Found\n");
            system("PAUSE");
            cnt++;
        }
    }
    while(cnt<=2);
    if (cnt>2)
    {
        system("CLS");
        printf("\n\t\t Forget Password?\n\n");
        system("pause");
        system("CLS");
        printf("\n\t\t Enter the Security Question: ");
        scanf("%s", &sq);
        if(strcmp(sq,security_ques)==0)
            return 1;
        else
            return 0;
    }

}

//menu function
void menu()
{
    system("CLS");
    int choice;
    printf("\n\n\t\t\t HOSTEL MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t 1>> Enter new Student's data");
    printf("\n\n\t\t 2>> Check individual Student's data");
    printf("\n\n\t\t 3>> View all Students of a particular room");
    printf("\n\n\t\t 4>> View Everything");
    printf("\n\n\t\t 5>> Exit");
    printf(" \nEnter your choice:");
    scanf("%d",&choice);

    switch(choice)
    {

    case 1:
        new_entry();
        break;
    case 2:
        student_data();
        break;
    case 3:
        view_room();
        break;
    case 4:
        view_everything();
        break;
    case 5:
        closer();
        break;
    default:
        menu();
    }
}

//------------------------------------------------------------------------------------------------------------------
//function to display all students of a room
void view_room()
{
    system("CLS");
    int choice,cnt=0;

    printf("Enter year choice:\n\n\t\t1. room1 \n\t\t2. room2 \n\t\t3. room3\n");
    scanf("%d",&choice);

    FILE *fp, *hostel;
    switch(choice)
    {
    case 1:
        hostel=fopen("room1.txt","a+");
        break;
    case 2:
        hostel=fopen("room2.txt","a+");
        break;
    case 3:
        hostel=fopen("room3.txt","a+");
        break;
    default:
        view_room();
    }
    while(fscanf(hostel,"%s\n",check.roll_no)!=EOF)
    {
        fp=fopen("record.txt","r");
        while(fscanf(fp,"%s %s %s %s %s\n",sort.roll_no, sort.name, sort.city, sort.room_no, sort.hostel_name)!=EOF)
        {
            if(strcmp(check.roll_no,sort.roll_no)==0)
            {
                if(cnt==0)
                {
                    printf("\t\tFollowing is the menu of requested students:");
                    printf("\n\tROLL NO.\tRoom No\t\tName.\n");
                }
                printf("\n\t%8s\t %8s\t %s", sort.roll_no, sort.room_no, sort.name);
                cnt++;
            }
        }
    }

    fclose(fp);
    if (cnt==0)
        printf("\nNO DATA FOUNDS\n");

sort_menu_invalid:
    printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&choose);

    if (choose==1)
        menu();
    else if(choose==0)
        closer();
    else
    {
        printf("\nInvalid!\a");
        goto sort_menu_invalid;
    }

}

//------------------------------------------------------------------------------------------------------------------
//new entry function
void new_entry()
{
    system("CLS");
    int choice;
    FILE *ptr,*hostel;

    ptr=fopen("record.txt","a+");
roll_no:

    printf("\t\t\t\xB2\xB2\xB2 ADD STUDENTS DATA  \xB2\xB2\xB2\xB2");
    printf("\nEnter your roll number:");
    scanf("%s",check.roll_no);
    while(fscanf(ptr,"%s %s %s %s %s\n",add.roll_no, add.name, add.city, add.room_no, add.hostel_name)!=EOF)
    {
        if (strcmp(check.roll_no,add.roll_no)==0)
        {
            printf("User already exist, enter an unique one\n\n\n\n");
            system("PAUSE");
            system("CLS");
            goto roll_no;
        }
    }

    strcpy(add.roll_no,check.roll_no);
    printf("\n\tEnter ");
    printf("\n\t Name:");
    scanf("%s",add.name);
    printf("\n\t City:");
    scanf("%s",add.city);
    printf("\n\t Room no.:");
    scanf("%s",add.room_no);
    printf("\n\t Room name form like room1/ room2/ room3(e.g. room1): ");
    scanf("%s",add.hostel_name);
    fprintf(ptr,"%s %s %s %s %s\n",add.roll_no, add.name, add.city, add.room_no, add.hostel_name);


    //adding student roll no. to hostels' menu
    if(strcmp(add.hostel_name,"room1")==0)
    {
        hostel=fopen("room1.txt","a+");
        fprintf(hostel, "%s\n", add.roll_no);
        fclose(hostel);
    }
    else if(strcmp(add.hostel_name,"room2")==0)
    {
        hostel=fopen("room2.txt","a+");
        fprintf(hostel, "%s\n", add.roll_no);
        fclose(hostel);
    }
    else if(strcmp(add.hostel_name,"room3")==0)
    {
        hostel=fopen("room3.txt","a+");
        fprintf(hostel, "%s\n", add.roll_no);
        fclose(hostel);
    }
    //----------------------------------------

    fclose(ptr);
    printf("\nStudent added successfully!");
add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&choose);

    if (choose==1)

        menu();
    else if(choose==0)
        closer();
    else
    {
        printf("\nInvalid!\a");
        goto add_invalid;
    }
}

//------------------------------------------------------------------------------------------------------------------
//function to view all students
void view_everything()
{
    system("CLS");
    FILE *view;
    view=fopen("record.txt","r");
    int cnt=0;

    printf("\nROLL NO.\tNAME\t\t\tcity\t\t\n");

    while(fscanf(view,"%s %s %s %s %s\n",add.roll_no, add.name, add.city, add.room_no, add.hostel_name)!=EOF)
    {
        printf("\n%8s\t %10s\t\t\t %10s\t\t",add.roll_no,add.name,add.city);
        cnt++;
    }
    fclose(view);

    if (cnt==0)
    {
        printf("\nNO DATA FOUNDS\n");
    }

view_everything_invalid:
    printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&choose);

    if (choose==1)
        menu();
    else if(choose==0)
        closer();
    else
    {
        printf("\nInvalid!\a");
        goto view_everything_invalid;
    }
}

//------------------------------------------------------------------------------------------------------------------
//function to view all data of 1 student
void student_data()
{
    system("CLS");
    FILE *ptr;
    int cnt=0;
    int choice;
    ptr=fopen("record.txt","r");
    printf("Do you want to check by\n1.Roll no\n2.Name\nEnter your choice:");
    scanf("%d",&choice);
    if (choice==1)
    {
        printf("\n\nEnter the roll number:");
        scanf("%s",check.roll_no);

        while (fscanf(ptr,"%s %s %s %s %s\n",add.roll_no, add.name, add.city, add.room_no, add.hostel_name)!=EOF)
        {
            if(strcmp(add.roll_no,check.roll_no)==0)
            {
                cnt=1;

                printf("\nROLL NO.:%s\nName:%s \ncity:%s  \nRoom No:%s \nHostel:%s \n",add.roll_no, add.name,add.city, add.room_no, add.hostel_name);
            }
        }
    }
    else if (choice==2)
    {
        printf("\n\nEnter the name:");
        scanf("%s",check.name);
        while (fscanf(ptr,"%s %s %s %s %s\n",add.roll_no, add.name, add.city, add.room_no, add.hostel_name)!=EOF)
        {
            if(strcmp(add.name,check.name)==0)
            {
                cnt=1;
                printf("\nROLL NO.:%s\nName:%s \ncity:%s  \nRoom No:%s \nHostel:%s \n",add.roll_no, add.name, add.city, add.room_no, add.hostel_name);
            }
        }
    }

    fclose(ptr);
    if(cnt!=1)
        printf("\nRecord not found!!\a\a\a");
student_data_invalid:
    printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
    scanf("%d",&choose);
    if (choose==1)
        menu();
    else if (choose==2)
        closer();
    else if(choose==0)
        student_data();
    else
    {
        printf("\nInvalid!\a");
        goto student_data_invalid;
    }
}
//----------------------------------------------------------------------------------------------------------
//exit of the program
void closer()
{
    system("CLS");
    printf("\n\n\n\n Thank you!!\n\n\n");
}



