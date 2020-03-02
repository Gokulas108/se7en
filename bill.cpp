#include<iostream>
#include<fstream>
#include<string.h>

void bill_gen()
{
	int i=1;
	ofstream f;
	f.open("history.dat",ios::out | ios::app);
	system("cls");
	cout<<"\t\t\t\tSe7eN"<<endl;
		cout<<"\nBill Details\n"<<endl;
		food fd;
		cout<<"S.no\tFood\t\tPrice\tPrep Time\tHotel Name"<<endl;
	while(!bill.empty())
	{
		fd = bill.front();
		cout<<i++<<"\t"<<fd.food_name;
		f<<" "<<fd.food_name;//////////////////
  		cout<<"\t"<<fd.price<<"Rs";
  		f<<" "<<fd.price<<"Rs";//////////////////
  		cout<<"\t"<<fd.time<<"Minutes";
		f<<" "<<fd.time<<"Minutes";//////////////////
		cout<<"\t"<<fd.hotel<<endl;
		f<<" "<<fd.hotel;////////////////////
  		bill.pop();
	}
	cout<<"Total Amount		"<<total<<"Rs";
	f<<" "<<total<<"Rs"<<endl;
}

void history()
{
	ifstream f;
	f.open("history.dat",ios::in);
	void read_food()
  	f.seekg(0);
 	while(cin>>str)
  {
  	
  	cout<<"Food : "<<fd.food_name<<endl;
  	cout<<"Price : "<<fd.price<<endl;
  	cout<<"Hotel : "<<fd.hotel<<endl;
  	cout<<"Time : "<<fd.time<<endl;
  }
  f.close();
}
}
