#include<bits/stdc++.h>
using namespace std;
int n=8;
void print_board(vector<vector<int> > board);
bool check(int x,int y)
{
	if(x%2==0 && y%2!=0)
		return true;
	if(y%2==0 && x%2!=0)
		return true;
	return false;
}
bool check_black(int x,int y)
{
	if(x>=0 && x<=2)
		return true;
	else return false;
}
bool check_white(int x,int y)
{
	if(x>=5 && x<=7)
		return true;
	else return false;
}
bool coord_valid(int x,int y)
{
	if(x>=0 && x<n && y>=0 && y<n)
		return true;
	else
		return false;
}
bool iskillingblack(int from_x,int from_y,int to_x,int to_y,int chance,vector<vector<int> > &board)
{
if(board[to_x][to_y]!=0)
	return false;
	if(to_x == from_x +2 && to_y == from_y+2 && (board[from_x+1][from_y+1]==3 || board[from_x+1][from_y+1]==6) )
	{
		board[from_x+1][from_y+1]=0;
		return true;
	}
	else if(to_x == from_x +2 && to_y == from_y-2 && (board[from_x+1][from_y-1]==3 || board[from_x+1][from_y-1]==6) )
	{
		board[from_x+1][from_y-1]=0;
		return true;
	}
	return false;
}
bool iskillingwhite(int from_x,int from_y,int to_x,int to_y,int chance,vector<vector<int> > &board)
{
	if(board[to_x][to_y]!=0)
	return false;
	if(to_x == from_x -2 && to_y == from_y+2 && (board[from_x-1][from_y+1]==1 || board[from_x-1][from_y+1]==2)  )
	{
		board[from_x-1][from_y+1]=0;
		return true;
	}
	else if(to_x == from_x -2 && to_y == from_y-2 && (board[from_x-1][from_y-1]==1 || board[from_x-1][from_y-1]==2) )
	{
		board[from_x-1][from_y-1]=0;
		return true;
	}
	return false;
}
bool iskillingking(int from_x,int from_y,int to_x,int to_y,int chance,vector<vector<int> > &board)
{
if(board[to_x][to_y]!=0)
	return false;
	if(to_x == from_x +2 && to_y == from_y+2 && (board[from_x+1][from_y+1]==3 || board[from_x+1][from_y+1]==6) )
	{
		board[from_x+1][from_y+1]=0;
		return true;
	}
	else if(to_x == from_x +2 && to_y == from_y-2 && (board[from_x+1][from_y-1]==3 || board[from_x+1][from_y-1]==6) )
	{
		board[from_x+1][from_y-1]=0;
		return true;
	}
	else if(to_x == from_x -2 && to_y == from_y+2 && (board[from_x-1][from_y+1]==1 || board[from_x-1][from_y+1]==2)  )
	{
		board[from_x-1][from_y+1]=0;
		return true;
	}
	else if(to_x == from_x -2 && to_y == from_y-2 && (board[from_x-1][from_y-1]==1 || board[from_x-1][from_y-1]==2) )
	{
		board[from_x-1][from_y-1]=0;
		return true;
	}
	return false;
}
bool move_black(int from_x,int from_y,int to_x,int to_y,int chance,vector<vector<int> > &board)
{
	if(to_x == from_x +1 && (to_y == from_y-1 || to_y == from_y+1))
		return true;
	if(iskillingblack(from_x,from_y,to_x,to_y,chance,board)==true)
	{
		return true;
	}
	return false;

}
bool move_king(int from_x,int from_y,int to_x,int to_y,int chance,vector<vector<int> > &board)
{
	if(to_x == from_x +1 && (to_y == from_y-1 || to_y == from_y+1))
		return true;
	else  if(to_x = from_x -1 && (to_y == from_y-1 || to_y == from_y+1))
		return true;
	if(iskillingking(from_x,from_y,to_x,to_y,chance,board)==true)
	{
		return true;
	}
	return false;

}
bool move_white(int from_x,int from_y,int to_x,int to_y,int chance,vector<vector<int> > &board)
{
   if(to_x == from_x -1 && (to_y == from_y-1 || to_y == from_y+1))
		return true;
	if(iskillingwhite(from_x,from_y,to_x,to_y,chance,board)==true)
	{
		return true;
	}
	return false;
}
bool is_valid(int from_x,int from_y,int to_x,int to_y,int chance,vector<vector<int> > &board)
{
	//cout<<1;
	if(board[from_x][from_y]==-1 || board[to_x][to_y]==-1 || from_x<0 || from_x >=n || from_y<0 || from_y >=n || to_x<0 || to_x >=n || to_y<0 || to_y >=n )
		return false;
	if(board[to_x][to_y]!=0)
	return false;
	if(chance==0 && (board[from_x][from_y]!=2 && board[from_x][from_y]!=1))
	return false;
	if(chance==1 && (board[from_x][from_y]!=3 && board[from_x][from_y]!=6))
	return false;
	if(chance==0)
	{
		//black
		if(board[from_x][from_y]==1 && move_black(from_x,from_y,to_x,to_y,chance,board)==true)
		{
			if(to_x==7)
			{
				board[from_x][from_y]=2;
			}
			return true;
		}
		else if(board[from_x][from_y]==2 && move_king(from_x,from_y,to_x,to_y,chance,board)==true)
		{
			return true;
		}
	}
	else if(chance==1)
	{
		//white
		if(board[from_x][from_y]==3 && move_white(from_x,from_y,to_x,to_y,chance,board)==true)
		{
			if(to_x==0)
			{
				board[from_x][from_y]=6;
			}
			return true;
		}
		else if(board[from_x][from_y]==6 && move_king(from_x,from_y,to_x,to_y,chance,board)==true)
		{
			return true;
		}
	}
	//cout<<1;
	return false;
}
bool perform_Action_computer(vector<vector<int> > &board,int from_x,int from_y, int to_x, int to_y,int chance)
{
	if(chance==1 && (is_valid(from_x,from_y,to_x,to_y,chance,board)))
	{
		
		board[to_x][to_y]=board[from_x][from_y];
		board[from_x][from_y]=0;
		print_board(board);
		return true;
	}
	else if(chance==0 && (is_valid(from_x,from_y,to_x,to_y,chance,board)))
	{
		
		board[to_x][to_y]=board[from_x][from_y];
		board[from_x][from_y]=0;
		print_board(board);
		return true;
	}
	else
	{
		return false;

	}

}

bool game_finished(vector<vector<int> > board,int chance)
{
	int b=0;
	int w=0;

 for(int i=0;i<n;i++)
 {
 	for(int j=0;j<n;j++)
 	{
 		if(board[i][j]==1 || board[i][j]==2)
 			b++;
 		if(board[i][j]==3 || board[i][j]==6)
 			w++;
 	}
 }
 if(b<=2 || w<=2 )
 	return true;

 for(int i=0;i<n;i++)
 {
 	for(int j=0;j<n;j++)
 	{
 		if(chance==0)
 		{
 			if(board[i][j]==1)
 			{
 				if(coord_valid(i+1,j-1) && is_valid(i,j,i+1,j-1,chance,board))
 					return false;
 				if(coord_valid(i+1,j+1) && is_valid(i,j,i+1,j+1,chance,board))
 					return false;

 			}
 			else if(board[i][j]==2)
 			{
 				 if(coord_valid(i-1,j-1) && is_valid(i,j,i-1,j-1,chance,board))
 					return false;
 				if(coord_valid(i-1,j+1) && is_valid(i,j,i-1,j+1,chance,board))
 					return false;
 				if(coord_valid(i+1,j-1) && is_valid(i,j,i+1,j-1,chance,board))
 					return false;
 				if(coord_valid(i+1,j+1) && is_valid(i,j,i+1,j+1,chance,board))
 					return false;
 			}
 		}
 		else if(chance==1)
 		{
 			if(board[i][j]==3)
 			{
 				if(coord_valid(i-1,j-1) && is_valid(i,j,i-1,j-1,chance,board))
 					return false;
 				if(coord_valid(i-1,j+1) && is_valid(i,j,i-1,j+1,chance,board))
 					return false;

 			}
 			else if(board[i][j]==6)
 			{
 				 if(coord_valid(i-1,j-1) && is_valid(i,j,i-1,j-1,chance,board))
 					return false;
 				if(coord_valid(i-1,j+1) && is_valid(i,j,i-1,j+1,chance,board))
 					return false;
 				if(coord_valid(i+1,j-1) && is_valid(i,j,i+1,j-1,chance,board))
 					return false;
 				if(coord_valid(i+1,j+1) && is_valid(i,j,i+1,j+1,chance,board))
 					return false;
 			}
 		}
 	}
 }
 return true;
}
bool check_killing(vector<vector<int> > &board,int chance)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(board[i][j]==3)
			{
				if(coord_valid(i-2,j-2))
				{
					if(iskillingwhite(i,j,i-2,j-2,chance,board)==true)
					{
						board[i-2][j-2]=board[i][j];
						board[i][j]=0;
						return true;
					}
				}
				if(coord_valid(i-2,j+2))
				{
					if(iskillingwhite(i,j,i-2,j+2,chance,board)==true)
					{
						board[i-2][j+2]=board[i][j];
						board[i][j]=0;

						return true;
					}
				}
			}
			else if(board[i][j]==6)
			{
				if(coord_valid(i+2,j-2))
				{
					if(iskillingking(i,j,i+2,j-2,chance,board)==true)
					{
						board[i+2][j-2]=board[i][j];
						board[i][j]=0;
						return true;
					}
				}
				if(coord_valid(i+2,j+2))
				{
					if(iskillingking(i,j,i+2,j+2,chance,board)==true)
					{
						board[i+2][j+2]=board[i][j];
						board[i][j]=0;
						return true;
					}
				}
				if(coord_valid(i-2,j+2))
				{
					if(iskillingking(i,j,i-2,j+2,chance,board)==true)
					{
						board[i-2][j+2]=board[i][j];
						board[i][j]=0;
						return true;
					}
				}
				if(coord_valid(i-2,j-2))
				{
					if(iskillingking(i,j,i-2,j-2,chance,board)==true)
					{
						board[i-2][j-2]=board[i][j];
						board[i][j]=0;
						return true;
					}
				}
			}
		}
	}
	return false;
}
bool check_killing1(vector<vector<int> > &board,int chance)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(board[i][j]==1)
			{
				if(coord_valid(i+2,j-2))
				{
					if(iskillingblack(i,j,i+2,j-2,chance,board)==true)
					{
						board[i+2][j-2]=board[i][j];
						board[i][j]=0;
						return true;
					}
				}
				if(coord_valid(i+2,j+2))
				{
					if(iskillingblack(i,j,i+2,j+2,chance,board)==true)
					{
						board[i+2][j+2]=board[i][j];
						board[i][j]=0;

						return true;
					}
				}
			}
			else if(board[i][j]==2)
			{
				if(coord_valid(i+2,j-2))
				{
					if(iskillingking(i,j,i+2,j-2,chance,board)==true)
					{
						board[i+2][j-2]=board[i][j];
						board[i][j]=0;
						return true;
					}
				}
				if(coord_valid(i+2,j+2))
				{
					if(iskillingking(i,j,i+2,j+2,chance,board)==true)
					{
						board[i+2][j+2]=board[i][j];
						board[i][j]=0;
						return true;
					}
				}
				if(coord_valid(i-2,j+2))
				{
					if(iskillingking(i,j,i-2,j+2,chance,board)==true)
					{
						board[i-2][j+2]=board[i][j];
						board[i][j]=0;
						return true;
					}
				}
				if(coord_valid(i-2,j-2))
				{
					if(iskillingking(i,j,i-2,j-2,chance,board)==true)
					{
						board[i-2][j-2]=board[i][j];
						board[i][j]=0;
						return true;
					}
				}
			}
		}
	}
	return false;
}
void computer1(vector<vector<int> > &board,int next_player)
{
	srand((unsigned) time(0));

	if(check_killing1(board,next_player))
	{
		print_board(board);
		return ;
	}
	int temp1=10000000;
	while(true)

	{
	temp1--;
	if(temp1==0)
	break;
	int from_x= 0 + (rand() % 7);
	int from_y= 0 + (rand() % 7);
	int to_x= 0 + (rand() % 7);
	int to_y= 0 + (rand() % 7);
		bool temp =perform_Action_computer(board,from_x,from_y,to_x,to_y,next_player);
		if(temp==true)
			break;
	}
	for(int i=0;i<n;i++)
	{
		bool temp=false;
		for(int j=0;j<n;j++)
		{
					int to_x= 0 + (rand() % 7);
					int to_y= 0 + (rand() % 7);	
		if(board[i][j]==1 || board[i][j]==2)
			{
				temp =perform_Action_computer(board,i,j,to_x,to_y,next_player);
				if(temp==true)
					break;
			}
		}
		if(temp==true)
			break;
	}
		
	return;

}
void computer(vector<vector<int> > &board,int next_player)
{
	srand((unsigned) time(0));

	if(check_killing(board,next_player))
	{
		print_board(board);
		return ;
	}
	int temp1=10000000;
	while(true)

	{
	temp1--;
	if(temp1==0)
	break;
	int from_x= 0 + (rand() % 7);
	int from_y= 0 + (rand() % 7);
	int to_x= 0 + (rand() % 7);
	int to_y= 0 + (rand() % 7);
		bool temp =perform_Action_computer(board,from_x,from_y,to_x,to_y,next_player);
		if(temp==true)
			return;
	}
	for(int i=0;i<n;i++)
	{
		bool temp=false;
		for(int j=0;j<n;j++)
		{	
		if(board[i][j]==3 || board[i][j]==6)
			{
					int to_x= 0 + (rand() % 7);
					int to_y= 0 + (rand() % 7);
				temp =perform_Action_computer(board,i,j,to_x,to_y,next_player);
				if(temp==true)
					break;
			}
		}
		if(temp==true)
			break;
	}
		
	return;

}
int next_player=0;
int main()
{
	vector<vector<int> > board(n,vector<int> (n));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(check(i,j))
				board[i][j]=-1;
			else if(check_black(i,j))
			{
				board[i][j]=1;
			}
			else if(check_white(i,j))
			{
				board[i][j]=3;
			}
			else
			{
				board[i][j]=0;
			}
		}
	}
	print_board(board);
	while(true)
	{
		cout<<endl;
		if(game_finished(board,next_player)==true)
		{
			if(next_player==0)
			cout<<" player1 losses Player2 WINS !!!!  "<<endl;
			if(next_player==1)
			cout<<" Player2 losses, Player1 WINS !!!!  "<<endl;
			break;
		}
		cout<<"To quit input '-1',else any key to continue"<<endl;
		int c;
		cin>>c;
		if(c==-1)
		break;
		 if(next_player==0)
				{
					cout<<"Computer (black) chance"<<endl;
					computer1(board,next_player);
					next_player=1;
			
				}
		else if(next_player==1)
		{
			cout<<"Computer (white) chance"<<endl;
			computer(board,next_player);
			next_player=0;
			
		}
		

	}
	cout<<"Game Ended";
	return 0;

}
void print_board(vector<vector<int> > board)
{
	cout<<"  ";
	cout<<"a b c d e f g h";
	cout<<endl;
	
	for(int i=0;i<n;i++)
	{
		cout<<i+1;

		cout<<' ';
		for(int j=0;j<n;j++)
		{
			if(board[i][j]==-1)
				cout<<' ';
			else if(board[i][j]==1)
				cout<<'b';
			else if(board[i][j]==2)
				cout<<'B';
			else if(board[i][j]==3)
				cout<<'w';
			else if(board[i][j]==6)
				cout<<'W';
			else if(board[i][j]==0)
				cout<<'-';
			cout<<" ";
		}

		cout<<i+1; 
		cout<<endl;
	}
	cout<<"  a b c d e f g h";
	cout<<endl;
}
