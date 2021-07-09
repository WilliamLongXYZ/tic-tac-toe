#include <stdio.h>

int player = 1;
int position;
int turn = 1;
int winner;

char positions[9] = {'_', '_', '_',
                    '_', '_', '_',
                    '_', '_', '_'};
char play(int position) {
    if (positions[position] == '_') {
if (player == 1) {
    positions[position] = 'X';
} else {
    positions[position] = 'O';
}
    }
    return positions[position];
}

void update(void) {
    char i[9];
    int j;
    for (j=0; j<9; j++) {
        i[j] = positions[j];
    }
    if ((i[0] == 'X' && i[1] == 'X' && i[2] == 'X') || (i[0] == 'X' && i[3] == 'X' && i[6] == 'X')){
        if (positions[1] == 'X' || positions[3] == 'X' || positions[4] == 'X') {
        printf("Player one wins!\n");
        winner = 1;
    }
    }
}

void printBoard() {
    printf("| %c | %c | %c |\n-------------\n| %c | %c | %c |\n-------------\n| %c | %c | %c |\n\n\n", positions[0], positions[1], positions[2], positions[3], positions[4], positions[5], positions[6], positions[7], positions[8]);
}

int main(void) {
    printBoard();
    while (1) {
        if (turn > 9) {
            break;
        }
        turn++;
        printf("What position would you like to play?  ");    
        scanf("%d", &position);
        play(position);
        printBoard();
        player == 1 ? player ++ : player --;
        update();
        if (winner){
            break;
        }
    }
  return 0;
}