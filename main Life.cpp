// FICP Assignment
//Life Care Hospital

#include <iostream>//Header file
#include <fstream>//Header file
#include <stdlib.h>//Header file
#include <string.h>//Header file
#include <windows.h>//Header file
#include <conio.h>//Header file


using namespace std;

void login();//Function prototype
void change_username_password();//Function prototype
void forgot();//Function prototype
void help();//Function prototype
void doctor();//Function prototype
void patient();//Function prototype
void mainmenu();//Function prototype

main()
{
	system("COLOR 02");//Setting the color
	cout<< "\t\t    ************************************************************************************\n\n";
	cout<< "\t\t\t***************************** Life Care Hospital ***************************\n\n";
	cout<< "\t\t    ************************************************************************************\n\n";
	cout<< "\t\t\t\t\t***************** Welcome *****************\n\n";
	int choice;
	cout<< "\t\t\t\t\t\t__________________________________\n";
	cout<< "\t\t\t\t\t\t|1.LOGIN                         |\n"<<endl;
	cout<< "\t\t\t\t\t\t__________________________________\n";
	cout<< "\t\t\t\t\t\t|2.CHANGE USERNAME & PASSWORD    |\n"<<endl;
	cout<< "\t\t\t\t\t\t__________________________________\n";
	cout<< "\t\t\t\t\t\t|3.FORGOT                        |\n"<<endl;
	cout<< "\t\t\t\t\t\t__________________________________\n";
	cout<< "\t\t\t\t\t\t|4.HELP                          |\n"<<endl;
	cout<< "\t\t\t\t\t\t__________________________________\n";
	cout<< "\t\t\t\t\t\t|5.EXIT                          |\n"<<endl;
	cout<< "\n\t\t\t\tEnter your choice: ";
	cin>> choice;
	switch(choice)
	{
		case 1:
			system("cls");//To clear the screen
			login();
			break;
		case 2:
			system("cls");//To clear the screen
			change_username_password();
			break;
		case 3:
			system("cls");//To clear the screen
			forgot();
			break;
		case 4:
			system("cls");//To clear the screen
			help();
			break;
		case 5:
			system("cls");//To clear the screen
			cout<<"\n\n\t\t\tPress enter to exit";
			exit(0);
		default:
			system("COLOR 04");
			cout<<"\t\t\tInvalid Request. Please try again.\n";
			system("pause");
			system("cls"); 
			main();
	}
}
void login()
{
	system("cls");//To clear the screen
	string username;//Decleration
	string password;//Decleration
	string setusername1;//Decleration
	string setpassword1;//Decleration
	int tries = 0;
	cout<<"\n\n\t\t\t\t****************** LOGIN *****************\n\n\n";
	
 while(tries < 5){
 	cout<< "\n\t\t\tEnter Username: ";
	cin>>username;//Input the data
	cout<< "\n\t\t\tEnter Password: ";
	cin>>password;//Input the data
	ifstream log("usernpass.txt");//read the data in the file
	log>>setusername1;
	log>>setpassword1;
	if(username == setusername1 && password == setpassword1){
		system("cls");
		cout<<"\n\n\t\t\tHi! " << username <<endl;
		cout<<endl;
		system("pause");//pause the console
		mainmenu();//Return to main menu
	break;
	}else{
		system("cls");
		system("COLOR 04");
		cout<< "\n\n\t\t\tOops! Invalid Username or Password. Try again.\n\t\t\t";
		system("pause");
		system("cls");
		system("COLOR 02");//setting the color
		tries ++;	
	}
	log.close();//close the file
}
if(tries == 5){
	system("cls");
	system("COLOR 04");
	cout<< "\n\nToo many attempts. Program will terminate..";
	system("pause");
	exit(0);//exits from the system
}
}
void mainmenu()
{
	system("cls");
	system("COLOR 02");
	int choice1;
	cout<< "\t\t\t**************************************************************************\n";
	cout<< "\t\t\t*                                                                        *\n";
	cout<< "\t\t\t*                                                                        *\n";
	cout<< "\t\t\t*                             MAIN MENU                                  *\n";
	cout<< "\t\t\t*                                                                        *\n";
	cout<< "\t\t\t*                                                                        *\n";
	cout<< "\t\t\t**************************************************************************\n\n\n\n";
	
	cout<< "\t\t1.Doctor's Database\n\n";
	cout<< "\t\t2.Patient's Database\n\n";
	cout<< "\t\t3.Exit";
	cout<< "\n\n\n\t\tEnter your choioce: ";
	cin>>choice1;
	switch(choice1)
	{
		case 1:
			doctor();
			break;
		case 2:
			patient();
			break;
		case 3:
			system("cls");
			cout<< "\nPress enter to Exit.\n";
			exit(0);// exits the system
			break;
		default:
			system("COLOR 04");
			cout<< "Invalid Request. Try Again\n";
			system("pause");
			system("cls");
			system("COLOR 02");
			mainmenu();// returns to mainmenu
			break;
	}
}


void doctor()
{
	struct doctor
{
	int id;//Decleration
	int age;//Decleration
	int exp;//Decleration
	char firstname[25];//Decleration
	char lastname[25];//Decleration
	char specialist[10];//Decleration
};
	loop:// Repeats the console
	doctor d;//declaring doctor as d
	system("COLOR 02");// change the color of the console
	system("cls");//clear the screen
	int choice, searchid;//decleration
	cout<< "\n\n\t\t***************************************** Doctor's Database ***************************************\n\n\n";
	cout<<"\n\t\t1. Save Doctor record \n\t\t2. View Doctor record \n\t\t3. Delete Doctor record \n\t\t4. Edit Doctor record\n\t\t5. Exit to mainmenu\n\n\t\t Choice is: ";
	cin>> choice;
	switch(choice)
	{
		case 1:
			{
				system("cls");
				cout<< "\n\n\tFill up the followings\n\n";
				cout<<"\n\tEnter Doctor ID: ";
				cin>>d.id;
				cout<< "\n\tEnter Doctor first name: ";
				cin>>d.firstname ;
				cout<< "\n\tEnter Doctor last name: ";
				cin>>d.lastname ;
				cout<< "\n\tEnter Doctor age: ";
				cin>>d.age ;
				cout<< "\n\tEnter Years of work experience: ";
				cin>>d.exp ;
				cout<< "\n\tSpecialist type (General medicine/ Neurology/ Oncology/ Haematology/ Gastroenterology/ Gynaecology):\n\n\t\t";
				cin>>d.specialist ;
				
				ofstream savedata;// write on the file
				savedata.open("doctor.txt", ios :: app);// open the file
				
				savedata<<endl;
				savedata<<d.id;
				savedata<<endl;
				savedata<<d.firstname ;
				savedata<<endl;
				savedata<<d.lastname ;
				savedata<<endl;
				savedata<<d.age ;
				savedata<<endl;
				savedata<<d.exp ;
				savedata<<endl;
				savedata<<d.specialist ;
				savedata<<endl<<endl;
				
				savedata.close();//close the file
				cout<< "\t\t\tData Saved\n\n\t\t";
				system("pause");
				goto loop;
				break;
			}
		case 2:
			{
				system("cls");
				cout<< "\n\n\t\t**********************Veiw Doctor Details******************\n\n";
				ifstream viewdata;//to read the file
				viewdata.open("doctor.txt");// open the file
				viewdata>>d.id ;
				viewdata>>d.firstname ;
				viewdata>>d.lastname ;
				viewdata>>d.age ;
				viewdata>>d.exp ;
				viewdata>>d.specialist ;
				
				while(!viewdata.eof())
				{
					cout<< "\n\tDoctor ID: "<<d.id;
					cout<< "\n\tDoctor name: "<<d.firstname << " " <<d.lastname  ;
					cout<< "\n\tDoctor age: "<< d.age ;
					cout<< "\n\tYears of work Experience: "<< d.exp ;
					cout<< "\n\tSpecialist: "<< d.specialist<< endl<<endl ;
					
					viewdata>>d.id ;
					viewdata>>d.firstname ;
					viewdata>>d.lastname ;
					viewdata>>d.age ;
					viewdata>>d.exp ;
					viewdata>>d.specialist ;
				}
				viewdata.close();
				system("pause");
				goto loop;
				break;
			}
		case 3:
			{
				system("cls");
				cout<<"\n\n\t\t\t\t***************** Delete Doctor Detail ************************\n\n\n";
				cout<< "\n\tEnter ID of Doctor want to delete: ";
				cin>>searchid;
				ifstream deletedata;// read the file
				deletedata.open("doctor.txt");
				ofstream editdata;
				editdata.open("new.txt");
				
				deletedata>>d.id ;
				deletedata>>d.firstname ;
				deletedata>>d.lastname ;
				deletedata>>d.age ;
				deletedata>>d.exp ;
				deletedata>>d.specialist ;
				
				while(!deletedata.eof())
				{
					if(d.id != searchid)
					{
						editdata<<endl;
						editdata<<d.id ;
						editdata<<endl;
						editdata<<d.firstname ;
						editdata<<endl;
						editdata<<d.lastname ;
						editdata<<endl;
						editdata<<d.age ;
						editdata<<endl;
						editdata<<d.exp ;
						editdata<<endl;
						editdata<<d.specialist ;
						editdata<<endl;
					}else{
						cout<<"\n\tRecord deleted";
					}
					deletedata>>d.id ;
					deletedata>>d.firstname ;
					deletedata>>d.lastname ;
					deletedata>>d.age ;
					deletedata>>d.exp ;
					deletedata>>d.specialist ;
				}
				editdata.close();
				deletedata.close();
				
				//Removes the file
				if(remove("doctor.txt") != 0)
				{
					cout<<"\n\tFile doesn't remove";
				}else
				{
					cout<<"\n\tFile Removed";
				}
				
				//Renames the file
				if(rename("new.txt", "doctor.txt") != 0)
				{
					cout<<"\n\tFile does not rename\n\n\t\t";
				}else
				{
					cout<<"\n\tFile renamed\n\n\t\t";
				}
				system("pause");
				goto loop;
				break;
			}
		case 4:
			{
				system("cls");
				cout<<"\n\n\t\t\t\t***************** Edit Doctor Data *******************\n\n\n";
				int new_id;
				int new_exp;
				int new_age;
				char new_firstname[25];
				char new_lastname[25];
				char new_specialist[10];
				cout<<"\n\tEnter Doctor ID to edit: ";
				cin>>searchid;
				ifstream deletedata;// Read the file
				deletedata.open("doctor.txt");
				ofstream editdata;// Write on the file
				editdata.open("new.txt");
				
				deletedata>>d.id ;
				deletedata>>d.firstname ;
				deletedata>>d.lastname ;
				deletedata>>d.age ;
				deletedata>>d.exp ;
				deletedata>>d.specialist ;
				while(!deletedata.eof())
				{
					if(d.id != searchid)
					{
						editdata<<endl;
						editdata<<d.id ;
						editdata<<endl;
						editdata<<d.firstname ;
						editdata<<endl;
						editdata<<d.lastname ;
						editdata<<endl;
						editdata<<d.age ;
						editdata<<endl;
						editdata<<d.exp ;
						editdata<<endl;
						editdata<<d.specialist ;
						editdata<<endl;
					}else{
						cout<<"\n\tEnter new ID: ";
						cin>>new_id;
						cout<<"\n\tEnter First name: ";
						cin>>new_firstname;
						cout<<"\n\tEnter last name: ";
						cin>>new_lastname;
						cout<<"\n\tEnter doctor age: ";
						cin>>new_age;
						cout<<"\n\tEnter years of work experience: ";
						cin>>new_exp;
						cout<< "\n\tSpecialist type (General medicine/ Neurology/ Oncology/ Haematology/ Gastroenterology/ Gynaecology):\n\t\t";
						cin>>new_specialist ;
						
						editdata<<endl;
						editdata<<new_id;
						editdata<<endl;
						editdata<<new_firstname;
						editdata<<endl;
						editdata<<new_lastname;
						editdata<<endl;
						editdata<<new_age;
						editdata<<endl;
						editdata<<new_exp;
						editdata<<endl;
						editdata<<new_specialist;
						editdata<<endl;
					}
					deletedata>>d.id ;
					deletedata>>d.firstname ;
					deletedata>>d.lastname ;
					deletedata>>d.age ;
					deletedata>>d.exp ;
					deletedata>>d.specialist ;
				}
				editdata.close();
				deletedata.close();
				
				// Remove the file
				if(remove("doctor.txt") != 0)
				{
					cout<<"\n\tFile doesn't remove";
				}else
				{
					cout<<"\n\tFile Removed";
				}
				
				//Rename the file
				if(rename("new.txt", "doctor.txt") != 0)
				{
					cout<<"\n\tFile does not rename\n\n\t\t";
				}else
				{
					cout<<"\n\tFile renamed\n\n\t\t";
				}
				system("pause");
				goto loop;
				break;
			}
			case 5:
				{
					system("cls");
					mainmenu();// goes back to mainmenu
					break;
				}
			default:
				system("COLOR 04");
				cout<< "Invalid Request. Please try again\n\t\t";
				system("pause");
				doctor();
				break;
			
	}
}

			
void patient()
{
	struct patient
{
	//Declerations
	int id;
	int age;
	int mobile_number;
	char firstname[25];
	char lastname[25];
	char disease_type[50];
};
		loop:
		patient p;// declaring patient as p
		system("cls");
		system("COLOR 02");
		cout<< "\n\n\t\t***************************************** Patient's Database **************************************\n\n\n";
		int choice, searchid;
		cout<<"\n\t\t1. Save patient record \n\t\t2. View patient record \n\t\t3. Delete patient record \n\t\t4. Edit patient record\n\t\t5. Exit to mainmenu\n\n\t\t Choice is: ";
		cin>> choice;
		switch(choice)
		{
			case 1:
				{
					system("cls");
					cout<< "\n\n\t\tFill up the following\n\n";
					cout<<"\n\tEnter patient ID: ";
					cin>>p.id ;
					cout<< "\n\tEnter patient first name: ";
					cin>>p.firstname ;
					cout<< "\n\tEnter patient last name: ";
					cin>>p.lastname ;
					cout<< "\n\tEnter patient age: ";
					cin>>p.age ;
					cout<< "\n\tEnter patient mobile number: ";
					cin>>p.mobile_number ;
					cout<< "\n\tEnter disease type: ";
					cin>>p.disease_type ;
			
				
					ofstream savedata;//write on the file
					savedata.open("patient.txt", ios :: app);// open the file
				
					savedata<<endl;
					savedata<<p.id;
					savedata<<endl;
					savedata<<p.firstname ;
					savedata<<endl;
					savedata<<p.lastname ;
					savedata<<endl;
					savedata<<p.age ;
					savedata<<endl;
					savedata<<p.mobile_number ;
					savedata<<endl;
					savedata<<p.disease_type ;
					savedata<<endl<<endl;
				
					savedata.close();//close the file
					cout<<"\t\t\tData Saved\n\n\t\t";
					system("pause");
					goto loop;
					break;
				}
		case 2:
			{
				system("cls");
				cout<< "\n\n\t\t*******************************View patient profile*********************************\n\n";
				ifstream viewdata;// Read the file
				viewdata.open("patient.txt");// open the file
				viewdata>>p.id ;
				viewdata>>p.firstname ;
				viewdata>>p.lastname ;
				viewdata>>p.age ;
				viewdata>>p.mobile_number ;
				viewdata>>p.disease_type ;
				
				while(!viewdata.eof())
				{
					cout<< "\n\tPatient ID: "<<p.id;
					cout<< "\n\tPatient name: "<<p.firstname << " " <<p.lastname  ;
					cout<< "\n\tPatient age: "<< p.age ;
					cout<< "\n\tMobile number: "<<p.mobile_number;
					cout<< "\n\tDisease type: "<< p.disease_type<<endl<<endl ;
					
					viewdata>>p.id ;
					viewdata>>p.firstname ;
					viewdata>>p.lastname ;
					viewdata>>p.age ;
					viewdata>>p.mobile_number ;
					viewdata>>p.disease_type ;
				}
				viewdata.close();//close the file
				system("pause");
				goto loop;
				break;
			}
		case 3:
			{
				system("cls");
				cout<< "\n\n\t\t*********************************Delete patient profile*****************************\n\n";
				cout<< "\n\tEnter ID of patient want to delete: ";
				cin>>searchid;
				ifstream deletedata;// read the file
				deletedata.open("patient.txt");
				ofstream editdata;// write on the file 
				editdata.open("newfile.txt");
				
				deletedata>>p.id ;
				deletedata>>p.firstname ;
				deletedata>>p.lastname ;
				deletedata>>p.age ;
				deletedata>>p.mobile_number ;
				deletedata>>p.disease_type ;
				
				while(!deletedata.eof())
				{
					if(p.id != searchid)
					{
						editdata<<endl;
						editdata<<p.id ;
						editdata<<endl;
						editdata<<p.firstname ;
						editdata<<endl;
						editdata<<p.lastname ;
						editdata<<endl;
						editdata<<p.age ;
						editdata<<endl;
						editdata<<p.mobile_number ;
						editdata<<endl;
						editdata<<p.disease_type ;
						editdata<<endl;
					}else{
						cout<<"\n\tRecord deleted";
					}
					deletedata>>p.id ;
					deletedata>>p.firstname ;
					deletedata>>p.lastname ;
					deletedata>>p.age ;
					deletedata>>p.mobile_number ;
					deletedata>>p.disease_type ;
				}
				editdata.close();
				deletedata.close();
				
				//Remove the file 
				if(remove("patient.txt") != 0)
				{
					cout<<"\n\tFile doesn't remove";
				}else
				{
					cout<<"\n\tFile Removed";
				}
				
				//Rename the file
				if(rename("newfile.txt", "patient.txt") != 0)
				{
					cout<<"\n\tFile does not rename\n\n\t\t";
				}else
				{
					cout<<"\n\tFile renamed\n\n\t\t";
				}
				system("pause");
				goto loop;
				break;
			}
		case 4:
			{
				system("cls");
				cout<< "\n\n\t\t******************************Edit patient profile********************************\n\n";
				int new_id;//Decleration
				int new_mobile_number;//Decleration
				int new_age;//Decleration
				char new_firstname[25];//Decleration
				char new_lastname[25];//Decleration
				char new_disease_type[50];//Decleration
				cout<<"\n\tEnter Patient ID to edit: ";
				cin>>searchid;
				ifstream deletedata;//Read the file
				deletedata.open("patient.txt");
				ofstream editdata;// Write on the file
				editdata.open("newfile.txt");
				
				deletedata>>p.id ;
				deletedata>>p.firstname ;
				deletedata>>p.lastname ;
				deletedata>>p.age ;
				deletedata>>p.mobile_number ;
				deletedata>>p.disease_type ;
				while(!deletedata.eof())
				{
					if(p.id != searchid)
					{
						editdata<<endl;
						editdata<<p.id ;
						editdata<<endl;
						editdata<<p.firstname ;
						editdata<<endl;
						editdata<<p.lastname ;
						editdata<<endl;
						editdata<<p.age ;
						editdata<<endl;
						editdata<<p.mobile_number ;
						editdata<<endl;
						editdata<<p.disease_type ;
						editdata<<endl;
					}else{
						cout<<"\n\tEnter new ID: ";
						cin>>new_id;
						cout<<"\n\tEnter First name: ";
						cin>>new_firstname;
						cout<<"\n\tEnter last name: ";
						cin>>new_lastname;
						cout<<"\n\tEnter patient age: ";
						cin>>new_age;
						cout<<"\n\tEnter patient mobile number: ";
						cin>>new_mobile_number;
						cout<< "\n\tEnter disease type: ";
						cin>>new_disease_type ;
						
						editdata<<endl;
						editdata<<new_id;
						editdata<<endl;
						editdata<<new_firstname;
						editdata<<endl;
						editdata<<new_lastname;
						editdata<<endl;
						editdata<<new_age;
						editdata<<endl;
						editdata<<new_mobile_number;
						editdata<<endl;
						editdata<<new_disease_type;
						editdata<<endl;
					}
					
					deletedata>>p.id ;
					deletedata>>p.firstname ;
					deletedata>>p.lastname ;
					deletedata>>p.age ;
					deletedata>>p.mobile_number ;
					deletedata>>p.disease_type ;
				}
				editdata.close();
				deletedata.close();
				
				//Remove the file
				if(remove("patient.txt") != 0)
				{
					cout<<"\n\tFile doesn't remove";
				}else
				{
					cout<<"\n\tFile Removed";
				}
				
				//Rename the file
				if(rename("newfile.txt", "patient.txt") != 0)
				{
					cout<<"\n\tFile does not rename\n\n\t\t";
				}else
				{
					cout<<"\n\tFile renamed\n\n\t\t";
				}
				system("pause");
				goto loop;
				break;
			}
			case 5:
				{
					system("cls");
					mainmenu();// Returns to mainmenu
					break;
				}
			default:
				system("COLOR 04");
				cout<< "Invalid Request. Please try again\n\t\t";
				system("pause");
				patient();// returns to patient menu
				break;
			
	}
}

void change_username_password()
{
	system("cls");
	system("COLOR 02");
	string username;//Decleration
	string password;//Decleration
	string setusername1;//Decleration
	string setpassword1;//Decleration
	int tries = 0;
	
	while(tries < 5){
 	cout<< "\n\t\t\tEnter existing Username: ";
	cin>>username;//Input the data
	cout<< "\n\t\t\tEnter existing Password: ";
	cin>>password;//Input the data
	ifstream log("usernpass.txt");//read the data in the file
	log>>setusername1;
	log>>setpassword1;
	if(username == setusername1 && password == setpassword1){
		system("cls");
		cout<<"\n\n\t\t\tHi! " << username <<endl;
		cout<<endl;
		system("pause");//pause the console
		system("cls");
		string setusername;
		string setpassword;
		cout<<"\n\n\t\t\tChange User Name and Password";
		cout<<"\n\n\t\tSet up a new user name: ";
		cin>>setusername;
		cout<<"\n\n\t\tSet up a new password: ";
		cin>>setpassword;
		cout<<"\n\n\t\tNew username and password succesfully added\n\n\t\t";
		ofstream userpass("usernpass.txt");
		userpass<<setusername<<endl;
		userpass<<setpassword<<endl;
		userpass.close();
		system("pause");
		system("cls");
		main();
		break;
	}else{
		system("cls");
		system("COLOR 04");
		cout<< "\n\n\t\t\tOops! Invalid Username or Password. Try again.\n\t\t\t";
		system("pause");
		system("cls");
		system("COLOR 02");//setting the color
		tries ++;	
	}
	log.close();//close the file
}
	
if(tries == 5){
	system("cls");
	system("COLOR 04");
	cout<< "\n\nToo many attempts. Program will terminate..";
	system("pause");
	exit(0);//exits from the system
}
	
}

void forgot()
{
	system("cls");
	system("COLOR 02");// setting the color of the console
	string setusername1;//Decleration
	string setpassword1;//Decleration
	string username;//Decleration
	cout<< "\n\n\t\tEnter user name: ";
	cin>>username;
	ifstream forget("usernpass.txt");//opens the file and reads the file
	forget>>setusername1;
	forget>>setpassword1;
	
	while(!forget.eof())
	{
		if(username != setusername1)
		{
			cout<< "\n\n\t\tOops! Wrong user name.\n\n\t\t";
			system("pause");
			system("cls");
			main();// Returns to main
		}
		else
		{
			cout<<"\n\n\t\tUser name: "<< setusername1<<endl;
			cout<<"\n\t\tPassword: "<<setpassword1<<endl;
			cout<< "\n\n\t\t";
			system("pause");
			system("cls");
			main();
		}
		forget>>setusername1;
		forget>>setpassword1;
	}
	
	
	
	forget.close();// close the file
	cout<<"\n\n\t\t";
	system("pause");
	system("cls");
	main();
}

void help()
{
	system("cls");
	system("COLOR 02");
			cout<<endl;
			cout<<"\t\t\t\t\t                    USER HELP DOCUMENT           \n";
			
			cout<<endl;
			cout<<endl;
			cout<<endl;
			cout<<endl;
			cout<<endl;
			cout<<"\t\t\t\t\t  You have some choices-                             \n";
			cout<<endl;
			cout<<"\t\t\t\t\t 	01.To Login                                  \n";
			cout<<"\t\t\t\t\t	02.To Register user name and password        \n";
			cout<<"\t\t\t\t\t	03.If you forgot your username and password \n";
			cout<<"\t\t\t\t\t    04.Help                                         \n";
			cout<<"\t\t\t\t\t    05.Exit                                         \n";
			cout<<endl;
			cout<<"\t\t\t\t\t  >>If that's your choice number 01-                \n";
			cout<<"\t\t\t\t\t    You have to enter user name and password        \n";
			cout<<"\t\t\t\t\t    Then you will view the MainMenu                 \n";
			cout<<endl;
			cout<<"\t\t\t\t\t  >>If that's your choice number 02-                \n";
			cout<<"\t\t\t\t\t    You can set new user name and a password        \n";
			cout<<endl;
			cout<<"\t\t\t\t\t  >>If that's your choice number 03-                \n";
			cout<<"\t\t\t\t\t    You can view the username and password          \n";
			cout<<"\t\t\t\t\t    if you forgot                                   \n";
			cout<<endl;
			cout<<"\t\t\t\t\t  >>If that's your choice number 04-                \n";
			cout<<"\t\t\t\t\t    You can read the help menu                      \n";
			cout<<endl;
			cout<<"\t\t\t\t\t  >>If that's your choice number 05-                \n";
			cout<<"\t\t\t\t\t    You can Exit the system                         \n";
			cout<<endl;
			cout<<"\t\t\t\t\t   In Main Menu (After loging in)                   \n";
			cout<<"\t\t\t\t\t                                                    \n";
			cout<<"\t\t\t\t\t   You have some choices:                           \n";
			cout<<endl;
			cout<<"\t\t\t\t\t   01.To Doctor database - In this menu you can     \n";
			cout<<"\t\t\t\t\t                           add, view, edit & delete \n";
			cout<<"\t\t\t\t\t                           doctor details.          \n";
			cout<<endl;
			cout<<"\t\t\t\t\t   02.To Patient database - In this menu you can    \n";
			cout<<"\t\t\t\t\t                           add, view, edit & delete \n";
			cout<<"\t\t\t\t\t                           patient details.         \n";
			cout<<endl;
			cout<<"\t\t\t\t\t   03.To Exit the system.                           \n";
			cout<<endl;
			cout<<endl;
			cout<<"\t\t\t\t\t     (Thank you using Help Document Now you can     \n";
			cout<<"\t\t\t\t\t         use this system without any problem)       \n";
			cout<<endl;
			system("PAUSE");//To Pause
			system("cls");//To Clear The Screen
			main();
			}//end of case

	

