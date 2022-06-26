#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

void wypisanie(double** tablica, int w, int k);
void wstawianiewartosci(double** tablica, int w, int k);
void zerowanie(double** tablica, int w, int k);
double** macierz(int w, int k);
void usuwanie(double** tablica, int w);
double** mnozeniemacierzy(double** tablica1, double** tablica2, int w1, int k1, int k2);
void dodawaniemacierzy(double** tablica1, double** tablica2, int w, int k);
void odejmowaniemacierzy(double** tablica1, double** tablica2, int w, int k);
void mnozenieprzezstala(double** tablica, int w, int k, double liczba);
double wyznacznikchio(double** tablica, int w);
double wyznacznikchiowypisz(double** tablica, int w);
double wyznaczniklaplace(double** tablica, int w);
double potega(double podstawa, double wykladnik);
double** transponuj(double** tablica, int w, int k);
double** macierzodwrotna(double** tablica, int w);
double** dopelnieniealgebraiczne(double** tablica, int w);

int main()
{
    int kolumny, kolumny2, wiersze, wiersze2, wybor;
    double **tab, **tab2, **trans, **zabijmnie, **tabtab2;
    double mnoznik, czydziala;
    char czy;

    do{
        //MACIERZ A
        cout << "----------KALKULATOR MACIERZY----------" << endl;
        cout << "Podaj liczbe kolumn macierzy A: ";
        cin >> kolumny;
        cout << "i wierszy: ";
        cin >> wiersze;
        if(kolumny==0||wiersze==0){
            cout << "To chcesz te macierz czy nie? Jesli tak to podaj dodatnie liczby kolumn i/lub wierszy ;)" << endl;
        }
        else{
            tab = macierz(wiersze, kolumny);

            cout << "A:" << endl;
            wstawianiewartosci(tab, wiersze, kolumny);

            //MENU
            cout << "0. Jeszcze raz" << endl;
            cout << "1. Mnozenie macierzy" << endl;
            cout << "2. Dodawanie macierzy" << endl;
            cout << "3. Mnozenie macierzy przez stala" << endl;
            cout << "4. Wyznacznik z uzyciem metody obnizania stopnia (metody Chio)" << endl;
            cout << "5. Wyznacznik z uzyciem metody obnizania stopnia (metody Chio) krok po kroku" << endl;
            cout << "6. Odejmowanie macierzy" << endl;
            cout << "7. Transponuj" << endl;
            cout << "8. Wyznacznik z uzyciem wzoru Laplace'a" << endl;
            cout << "9. Macierz odwrotna" << endl;
            cout << "10. Tablica odpowiednich dopelnien algebraicznych" << endl << endl;

            cout << "A: " << endl;
            wypisanie(tab, wiersze, kolumny);
            cout << endl;

            cout << "Wybierz operacje: ";
            cin >> wybor;

            switch(wybor){
            case 0:
                break;
            case 1:
                system("cls");
                //MACIERZ 2
                cout << "Podaj liczbe kolumn macierzy B: ";
                cin >> kolumny2;
                cout << "(liczba wierszy A jest rowna liczbie kolumn B ofc)" << endl;
                tab2 = macierz(kolumny, kolumny2);
                wstawianiewartosci(tab2, kolumny, kolumny2);

                cout << "A:" << endl;
                wypisanie(tab, wiersze, kolumny);
                cout << endl << "B:" << endl;
                wypisanie(tab2, kolumny, kolumny2);

                tabtab2=mnozeniemacierzy(tab, tab2, wiersze, kolumny, kolumny2);
                cout << endl << "AB: " << endl;
                wypisanie(tabtab2, wiersze, kolumny2);
                usuwanie(tabtab2, kolumny);
                usuwanie(tab2, kolumny);
                break;
            case 2:
                cout << "Aby dodac macierze do siebie musza one miec takie same wymiary." << endl;
                tab2 = macierz(wiersze, kolumny);
                wstawianiewartosci(tab2, wiersze, kolumny);
                dodawaniemacierzy(tab, tab2, wiersze, kolumny);
                cout << "Po dodaniu: " << endl;
                wypisanie(tab, wiersze, kolumny);
                usuwanie(tab2, wiersze);
                break;
            case 3:
                cout << "Podaj stala przez ktora mam pomnozyc macierz: ";
                cin >> mnoznik;
                mnozenieprzezstala(tab, wiersze, kolumny, mnoznik);
                cout << "Wynik mnozenia przez stala: " << endl;
                wypisanie(tab, wiersze, kolumny);
                break;
            case 4:
                if(wiersze==kolumny){
                    double wynik=wyznacznikchio(tab, wiersze);
                    cout << "Wyznacznik: " << wynik << endl;
                }
                else{
                    cout << "Ten program nie jest az tak dobry zeby liczyl wyznacznik macierzy niekwadratowej ;)" << endl;
                }
                break;
            case 5:
                if(wiersze==kolumny){
                    double wynik=wyznacznikchiowypisz(tab, wiersze);
                    cout << "Wyznacznik: " << wynik << endl;
                }
                else{
                    cout << "Ten program nie jest az tak dobry zeby liczyl wyznacznik macierzy niekwadratowej ;)" << endl;
                }
                break;
            case 6:
                cout << "Aby odjac macierze od siebie musza one miec takie same wymiary." << endl;
                tab2 = macierz(wiersze, kolumny);
                wstawianiewartosci(tab2, wiersze, kolumny);
                odejmowaniemacierzy(tab, tab2, wiersze, kolumny);
                usuwanie(tab2, wiersze);
                break;
            case 7:
                cout << "Macierz wytransponowana:" << endl;
                trans=transponuj(tab, wiersze, kolumny);
                wypisanie(trans,kolumny, wiersze);
                usuwanie(trans, kolumny);
                cout << endl;
                break;
            case 8:
                czydziala = wyznaczniklaplace(tab, wiersze);
                cout << "Wyznacznik Laplace: " << czydziala << endl;
                break;
            case 9:
                if(wiersze==kolumny){
                    double W = wyznacznikchio(tab, wiersze);
                    if(W!=0){
                        double** pom = macierzodwrotna(tab, wiersze);
                        cout << "Macierz odwrotna: " << endl;
                        wypisanie(pom, wiersze, wiersze);
                        usuwanie(pom, wiersze);
                        break;
                    }
                    else{
                        cout << "Nie oszukuj! Nie ma macierzy odwrotnej z wyznacznikiem W=0! :O" << endl;
                        break;
                    }
                    break;
                }
                else{
                    cout << "Asertywne 'nie zrobie tego'. Tylko dla macierzy kwadratowych." << endl;
                }
                break;
            case 10:
                tab2=dopelnieniealgebraiczne(tab, wiersze);
                wypisanie(tab2, wiersze, wiersze);
        }
        usuwanie(tab, wiersze);
    }

    cout << endl << "Czy powtorzyc (t/n)?: ";
    cin >> czy;
    system("cls");

    }while(czy=='t'||czy=='T');

    return 0;
}

void wypisanie(double** tablica, int w, int k){
    for(int i=0; i<w; i++){
        for(int j=0; j<k; j++){
            cout.width(4);
            cout << right << tablica[i][j] << " ";
        }
        cout << endl;
    }
}

void wstawianiewartosci(double** tablica, int w, int k){
    for(int i=0; i<w; i++){
        for(int j=0; j<k; j++){
            wypisanie(tablica, w, k);
            cout << "a" << i+1 << j+1 << ": ";
            cin >> tablica[i][j];
            system("cls");
        }
    }
}

void zerowanie(double** tablica, int w, int k){
    for(int i=0; i<w; i++){
        for(int j=0; j<k; j++){
            tablica[i][j]=0;
        }
    }
}

double** macierz(int w, int k){
    double **tablica = new double* [w];
    for(int i=0; i<w; i++){
        tablica[i]=new double[k];
    }
    zerowanie(tablica, w, k);
    return tablica;
}

void usuwanie(double** tablica, int w){
    for(int i=0; i<w; i++){
        delete[] tablica[i];
    }
    delete[] tablica;
}

double** mnozeniemacierzy(double** tablica1, double** tablica2, int w1, int k1, int k2){
    double** C = macierz(w1, k2);
    zerowanie(C, w1, k2);
    for(int i=0; i<w1; i++){
        for(int k=0; k<k2; k++){
            for(int j=0; j<k1; j++){
                C[i][k]+=tablica1[i][j]*tablica2[j][k];
            }
        }
    }
    return C;
}

void dodawaniemacierzy(double** tablica1, double** tablica2, int w, int k){
    for(int i=0; i<w; i++){
        for(int j=0; j<k; j++){
            tablica1[i][j]+=tablica2[i][j];
        }
    }
}

void odejmowaniemacierzy(double** tablica1, double** tablica2, int w, int k){
    for(int i=0; i<w; i++){
        for(int j=0; j<k; j++){
            tablica1[i][j]-=tablica2[i][j];
        }
    }
    cout << "Po odjeciu: " << endl;
    wypisanie(tablica1, w, k);
}

void mnozenieprzezstala(double** tablica, int w, int k, double liczba){
    for(int i=0; i<w; i++){
        for(int j=0; j<k; j++){
            tablica[i][j]*=liczba;
        }
    }
}

double wyznacznikchio(double** tablica, int w){
    int z=1;
    if(w==1){
        cout << "Chciales mnie oszukac ale ci nie wyjdzie. " << endl;
        return tablica[0][0];
    }
    if(w==2){
        return tablica[0][0]*tablica[1][1]-tablica[0][1]*tablica[1][0];
    }
    while(tablica[0][0]==0){
        if(z>=w){
            cout << "Pierwszy wiersz jest zerowy wiec:" << endl;
            return 0;
        }
        else{
            double* temp = new double[w];
            for(int i=0; i<w; i++){
                temp[i]=tablica[i][0];
            }
            for(int i=0; i<w; i++){
                tablica[i][0]=tablica[i][z];
                tablica[i][z]=temp[i];
            }
            z++;
            delete[] temp;
        }
    }
    if(tablica[0][0]!=0){
        double** malywyznacznik = macierz(w-1,w-1);
        double czynnikprzedchio=1.0/potega(tablica[0][0], w-2);
        for(int i=1; i<w; i++){
            for(int j=1; j<w; j++){
                malywyznacznik[i-1][j-1]=tablica[0][0]*tablica[i][j]-tablica[0][j]*tablica[i][0];
            }
        }
        double pom1 = wyznacznikchio(malywyznacznik, w-1);
        usuwanie(malywyznacznik, w-1);
        if(z%2==0){
            return -(czynnikprzedchio*pom1);
        }
        else{
            return czynnikprzedchio*pom1;
        }
    }
}

double wyznacznikchiowypisz(double** tablica, int w){
    int z=1;
    if(w==1){
        return tablica[0][0];
    }
    if(w==2){
        return tablica[0][0]*tablica[1][1]-tablica[0][1]*tablica[1][0];
    }
    while(tablica[0][0]==0){
        if(z>=w){
            cout << "Pierwszy wiersz jest zerowy wiec:" << endl;
            return 0;
        }
        else{
            double* temp = new double[w];
            for(int i=0; i<w; i++){
                temp[i]=tablica[i][0];
            }
            for(int i=0; i<w; i++){
                tablica[i][0]=tablica[i][z];
                tablica[i][z]=temp[i];
            }
            z++;
            delete[] temp;
        }
    }
    if(z>1){
        cout << "Ilosc zamian kolumn: " << z-1 << endl;
        if(z%2==0){
            cout << "Pamietaj o ujemnym znaku wyniku!" << endl;
        }
        wypisanie(tablica, w, w);
    }
    if(tablica[0][0]!=0){
        double** malywyznacznik = macierz(w-1,w-1);
        double czynnikprzedchio=1.0/potega(tablica[0][0], w-2);
        for(int i=1; i<w; i++){
            for(int j=1; j<w; j++){
                malywyznacznik[i-1][j-1]=tablica[0][0]*tablica[i][j]-tablica[0][j]*tablica[i][0];
            }
        }
        cout << endl;
        if(z%2==0){cout << -1 << "*";}else{cout << 1 << "*";};
        cout << "(1/" << potega(tablica[0][0], w-2) << ")*" << endl;
        wypisanie(malywyznacznik, w-1, w-1);
        double pom1 = wyznacznikchiowypisz(malywyznacznik, w-1);
        usuwanie(malywyznacznik, w-1);
        if(z%2==0){
            return -(czynnikprzedchio*pom1);
        }
        else{
            return czynnikprzedchio*pom1;
        }
    }
}

double wyznaczniklaplace(double** tablica, int w){
    if(w==1){
        return tablica[0][0];
    }
    else if(w==2){
        return tablica[0][0]*tablica[1][1]-tablica[0][1]*tablica[1][0];
    }
    else{
        double** dopelnienie = dopelnieniealgebraiczne(tablica, w);
        double liczba=0;
        for(int i=0; i<w; i++){
            liczba+= tablica[0][i]*dopelnienie[0][i];
        }
        usuwanie(dopelnienie, w);
        return liczba;
    }
}

double potega(double podstawa, double wykladnik){
    if (wykladnik != 0){
        return (podstawa*potega(podstawa, wykladnik-1));
    }
    else{
        return 1;
    }
}

double** transponuj(double** tablica, int w, int k){
    double** trans = macierz(k, w);
    for(int i=0; i<w; i++){
        for(int j=0; j<k; j++){
            trans[j][i]=tablica[i][j];
        }
    }
    return trans;
}

double** macierzodwrotna(double** tablica, int w){
    double W = wyznacznikchio(tablica, w);
    double** pom = dopelnieniealgebraiczne(tablica, w);
    mnozenieprzezstala(pom, w, w, 1/W);
    return transponuj(pom, w, w);
}

double** dopelnieniealgebraiczne(double** tablica, int w){
    double** wynik = macierz(w, w);
    double** pom = macierz(w-1, w-1);
    int k, l;
    for(int m=0; m<w; m++){
        for(int n=0; n<w; n++){ // n - kolumna pomijana w tab glownej
            k=0; // k - iterator sprawdzajacy wiersze tab glow
            for(int i=0; i<w-1; i++){ // i - wiersze wyznacznika pomocniczego (a11*akl-a0l*al0)
                l=0; // l - iterator sprawdzajacy kolumny tab glow
                if(m==k){ // - przeskakiwanie pomijanych wierszy
                    k++;
                }
                for(int j=0; j<w-1; j++){ // j - kolumny wyzn pom
                    if(n==l){ // przeskakiwanie kolumn
                        l++;
                    }
                    pom[i][j]=tablica[k][l]; // przypisywanie el tab glow do wyzn pom
                    l++;
                }
                k++;
            }
            wynik[m][n]=potega((-1),((m+1)+(n+1)))*wyznacznikchio(pom, w-1);
        }
    }
    usuwanie(pom, w-1);
    return wynik;
}
