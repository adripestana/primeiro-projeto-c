# Sistema de Pedágio em C

Programa de terminal que simula um caixa de pedágio, feito em C como exercício da faculdade (Análise e Desenvolvimento de Sistemas).

## O que o programa faz
- Mostra um menu de categorias de veículo (Moto, Carro e Caminhão), com a tarifa de cada uma.
- Valida a entrada do usuário e ignora letras e símbolos digitados no lugar de números.
- Registra a contagem de veículos por categoria.
- Encerra o turno com a opção 0 e gera o relatório final.

## Conceitos praticados
- Vetores e matrizes
- Laços de repetição (`while` e `for`)
- Funções
- Tratamento de entrada com `scanf` e limpeza de buffer

## Como compilar e executar
```
gcc pedagio.c -o pedagio
./pedagio
```
No Windows, use `pedagio.exe` no lugar de `./pedagio`.