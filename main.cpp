#include <iostream>
#include <string>
#include <unistd.h>
#include <curses.h>
using namespace std;

void initMap();
void displayMap();
bool updateMap();
void clearMap();
void addFood();

struct Map
{
	int y;
	int x;
	int dir;
	char map[26][64];
};


struct Map map;
int posSnkX = 32;
int posSnkY = 13;
int posSnkFdX = 10;
int posSnkFdY = 10;

struct Snake
{
  int xx;
  int yy;
  struct Snake* keu;
};

  struct Snake snake;


int main()
{
	initMap();//create map
	displayMap();
	cout << "press any control key to start" << endl;
        initscr();
	timeout(-1);
	getch();
	endwin();
	
	while(updateMap())
	{
		displayMap();//display the whole map
		usleep(50000);
	}
}

void addFood()
{
	map.map[posSnkFdY][posSnkFdX] = '+';
}

bool updateMap()
{

//	scanf("%c", &k);
	initscr();
	cbreak();
	timeout(30);
	int k = getch();
	endwin();
	clearMap();

	switch(k)
	{
        case 'z':
        {
		if(map.dir != 1)
		{
		map.dir = 0;
		}
		break;
	}
	case 's':
	{
		if(map.dir != 0)
			map.dir = 1;
		break;
	}
	case 'q':
	{
		if(map.dir != 3)
			map.dir = 2;
		break;
	}
	case 'd':
	{
		if(map.dir != 2)
			map.dir = 3;
		break;
	}
       }	
	int pastX = snake.xx;
	int pastY = snake.yy;
	switch(map.dir)
        {
        case 0:
        {
                snake.yy--;
                break;
        }
        case 1:
        {
	        snake.yy++;
                break;
        }
        case 2:
        {
                snake.xx--;
                break;
        }
        case 3:
        {
	        snake.xx++;
                break;
        }
       }
	

	bool eaten = false;
        if(map.map[snake.yy][snake.xx] == '+')
	  {
	    posSnkFdX = rand()%62 + 1;
	    posSnkFdY = rand()%24 + 1;
	    eaten = true;
	    printf("%c\n", '\a');
	  }
	if(map.map[snake.yy][snake.xx] == ' ' || map.map[snake.yy][snake.xx] == '+'  )
		{
		  struct Snake* snk = &snake;
		  while (snk != NULL)
		    {
		      map.map[snk->yy][snk->xx] = 'o';
		      if(snk->keu != NULL)
			{
			  snk = snk->keu;
			  int posX = snk->xx;
			  int posY = snk->yy;
			  snk->xx = pastX;
			  snk->yy = pastY;
			  pastX = posX;
			  pastY = posY;
			}
		      else if(eaten == true)
			{
			  snk->keu = new struct Snake;
			  snk->keu->xx = pastX;
			  snk->keu->yy = pastY;
			  snk->keu->keu = NULL;
			  snk = NULL;
			}
		      else
			snk = NULL;
		    }
			return true;
		}
	else
		{
			cout << "YOU DIED" << endl;	
			return false;
		}
}

void clearMap()
{
	
  //init the first line
  for(int x = 0; x < map.x; x++)
    {
      map.map[0][x]='-';
    }
  
                //init the middle of the map
        for(int y = 1; y < map.y; y++)
        {
                map.map[y][0]='!';//draw the left side
                for(int x = 1; x < map.x; x++)
                 {
                        map.map[y][x]=' ';////put white space  inside the map
                 }
                 map.map[y][map.x - 1]='!'; //draw the right side

        }

        //draw the bottom line
                for(int x = 0; x < map.x; x++)
                 {
                        map.map[map.y - 1][x]='-';
                 }
			addFood();

}

void initMap()
{
 map.y = 26;
 map.x = 64;
 map.dir = 0;
 snake.xx = 32;
 snake.yy = 13;
 snake.keu = NULL;
  //init the first line
  for(int x = 0; x < map.x; x++)
    {
      map.map[0][x]='-';
    }
  
		//init the middle of the map
	for(int y = 1; y < map.y; y++)
	{
		map.map[y][0]='!';//draw the left side
		for(int x = 1; x < map.x; x++)
		 {
		 	map.map[y][x]=' ';////put white space  inside the map
		 }
		 map.map[y][map.x - 1]='!'; //draw the right side
		
	} 
	
	//draw the bottom line
		for(int x = 0; x < map.x; x++)
		 {
		 	map.map[map.y - 1][x]='-';
		 }
		 

  
}
void displayMap()
{
  
for(int p = 0; p < 30; p++)
{
	cout<<endl;
}

  for(int y = 0; y < map.y; y++)
    {
      for(int x = 0; x < map.x; x++)
	{
	  cout << map.map[y][x];
	}
      cout << endl;
    }
for(int c = 0; c < 30; c++)
{
	cout<<endl;
}

}
