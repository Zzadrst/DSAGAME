#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <thread>
#include <chrono>
#include <windows.h>
#include <mmsystem.h>
#include <unistd.h>
#include <conio.h>
#include <cstdlib> // For system("cls")


using namespace std;

// Function to display the current state of the player's army
void display(const vector<int>& tree, const string& armyName) {
    cout << "--------------------" << armyName << "--------------------" << endl;
    for (int i = 0; i < tree.size(); i++) {
        cout << "Soldier " << i + 1 << ": Power Level " << tree[i] << endl;
    }
    cout << endl;
}

// Heapify function to build max heap
void heapify(vector<int>& tree, int index, int size) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;

    if (left < size && tree[left] > tree[largest]) {
        largest = left;
    }

    if (right < size && tree[right] > tree[largest]) {
        largest = right;
    }

    if (largest != index) {
        swap(tree[index], tree[largest]);
        heapify(tree, largest, size);
    }
}

// Build max-heap function
void buildMaxHeap(vector<int>& tree) {
    int n = tree.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(tree, i, n);
    }
}

// Function to simulate the battle
void battle(vector<int>& playerArmy, vector<int>& enemyArmy) {
    int playerWins = 0;

    for (int i = 0; i < playerArmy.size(); i++) {
        if (playerArmy[i] > enemyArmy[i]) {
            playerWins++;
            cout << "Your Soldier (" << playerArmy[i] << ") overpowers Enemy's Warrior(" << enemyArmy[i] << ")!" << endl;
        } else {
            cout << "Your Soldier (" << playerArmy[i] << ") is outmatched by Enemy's Warrior(" << enemyArmy[i] << ")!" << endl;
        }
        sleep(2); // Small delay for battle excitement
    }

    sleep(3);
    cout<<endl;

    if (playerWins > 2) {
        cout << "You secured the Hextech energy and defended Piltover! Victory!" << endl;
    } else {
        cout << "The enemy has overtaken your defenses. Piltover falls to the Noxians..." << endl;
    }
}

//typing effect
void typingEffect(const string& text, int delay) {
    for (char c : text) {
        cout << c << flush;  // Print one character at a time
        this_thread::sleep_for(chrono::milliseconds(delay));  // Delay between characters
    }
    cout << endl;  // Move to the next line after printing the text
}

int main() {

   //PlaySound(TEXT("bg.wav"), NULL, SND_FILENAME | SND_ASYNC); //for background music #Enable this when the bg wav file is inserted in the folder



    srand(time(0));  // Initialize random number generator
    char pin; //player input

    vector<int> playerArmy;
    vector<int> enemyArmy;
    vector<int> availableHextechDevices;


    cout<<"---------------------------------------------------WELCOME TO HEX WARS--------------------------------------------------"<<endl;
    cout<<"------------------------------(this is a game based from the events in the TV series Arcane)----------------------------"<<endl;
    sleep(4);
    system("cls");


    cout<<"DEFINITIONS: "<<endl<<endl;
    cout<<" NOXUS - Noxus is a ruthless and militaristic empire in Runeterra "
    <<"driven by the belief that strength and conquest define one's worth,where power is seized through cunning, war, and unyielding ambition."<<endl<<endl;
    sleep(2);
    cout<<" PILTOVER - Piltover is a bustling, prosperous city in Runeterra, renowned for"
    <<" its advancements in science, trade, and \n innovation, making it a beacon of progress and culture."<<endl<<endl;
    sleep(2);
    cout<<" HEXGEM - Hexgems are mysterious, magical crystals that serve as the core energy source for "
    "Hextech inventions, \n amplifying the magic within to power groundbreaking technologies."<<endl<<endl;
    sleep(2);
    cout<<" HEXTECH - Hextech is a revolutionary form of magic-infused technology in Runeterra,"
    " combining arcane power with \n mechanical ingenuity to create incredible devices and tools."<<endl<<endl;
    sleep(2);
    cout<<" HEXGATES - Hexgates are advanced portals powered by Hextech, allowing instant"
    <<" transportation across vast distances, \n revolutionizing travel and trade in Runeterra."<<endl<<endl;

    cout<<"Press Space to continue...";
    while(!_kbhit()){

    }

    system("cls");

    //Story
    string story = "The Noxians discovered the creation of the Hextech technology that uses the power of the Hexgems. Technology that can be weaponized and used to enslave other nations. Through espionage they concluded that the Hextech particularly beneath    the Hexgates is enough to empower every Noxian warrior and with this new power they can wage war against any country in  Runeterra. \n\n You as a general must ready your soldiers to battle and lead them to victory. Glory to the land of progress!!";
    typingEffect(story, 25);

    sleep(5);

    do{
    system("cls");
    //loading
    string loading = "Generating Battle Field...";
    typingEffect(loading, 50);
    sleep(3);
    system("cls");


    for (int i = 0; i < 10; i++) {
        availableHextechDevices.push_back(rand() % 100 + 1);  // Random numbers between 1 and 100
    }

    // Display the available Hextech Devices to the player
    cout << "Choose 5 Piltover Soldiers (choose indices 0 to 9):" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "Soldier " << i << ": Power Level " << availableHextechDevices[i] << endl;
    }

    // Player selects 5 Hextech devices for their defense army
    cout << "Enter 5 indices to select your soldiers:" << endl;
    for (int i = 0; i < 5; i++) {
        int index;
        cout << "Enter Soldier " << i + 1 << ": ";
        cin >> index;
        if (index >= 0 && index < 10) {
            playerArmy.push_back(availableHextechDevices[index]);
        } else {
            cout << "Invalid index. Please choose a valid number between 0 and 9." << endl;
            i--;
        }
    }

    // Build the max-heap for the player's army
    buildMaxHeap(playerArmy);

    system("cls");

    // Display the player's army
    cout << "\nYour Army:" << endl;
    display(playerArmy, "Piltover's Army");

    sleep(4);

    // Generate 5 random power levels for the enemy's army

    loading = "The Noxians are gathering their forces...";
    typingEffect(loading, 50);

    sleep(3);

    for (int i = 0; i < 5; i++) {
        enemyArmy.push_back(rand() % 100 + 1);  // Random numbers between 1 and 100
    }

    // Build the max-heap for the enemy's army
    buildMaxHeap(enemyArmy);

    // Display the enemy's army
    cout << "\nThe Noxians' Army:" << endl;
    display(enemyArmy, "Noxian Army");

    // Battle simulation
    sleep(6);
    system("cls");
    cout << "\nTHE HEX WARS BEGINS!" << endl;
    battle(playerArmy, enemyArmy);

    sleep(2);
    cout<<endl<<endl;
    cout<<"FIGHT AGAIN? [Y/N]: ";
    cin>>pin;

    if(pin=='N')
    {
        system("cls");
        cout<<"GOOD FIGHT GENERAL!";
    }

}while(pin=='Y');



    return 0;
}
