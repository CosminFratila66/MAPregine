#include <iostream>
#include <cmath>
using namespace std;

int regine[100]; // regine[k] reprezinta coloana pe care se afla regina de pe randul k

void Afis()
{
    for (int i = 1; i <= 8; i++)
    {
        for (int k = 1; k <= 8; k++)
        {
            if (regine[i] == k) // Regina este pe coloana k in randul i
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

bool OK(int k) {
    for (int i = 1; i < k; i++)
    {
        // Verifica daca regina de pe randul k este atacata de regina de pe randul i
        if (regine[k] == regine[i] || abs(regine[k] - regine[i]) == abs(k - i))
            return false;
    }
    return true;
}

bool Solutie(int k)
{
    return k == 8; // Am plasat toate reginele
}

void back(int k) {
    for (int i = 1; i <= 8; i++) // Itereaza prin coloanele posibile
    {
        regine[k] = i; // Plaseaza regina pe coloana i
        if (OK(k)) // Verifica daca poziția este valida
            if (Solutie(k))
                Afis(); // Afiseaza tabla
            else
                back(k + 1); // Continua pe randul urmator
    }
}

int main() {

    back(1); // Porneste de la primul rand
    return 0;
}
