#include<iostream>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<fstream>
#include<windows.h>   /// to use windows library(windows API) functions
using namespace std;
#define MAX 256

int id,sem_num;
char name[20], dept[10], ph_num[10];


///alocate memory
struct student{
    char name[40];
    int id,sem_num;
    char dept[50];
    char ph_num[30];
    int roomNo;
	char seatNo[10];
};
struct room{
    int room_no,seat_no;
    char an[10];

};
typedef struct student stu;
typedef struct room rm;

///class
    int registration(){

			int roomNo;
			char seatNo[10];
			system("COLOR f0");
        cout<<"Enter the information of students: \n";
        cout<<"Name: \t";
        cin.ignore();
        cin.getline(name,40);
        cout<<"ID: \t";
        cin>>id;
        cout<<"Department: \t";
        cin>>dept;
        cout<<"Phone number:  \t+880";
        cin>>ph_num;
        cout<<"Room number: \t";
        cin>>roomNo;
        cout<<"Seat number: \t";
        cin>>seatNo;
        cout<<"Room Booked Successfully";
        FILE *fp;
        fp=fopen("a.txt","a");
        fprintf(fp,"|| %d  || %s ||  %s||   %d ||   %s   || +880%s ||\n",roomNo,seatNo,name,id,dept,ph_num);
        fclose(fp);

    }


   int rules(){
        system("COLOR 4");
        cout<<"\t\t=>Hostel gate will be closed at 8 p.m \n";
        cout<<"\t\t=>No Smoking\n";
        cout<<"\t\t=>No ragging\n";
        cout<<"\t\t=>Discipline maintain\n";
        cout<<"\t\t=>Beware of all notices\n";
        cout<<"\t\t=>No interchange of seat without permission\n ";
    }
     int search()  /// Search student's info by room number in Admin Page
{
    system("COLOR f0");
     FILE *ptr;
    char arr[2345];
    int room_no,z;
    ptr=fopen("a.txt","r");

    cout<<"Enter the room you want to search (Room number's are 1,2,3,4,5,6,7) ....\n\n";
    cin>>z;
    cout<<"RoomNo  Bed No      Name          Id      Dept   .   Phone No.       "<<endl;
    cout<<"------  ------      ------        ---     ----       --------       "<<endl;

    for(int i=0;i<=100;i++){
        fscanf(ptr,"%s",arr);
        room_no=atoi(arr); // takes a string (which represents an integer) and returns its value
            if(room_no==z)
            {
                fgets(arr,2345,(FILE*)ptr);
                printf("%d %s\n",room_no,arr);

            }
        }
    }

    int main menu(){
        system("COLOR E");
            cout<<"\n\n\n\n\n";
            cout<<"\t\t********************************"<<endl;
            cout<<"                                "<<endl;
            cout<<"        \t\tHOSTEL MANAGEMENT       "<<endl;
            cout<<"                                "<<endl;
            cout<<"\t\t********************************"<<endl;
            cout<<"  "<<endl;
    }
    int admin(){
         system("COLOR B");
            cout<<"\t\t*********************************"<<endl;
            cout<<"\t\t                               "<<endl;
            cout<<"\t\t        ADMIN  PAGE             "<<endl;
            cout<<"\t\t                              "<<endl;
            cout<<"\t\t********************************\n\n"<<endl;
}
    int student(){
           system("COLOR 60");
            cout<<"\t\t********************************"<<endl;
            cout<<"                                                                "<<endl;
            cout<<"                 \tSTUDENT  PAGE                "<<endl;
            cout<<"                                                                "<<endl;
            cout<<"\t\t********************************\n\n"<<endl;

    }

int add(){ /// room information for both Admin and student
    FILE *fp;
    stu st;
    char ch;
     fp=fopen("a.txt","r");
     if(fp==NULL)
        printf("Error\n");
     else

          cout<<"RoomNo    Bed No      Name        Id      Dept      Phone No.       "<<endl;
          cout<<"------    ------      ------      ---     ----       --------       "<<endl;
     while((ch=fgetc(fp))!=EOF){
        printf("%c",ch);
     }
}

int helpline(){
            system("COLOR 2");
            cout<<"\n\n\tIf you need any help then you can contact with us.........\n"<<endl;
            cout<<"\n\n\tFor more information->\t Contact number of Hostel manager";

}

int Administrator(){
    FILE *fp;
    char ans;
    int room_no,id,seat_no;
    char an;
	int t_num;


    do{
        system("cls"); /// When the screen is cleared , the cursor is moved to the upper left corner of the screen
        admin();
        cout<<"\t\t1.Registration\n"<<endl;
        cout<<"\t\t2.Student record\n" <<endl;
        cout<<"\t\t3.Search\n "<<endl;
        cout<<"\t\t4.Rules and regulation\n"<<endl;
        cout<<"\t\t5.Helpline\n"<<endl;
        cout<<"\t\t6.Exit\n"<<endl;
        cout<<"\n--------------------------------------------------------------";
        cout<<"\n\nEnter your choice (1-6) ==> ";
        int choice;
        cin>>choice;
        system("COLOR F");

        switch(choice)
        {
                case 1:
                        registration();
                        system("cls");
                        break;
                case 2:
                        system("cls");
                        add();
                        break;
                case 3:

                		search();
                		break;
            	case 4:
                        rules();
                		break;
        		case 5:
        		    	helpline();
                		break;
        		case 6:
                		cout<<"\n\n\n\t\t*****  THANK YOU  ******";

            			getch();
            			break;
                default:
                        cout<<"\n\nYou entered wrong keyword. You have to enter any option within 1-8\n\n ";

    }
            cout<<"\n\nWant To continue as Administration (Y/N)? ==> ";
            cin>>ans;
	}while(ans=='y' || ans=='Y');
}

int Student(){
        FILE *fp;
        char ans;
        int room_no,id,seat_no;
        char an;
        int t_num;


    do{
        system("cls");
        student();
        cout<<"\t\t1.Student record\n" <<endl;
        cout<<"\t\t2.Rules and regulation\n"<<endl;
        cout<<"\t\t3.Helpline\n"<<endl;
        cout<<"\t\t4.Exit\n"<<endl;
        cout<<"\n--------------------------------------------------------------";
        cout<<"\n\nEnter your choice (1-4) ==> ";
        int choice;
        cin>>choice;
        switch(choice){

                case 1:
                        system("cls");
                        add();
                        break;
                case 2:
                        rules();
                        break;
                case 3:
                        helpline();
                        break;
                case 4:
                        cout<<"\n\n\t\t*****  THANK YOU  ******";
                        break;
                default:
                        cout<<"\n\nYou have entered wrong keyword. You have to press any option within 1-5\n\n";
}
        cout<<"\n\nWant To continue as Student (Y/N)? ==> ";
		cin>>ans;
	}while(ans=='y' || ans=='Y');


return 0;
}

int main()
{
      char ans;
      do{
        system("cls");
        main menu();
        cout<<"\n\n";
        cout<<"\t*-------------------------------------*"<<endl;
        cout<<"\t|                                     |"<<endl;
        cout<<"\t|      1.  For  Administrator         |"<<endl;
        cout<<"\t|                                     |"<<endl;
        cout<<"\t|      2.  For  Student               |"<<endl;
        cout<<"\t|                                     |"<<endl;
        cout<<"\t|      3.  Exit                       |"<<endl;
        cout<<"\t|                                     |"<<endl;
        cout<<"\t*-------------------------------------*";
        cout<<"\n\n\t\tEnter your choice ==> \t";
        int ch;
        cin>>ch;
        cout<<"\n\n";
    switch(ch){
        case 1:

            cout<<"\nEnter the password >>> ";
                int a;
            cin>>a;
            if(a==1234567){
            Administrator();
            }

            else
            {
                cout<<"\nYou entered wrong password.";
            }

     break;
        case 2:
            Student();
            break;

        case 3:
            cout<<"\n\n\t\t*****  THANK YOU  ******";
            getch();
            exit(1);
            break;
        default:
            cout<<"\n\nYou have entered wrong keyword. You have to press any option within 1-3 \n\n";
          }


            cout<<"\n\nWant To Go to Main Menu (Y/N)? ==> ";

            cin>>ans;
            }while(ans=='y' || ans=='Y');
        }
