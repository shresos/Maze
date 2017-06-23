//This is a text based game to solve a maze. give inputs it gives output till you hit the exit. It works on the most powerful graphic chip available, our Imagination...
//v7i as in version:0.7improved
#include<iostream>
#include<cstring>
#include<ctype.h>
#include<stdio.h>


using namespace std;
int first=1;			//first is global for variation in output lines

void menu();			//gives output as game's main menu
void input();			//asks two word input from the user, splits the word and assigns them in different variables
void processor(char[] ,char[]);	//checks condition for known inputs and carry out accordingly, and gives error for invalid inputs
void response(int);		//an integer value is passed to it by processor and generates response accordingly
void check_dir_go(char[]);	//
void check_door();
void open_door();

class maptile
{
	static int current_x,current_y;				//players current co-ordinates
	static maptile* current_tile;				//players's current tile position

	char left[15],right[15],up[15],down[15];		//variables: directions
	int pos_x,pos_y;					//variables: co-ordinates

	public:

		int static cmp_up()					//compares up of current_tile* and returns appropriate response
		{
			if(!strcmp(current_tile->up,"passage"))
				return 1;
			else if(!strcmp(current_tile->up,"wall"))
			{
				return 0;
			}
			else if(!strcmp(current_tile->up,"door"))
			{
				return 3;
			}

		}
		int static cmp_down()					//compares down of current_tile* and returns appropriate response
		{
			if(!strcmp(current_tile->down,"passage")||!strcmp(current_tile->down,"exit"))
				return 1;
			else if(!strcmp(current_tile->down,"wall"))
			{
				return 0;
			}
			else if(!strcmp(current_tile->down,"door"))
			{
				return 3;
			}
			else return 0;

		}
		int static cmp_left()					//compares left of current_tile* and returns appropriate response
		{
			if(!strcmp(current_tile->down,"passage")||!strcmp(current_tile->down,"exit"))
				return 1;
			else if(!strcmp(current_tile->left,"wall"))
			{
				return 0;
			}
			else if(!strcmp(current_tile->left,"door"))
			{
				return 3;
			}

		}
		int static cmp_right()					//compares right of current_tile* and returns appropriate response
		{
			if(!strcmp(current_tile->right,"passage"))
				return 1;
			else if(!strcmp(current_tile->right,"wall"))
			{
				return 0;
			}
			else if(!strcmp(current_tile->right,"door"))
			{
				return 3;
			}


		}
		void static set_initial_pos_tile(int x,int y, maptile &t)	//used once at first to set the primary position of the player.
		{
			current_x=x;
			current_y=y;
			current_tile=&t;
		}
		void static add_x()					//adds 1 from current x
		{
			current_x=current_x+1;

		}
		void static sub_x()					//subtracts 1 from current x
		{
			current_x=current_x-1;

		}
		void static add_y()					//adds 1 from current y
		{
			current_y=current_y+1;

		}
		void static sub_y()					//subtracts 1 from current y
		{
			current_y=current_y-1;

		}

		void static set_pos(maptile &ti)			//sets current_tile* to input object
		{
			current_tile=&ti;
		}

		int cmp_x_y()								//
		{
			if(current_x==pos_x && current_y==pos_y)
				return 1;
			else
				return 0;
		}
		void setall(int x,int y, char l[], char r[], char u[], char d[])	//loads map onto the objects
		{
			strcpy(left,l);
			strcpy(right,r);
			strcpy(up,u);
			strcpy(down,d);
			pos_x=x;
			pos_y=y;


		}

		int static game()				//checks position of current tile if game is over or not. returns integer
		{
			if((current_x==6 && current_y==-1)||(current_x==-1 && current_y==5))
				return 1;
			else
				return 0;
		}


		void static look_around()			//gives output of all direction in currentile.
		{
		    int i;
			for(i=0;i<3;i++)
			{
				switch(i)
                {


				case 1:	if(!strcmp(current_tile->left,"passage"))
							printf("_");
						else if(!strcmp(current_tile->left,"wall"))
							printf(" ");
						else if(!strcmp(current_tile->up,"wall"))
							printf(" _ ");
						else if(!strcmp(current_tile->up,"passage"))
							printf("|_|");
						else if(!strcmp(current_tile->right,"passage"))
							printf("_\n");
						else if(!strcmp(current_tile->right,"wall"))
							printf("\n");
						break;

				case 2:	if(!strcmp(current_tile->left,"wall"))
							printf(" |");
						else if(!strcmp(current_tile->left,"passage"))
							printf("_|");

						else if(!strcmp(current_tile->right,"wall"))
							printf("\n");
						else if(!strcmp(current_tile->right,"passage"))
							printf("_\n");
						break;

				case 3:	printf(" ");
						if(!strcmp(current_tile->down,"wall"))
							printf("\n");
						if(!strcmp(current_tile->down,"passage"))
							printf("|_|\n");
						break;
                }
			}


		cout<<"\n			UP-"<<current_tile->up<<endl;
		cout<<"\n";
		cout<<"	LEFT-"<<current_tile->left<<"	   	   		RIGHT-"<<current_tile->right<<endl;
		cout<<"                  	DOWN-"<<current_tile->down<<endl;
		cout<<"\n";

		}

}tile[20];




int maptile ::current_x;
int maptile ::current_y;
maptile* maptile::current_tile;


int main()
{
	menu();
	return 0;
}

void menu()		//consists of main menu: start game,
{
	int i;
	char w[5]="wall",p[8]="passage";
	char d[5]="door";
	char* wall;
	char* passage;
	char* door;
	wall=w;
	passage=p;
	door=d;

	int choice;

	cout<<"GET ME OUT OF HERE\n";			//interface display for main menu
	cout<<"MENU::\n";
	cout<<"1.Start Game\n2.Instructions\n3.exit\n";

	cin>>choice;

	cin.clear();
	cin.ignore();

	if(choice==1)					//start game is chosen.
	{
	cout<<"Your car broke down, you went to get help. And found yourself standing in \nfront of a Mansion! You go inside, it was quite plesant, but noone was answering. \nSuddenly the lights went out, and its pitch black. Luckly you got a lighther.. \nLight it up... Now Lets Get Out Of Here!!\n-find an exit..\n";

							//LOADING MAP...
	tile[0].setall(0,0,wall,wall,wall,wall);
	tile[1].setall(1,0, wall,passage,wall,wall);
//loading 10..
	tile[2].setall(1,1,passage,passage,passage,wall);

	tile[3].setall(1,2,passage,passage,wall,wall);
//loading 20..
	tile[4].setall(1,3,passage,wall,passage,wall);
	tile[5].setall(2,3,wall,passage,passage,passage);
//loading 30..
	tile[6].setall(2,4,passage,passage,wall,wall);
	tile[7].setall(2,5,passage,wall,wall,passage);
//loading 40..
	tile[8].setall(1,5,wall,wall,passage,passage);
	tile[9].setall(0,5,wall,wall,passage,door);
//loading 50..

	tile[10].setall(2,1,wall,wall,passage,passage);
	tile[11].setall(3,1,wall,passage,wall,passage);
//loading 60..

	tile[12].setall(3,2,passage,passage,wall,wall);
	tile[13].setall(3,3,passage,wall,passage,passage);
//loading 80..
	tile[14].setall(4,3,wall,wall,passage,passage);
	tile[15].setall(5,3,passage,wall,wall,passage);
//loading 90..
	tile[16].setall(5,2,passage,passage,wall,wall);
	tile[17].setall(5,1,passage,passage,wall,wall);
//loading 99..
	tile[18].setall(5,0,wall,passage,passage,wall);
	tile[19].setall(6,0,door,wall,wall,passage);
//loading 100..
//lets start

	maptile::set_initial_pos_tile(1,0,tile[1]);


	while(!maptile::game())
	{
		input();
		for(i=1;i<20;i++)
		{
			if(tile[i].cmp_x_y())
			{
				maptile::set_pos(tile[i]);
				break;
			}

		}


	}
	cout<<"\n\nyeah!! i got out.."<<endl;

	cout<<"GAME OVER!!!"<<endl;
	cout<<"\nThank You for Playing..."<<endl;
	cout<<"Brought to you by::"<<endl;
	cout<<"Oshan Shrestha"<<endl;
	cout<<"Ramendra Manandhar\n"<<endl;


	}

	else if(choice==2)		//instruction menu.
	{
cout<<"\n\nGO/WALK\tLEFT\n\tRIGHT\n\tUP\n\tDOWN\n\n\tNORTH\n\tSOUTH\n\tEAST\n\tWEST\n\nOPEN\tDOOR\n\nLOOK\tAROUND\n\n";
		cout<<"Enter string commands like 'Go/Walk left', 'walk down', 'go up' to move.\nUse 'look around' command to know what is around you\nQuit to go back to main menu during the game.\n\n\n";
		menu();
	}


}

void input()	//function to get input, split it into two words and pass them on to processor module.
{
	string ip;
	char action[15], direction[15];
	int i,j,k,ac_flg;
	if(first<3)			//checking for variation in output lines
	{
	cout<<"\nWhere do i go?"<<endl;
	getline(cin,ip);		//takes input as a sentence, including spaces.
	first++;
   	}
	else
	{
	cout<<"\nNow what?"<<endl;
	getline(cin,ip);
	first=+first%5;
	first++;
	}

	j=0;
	k=0;
	ac_flg=0;

	for(i=0;i<ip.size();i++)
	{

		if(ip[i]==' ')
		{
			ac_flg++;
			if(ac_flg==2)
				goto next;
			i++;
		}
		if(ac_flg==0)
		{
			action[j++]=ip[i];
		}
		else
		{
			direction[k++]=ip[i];
		}
	}
	next:
	action[j++]='\0';
	direction[k++]='\0';

	for(i=0;action[i]!='\0';i++)
	{
		action[i]=tolower(action[i]);
	}
	action[i++]='\0';

	for(i=0;direction[i]!='\0';i++)
	{
		direction[i]=tolower(direction[i]);
	}
	direction[i++]='\0';

	processor(action, direction);

}




void processor(char action[], char direction[])
{

	if (!strcmp(action,"go")||!strcmp(action,"walk"))	//check condition to move
	{
		check_dir_go(direction);
	}
	else if(!strcmp(action,"look"))	//check condition to call look_around() function
	{

		maptile::look_around();
	}

	else if(!strcmp(action,"quit"))	//check condition to quit to main menu
	{
		first=1;
		menu();
	}
	else if(!strcmp(action,"open"))	//check condition to open door
	{
		check_door();
	}
	else				//invalid input
	{
		cout<<"type easy, cant understand..\n";
	}

}

void check_door()			//checks in current tile's all direction for a door if found, continues on to open door sub module.
{

	if ((maptile::cmp_down()==3)||(maptile::cmp_left()==3))
	{
		cout<<"DOOR OPENED.. :D\n";
		open_door();
	}
	else
	{
		cout<<"Where did you see a door? o_O"<<endl;
	}
}


void open_door()			//changes door, to an exit, to end game.
{
	char w[5]="wall",e[5]="exit",p[8]="passage";
	char* wall;
	char* passage;
	char* exit;
	wall=w;
	exit=e;
	passage=p;
	tile[19].setall(6,0,exit,wall,wall,passage);
	tile[9].setall(0,5,wall,wall,passage,exit);
}

void check_dir_go(char direction[])	//checking direction for go action, if wall, cant, if passage, change current position. Also gives appropriate output via response module.
{
	int flag=2;

	if(!strcmp(direction,"left")||!strcmp(direction,"west"))
	{
		flag=maptile::cmp_left();
		if(flag==1)
		{
			maptile::sub_y();
			response(0);
		}

		else if(flag==3)
		{
			response(2);
		}
		else
			response(1);
	}

	else if(!strcmp(direction,"right")||!strcmp(direction,"east"))
	{
		flag=maptile::cmp_right();
		if(flag==1)
		{
			maptile::add_y();
			response(0);
		}
		else
			response(1);
	}

	else if(!strcmp(direction,"up")||!strcmp(direction,"north"))
	{
		flag=maptile::cmp_up();
		if(flag==1)
		{

			maptile::add_x();
			response(0);
		}
		else
			response(1);
	}

	else if(!strcmp(direction,"down")||!strcmp(direction,"south"))
	{
		flag=maptile::cmp_down();

		if(flag==1)
		{
			maptile::sub_x();
			response(0);
		}
		else if(flag==3)
		{
			response(2);
		}

		else response(1);
	}

	else
	{
		cout<<"hmm.. type again please?\n";		//error message for valid action but invalid direction
	}

}

void response(int r) 				//returns on screen appropriate output from the supplied integer
{
	if(r==1)
	{
		if(first>3)			//variation in output, wall error
			cout<<"I CANT!"<<endl;
		else
			cout<<"Can't walk through walls.."<<endl;
	}
	else if(r==0)
	{
		if(first>4)			//variation in output, passage response
			cout<<"done!"<<endl;
		else
			cout<<"I took a step"<<endl;

	}
	else if(r==2)				//output when door is encountered
	{
		cout<<"i see a door\n";
	}

}
