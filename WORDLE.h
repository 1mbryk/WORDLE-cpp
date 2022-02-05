#include <string>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>
#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define WHITE "\e[37m"
using namespace std;

struct alpha
{
    char letter;
    char condition;
    char curr_condition;
};

void init_struct(struct alpha *alphabet)
{
    for (int i = 0; i < 26; i++)
    {
        alphabet[i].letter = 'a' + i;
        alphabet[i].condition = 'W';
        alphabet[i].curr_condition = 'W';
    }
}

void start(string *dictnr, string &chos_word)
{
    srand(time(NULL));
    int s_rand = rand() % 157;
    ifstream s_in("/Users/macvejpazh/Documents/proga/wordle/dictionary.txt", ios::in);
    for (int i = 0; i < 157; i++)
    {
        getline(s_in, dictnr[i]);
    }
    s_in.close();

    chos_word = dictnr[s_rand];
}

string chng_reg(string text)
{
    for (int i = 0; text[i] != 0; i++)
    {
        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            text[i] = (text[i] - 'A') + 'a';
        }
    }
    return text;
}

void inpt(string &inpt_word)
{
    bool match;
    cin >> inpt_word;
    inpt_word = chng_reg(inpt_word);
    string dictnr;
    ifstream s_in("/Users/macvejpazh/Documents/proga/wordle/dictionary.txt", ios::in);
    while (s_in)
    {
        s_in >> dictnr;
        if (dictnr == inpt_word)
        {
            match = 1;
            break;
        }
        else
        {
            match = 0;
        }
    }
    s_in.close();
    if (!match)
    {
        cout << "\t\tword not found in dictionary\n";
        inpt(inpt_word);
    }
}

void outpt_word(string &inpt_word, struct alpha *alphabet)
{
    int indx = 0;
    for (int i = 0; i < 5; i++)
    {
        indx = int(inpt_word[i] - 'a');
        switch (alphabet[indx].curr_condition)
        {
        case 'G':
        {
            cout << GREEN;
            break;
        }
        case 'Y':
        {
            cout << YELLOW;
            break;
        }
        default:
        {
            cout << WHITE;
            break;
        }
        }
        cout << inpt_word[i];
    }
    cout << "\t\t";
}

void outpt_alpha(struct alpha *alphabet)
{

    for (int i = 0; i < 26; i++)
    {
        switch (alphabet[i].condition)
        {
        case 'G':
        {
            cout << GREEN;
            break;
        }
        case 'Y':
        {
            cout << YELLOW;
            break;
        }
        case 'R':
        {
            cout << RED;
            break;
        }
        case 'W':
            cout << WHITE;
            break;
        }

        cout << char(alphabet[i].letter - 'a' + 'A') << ' ';
        cout << WHITE;
        if (i == 12)
        {
            cout << "\n\t\t";
        }
    }
    cout << '\n';
}

void check_word(struct alpha *alphabet, string chos_word, string inpt_word)
{
    int indx = 0;
    for (int i = 0; i < 5; i++)
    {
        indx = int(inpt_word[i] - 'a');
        for (int j = 0; j < 5; j++)
        {
            if (inpt_word[i] == chos_word[j])
            {
                alphabet[indx].curr_condition = 'Y';
                if (i == j)
                {
                    alphabet[indx].curr_condition = 'G';
                    alphabet[indx].condition = 'G';
                    break;
                }
                else if (alphabet[indx].condition != 'G')
                {
                    alphabet[indx].condition = 'Y';
                    break;
                }
            }
            else if (alphabet[indx].condition != 'G')
            {
                alphabet[indx].condition = 'R';
            }
        }
    }
}
