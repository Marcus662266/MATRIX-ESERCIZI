#include <iostream>

int main()
{
    std::cout << "Hello World!" << std::endl;
    using namespace std;

    // 1 per la vittoria
    // 0 per continuare la partita
    // -1 per il pareggio
    // Funzione per disegnare la griglia di gioco
    void disegnaGriglia(char tabella[])
    {
        std::cout << " " << griglia[0] << " | " << griglia[1] << " | " << griglia[2] << endl;
        std::cout << "-----------" << endl;
        std::cout << " " << griglia[3] << " | " << griglia[4] << " | " << griglia[5] << endl;
        std::cout << "-----------" << endl;
        std::cout << " " << griglia[6] << " | " << griglia[7] << " | " << griglia[8] << endl;
    }

    // Funzione per controllare se c'è una vittoria
    bool controlloVittoria(char tabella[], char simbolo)
    {
        // Controllo righe
        for (int i = 0; i < 9; i += 3)
        {
            if (griglia[i] == simbolo && griglia[i + 1] == simbolo && griglia[i + 2] == simbolo)
            {
                return true;
            }
        }
        // Controllo colonne
        for (int i = 0; i < 3; i++)
        {
            if (griglia[i] == simbolo && griglia[i + 3] == simbolo && griglia[i + 6] == simbolo)
            {
                return true;
            }
        }
        // Controllo diagonali
        if (griglia[0] == simbolo && griglia[4] == simbolo && griglia[8] == simbolo)
        {
            return true;
        }
        if (griglia[2] == simbolo && griglia[4] == simbolo && griglia[6] == simbolo)
        {
            return true;
        }
        return 0;
    }

    // Funzione per giocare
    void gioca(char griglia[], char simbolo)
    {
        int posizione;
        std::cout << "Giocatore " << simbolo << ", inserisci la posizione (da 1 a 9): ";
        std::cin >> posizione;
        while (posizione < 1 || posizione > 9 || griglia[posizione - 1] != ' ')
        {
            std::cout << "Posizione non valida. Inserisci un'altra posizione: ";
            std::cin >> posizione;
        }
        griglia[posizione - 1] = simbolo;
        tabella(griglia);
    }

    int main()
    {

        char vuoto = '_';

        // inizializzo la tabella
        char tabella[9];
        for (int i = 0; i < 9; i++)
        {
            tabella[i] = vuoto;
        }
        stampa(tabella);

        bool xprox = true; // gestisce il turno
        while (true)       // i turni del gioco
        {

            int mossa;

            std::cout << "Giocatore " << (xprox ? 'X' : 'O') << " inserisci la tua mossa (1-9) ";
            std::cin >> mossa;
            mossa--; // per capirci ;)

            while (tabella[mossa] != vuoto || (!(0 <= mossa && mossa < 9))) // controllo 2 condizioni (valido e vuoto)
            {
                std::cout << "Non puoi inserire qui" << std::endl;
                std::cout << "Giocatore " << (xprox ? 'X' : 'O') << " inserisci la tua mossa (1-9) ";
                std::cin >> mossa;
            }

            // se sono arrivato qui è solo perchè l'utente ha inserito un numero corretto
            xprox ? tabella[mossa] = 'X' : tabella[mossa] = 'O'; // se è vero metti X altrimenti metti O

            stampa(tabella);

            if (isWinner(tabella) == 1)
            {
                std::cout << "Hai vinto " << (xprox ? 'X' : 'O') <<std:: endl;
                break;
            }
            else if (isWinner(tabella) == -1)
            {
                std::cout << "Pareggio" << std::endl;
                // reset del gioco
                for (int i = 0; i < 9; i++)
                {
                    tabella[i] = vuoto;
                }
                xprox = true;
                stampa(tabella);
            }
            else if (isWinner(tabella) == 0)
            {
                xprox = !xprox; // cambio giocatore
            }
            else
            {
                std::cout << "Errore nella funzione isWinner" << std::endl;
            }
        }
    }
}