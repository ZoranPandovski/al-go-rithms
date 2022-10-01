#include<iostream>
using namespace std;

void rules();
string toss();

int batting(){
    int bat[6];
    int totalruns = 0;
    bool wicket = false;
    
    for(int i=1;i<=6;i++){
        cout<<"\nBATTING | 0."<<i-1<<" overs"<<endl;
        cout<<"You entered ";
        cin>>bat[i];
        if(bat[i]<0 || bat[i]>6){
            cout<<"Only Numbers between 0 and 6, included."<<endl;
            cout<<"\n\nGameover Play Again\n\n\n\n"<<endl;
            i = 7;
        }
        cout<<"Opponent entered ";
        srand (time(NULL));
        int r = rand() % 7;
        cout<<r<<endl;
        int temp = bat[i];
        if(bat[i]==0){bat[i] = r;}
        
        totalruns = totalruns + bat[i];
        cout<<"Your runs is ---- "<<totalruns<<endl;
        
        if(temp==r){
            cout<<"\n\n | Innings over | "<<endl;
            wicket = true;
            i=7;
        }
        
        
    
    }
    cout<<"\n\nYour Total Runs = "<<totalruns<<endl;
    return(totalruns);
}

int bowling(int target){
    int bowl[6];
    int totalruns = 0;
    bool wicket = false;
    
    for(int i=1;i<=6;i++){
        cout<<"\nBOWLING | 0."<<i-1<<" overs"<<endl;
        cout<<"You entered ";
        cin>>bowl[i];
        if(bowl[i]<0 || bowl[i]>6){
            cout<<"Only Numbers between 0 and 6, included."<<endl;
            cout<<"\n\n\nGameover | Try again\n\n\n"<<endl; 
            i = 8;
        }
        cout<<"Opponent entered ";
        srand (time(NULL));
        int r = rand() % 7;
        cout<<r<<endl;
        int temp = r;
        if(r==0){r = bowl[i];}
        
        totalruns = totalruns + r;
        cout<<"Opponents runs is ---- "<<totalruns<<endl;
        
        if(temp==bowl[i]){
            cout<<"\n\n\n | You Win the MATCH | "<<endl;
            wicket = true;
            i=7;
        }
        if(totalruns>=target){
            i=7;
            cout<<"\n\n\n Opponent has won the MATCH \n";
        }
        
        
    
    }
    cout<<"\n\nOpponents Total Runs = "<<totalruns<<endl;
    return(totalruns);
}

void game(int innings){
    if(innings == 1){
        //batting first
        cout<<"\nYour Batting \n\n"<<endl;
        int target = batting();
        cout<<"Opponents Target is "<<target+1<<"\n\n";
        bowling(target+1);
    }
    else{
        //bowling first Feature not added yet;
        //bowling(target);
    }
}

void start(){
    string side;
    string choice;
    side = toss();
    cout<<"\nHeads or Tails?  (Press h or t)"<<endl;
    cin>>choice;
    if(choice == side){
        int ch;
        cout<<"You have won the toss! Press 1 for Bat or 2 for Ball"<<endl;
        cin>>ch;
        if(ch==1){game(1);}
        else if(ch == 2){
            cout<<"Sorry Bowling first feature not added yet";
            game(1);
        }
        else{cout<<"Invalid Input"<<endl;}
    }
    else{
        cout<<"Opponent has won the toss, and chose to Ball first"<<endl;
        game(1);
    }
    
}

int main(){
    cout<<"Hand Cricket (Odd or Even) //Press r for Rules"<<endl;
    rules();
    cout<<"\n\n";
    start();
 return 0;   
}

void rules(){
    cout<<"\nRULES-----------------"<<endl;
    cout<<"\nThe Game starts with a toss of coin deciding who gets to select Batting first of Bowling first"<<endl;
    cout<<"The batting phase is where user inputs number between 0 and 6 inc., and scores the runs respectively"<<endl;
    cout<<"If a 0 is scored, then batsmen gets the score of the bowler"<<endl;
    cout<<"Each phase is called an innings, and it either ends with wicket (same number) or end of an over (6 balls)"<<endl;
    cout<<"You will learn the game as you play, so All the Best\n"<<endl;
    cout<<"End of Rules------------"<<endl;
}

string toss(){
    srand((unsigned) time(0));
    int r = rand()%2;
    if(r==0){
        return "h";
    }
    else{return "t";}
}
