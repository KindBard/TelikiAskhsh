//include Libs
#include <iostream>
#include <string>
#include <conio.h>
#include <dos.h> 
#include <windows.h>
#include <chrono>
#include <thread>

//screen define
#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 30
#define WIN_WIDTH 70
//namepsaces
using namespace std;



void Credits();
void GameOver();
void CombatHUB();
void Combat();
void monstercreate();
void Stats();
void GameStart();
void playSword();
void playWand();
void playBow();
void lore();
void play();


namespace detail_
{
    struct wait_for
    {
        explicit wait_for( unsigned int msecs ) : ms(msecs) {}
        const std::chrono::milliseconds ms ;

        template< typename C, typename T >
        friend std::basic_ostream<C,T>& operator<< ( std::basic_ostream<C,T>& stm, wait_for w )
        { if(stm) std::this_thread::sleep_for(w.ms) ; return stm ; }
    };
}

template< typename C, typename T >
std::basic_ostream<C,T>& operator<< ( std::basic_ostream<C,T>& stm, std::pair< std::string, detail_::wait_for> str_slow )
{
    for( char c : str_slow.first ) stm << str_slow.second << c << std::flush ;
    return stm ;
}

std::pair< std::string, detail_::wait_for> slowly( std::string str, unsigned int ms = 100 ) 
{ return { str, detail_::wait_for(ms) } ; }

//public ints
int cho;

string name="",race="";
string monstername[] = {"Wolf"};
int currentmonstername=1;
string mName ="";


//structure
struct
{
	int damage;
	int xp;
	int level;
	int health;
	int totalhp;
	int monsterhp;
}bard,monsters,goblin;
//voids

void Credits()
{
	system("cls");
	cout<<"\t\t\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\t\t\t------------Thanks For Playing--------------"<<endl;
	cout<<"\t\t\t\t\t--------------------------------------------"<<endl<<endl;
	cout << "\n\n" << endl;
	cout <<"1.Play again for a different outcome" << endl;
	cout <<"2.Exit Game" << endl;
	char cho = getche(); 
			if( cho=='1')
			{
				GameStart();
			}
			else if( cho =='2') exit(0);
	
}

void GameOver()
{
	system("cls");
	cout<<"\t\t\t\t\t----------------------------------"<<endl;
	cout<<"\t\t\t\t\t------------YOU DIED--------------"<<endl;
	cout<<"\t\t\t\t\t----------------------------------"<<endl<<endl;
	cout << "\n\n" << endl;
	cout <<"Play again for a different outcome" << endl;
	system("pause");
	GameStart();
}
void CombatHUB()
{
	Sleep(500);
	system ("cls");
	cout << "Name: " << name << "		|		Monster Name: Wolf"  << "\nHealth: " << bard.totalhp << "		|		Monster's Health: " << monsters.health << endl;
	cout << "Level: " << bard.level << "		|		Monster's level: " << monsters.level << endl;
} 

void Combat()
{	
	CombatHUB();
	int playerattack;

	bard.damage=25 * bard.level;
	
	if(bard.totalhp >=1 && monsters.health >=1)
	{
		
		cout << "\n\n" << endl;
		cout << "1.Attack" << endl;
		cout << "2.Flee" << endl;
		cin >> playerattack;
		//Attack
		
		if (playerattack==1)
		{
			cout << "You decided to attack the monster...\n" << slowly("You did ") << bard.damage <<slowly( " damage to the Wolf" )<< endl;
			monsters.health = monsters.health - bard.damage;
			Sleep(500);
			if (monsters.monsterhp<=0)
		{		CombatHUB();
				cout << "\n\n" << endl;
				cout << "You Killed it!! " << endl; 

			Sleep(6000);
			system("cls");
			cout <<slowly("You stand there watching the animal you just killed...") <<endl;
			cout <<slowly("You do feel remorse for your actions but you decide to...") <<endl;
			cout <<"\n\n";
			cout <<"1.Eat the wolf"<<endl;
			cout <<"2.Walk away" << endl;
			
			char choi = getche(); 
			if( choi=='1')
			{
				system("cls");
				cout <<slowly ("You decided to eat the wolf's meat") << endl;
				cout <<slowly ("Because you were in a hurry you ate it raw") << endl;
				cout <<slowly("You felt sick soon after while trying to find your way out of the woods ") << endl;
				cout << slowly("After a while you decided to lay down in front of a big tree and your last breath left your body") << endl;
				system("pause");
				system("cls");
				cout << "Loading the game..." << endl;
				Sleep(500);
				GameOver();
				
			}
			else if (choi=='2')
			{
				system("cls");
				cout <<slowly ("You decided to walk away") << endl;
				cout <<slowly ("After walking for a while you decide to rest near a tree") << endl;
				cout <<slowly ("You consider that more wild animals might attack you while you regain your strength") << endl;
				cout <<slowly ("So you decide to climb on a tree's branch and spent your night up there") << endl;
				cout <<slowly ("The next day you find a path whitch leads you outside the forest") << endl;
				cout <<slowly ("You glance at your sword and start preparing for the next adventure") << endl;
				system("pause");
				system("cls");
				cout << "Loading the game..." << endl;
				Sleep(500);
				Credits();
			}
		}
		//Run
		}else if (playerattack==2)
		{
			system("cls");
			cout <<slowly( "You decide to run for your life") << endl;
			cout <<slowly("You run faster than the wind and escape the Wolf") <<endl;
			cout <<slowly( "While running away you can hear a river on your left") << endl;
			cout <<slowly( "You glance back and see that wolf is catching up on you...\nYou make a fast decision and decide to...") << endl;
			cout << "\n\n" << endl;
			cout << "1.Make a run for the river" << endl;
			cout << "2.Try to scare the wolf away" << endl;
			
			char chop = getche(); 
			if( chop=='1')
			{
				system("cls");
				cout << slowly ("You can now see the river's bank clrearly") << endl;
				cout << slowly ("You make your way to the bridge only to find it broken in half") << endl;
				cout << slowly ("The Wolf is right behing you..you search for your trusty sword") << endl;
				cout << slowly ("As the wolf approaches you...a friendly hunter shot him dead and saved your life") << endl;
				cout << slowly ("You follow the hunter on a nearby town and start a new life there") << endl;
				system("pause");
				system("cls");
				cout << "Loading the game..." << endl;
				Sleep(500);
				Credits();
			}
			else if ( chop == '2')
			{
				system("cls");
				cout << slowly ("You are a man you think to yourself...why am i scared of a wolf?") << endl;
				cout << slowly ("You decide to turn and face the wolf face to face") << endl;
				cout << slowly ("But while you are about to do that you notice the whole pack is chasing you") << endl;
				cout << slowly ("You turn around to continue fleeing but it's already too late") << endl;
				cout << slowly ("A wolf grabs you from the ankle and soon after you die a slow and painfull death") << endl;
				cout << slowly ("While the wolves are feasting on your flesh") << endl;
				system("pause");
				system("cls");
				cout << "Loading the game..." << endl;
				Sleep(500);
				GameOver();
			}
			
		}
		else 
		{
		cout << "ERROR\n";
		system("pause");
		Combat();
		}
	} 
}

void monstercreate()
{
	monsters.health=20;
	monsters.level = (rand() % 3) + bard.level/2;
} 
void Stats()
{
	Sleep(500);
	system ("cls");
	cout << "Level: " << bard.level << "\n Health: " << bard.health <<" / "<< bard.totalhp << endl;
	cout << "Name: " << name << "\n Race :" << race << endl; 
	cout <<"\n\n";
}

void GameStart()
{	
	system("cls");
	cout << "Loading the game..." << endl;
	Sleep(2500);
	int action;
	system("cls");
	cout <<slowly("You make your way to the woods while the king's army spots you...'") << endl;
	Stats();
	cout <<"\n\n" <<endl;
	cout << "1.Move Forward" << endl;
	cout << "2.Chill" << endl;
	cout << "3.Go back" << endl;
	
	cin >> action;
	
	if (action==1)
	{
		
		cout << slowly ("You move forward...") << endl;
				monstercreate();
				cout <<slowly("You bumbed into something") <<endl; Sleep(200);
				cout <<slowly( "A strange figure appears before you") <<endl; Sleep(200);
				cout <<slowly ("IT'S A WOLF!!!") <<endl;
				
				Sleep(500);
				Combat();
	}	
	else if (action==2)
	{
		system("cls");
		cout <<slowly("While you are regaining your stamina you hear humans approaching...") << endl;
		cout <<slowly("You see a nearby cave") << endl;
		cout <<slowly("While you are in a panic you decide to...") << endl;
		cout <<"\n\n1.Run" << endl;
		cout <<"2.Hide" << endl;
			
			char action2 = getche(); 
			if( action2=='1') 
			{
				system("cls");
				cout <<slowly("While you are hiding into the cave you hear a strange sound") << endl;
				cout <<slowly("A goblin emerges behind you from the shadows and grabs you from the neck") << endl;
				cout <<slowly("You can't breathe...you slowly close your eyes...") << endl;
				cout <<slowly("And never wake up again") << endl;
				system("pause");
				system("cls");
				cout << "Loading the game..." << endl;
				Sleep(500);
				GameOver();
			}
			else if (action2=='2')
			{
				system("cls");
				cout <<slowly("You decide to skip the cave and continue running away") << endl;
				cout <<slowly("After a while you manage to outrun the king's army") << endl;
				cout <<slowly("You slowly close your eyes...Untill") << endl;
				cout <<slowly("A familiar melody echoes to your ears") << endl;
				cout <<slowly("<<Far away,the Misty's mountain cold") << endl;
				cout <<slowly("Two dungeons,deep and caverns old") << endl;
				cout <<slowly("We must away...Ere break of day") << endl;
				cout <<slowly("To find our looong...Forgotten gold>>") << endl;
				cout <<slowly("As a fellow bard yourself, you decide to play your flute along with the music of the female bard") << endl;
				cout <<slowly("The two of you become a couple and eventually get married with 2 beautiful kids.") << endl;
				system("pause");
				system("cls");
				cout << "Loading the game..." << endl;
				Sleep(500);
				Credits();
			}
	}
	else if (action==3)
	{
		cout << slowly ("You decided to go back...") << endl;
		system("cls");
		cout << slowly ("While making your way back to Elber's home") << endl;
		cout << slowly ("You cross paths with the king's army") << endl;
		cout << slowly ("They instantlly capture you") << endl;
		cout << slowly ("and they take you to the central square\nfor your public execution") << endl;
		cout << slowly ("As the wooden stool got kicked under your feet and\nthe rope gets tighter around your neck") << endl;
		cout << slowly ("You think to yourself <<Walking back was a stupid idea...>>.") << endl;
			system("pause");
				system("cls");
				cout << "Loading the game..." << endl;
				Sleep(500);
				GameOver();
	}
	else 
	{
		cout << "ERROR\n";
		system("pause");
		Stats();
	}
}


void playSword()
{
	system("cls");
	cout << "Loading the game..." << endl;
	Sleep(3000);
	system("cls");
	cout<<slowly("You had to much of a drink last night...you wake up in a bed far away from home...") <<endl;
	cout << name <<": Wh...Where am i?" <<endl; Sleep(3000);
	cout<<"Stranger: You are finally awake...You were out for a week..."<<endl; Sleep(3000);
	cout<< name <<": Elber is that you?" <<endl; Sleep(1000);
	cout << "Elber:Yeah...Its me...do you have any idea on how much trouble you got yourself?" <<endl; Sleep(3000);
	cout<< name <<": No...My head still feels heavy,so what happened?" <<endl; Sleep(3000);
	cout << "Elber:You got into a fight with Arthur" <<endl; Sleep(3000);
	cout << name<< ": THE KING'S SON?" <<endl; Sleep(3000);
	cout << "Elber:Not only that..you killed him with your rusty sword..the whole kingdom is after you" <<endl; Sleep(3000);
	cout << name <<": Sh*t Sh*t Sh*t..What should i do now?" <<endl; Sleep(3000);
	cout << "Elber:Flee to the woods...I will try to stall them so you can run away...\n But be carefull...these woods are dangerous...Good luck old pal" <<endl; Sleep(1000);
	cout << name <<":Thanks Elber...you are a true friend" <<endl; Sleep(3000); 
	cout << "Elber:HEY "<< name << " DONT FORGET THIS!!!" <<endl; Sleep(3000);
	cout << name <<":Oh yeah I almost forgot...thanks again i owe you one.\n\n" <<endl; Sleep(3000); 
	cout << "Press 1 to grab your sword \n" << endl; 
	char cho = getche(); 
	if( cho=='1') 
	{
		GameStart();
	}
}

void playBow()
{
	system("cls");
	cout <<slowly("Coming Soon...Play the Sword Version\n");
	system("pause");
	playSword();
}             ;

void playWand()
{
	system("cls");
	cout <<slowly("Coming Soon...Play the Sword Version\n");
	system("pause");
	playSword();
}

void lore()
{	
	system("cls");
	cout<<"\t\t\t\t\t----------------------------------"<<endl;
	cout<<"\t\t\t\t\t----------------LORE--------------"<<endl;
	cout<<"\t\t\t\t\t----------------------------------"<<endl<<endl;
	
	cout << "\n\n In this game you play as a mighty Bard named "<<name <<endl;
	cout << " You like to spent your time either singing folk ballads in taverns or elaborate compositions in royal courts." << endl;
	cout << " You use your bard gifts to hold audiences spellbound." <<endl;
	cout <<"\n\n Untill one fatefull day..." <<endl;
	cout <<"\n\nPress any key to go back to main menu"<< endl;
	getch();
}

void play()
{	
	system("cls");
	cout<<slowly("The story's progression depends on the actions you take")<<endl;
	system ("pause");
	system("cls");
    cout<<"\t\t\t\t\t----------------------------------"<<endl;
	cout<<"\t\t\t\t\t---------CHOOSE YOUR WEAPON--------"<<endl;
	cout<<"\t\t\t\t\t----------------------------------"<<endl;
	
	cout << "\n\nType 1 to pick Sword" << endl;
	cout << "Type 2 to pick Wand" << endl;
	cout << "Type 3 to pick Bow" << endl;
	
	while(1){
	char cho = getche(); 
	 				                        
		if( cho=='1') playSword();
		else if( cho =='2') playWand();
		else if( cho =='3') playBow();
			}
}

//main game
int main(int argc, char** argv)
{	

bard.level = 1;
bard.xp = 0;  
bard.health=100;
bard.totalhp = bard.health;


cout << "Type your name brave warrior:"; cin >> name;
cout << "Type your race brave warrior:"; cin >> race;

cout << "Creating your character..." << endl;
Sleep(750);
system("cls");
cout << "Loading the game..." << endl;
Sleep(500);
system("cls");
	do{	
	system("cls");
	cout<<"\t\t\t\t\t----------------------------------"<<endl;
	cout<<"\t\t\t\t\t--------WELCOME "<<name<<"--------"<<endl;
	cout<<"\t\t\t\t\t----------------------------------"<<endl<<endl;
	
	cout << "1.Play" << endl;
	cout <<"2.Lore" << endl;
	cout <<"3 Exit Game" <<endl;

		char cho = getche();                          
		if( cho=='1') play();
		else if( cho =='2') lore();
		else if( cho =='3') exit(0);
		
	}
	while(1);
	
	return 0;
}