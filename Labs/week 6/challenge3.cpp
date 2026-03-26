

#include <iostream>
using namespace std;

int main()
{
    char str[100];

    cout << "Enter a string: ";
    cin >> str;

    for(int i = 0; str[i] != '\0'; i++)
    { 
     
        if(str[i] >= 'a' && str[i] <= 'z')
        {
            if(str[i] == 'z')
                str[i] = 'a';
            else
                str[i] = str[i] + 1;
        }
        
        
        else if(str[i] >= 'A' && str[i] <= 'Z')
        {
            if(str[i] == 'Z')
                str[i] = 'A';
            else
                str[i] = str[i] + 1;
        }
    }

    cout << "Updated string: " << str;

    return 0;
}