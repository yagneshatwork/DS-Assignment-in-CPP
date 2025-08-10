#include<iostream>
using namespace std;

int main()
{
    int m, i, j, key;
    cout << "Welcome to the Card Hand Organizer!\n";
    cout << "Application: Organizing cards in a hand using Insertion Sort\n\n";

    cout << "Enter the number of cards (scores) in each hand: ";
    cin >> m;

    int p1[m], p2[m];

    // Input scores for Player 1
    cout << "\nEnter the card values for Player 1:\n";
    for (i = 0; i < m; i++) 
    {
        cout << "Card " << i + 1 << ": ";
        cin >> p1[i];
    }

    // Input scores for Player 2
    cout << "\nEnter the card values for Player 2:\n";
    for (i = 0; i < m; i++) 
    {
        cout << "Card " << i + 1 << ": ";
        cin >> p2[i];
    }

    // Insertion Sort for Player 1
    cout << "\nOrganizing Player 1's hand using Insertion Sort...\n";
    for (i = 1; i < m; i++)
    {
        key = p1[i];
        j = i - 1;
        while (j >= 0 && p1[j] > key)
        {
            cout << "Moving card " << p1[j] << " to the right to make space for " << key << "\n";
            p1[j + 1] = p1[j];
            j--;
        }
        p1[j + 1] = key;
        cout << "Inserted card " << key << " at position " << j + 1 << "\n";
    }

    // Display sorted scores of Player 1
    cout << "\nSorted hand (Player 1): ";
    for (i = 0; i < m; i++)
        cout << p1[i] << " ";
    cout << "\n";

    // Insertion Sort for Player 2
    cout << "\nOrganizing Player 2's hand using Insertion Sort...\n";
    for (i = 1; i < m; i++)
    {
        key = p2[i];
        j = i - 1;
        while (j >= 0 && p2[j] > key)
        {
            cout << "Moving card " << p2[j] << " to the right to make space for " << key << "\n";
            p2[j + 1] = p2[j];
            j--;
        }
        p2[j + 1] = key;
        cout << "Inserted card " << key << " at position " << j + 1 << "\n";
    }

    // Display sorted scores of Player 2
    cout << "\nSorted hand (Player 2): ";
    for (i = 0; i < m; i++)
        cout << p2[i] << " ";
    cout << "\n";

    cout << "\nCards are now organized for both players!\n";

    return 0;
}
