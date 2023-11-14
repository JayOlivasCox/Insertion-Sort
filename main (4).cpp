#include <iostream>
#include <string>
#include <fstream>
#include <string.h>
#include <vector>
#include <cstdlib>

using namespace std;

// define the Player struct
struct Player {
    string lastName;
    string firstName;
    string college;
    double height;
    double weight;
};
ostream& operator<<(ostream& os, const Player& player){
    os << player.firstName << " " << player.lastName << " " << player.height << " " << player.weight << " " << player.college << endl;
    return os;
}
bool operator<(Player &a, Player &b){
    return a.weight<b.weight;
}
// print the data
void printPlayers(const vector<Player> &players){
    for(long unsigned int i = 0; i<players.size();i++){
        cout << players[i];
    }
}

//Insertion sort by height
void insertionSortByWeight(vector<Player> &players){

    for (size_t i = 1; i<players.size();i++){
        size_t j = i;
        while(j>0&&players[j]<players[j-1]){
            Player tmp = players[j];
            players[j] = players[j-1];
            players[j-1] = tmp;
            j--;
        }
        cout << "End of insertion index " << i <<endl;
        printPlayers(players);
    }
}

// Read the data into a vector of Players
void readDataFile(vector<Player> &players) {
    ifstream inputFile;
    string filename;

    cout << "Enter a filename to read:" << endl;
    getline (cin, filename);  

    // Open the file.
    inputFile.open(filename);
 
   // If the file successfully opened, process it.
   if (!inputFile.fail())
   {
        char fline[1024];
        inputFile.getline (fline, 1024);  // eat the heading line
     
        while(inputFile.getline (fline, 1024)) {

            // Returns first token 
            char* token = strtok(fline, ","); 
  
            int field = 1;
        
            Player p;
        
            while (token != NULL) { 
                if (field == 2) {
                    p.firstName = token;
                }
                else if (field == 3) {
                    p.lastName = token;
                }
                else if (field == 5) {
                    p.height = atof(token);
                }
                else if (field == 6) {
                    p.weight = atof(token);
                }
                else if (field == 7) {
                    p.college = token;
                }
                else if (field >9) {
                    break;
                }

                token = strtok(NULL, ","); 
                field++;
            } 
        
            players.push_back(p);
        
        }
    
        // Close the file.
        inputFile.close();
    }

}



int main()
{
    vector<Player> players;
    
    cout << "\n******************* Reading the data *********************\n";
    readDataFile(players);
    cout << "\n******************* Printing the data *********************\n";
    printPlayers(players);
    cout << "\n******************* Sorting *********************\n";
    insertionSortByWeight(players);
    cout << "\n******************* Sorted *********************\n";
    printPlayers(players);

    return 0;
}