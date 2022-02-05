#include "WORDLE.h"

int main()
{
    string chos_word;
    string inpt_word;
    string dictnr[157];

    alpha alphabet[26];
    init_struct(alphabet);

    start(dictnr, chos_word);

    cout << "WORDLE\t\t";
    outpt_alpha(alphabet);
    for (int k = 0; k < 6; k++)
    {
        inpt(inpt_word);
        check_word(alphabet, chos_word, inpt_word);
        outpt_word(inpt_word, alphabet);
        outpt_alpha(alphabet);

        if (chos_word == inpt_word)
        {
            cout << YELLOW << "CONGRATULATIONS! YOU WIN!" << endl;
            return 0;
        }
    }
    cout << RED << "YOU LOSE!" << '\n'
         << GREEN << chos_word;
    return 0;
}