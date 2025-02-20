#include <vector>
#include <iostream>
using namespace std;

typedef struct
{
    vector<vector<char>>grille ;
    int difficulte ;

} p4 ;

p4 initialise(int largeur, int hauteur) {
    p4 jeu;

    jeu.grille = vector<vector<char>>(largeur, vector<char>(hauteur, ' '));
    jeu.difficulte = 0;

    return jeu;
}

void affgrille (p4 p) //f1 ne sert a rqu'a afficher la grille puisque void et pas de passage par adresse il ne retourne donc rien
{
    int x, y ;
    for ( y=0; y < p.grille.size() ; y++)
    {
        for ( x=0; x<p.grille[y].size() ; x++)
        {
            cout << p.grille[y][x] << " | " ;
        }
        cout <<endl ;
    }
}

void f2 (p4 *p) // meilleru car s'actuallise en focntion de la grille
{
    int x, y ;
    for ( y=0; y < p->grille.size() ; y++)
    {
        for ( x=0; x<p->grille[y].size() ; x++)
        {
            cout << p->grille[y][x] << " | " ;
        }
        cout <<endl; ;
    }
}

int nb_cases_vides(p4 *p) {
    int nb= 0;

    for(int i=0 ; i<p->grille.size(); i++) {
        for(int j=0; j<p->grille[i].size(); j++) {
            if(p->grille[i][j]==' ') {
                nb+=1;
            }
        }
    }
    return nb;
}

void place_pion(p4 *p, int x, char symb) {

    if(x<0 || x>p->grille[0].size()) {
        cout<< "imposible de placer le pion"<<endl;
        return;
    }

    for(int i= p->grille.size()- 1 ; i>=0 ; i--) {
        if(p->grille[i][x]==' ') {
            p->grille[i][x]=symb;
            return;
        }
    }
    cout<<"la collone est pleine"<<endl;

}


int main ()
{   int x, tour =0;
    char pion, pionX = 'X', pionO = 'O';
    p4 jeu = initialise (7,5) ;



    f2(&jeu);
    while(nb_cases_vides(&jeu)!=0) {

        if(tour%2==0) {
            cout<<"Joueur "<<pionX <<"quelle case placer le pion "<<endl;
            cin>>x;
            place_pion(&jeu,x,pionX);
        }
        else {
            cout<<"Joueur "<<pionO <<"quelle case placer le pion "<<endl;
            cin>>x;

            place_pion(&jeu,x,pionO);
        }

        f2(&jeu);

        tour++;

    }



    return 0;
}
