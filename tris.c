#include <stdio.h>
#include <conio.h>

char tris[3][3] = {{'-','-','-'}, {'-','-','-'}, {'-','-','-'}};
const int TURNI = 8;
int menuch;

void game();
int win();
void print_tris();

int main(){

    game();

    return 0;
}

void game(){

    int turno;
    int occupato = 0;
    int riga, colonna;

    for (turno = 0; turno <= TURNI; turno++){

        do {

            occupato = 0;

            printf("\e[1;1H\e[2J");
            print_tris();

            turno%2 == 0 ? printf("TURNO DEL GIOCATORE 1\n\n") : printf("TURNO DEL GIOCATORE 2\n\n");

            do {
                printf("Inserisci una riga >>> ");
                scanf("%d", &riga);
                printf("\033[A\33[2K\r");
            } while (riga < 1 || riga > 3);

            do {
                printf("Inserisci una colonna >>> ");
                scanf("%d", &colonna);
                printf("\033[A\33[2K\r");
            } while (colonna < 1 || colonna > 3);

            if (tris[riga-1][colonna-1] != '-'){
                occupato++;
            }
            else {
                tris[riga-1][colonna-1] = turno%2 == 0 ? 'X' : 'O';
            }

            if (occupato){
                printf("Posizione già occupata");
            }

        } while(occupato);

        print_tris();

        if (win()){
            win() == 1 ? printf("HA VINTO IL GIOCATORE 1") :  printf("HA VINTO IL GIOCATORE 2");
            break;
        }

        else if (win() == 0 && turno == TURNI){
            printf("PAREGGIO");
        }

    }

}

int win(){

    int x;

    for (x = 0; x < 3; x++){
        if(tris[x][0] != '-' && (tris[x][0] == tris[x][1] && tris[x][0] == tris[x][2])){
            return (tris[x][0] == 'O' ? 2 : 1);
        }
        if(tris[0][x] != '-' && (tris[0][x] == tris[1][x] && tris[0][x] == tris[2][x])){
            return (tris[0][x] == 'O' ? 2 : 1);
        }
    }

    if (tris[1][1] != '-' && ((tris[0][0] == tris[1][1] && tris[0][0] == tris[2][2]) || (tris[2][0] == tris[1][1] && tris[2][0] == tris[0][2]))){
        return (tris[1][1] == 'O' ? 2 : 1);
    }

    return 0;

}

void print_tris(){

    int riga, colonna;

    printf("\e[1;1H\e[2J"); //pulisce lo schermo

    for (riga = 0; riga < 3; riga++){
        printf("\t");
        for (colonna = 0; colonna < 3; colonna++){
            printf("%c\t", tris[riga][colonna]);
            if (colonna != 2){
                printf("|\t");
            }
        }
        if (riga != 2){
            printf("\n-------------------------------------------------\n");
        }
    }
    printf("\n\n");
}
