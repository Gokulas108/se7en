#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include "form.cpp"
#include "theme.cpp"
//#include "avlhotel7G.cpp"
int main()
{
	theme();
	node *root=NULL;
    int x,n,i;
    char hot[30], str[30], are[20], dummy[1];
	int a;
	do{
			system("cls");
			HANDLE  hConsole;
  			hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	 		SetConsoleTextAttribute(hConsole, 10);
	cout<<"\t\t\tSe7eN - ADMIN\n";
		cout<<"\n1)Add Restaurant";
        cout<<"\n2)Delete Restaurant";
        cout<<"\n3)Favourite Restaurant";
        cout<<"\n4)View Restaurants";
        cout<<"\n5)History";
        cout<<"\nEnter Your Choice :";
	
	cin>>a;
	root = readf();
	
	switch(a)
	{
		case 1:
			system("cls");
			cout<<"\tAdd Restaurant"<<endl;
         	cin.getline(dummy,1,'\n');
			cout<<"Restaurant Name :"; 
			cin.getline(hot,30,'\n');
			cout<<"Street :"; cin.getline(str,30,'\n');
			cout<<"Area :";  cin.getline(are,20,'\n');
            root=insert(root,hot,str,are);
            writef(root);
			break;
        
		case 2: 
		system("cls");
		cout<<"\tDelete Restaurant\n";
			cin.getline(dummy,1,'\n');
			cout<<"\nEnter a data to delete:";
			cin.getline(hot,30,'\n');
            root=Delete(root,hot);
            writef(root);
            break;
        case 3:
        	system("cls");
        	cout<<"\n\nFavourite Restaurant\n";
        	SetConsoleTextAttribute(hConsole, 12);
        	fav(root);
        	SetConsoleTextAttribute(hConsole, 10);
        	break;
		case 4: 
		system("cls");

        			printf("\n\nAvailable Restaurants\n");
                    inorder(root);
                    printf("\n");
                    break;  
		case 5: 
		system("cls");
		cout<<"\tHistory\n";
					history(); 
					break;
	}
	
	cout<<"\n<Press Any Key to Continue>";
	getch();
	}while(a!=65);
}
