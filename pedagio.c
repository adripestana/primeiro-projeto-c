#include <stdio.h>

// Funcao auxiliar para esvaziar o buffer do teclado (stdin)
// Remove quaisquer caracteres residuais e o '\n' gerado pela tecla Enter
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    // 1. ESTRUTURAS DE ARMAZENAMENTO (Vetores e Matrizes)
    float tarifas[3] = {2.50, 5.80, 12.40};
    int contagemVeiculos[3] = {0, 0, 0};
    char nomesCategorias[3][20] = {"Moto", "Carro", "Caminhao"};
    
    // 2. VARIAVEIS DE CONTROLE
    int opcao_veiculo;
    float valor_pago, troco, valor_final;
    int qtd_eixos;
    
    printf("=== SISTEMA DE PEDAGIO INICIADO ===\n\n");
    
    // 3. LACO DE REPETICAO PRINCIPAL (O sistema roda ate o caixa ser fechado)
    while(1) {
        printf("-----------------------------------\n");
        printf("Selecione a categoria do veiculo:\n");
        
        // Laco FOR interage com os vetores para montar o menu dinamicamente
        for(int i = 0; i < 3; i++) {
            printf("[%d] %s - R$ %.2f\n", i + 1, nomesCategorias[i], tarifas[i]);
        }
        printf("[0] Encerrar Turno e Gerar Relatorio\n");
        printf("-----------------------------------\n");
        printf("Opcao: ");
        
        // Tratamento do buffer na opcao do menu:
        // Se o usuario digitar letras ou simbolos, o scanf retorna valor diferente de 1
        if (scanf("%d", &opcao_veiculo) != 1) {
            printf("Opcao invalida! Digite apenas numeros.\n\n");
            limparBuffer();
            continue;
        }
        limparBuffer(); // Remove o '\n' que sobra no buffer
        
        // Regra de negocio: Opcao 0 encerra o laco e vai para o relatorio final
        if(opcao_veiculo == 0) {
            break; 
        }
        
        // Validacao contra opcao numerica fora do intervalo
        if(opcao_veiculo < 1 || opcao_veiculo > 3) {
            printf("Opcao invalida! Tente novamente.\n\n");
            continue;
        }
        
        // O indice do vetor comeca em 0, por isso subtraimos 1 da opcao digitada
        int indice = opcao_veiculo - 1;
        valor_final = tarifas[indice];
        
        // 4. DESAFIO BONUS: Regra especifica para Caminhao (multiplicador de eixos)
        if(opcao_veiculo == 3) {
            printf("Digite a quantidade de eixos do caminhao: ");
            // Valida se foi digitado um numero e se a quantidade de eixos e valida (> 0)
            while (scanf("%d", &qtd_eixos) != 1 || qtd_eixos <= 0) {
                printf("Quantidade invalida! Digite um numero de eixos valido (maior que 0): ");
                limparBuffer();
            }
            limparBuffer();
            
            valor_final = tarifas[indice] * qtd_eixos;
            printf("Valor ajustado por eixos (R$ %.2f x %d) = R$ %.2f\n", tarifas[indice], qtd_eixos, valor_final);
        }
        
        // 5. RECEBIMENTO E TROCO
        printf("Valor pago pelo motorista: R$ ");
        if (scanf("%f", &valor_pago) != 1) {
            printf("Entrada invalida! Pagamento cancelado.\n\n");
            limparBuffer();
            continue;
        }
        limparBuffer();
        
        if(valor_pago < valor_final) {
            printf("Valor insuficiente! Pagamento cancelado.\n\n");
        } else {
            troco = valor_pago - valor_final;
            printf("Pagamento aprovado. Troco: R$ %.2f\n\n", troco);
            
            // Incrementa dinamicamente a estatistica da categoria que acabou de passar
            contagemVeiculos[indice]++;
        }
    }
    
    // 6. PROCESSAMENTO FINAL NO CONSOLE
    printf("\n===================================\n");
    printf("   RELATORIO DE FECHAMENTO DE TURNO  \n");
    printf("===================================\n");
    
    int total_veiculos = 0;
    
    // Laco FOR percorre os vetores para exibir os resultados gravados na memoria
    for(int i = 0; i < 3; i++) {
        printf("%s: %d passagens registradas\n", nomesCategorias[i], contagemVeiculos[i]);
        total_veiculos += contagemVeiculos[i];
    }
    
    printf("-----------------------------------\n");
    printf("Total geral de veiculos: %d\n", total_veiculos);
    printf("===================================\n");
    
    return 0;
}
