#include<iostream>
#include<iomanip>
#include<stdlib.h>
using namespace std;
static char board[10]={'0','1','2','3','4','5','6','7','8','9'},symbol;
int player=1,slot,choice,option;
string name1,name2;
char result='z';
void Display_Board(void);
int Player_Vs_Player();
int player_Vs_Computer();
int Game_Condition();
int Player_Vs_Player()
{
	cout<<"Enter First Player Name"<<endl;
	cin>>name1;
	cout<<"Enter Second Player name"<<endl;
	cin>>name2;
	player=1;
	system("cls");
	do{
		Display_Board();
		up:{}
		player=(player%2)?1:2;
		symbol=(player==1)?'X':'Y';
		if(player==1)
		cout<<name1<<" Turn Enter The Slot "<<endl;
		else
		cout<<name2<<" Turn Enter The Slot "<<endl;
		//cout<< "\tEnter The  "<<player<<" Player  With ["<<symbol<<" ]"<<endl;
		cin>>slot;
		if(board[slot]=='X'||board[slot]=='X')
		{
			cout<<"Enter Vaild Position "<<endl;
			goto up;
		}
		else
		{
			
			board[slot]=symbol;
			
		}	 
		player++;
		system("cls");
		Game_Condition();
	}while(result=='z');
   Display_Board();
}
int Game_Condition()
{
	if(board[1]==board[2]&&board[1]==board[3] || board[4]==board[5]&&board[4]==board[6] || board[7]==board[8]&&board[7]==board[9])
	result='w';
	else if(board[1]==board[4]&&board[1]==board[7] ||board[2]==board[5]&&board[2]==board[8] ||board[3]==board[6]&&board[3]==board[9] )
    result='w';
       else if(board[1]==board[2] &&board[1]==board[9] || board[3]==board[5] &&board[3]==board[7])
        result='w';
       else if(board[1]!='1' && board[2]!='2' && board[3]!='3' && board[4]!='4' && board[5]!='5' && board[6]!='6' && board[7]!='7'&& board[8]!='8'&& board[9]!='9')
	result='d';
	else 
	result='z';
}
void Display_Board()
{
    cout<<"\n\n"<<endl;
	cout<<setw(10)<<"  "<<board[1]<<" | "<<board[2]<<""<<" |  "<<board[3]<<endl;
	cout<<setw(10)<<" "<<"------------"<<endl;
	cout<<setw(10)<<"  "<<board[4]<<" | "<<board[5]<<""<<" |  "<<board[6]<<endl;
	cout<<setw(10)<<" "<<"------------"<<endl;
	cout<<setw(10)<<"  "<<board[7]<<" | "<<board[8]<<""<<" |  "<<board[9]<<"\n\n"<<endl;
}
int player_Vs_Computer()
{
	int player=1;
	do
	{
	Display_Board();	
	player=(player%2)?1:2;
	 symbol=(player==1)?'X':'Y';
	 up:
	 if(player==1)
	 {
	 	cout<<"Enter Player 1 With [X] "<<endl;
	 	cin>>slot;
	 }
	 else
	 {
	 	slot=(rand()%10);
	 	if(slot==0)
	 	slot++;
	 }
	 if(board[slot]=='X'|| board[slot]=='Y')
	 goto up;
	 else
	 {
	 	board[slot]=symbol;
	 }
	 
	 player++;
	 system("cls");
	 Game_Condition();
	}while(result=='z');
	Display_Board();
}
int main()
{
	cout<<"\n\n"<<endl;
	cout<<setw(80)<<"---------WELCOME TO TIC TAK TOE ---------\n\n"<<endl;
	do{
	opt:
	cout<<setw(20)<<"Enter Option \n"<<endl;
	cout<<setw(38)<<" 1 . Player Vs Player \n"<<endl;
	cout<<setw(38)<<" 2 . Player vs Computer"<<endl;
	cin>>option;
	if(option==1 || option==2)
	{
		system("cls");
  (option==1)?Player_Vs_Player():player_Vs_Computer();
	}
	else
	{
		cout<<"Enter Vaild Option"<<endl;
		system("cls");
		goto opt;
}
if(board[1]=='X' && board[2]=='X' && board[3]=='X' || board[4]=='X' && board[5]=='X' && board[6]=='X'|| board[7]=='X' && board[7]=='X' && board[8]=='X' || board[1]=='X' && board[4]=='X' &&board[7]=='X'|| board[2]=='X' && board[5]=='X' &&board[8]=='X'|| board[3]=='X' && board[6]=='X' &&board[9]=='X' || board[1]=='X' && board[5]=='X' &&board[9]=='X' || board[3]=='X' && board[5]=='X' && board[7]=='X')
cout<<"--------Player 1  "<<name1<<"  Won The Match--------\n\n"<<endl;
	else if(result=='w') 
   cout<<"--------player 2 "<<name2<<"  won--------\n\n"<<endl;
   else
   cout<<"--------match draw-------- \n\n"<<endl;
	cout<<setw(20)<<"Do You Want TO countine \n"<<endl;
	cout<<setw(20)<<"1 . For Countine... "<<setw(15)<<"2 . For End... \n\n"<<endl;
	cin>>option;
	system("cls");
	if(option==1)
	{
		int j=1;
		for(int i=49;i<57;i++)
		{
			board[j]=i;
			j++;
		}
	}
}while(option==1);
cout<<"Thank For Spending Time With Me "<<endl;

}
