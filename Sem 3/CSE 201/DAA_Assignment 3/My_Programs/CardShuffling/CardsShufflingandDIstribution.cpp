/*
The program creates and displays a deck of 52 cards.
Next, the cards are shuffled and displayed again.
After that, the cards are distributed among 4 players and cards of each player are displayed.
The total points for each players is also displayed.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Card
{
private:
    int type;
    int value;

public:
    void setData(int t, int v)
    {
        type = t;
        value = v;
    }
    int getType()
    {
        return type;
    }
    int getValue()
    {
        return value;
    }

    void displayData()
    {
        // Displaying type of card
        if (type == 1)
            cout << "Spades ";
        else if (type == 2)
            cout << "Hearts ";
        else if (type == 3)
            cout << "Clubs ";
        else
            cout << "Diamonds ";

        // Displaying value of card
        if (value <= 10)
            cout << value;
        else if (value == 11)
            cout << "Jack";
        else if (value == 12)
            cout << "Queen";
        else if (value == 13)
            cout << "King";
        else
            cout << "Ace";

        cout << endl; // New line after displaying a card
    };
};

int main()
{
    srand((unsigned)time(NULL));
    Card deck[52], temp, players[5][13];
    int i, j, k = 0, rc1, rc2;
    int id[5] = {0, 0, 0, 0, 0}, tot[5] = {0, 0, 0, 0, 0};
    // Generating and displaying 52 cards in order
    cout << "UNSHUFFLED DECK OF CARDS:\n\n";
    for (i = 1; i <= 4; i++)
    {
        for (j = 2; j <= 14; j++)
        {
            deck[k].setData(i, j);
            cout << "Card " << k + 1 << " : ";
            deck[k].displayData();
            k++;
        }
        if (i != 4)
        {
            cout << "\n\nPress any key for next set of cards:";
            cin.get();
        }
    }

    // Shuffling the cards
    cout << "\n\nPress any key to shuffle the deck of cards:";
    cin.get();
    for (i = 0; i < 100; i++)
    {
        // Select 2 cards randomly
        rc1 = rand() % 52;
        rc2 = rand() % 52;
        // Select a temporary card
        temp.setData(deck[rc1].getType(), deck[rc1].getValue());
        // Swap the cards
        deck[rc1].setData(deck[rc2].getType(), deck[rc2].getValue()); //deck[rc1] = deck[rc2]
        deck[rc2] = temp;
    }

    // Displaying the shuffled cards
    cout << "\n\nTHE SHUFFLED DECK OF CARDS\n\n";
    for (i = 0; i < 52; i++)
    {
        cout << "Card " << i + 1 << ": ";
        deck[i].displayData();
    }
    cout << "\n\nPress any key to distribute the cards:";
    cin.get();

    // Distribute the cards among 5 players
    for (i = 0; i < 52; i++)
    {
        j = i % 5;
        players[j][id[j]].setData(deck[i].getType(), deck[i].getValue());
        id[j] = id[j] + 1;
    }

    cout << "\n\nCARDS HAVE BEEN DISTRIBUTED\n\n";

    // Displaying cards of each player
    cout << "\n\nPress any key to view the cards of each player:";
    cin.get();

    for (i = 0; i < 5; i++)
    {
        cout << "\n PLAYER " << i + 1 << ": " << endl
             << endl;
        for (j = 0; j < id[i]; j++)
        {
            players[i][j].displayData();
            tot[i] += players[i][j].getType() + players[i][j].getValue();
        }
    }
    // Display total points for each player
    cout << "\n\nPress any key to know total points of each player:";
    cin.get();

    cout << "\n\nTOTAL POINTS OF EACH PLAYER\n\n";
    for (i = 0; i < 5; i++)
    {
        cout << "Player " << i + 1 << ": " << tot[i] << endl
             << endl;
    }
}