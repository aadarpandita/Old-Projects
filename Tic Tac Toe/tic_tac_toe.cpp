#include<iostream>

using namespace std;




int arr[3][3];  // global array
int flag=0;

void greet()
{
	cout<<endl<<endl<<"Hi! Welcome to the game of tic tac toe "<<endl;
	cout<<"This is a 2 player game"<<endl;
	cout<<"Player 1 is 'O' and Player 2 is 'X' "<<endl<<endl<<endl;
}

void initarr(int array[3][3])
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			array[i][j]=0;
		}
	}
}

void displayarr(int array[3][3])
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			//cout<<(array[i][j]);
			//cout<<' ';
			if(array[i][j]==0)
			{
				cout<<'_'<<' ';
			}
			else if(array[i][j]==1)
			{
				cout<<'O'<<' ';	
			}
			else if(array[i][j]==2)
			{
				cout<<'X'<<' ';	
			}

		}
		cout<<endl;
	}
}

int win1(int array[3][3])
{

	int draw(int array[3][3]);

 	if((array[2][0]==1&&array[1][1]==1&&array[0][2]==1))
 	{	
 		cout<<"Player 1 wins.."<<endl;
 		flag=1;
 		
 	}
 	else if((array[0][0]==1&&array[0][1]==1&&array[0][2]==1))
 	{
 		cout<<"Player 1 wins.."<<endl;
 		flag=1;
 	}
 	else if((array[1][0]==1&&array[1][1]==1&&array[1][2]==1))
 	{
 		cout<<"Player 1 wins.."<<endl;
 		flag=1;
 	}
	else if((array[2][0]==1&&array[2][1]==1&&array[2][2]==1))
	{
	 	cout<<"Player 1 wins.."<<endl;
 		flag=1;
	}
	else if((array[0][0]==1&&array[1][0]==1&&array[2][0]==1))
	{
	 	cout<<"Player 1 wins.."<<endl;
 		flag=1;
	}
	else if((array[0][1]==1&&array[1][1]==1&&array[2][1]==1))
	{
	 	cout<<"Player 1 wins.."<<endl;
 		flag=1;
	}
	else if((array[0][2]==1&&array[1][2]==1&&array[2][2]==1))
	{
	 	cout<<"Player 1 wins.."<<endl;
 		flag=1;
	}
	else if((array[0][0]==1&&array[1][1]==1&&array[2][2]==1))
	{
	 	cout<<"Player 1 wins.."<<endl;
 		flag=1;	
	}
	else
		draw(array);
	
	return flag;
}

int win2(int array[3][3])
{	

	int draw(int array[3][3]);

	if((array[2][0]==2&&array[1][1]==2&&array[0][2]==2))
	{
		cout<<"Player 2 wins.."<<endl;
 		flag=1;
	}
	else if((array[0][0]==2&&array[0][1]==2&&array[0][2]==2))
	{
		cout<<"Player 2 wins.."<<endl;
 		flag=1;
	}
	else if((array[1][0]==2&&array[1][1]==2&&array[1][2]==2))
	{
		cout<<"Player 2 wins.."<<endl;
 		flag=1;
	}
	else if((array[2][0]==2&&array[2][1]==2&&array[2][2]==2))
	{
		cout<<"Player 2 wins.."<<endl;
 		flag=1;
	}
	else if((array[0][0]==2&&array[1][0]==2&&array[2][0]==2))
	{
		cout<<"Player 2 wins.."<<endl;
 		flag=1;
	}
	else if((array[0][1]==2&&array[1][1]==2&&array[2][1]==2))
	{
		cout<<"Player 2 wins.."<<endl;
 		flag=1;
	}
	else if((array[0][2]==2&&array[1][2]==2&&array[2][2]==2))
	{
		cout<<"Player 2 wins.."<<endl;
 		flag=1;
	}
	else if((array[0][0]==2&&array[1][1]==2&&array[2][2]==2))
	{
		cout<<"Player 2 wins.."<<endl;
 		flag=1;
	}
	else 
		draw(array);

	return flag;
}

int draw(int array[3][3])
{
	int temp=0;

	for(int i=0;i<3;)
	{
		for(int j=0;j<3;)
		{
			if((array[i][j]!=0)&&(flag!=1))
				j++;
			else 
				{
					temp=1;
					break;
				}
		}
		if(temp==1)
			break;
		else
			i++;
	}
	if(temp==1)
	{
		return flag;
	}
	else
	{
		cout<<"Match draw.."<<endl;
		flag=1;
		return flag;
	}

}



int main()
{

	
	greet();

	initarr(arr);
	displayarr(arr);

	int i,j;

	for(int a=0;a<2;)
	{
		if(flag==1)
			break;

		while(a==0)
		{
			cout<<endl<<"Player 1 : "<<endl<<"Enter location : ";
			cin>>i>>j;

			if(arr[i-1][j-1]==0)
			{
				arr[i-1][j-1]=1;
				displayarr(arr);
				flag=win1(arr);
				break;
			}
			else
			{
				cout<<endl<<"Place occupied.. "<<endl;
			}
		}

		if(flag==1)
			break;
		a++;


		while(a==1)
		{
			cout<<endl<<"Player 2 : "<<endl<<"Enter location : ";
			cin>>i>>j;

			if(arr[i-1][j-1]==0)
			{
				arr[i-1][j-1]=2;
				displayarr(arr);
				flag=win2(arr);
				break;
			}
			else
			{
				cout<<endl<<"Place occupied.. "<<endl;
			}
		}
		a=0;

	}

	

	return 0;

}