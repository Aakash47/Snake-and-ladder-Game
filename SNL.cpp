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
        cout<<"Palyer "<<player+1<<" chance."<<endl;
        cout<<"Press Enter to roll a dice";
        cin.ignore();
        cout<<"=================================="<<endl;
        cout<<"Player "<<player+1<<" rolled a "<<dice()<<endl;

        cout<<"=================================="<<endl;

        if (current[player]==0 && dice()!=6)
        {
            // current[player] -= dice();
            cout<<"Game not started for player "<<player+1<<" as player not get 6 to start the game"<<endl;
        }
        else
        {
            current[player] += dice();
        }
        
        switch (current[player])
        {
        // cases to climbe ladders
        case 5:
            current[player]=10;
            cout<<"player "<<player+1<<" climbed a ladder to 10"<<endl;
            break;
        case 20:
            current[player]=45;
            cout<<"player "<<player+1<<" climbed a ladder to 45"<<endl;
            break;
        case 35:
            current[player]=42;
            cout<<"player "<<player+1<<" climbed a ladder to 42"<<endl;
            break;
        case 50:
            current[player]=63;
            cout<<"player "<<player+1<<" climbed a ladder to 63"<<endl;
            break;
        case 65:
            current[player]=76;
            cout<<"player "<<player+1<<" climbed a ladder to 76"<<endl;
            break;
        case 70:
            current[player]=87;
            cout<<"player "<<player+1<<" climbed a ladder to 87"<<endl;
            break;
        case 83:
            current[player]=96;
            cout<<"player "<<player+1<<" climbed a ladder to 96"<<endl;
            break;

        // cases for snake bite
        case 15:
            current[player]=2;
            cout<<"player "<<player+1<<" is bitten by snake and is at postion 2"<<endl;
            break;
        case 25:
            current[player]=10;
            cout<<"player "<<player+1<<" is bitten by snake and is at postion 10"<<endl;
            break;
        case 37:
            current[player]=29;
            cout<<"player "<<player+1<<" is bitten by snake and is at postion 29"<<endl;
            break;
        case 52:
            current[player]=45;
            cout<<"player "<<player+1<<" is bitten by snake and is at postion 45"<<endl;
            break;
        case 68:
            current[player]=55;
            cout<<"player "<<player+1<<" is bitten by snake and is at postion 55"<<endl;
            break;
        case 85:
            current[player]=71;
            cout<<"player "<<player+1<<" is bitten by snake and is at postion 71"<<endl;
            break;
        case 98:
            current[player]=37;
            cout<<"player "<<player+1<<" is bitten by snake and is at postion 37"<<endl;
            break;
        }

        if (current[player] > board)
        {
            current[player]-=dice();
            cout<<"player "<<player+1<<" didn't move as to score on dice more to reach home."<<endl;
        }
        else if (current[player]==100)
        {
            cout<<"Player "<<player+1<<" wins!!!"<<endl;
            cout<<"=================================="<<endl;
            gameOver= true;
        }
        
        for (int i = 0; i < maxplayer; i++)
        {
            cout<<"Player "<<i+1<<" is at postion "<<current[i]<<endl;
        }
		
        player = (player+1) % maxplayer;
        // system("pause");
        cout<<"Press Enter to continue game";
        cin.ignore();
    }
}