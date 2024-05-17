/*
"Consoled-Based Music Playlist Management System"

Leader: Mark Anthony Bunsay 
Member: Jc jade Nealega
Section: BSIT - 1203
*/

#include <iostream>    // input/output stream library
#include <conio.h>     // console input/output library
#include <cstring>     // C string manipulation library
#include <string.h>    // string manipulation library
#include <stdio.h>     // standard input/output library
#define max 50         // Maximum of 50 music can be saved by the user

using namespace std; 

int num=0;
class musicPlaylist
{
    public:
    int musicNum;
    char title[20];
    char artist[20];
    char genre[20];
};

musicPlaylist music[max],tempPlaylist[max];

// Delay function
void cDelay(int msec){
    long goal = msec + (clock());
    while (goal > (clock())); 
}

// Introduction banner
void banner() { 
    const string lime_green = "1;32";
    const string aqua = "1;96";
    const string reset = "0";

    cout << "\033[2J\033[1;1H"; // Clear screen ANSI escape code
    cout <<"\033[" << lime_green << "m"
         << " \t\t\t\t\t\t$$\\      $$\\ $$\\   $$\\  $$$$$$\\  $$$$$$\\  $$$$$$\\         $$$$$$\\  $$\\       $$\\   $$\\     $$\\ \n"
         << " \t\t\t\t\t\t$$$\\    $$$ |$$ |  $$ |$$  __$$\\ \\_$$  _|$$  __$$\\       $$  __$$\\ $$ |      $$ |  \\$$\\   $$  |\n"
         << " \t\t\t\t\t\t$$$$\\  $$$$ |$$ |  $$ |$$ /  \\__|  $$ |  $$ /  \\__|      $$ /  $$ |$$ |      $$ |   \\$$\\ $$  / \n"
         << " \t\t\t\t\t\t$$\\$$\\$$ $$ |$$ |  $$ |\\$$$$$$\\    $$ |  $$ |            $$$$$$$$ |$$ |      $$ |    \\$$$$  /  \n"
         << " \033[" << aqua << "m"
         << " \t\t\t\t\t\t$$ \\$$$  $$ |$$ |  $$ | \\____$$\\   $$ |  $$ |            $$  __$$ |$$ |      $$ |     \\$$  /   \n"
         << " \t\t\t\t\t\t$$ |\\$  /$$ |$$ |  $$ |$$\\   $$ |  $$ |  $$ |  $$\\       $$ |  $$ |$$ |      $$ |      $$ |     \n"
         << " \t\t\t\t\t\t$$ | \\_/ $$ |\\$$$$$$  |\\$$$$$$  |$$$$$$\\ \\$$$$$$  |      $$ |  $$ |$$$$$$$$\\ $$$$$$$$\\ $$ |     \n"
         << " \t\t\t\t\t\t\\__|     \\__| \\______/  \\______/ \\______| \\______/       \\__|  \\__|\\________|\\________|\\__|     \n"
         << "\033[" << reset << "m";

    cout << "\033[31m\033[3m\t\t\t\t\t\t  A console-based program for music playlist management, Developed by Jc Jade & Mark Anthony\033[0m\n";
    cout << "\033[" << lime_green << "m"
         << "\n\t\t\t\t\t\t================================================================================================\n"
         << "\033[" << reset << "m";
    cout << "\t\t\t\t\t\t\t\t\t\tMUSIC PLAYLIST MANAGER\n";
    cout << "\033[" << lime_green << "m"
         << "\t\t\t\t\t\t================================================================================================\n"
         << "\033[" << reset << "m";
    cout << endl;  
}

// Press any key to continue
void anyKey() { 
    banner();
    cout << "\n\t\t\t\t\t\t\t\t\t    Press any key to start the program...";
    getch();
}

// loading screen
void loadingScreen(){ 
    cout << "\033[2J\033[1;1H"; // Clear screen ANSI escape code
    banner();
    cout << "\n\t\t\t\t\t\t\t\t\t\tInitializing";
    for(int i=0; i < 10; i++){
        cDelay(100);
        cout << ".";
    }
}

// loading screen
void loginLoading(){ 
    cout << "\n\t\t\t\t\t\t\t\t\t\t    Loading";
    for(int i=0; i < 10; i++){
        cDelay(80);
        cout << ".";
    }
}

// User login function
void loginScreen(){ 
    cout << "\033[2J\033[1;1H"; // Clear screen ANSI escape code
    char UserName[30], password[30], ch;
    int i=0; 
    banner(); 

    cout << "\n\t\t\t\t\t\t\t\t\t ================ LOGIN ================" << endl;
    cout << "\n\t\t\t\t\t\t\t\t\t\tUsername : ";
    cin >> UserName;
    cout << "\t\t\t\t\t\t\t\t\t\tPassword : ";
    while (1){
        ch = getch();
        if(ch==13)
            break;
        if(ch==32 || ch==9)
            continue;
        else{
            cout << "*";
            password[i]=ch;
            i++;
        }
    }
    password[i] = '\0';
    if(strcmp(UserName, "admin")==0 && strcmp(password, "admin")==0)
    {
        cout << "\033[2J\033[1;1H"; // Clear screen ANSI escape code
        banner();
        cout << "\n\t\t\t\t\t\t\t\t\t ================ LOGIN ================" << endl;
        cout << "\n\t\t\t\t\t\t\t\t\t\t    Login Success!!\n";
        loginLoading();
    }
    else{
        cout << "\033[2J\033[1;1H"; // Clear screen ANSI escape code
        banner();
        cout << "\n\t\t\t\t\t\t\t\t\t ================ LOGIN ================" << endl; 
        cout << "\033[31m\033[1m\n\t\t\t\t\t\t\t\t\t\t    Access Denied!!\033[0m\n";
        loginLoading();
        loginScreen();
    }
}

// Function to display menu
void menu() { 
    cout << "\033[2J\033[1;1H"; // Clear screen ANSI escape code
    banner();
        cDelay(50);
        cout << "\n\t\t\t\t\t\t\t\t\t ================ MENU ================" << endl;
        cDelay(50);
        cout << "\n\t\t\t\t\t\t\t\t\t Press 1 --> Add a song" << endl;
        cDelay(50);
        cout << "\t\t\t\t\t\t\t\t\t Press 2 --> Display songs in playlist" << endl;
        cDelay(50);
        cout << "\t\t\t\t\t\t\t\t\t Press 3 --> Update a song" << endl;
        cDelay(50);
        cout << "\t\t\t\t\t\t\t\t\t Press 4 --> Delete a song" << endl;
        cDelay(50);
        cout << "\t\t\t\t\t\t\t\t\t Press 5 --> Exit" << endl;
        cDelay(50);
        cout << "\n\t\t\t\t\t\t\t\t\t ======================================";
        cout << "\n\t\t\t\t\t\t\t\t\t\t    Pick a choice";
}

// Function to insert a new music into the playlist array based on music number
void insertInPlaylist(musicPlaylist newMusic) {
    int i = num;
    num += 1;

    // Find the correct position to insert the new music based on musicNum
    while (i > 0 && music[i - 1].musicNum > newMusic.musicNum) {
        music[i] = music[i - 1];
        i--;
    }

    // Insert the new music at the correct position
    music[i] = newMusic;
}

// Function to sort the music playlist in ascending order based on music numbers
void sortPlaylist() {
    for (int i = 0; i < num - 1; i++) {
        for (int j = 0; j < num - i - 1; j++) {
            if (music[j].musicNum > music[j + 1].musicNum) {
                // Swap the music items
                musicPlaylist temp = music[j];
                music[j] = music[j + 1];
                music[j + 1] = temp;
            }
        }
    }
}

// Function to create a new playlist entry with user input for music details
void createPlaylist() {
    cout << "\033[2J\033[1;1H"; // Clear screen
    banner(); // Display banner
    cout << "\t\t\t\t\t\t\t\t\t\tAdd Music to Playlist \n";

    // Get user input for new music
    musicPlaylist newMusic;
    cout << "\t\t\t\t\t\t\t\t\t\tMusic Number : ";
    cin >> newMusic.musicNum;

    if (newMusic.musicNum == 0) {
        cout << "\033[31m\n\t\t\t\t\t\t\t\t\t\tError: Music number cannot be 0!\033[0m\n";
        cout << "\t\t\t\t\t\t\t\t\t\tPress Any Key To Continue. . ";
        getch();
        return; // Exit the function
    }

    // Check if the music number already exists
    bool exists = false;
    for (int j = 0; j < num; j++) {
        if (music[j].musicNum == newMusic.musicNum) {
            exists = true;
            break;
        }
    }

    if (exists) {
        cout << "\033[31m\n\t\t\t\t\t\t\t\t\t\tError: Music number is already added!\033[0m\n";
        cout << "\t\t\t\t\t\t\t\t\t\tPress Any Key To Continue. . ";
        getch();
        return; // Exit the function
    }

    // Get additional details for new music
    cout << "\t\t\t\t\t\t\t\t\t\tTitle : ";
    cin.ignore(); // Ignore any remaining characters in the input buffer
    cin.getline(newMusic.title, sizeof(newMusic.title)); // Read input including spaces for title
    cout << "\t\t\t\t\t\t\t\t\t\tArtist: ";
    cin.getline(newMusic.artist, sizeof(newMusic.artist)); // Read input including spaces for artist
    cout << "\t\t\t\t\t\t\t\t\t\tGenre: ";
    cin.getline(newMusic.genre, sizeof(newMusic.genre)); // Read input including spaces for genre

    // Insert the new music in the playlist array
    insertInPlaylist(newMusic);

    cout << "\n\t\t\t\t\t\t\t\t\t\tSaving";
    for (int i = 0; i < 10; i++) {
        cDelay(100);
        cout << ".";
    }
    cout << "\n\t\t\t\t\t\t\t\t\t\tSaved Successfully!!";
    cDelay(50);
    cout << "\n\n\t\t\t\t\t\t\t\t\t\tPress Any Key To Continue. . ";
    getch();
}

// Function to display all music entries in the playlist
void readPlaylist()
{
    cout << "\033[2J\033[1;1H";
    banner();
    cout << "\n\t\t\t\t\t\t\t\t\t     List of all the Music on Playlist\n";
    cout << "\n\t\t\t\t\t\tMUSIC #\t\tTITLE\t\t\t\tARTIST\t\t\t\tGENRE" << endl;
    cout << "\t\t\t\t\t\t------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0, j = 8; i < num; i++, j++)
    {
        // Skip displaying if the music number is 0
        if (music[i].musicNum == 0) {
            continue;
        }
        
        cout << "\t\t\t\t\t\t" << music[i].musicNum << " ";
        cout << "\t\t" << music[i].title << " ";
        cout << "\t\t\t\t" << music[i].artist << " ";
        cout << "\t\t\t" << music[i].genre << " \n";
    }

    cDelay(500); 
    cout << "\n\n\n\n\n\t\t\t\t\t\t\t\t\t       Press Any Key To Continue. . ";
    getch();

}

// Function to display options for editing a playlist entry
void editPlaylist()
{
cout << "\033[2J\033[1;1H";
banner();
    cout<<"\t\t\t\t\t\t\t\t\t What Do You Want To edit\n\n";
    cout<<"\t\t\t\t\t\t\t\t\t m ---------> Music Number \n";
    cout<<"\t\t\t\t\t\t\t\t\t t ---------> Title \n";
    cout<<"\t\t\t\t\t\t\t\t\t a ---------> Artist\n";
    cout<<"\t\t\t\t\t\t\t\t\t g ---------> Genre \n";
    cout<<"\t\t\t\t\t\t\t\t\t q ---------> QUIT\n\n";
    cout<<"\t\t\t\t\t\t\t\t\t Enter Choice:  ";
}

// Function to display a loading message during update
void updateMsg(){
    cout<<"\n\t\t\t\t\t\t\t\t\t Updating";
    for(int i = 0; i<10; i++)
{
    cDelay(100);
    cout<<".";
}
    sortPlaylist();
}

// Function to edit the music number of a playlist entry
void editNum(int i)
{
    cout<<"\n\t\t\t\t\t\t\t\t\t Enter New Music Number:";
    cin>>music[i].musicNum;
    updateMsg();
}

// Function to edit the title of a playlist entry
void editTitle(int i)
{
    cout<<"\n\t\t\t\t\t\t\t\t\t Enter New Title:";
    cin>>music[i].title;
    updateMsg();
}

// Function to edit the artist of a playlist entry
void editArtist(int i)
{
    cout<<"\n\t\t\t\t\t\t\t\t\t Enter New Artist:";
    cin>>music[i].artist;
    updateMsg();
}

// Function to edit the genre of a playlist entry
void editGenre(int i)
{
cout<<"\n\t\t\t\t\t\t\t\t\t Enter New Genre:";
cin>>music[i].genre;
updateMsg();
}

// Function to update/edit a playlist entry based on user input
void updatePlaylist()
{
    cout << "\033[2J\033[1;1H";
    banner();
    cout << "\n\t\t\t\t\t\t\t\t\t\t******** Edit/Update the Records ******** \n\n";
    cout << "\033[2J\033[1;1H";
    banner();
    int musicNum;
    char option;
    bool found = false;

    cout << "\t\t\t\t\t\t\t\t\tEnter the Music Number To Edit/Update : ";
    cin >> musicNum;

    for (int i = 0; i < num; i++) {
        if (music[i].musicNum == musicNum) {
            found = true;
            editPlaylist(); // Display edit menu

            while ((option = cin.get()) != 'q') {
                switch (option) {
                    case 'm':
                        editNum(i);
                        break;
                    case 't':
                        editTitle(i);
                        break;
                    case 'a':
                        editArtist(i);
                        break;
                    case 'g':
                        editGenre(i);
                        break;
                }
                editPlaylist();
            }
            break; // Exit loop if music number is found
        }
    }

    if (!found) {
        cout << "\033[31m\033[1m\n\t\t\t\t\t\t\t\t Music Number not found! Press Any Key To Continue...\033[0m\n";
        getch();
    }
}

// Function to delete a playlist entry based on music number
void deletePlaylist()
{
    int musicNum;
    bool found = false;

    cout << "\033[2J\033[1;1H";
    banner();
    cout << "\n\t\t\t\t\t\t\t\t\t   ******* Delete Records ******** \n";
    cout << "\n\t\t\t\t\t\t\t\t\tEnter the Music Number you want to delete: ";
    cin >> musicNum;

    for (int i = 0; i < num; i++) {
        if (music[i].musicNum == musicNum) {
            found = true;
            for (int j = i; j < num - 1; j++) {
                music[j] = music[j + 1];
            }
            num--;

            cout << "\n\t\t\t\t\t\t\t\t\tDeleting";
            for (int i = 0; i < 10; i++) {
                cDelay(200);
                cout << ".";
            }
            cout << "\n\t\t\t\t\t\t\t\t\tDeleted Successfully...!!!";
            cDelay(500);
            anyKey();
            break; // Exit loop if music number is found
        }
    }

    if (!found) {
        cout << "\033[31m\033[1m\n\t\t\t\t\t\t\t\t    Music Number not found! Press Any Key To Continue...\033[0m\n";
        getch();
    }
    sortPlaylist();
}

int main() {
    banner();
    anyKey();
    loadingScreen();
    loginScreen();
    menu();
    
    char option;
while(1)
{
    option=getch();
    switch(option)
{
    case '1':
        createPlaylist();
    break;
    case '2':
        readPlaylist();
    break;
    case '3':
        updatePlaylist();
    break;
    case '4':
        deletePlaylist();
    break;
    case '5':
    cout<<"\n\n\t\t\t\t\t\t\t\t\tThank you for using our system!!! ";
    exit(0);
}
menu();
}
return 0;
}