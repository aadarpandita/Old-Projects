#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
using namespace std;

	int n=0; int i=0;

	void greet()
	{
		for(int i=0;i<10;i++)
		{
			cout<<"*$*"<<setw(75)<<"*$*"<<endl;

			if(i==5)
			{
				cout<<setw(55)<<"*********************************"<<endl;
				cout<<setw(55)<<"Hello..Welcome to Hotel Booking.."<<endl;
				cout<<setw(55)<<"*********************************"<<endl<<endl;
				cout<<setw(70)<<"We hope that your stay is everything you wished for and more.."<<endl<<endl;
				cout<<setw(60)<<"We will be at your service at all times.."<<endl<<endl;
			}
		}	
	}

	bool room_booked(int room_no, vector<int> &v)
	{ 
		for(int i=0; v[i]!=0; i++)
		{
			if(v[i]==room_no)
				return true;
		}
		return false;
	}

	void room_enquiry(vector<int> &v)
	{
			if(v.empty())
				cout<<endl<<endl<<setw(15)<<'\t'<<"No rooms booked yet.."<<endl;
			else
			{
				cout<<setw(15)<<'\t'<<"Booked Rooms : "<<endl;	
				for(int i=0; v[i]!=0 ;i++)
				{
					cout<<setw(15)<<'\t'<<v[i]<<endl;
				}
			}
	}

	class customer
	{	
	
			int days=-1;
			char phone_num[15]={'N','A'};
			
		public:
			char name[20]={'N','A'};
			int room_no = -1;
			void getdata(vector<int> &v)
			{	
				cin.ignore();

				cout<<endl<<endl<<'\t'<<"Please enter your name : ";
				cin.getline(name,sizeof(name));

				cout<<endl<<'\t'<<"Please enter your phone number : ";
				cin.getline(phone_num,sizeof(phone_num));

				cout<<endl<<'\t'<<"Enter the number of days of your stay : ";
				cin>>days;

				cout<<endl<<'\t'<<"Enter the room number you would like to have (1-100) : ";
				cin>>room_no;

				while(room_booked(room_no,v))
				{
					cout<<'\t'<<"Room is booked..Please choose a different room..";
					cin>>room_no;
				}

				v.push_back(room_no);
				i++;
			}

			void showdata()
			{
				cout<<endl<<endl<<'\t'<<" Details : "<<endl<<endl;

				cout<<'\t'<<"1. Name : "<<name<<endl;

				cout<<'\t'<<"2. Phone Number : "<<phone_num<<endl;

				cout<<'\t'<<"3. Duration of stay : "<<days<<" days"<<endl;

				cout<<'\t'<<"4. Room Number : "<<room_no<<endl;
			}
	};

	customer obj[5];

	void guest_info(string str)
	{
		for(int n=0;n<5;n++)
		{
			if(obj[n].name==str)
			{
				obj[n].showdata();
				break;
			}
		}
		if(n==5)
			cout<<endl<<setw(15)<<'\t'<<"No such guest exists..!"<<endl;
	}

	void room_info(int room)
	{
		for(int n=0;n<5;n++)
		{
			if(obj[n].room_no==room)
			{
				obj[n].showdata();
				break;
			}
		}
		if(n==5)
			cout<<endl<<setw(15)<<'\t'<<"Room isn't booked yet..!"<<endl;

	}

	void hotel_choice();

	void menu(vector<int> &v)
	{			
				char choice;
				string str;
				int room;

				cout<<endl<<endl;
				cout<<setw(55)<<"*********************************"<<endl;
				cout<<setw(30)<<"			  MAIN MENU 		  "<<endl;
				cout<<setw(55)<<"*********************************"<<endl<<endl;
				cout<<setw(15)<<'\t'<<"1. Book a room "<<endl;
				cout<<setw(15)<<'\t'<<"2. Customer Details "<<endl;
				cout<<setw(15)<<'\t'<<"3. Guest Information "<<endl;
				cout<<setw(15)<<'\t'<<"4. Room Information "<<endl;
				cout<<setw(15)<<'\t'<<"5. Room Enquiry "<<endl;
				cout<<setw(15)<<'\t'<<"6. Hotel Options "<<endl;

				cout<<setw(15)<<'\t'<<" Enter your choice : ";
				cin>>choice;
				switch(choice-48)
				{
					case 1 :    obj[n].getdata(v);
								n++;
								menu(v);
								break;

					case 2 : 	for(n=0;n<5;n++)
								obj[n].showdata();
								n=0;
							 	menu(v);
								break;
									
					case 3 : 	cout<<endl<<setw(15)<<'\t'<<"Enter the name of the guest : ";
								cin>>str;
								guest_info(str);
								menu(v);
								break;			

					case 4 : 	cout<<endl<<setw(15)<<'\t'<<"Enter the room number : ";
								cin>>room;
								room_info(room);
								menu(v);
								break;	

					case 5 : 	room_enquiry(v);
								menu(v);
								break;

					case 6 : 	hotel_choice();
								break;
					
					default :   cout<<endl<<endl<<setw(15)<<'\t'<<"Invalid choice..!"<<endl;
								menu(v);
				}

	}

	class hotel
	{
		vector<int> tri;
		vector<int> taj;
		vector<int> xan;
		vector<int> obe;

		public:

			void trivago()
			{
				menu(tri);
			}

			void taaj()
			{
				menu(taj);
			}

			void xander()
			{
				menu(xan);
			}

			void oberoi()
			{
				menu(obe);
			}

	}h;

	void hotel_choice()
	{

				char choice;

				cout<<setw(55)<<"Here is a list of hotels you might"<<endl;
				cout<<setw(40)<<"want to stay at.."<<endl;
				cout<<endl<<endl;
				cout<<setw(55)<<"*********************************"<<endl;
				cout<<setw(37)<<"		   	    HOTELS   	  	  "<<endl;
				cout<<setw(55)<<"*********************************"<<endl<<endl;
				cout<<setw(15)<<'\t'<<"1. Trivago "<<endl;
				cout<<setw(15)<<'\t'<<"2. Taj "<<endl;
				cout<<setw(15)<<'\t'<<"3. Xander "<<endl;
				cout<<setw(15)<<'\t'<<"4. Oberoi "<<endl;

				cout<<setw(15)<<'\t'<<" Which hotel would you like to visit ? : ";
				cin>>choice;
				switch(choice-48)
				{
					case 1 : h.trivago();
							 hotel_choice();
								break;

					case 2 : h.taaj();
							 hotel_choice();
								break;	 

					case 3 : h.xander();
							 hotel_choice();
								break;
							 
					case 4 : h.oberoi();
							 hotel_choice();
								break;
					
					default : cout<<endl<<endl<<setw(15)<<'\t'<<"Invalid choice..!"<<endl;
							  hotel_choice();
				}
	}
	

	int main()
	{
		greet();
		hotel_choice();

		return 0;
	}