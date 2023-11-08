#include <stdio.h>

int main() {
    int valores[10];
    int novo_conjunto[10];
    

    for (int i = 0; i < 10; i++) {
        scanf("%d", &valores[i]);
    }
    
    for (int i = 0; i < 10; i++) {
        printf("%d", valores[i]);
        if (i < 9) {
            printf(" ");
        }
    }
    printf("\n");
    
    int tamanho_janela = 2;
    
    while (tamanho_janela < 10) {
        for (int i = 0; i < 10 - tamanho_janela + 1; i++) {
            int soma = valores[i] + valores[i + 1];
            novo_conjunto[i] = soma;
        }
        
        for (int i = 0; i < 10 - tamanho_janela + 1; i++) {
            valores[i] = novo_conjunto[i];
        }
        
        for (int i = 0; i < 10 - tamanho_janela + 1; i++) {
            printf("%d", novo_conjunto[i]);
            if (i < 10 - tamanho_janela) {
                printf(" ");
            }
        }
        printf("\n");
        
        tamanho_janela++;
    }
    
    return 0;
}