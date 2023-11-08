#include <stdio.h>
#include <string.h>

struct Jogador {
    char nome[31];
    char posicao;
    int forca;
};

float calcularForcaPonderada(struct Jogador jogadores[11]) {
    int G = 0, L1 = 0, L2 = 0, Z1 = 0, Z2 = 0, V1 = 0, V2 = 0, M1 = 0, M2 = 0, A1 = 0, A2 = 0;

    for (int i = 0; i < 11; i++) {
        switch (jogadores[i].posicao) {
            case 'G':
                G = jogadores[i].forca;
                break;
            case 'L':
                if (L1 == 0)
                    L1 = jogadores[i].forca;
                else
                    L2 = jogadores[i].forca;
                break;
            case 'Z':
                if (Z1 == 0)
                    Z1 = jogadores[i].forca;
                else
                    Z2 = jogadores[i].forca;
                break;
            case 'V':
                if (V1 == 0)
                    V1 = jogadores[i].forca;
                else
                    V2 = jogadores[i].forca;
                break;
            case 'M':
                if (M1 == 0)
                    M1 = jogadores[i].forca;
                else
                    M2 = jogadores[i].forca;
                break;
            case 'A':
                if (A1 == 0)
                    A1 = jogadores[i].forca;
                else
                    A2 = jogadores[i].forca;
                break;
        }
    }

    return (8 * G + 10 * (L1 + L2) + 5 * (Z1 + Z2) + 8 * (V1 + V2) + 11 * (M1 + M2) + 12 * (A1 + A2)) / 100.0;
}

int main() {
    struct Jogador time1[11];
    struct Jogador time2[11];
    char nomeTime1[31], nomeTime2[31];

    scanf("%30[^\n]", nomeTime1);

    for (int i = 0; i < 11; i++) {
        scanf(" %30[^;];%c;%d", time1[i].nome, &time1[i].posicao, &time1[i].forca);
    }

    scanf(" %30[^\n]", nomeTime2);

    for (int i = 0; i < 11; i++) {
        scanf(" %30[^;];%c;%d", time2[i].nome, &time2[i].posicao, &time2[i].forca);
    }

    float forcaTime1 = calcularForcaPonderada(time1);
    float forcaTime2 = calcularForcaPonderada(time2);

    printf("%s: %.2f de forca\n", nomeTime1, forcaTime1);
    printf("%s: %.2f de forca\n", nomeTime2, forcaTime2);

    if (forcaTime1 > forcaTime2) {
        printf("%s eh mais forte.\n", nomeTime1);
    } else if (forcaTime2 > forcaTime1) {
        printf("%s eh mais forte.\n", nomeTime2);
    } else {
        printf("Os times tem a mesma forca.\n");
    }

    return 0;
}