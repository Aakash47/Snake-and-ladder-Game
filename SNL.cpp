#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int random(int min, int max){
    srand(static_cast<unsigned int>(time(0)));
    return min+rand()%(max-min+1);
}

int dice(){
    return random(1,6);
    }

int main(){
    int ladder[]={5,20,35,50,65,80,90}; //positions of ladders on board
    int snake[]={15,25,37,52,68,85,98}; //postion of snakes on board
    int board=100; //maximum numbers of postions on board
    int maxplayer=2; //maximum players
    bool gameOver=false; //is game completed on not
    int current[maxplayer]={0}; //current postion of player defau;t is 0
    int player=0; //player variable to increment and current display

    while (!gameOver)
    {
        system("cls");
        cout<<"Snake and Ladder Game!!!"<<endl;
        cout<<"Current palyer "<<player+1<<endl;
        cout<<"=================================="<<endl;
        for (int i = 0; i < maxplayer; i++)
        {
            cout<<"Player "<<i+1<<" is at postion "<<current[i]<<endl;
        }
        cout<<"Player "<<player+1<<" rolled a "<<dice()<<endl;
        current[player] += dice();
        if (current[player] >= board)
        {
            cout<<"Player "<<player+1<<" wins!!!"<<endl;
            gameOver= true;
        }
        /* sizeof returns size of datatype e.g if we type sizeof(1) it will return 4 as size of int is 4.
        so in that way size of float is 4 and char is 1 */
        for(int i=0; i<sizeof(ladder) / sizeof(ladder[0]); i++){
			if(current[player] == ladder[i]){
			cout<<"player "<<player+1<<" climbed a ladder "<<dice()<<endl;
		    current[player] += dice();
			}
		}
		
		for(int i=0; i<sizeof(snake) / sizeof(snake[0]); i++){
			if(current[player] == snake[i]){
			cout<<"player "<<player+1<<" is bitten by snake "<<dice()<<endl;
            current[player] -= dice();
            current[player] -= dice();
			}
		}

        player = (player+1) % maxplayer;
        system("pause");
    }
    
}