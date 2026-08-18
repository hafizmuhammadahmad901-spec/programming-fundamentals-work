#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of chords: ";
    cin >> n;

    string chords[100];

    cout << "Enter chords:\n";
    for(int i = 0; i < n; i++)
    {
        cin >> chords[i];
    }

    \
    for(int i = 0; i < n; i++)
    {
       
        int len = chords[i].length();

        if(chords[i][len - 1] != '7')   
        {
            chords[i] = chords[i] + "7";
        }
    }

    
    cout << "Updated chords:\n";
    for(int i = 0; i < n; i++)
    {
        cout << chords[i] << " ";
    }

    return 0;
}