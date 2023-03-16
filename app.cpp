#include <iostream>

using namespace std;
const char VUOTO = '_';
int mossaPensata(char *tab)
{

    int risultato = -1;
    int combinazioni[8][3] = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6}};

    // prima controllo se il giocatore può vincere
    // se il giocatore può vincere io lo blocco
    // XXO

    for (int i = 0; i < 8; i++) // due X su 0 e 1
    {

        char a = tab[combinazioni[i][0]];
        char b = tab[combinazioni[i][1]];
        char c = tab[combinazioni[i][2]];

        bool condizione = a == b && c == VUOTO && a == 'X';

        if (condizione)
        {
            risultato = combinazioni[i][2];
        }
    }

    for (int i = 0; i < 8; i++) // due X su 0 e 2
    {
        char a = tab[combinazioni[i][0]];
        char b = tab[combinazioni[i][2]];
        char c = tab[combinazioni[i][1]];

        bool condizione = a == b && c == VUOTO && a == 'X';

        if (condizione)
        {
            risultato = combinazioni[i][1];
        }
    }

    for (int i = 0; i < 8; i++) // due X su 1 e 2
    {

        char a = tab[combinazioni[i][1]];
        char b = tab[combinazioni[i][2]];
        char c = tab[combinazioni[i][0]];

        bool condizione = a == b && c == VUOTO && a == 'X';

        if (condizione)
        {
            risultato = combinazioni[i][0];
        }
    }

    // ora controllo se il computer può vincere
    // se ci sono due O metto il terzo

    for (int i = 0; i < 8; i++) // due X su 0 e 1
    {

        char a = tab[combinazioni[i][0]];
        char b = tab[combinazioni[i][1]];
        char c = tab[combinazioni[i][2]];

        bool condizione = a == b && c == VUOTO && a == 'O';

        if (condizione)
        {
            risultato = combinazioni[i][2];
        }
    }

    for (int i = 0; i < 8; i++) // due X su 0 e 2
    {
        char a = tab[combinazioni[i][0]];
        char b = tab[combinazioni[i][2]];
        char c = tab[combinazioni[i][1]];

        bool condizione = a == b && c == VUOTO && a == 'O';

        if (condizione)
        {
            risultato = combinazioni[i][1];
        }
    }

    for (int i = 0; i < 8; i++) // due X su 1 e 2
    {

        char a = tab[combinazioni[i][1]];
        char b = tab[combinazioni[i][2]];
        char c = tab[combinazioni[i][0]];

        bool condizione = a == b && c == VUOTO && a == 'O';

        if (condizione)
        {
            risultato = combinazioni[i][0];
        }
    }

    if (risultato == -1)
    {
        risultato = rand() % 9;
    }

    cout << "risultato: " << risultato << endl;
    return risultato;
}
// 1 per la vittoria
// 0 per continuare la partita
// -1 per il pareggio
int isWinner(char *arr)
{

    for (int i = 0; i < 9; i += 3)
    {
        if ((arr[i] == arr[i + 1]) && (arr[i + 1] == arr[i + 2]) && (arr[i] != VUOTO)) // ho tre x vicine
        {
            return 1; // hai vinto quindi 1
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if ((arr[i] == arr[i + 3]) && (arr[i + 3] == arr[i + 6]) && (arr[i] != VUOTO)) // ho tre x in colonna
        {
            return 1; // hai vinto quindi 1
        }
    }

    // se li ho trovati in diagonale hai vinto =1
    if ((arr[0] == arr[4] && arr[4] == arr[8]) && (arr[0] != VUOTO))
    {
        return 1;
    }
    if ((arr[2] == arr[4] && arr[4] == arr[6]) && (arr[2] != VUOTO))
    {
        return 1;
    }

    for (int i = 0; i < 9; i++)
    {
        if (arr[i] == VUOTO)
        {
            return 0;
        }
    }

    return -1;
}

void stampa(char *tabella)
{
    for (int i = 0; i < 9; i++)
    {
        cout << tabella[i] << " ";
        if (i == 2 || i == 5 || i == 8) // alla fine di ogni riga (3x3) vai a capo
        {
            cout << endl;
        }
    }
}

int main()
{
    // inizializzo la tabella
    char tabella[9];
    for (int i = 0; i < 9; i++)
    {
        tabella[i] = VUOTO;
    }
    stampa(tabella);

    bool xIsNext = true; // gestisce il turno
    while (true)         // i turni del gioco
    {

        int mossa;

        if (!xIsNext) // COMPUTER
        {
            mossa = mossaPensata(tabella);

            // while (tabella[mossa] != VUOTO || (!(0 <= mossa && mossa < 9))) // controllo 2 condizioni (valido e VUOTO)
            // {
            //     mossa = random() % 10;
            // }
        }
        else
        {
            cout << "Giocatore " << (xIsNext ? 'X' : 'O') << " inserisci la tua mossa (1-9) ";
            cin >> mossa;
            mossa--; // per capirci ;)

            while (tabella[mossa] != VUOTO || (!(0 <= mossa && mossa < 9))) // controllo 2 condizioni (valido e vuoto)
            {
                cout << "Non puoi inserire qui" << endl;
                cout << "Giocatore " << (xIsNext ? 'X' : 'O') << " inserisci la tua mossa (1-9) ";
                cin >> mossa;
                mossa--;
            }
        }

        // se sono arrivato qui è solo perchè l'utente ha inserito un numero corretto
        xIsNext ? tabella[mossa] = 'X' : tabella[mossa] = 'O'; // se è vero metti X altrimenti metti O

        stampa(tabella);

        if (isWinner(tabella) == 1)
        {
            cout << "Hai vinto " << (xIsNext ? 'X' : 'O') << endl;
            break;
        }
        else if (isWinner(tabella) == -1)
        {
            cout << "Pareggio" << endl;
            // reset del gioco
            for (int i = 0; i < 9; i++)
            {
                tabella[i] = VUOTO;
            }
            xIsNext = true;
            stampa(tabella);
        }
        else if (isWinner(tabella) == 0)
        {
            xIsNext = !xIsNext; // cambio giocatore
        }
        else
        {
            cout << "Errore nella funzione isWinner" << endl;
        }
    }
}