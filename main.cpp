#include <iostream>
#include <string>
#include <unistd.h>
using namespace std;

void initMap();
void displayMap();
bool updateMap();
void clearMap();


struct Map
{
	int y;
	int x;
	char map[26][64];
};

struct Map map;
int posSnkX = 5;
int posSnkY = 5;

int main()
{
	initMap();//create map
  	while(updateMap())
	{
		displayMap();//display the whole map
		usleep(50000);
	}
}

bool updateMap()
{
	char k;
	scanf("%c", &k);
	clearMap();

	switch(k)
	{
        case 'z':
        {
		posSnkY--;
		break;
	}
	case 's':
	{
		posSnkY++;
		break;
	}
	case 'q':
	{
		posSnkX--;
		break;
	}
	case 'd':
	{
		posSnkX++;
		break;
	}
       }	

	if(map.map[posSnkY][posSnkX] == ' ')
		{
			map.map[posSnkY][posSnkX] = 'o';
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


}

void initMap()
{
 map.y = 26;
 map.x = 64;

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
