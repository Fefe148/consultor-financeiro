#include <stdio.h>
#include<unistd.h>
#include <ctype.h>

    struct Transacao //Struct que serve como modelo paras as transações.
    {
        char nome[50];
        double valor;
        char tipo;
    };

    struct Transacao transacoes[100]; //Este array armazena as transações
    int quantidade_transacoes = 0; //Esta variável irá guardar as transações    

void mostrar_menu()
{ 
    printf("1- Adicionar receita\n");
    printf("2- Adicionar despesa\n");
    printf("3- Consultar saldo\n");
    printf("4- Listar transações\n");
    printf("0- Sair\n");
}

void adicionar_receita()
{

    printf("Você escolheu adicionar receita.\n");
    printf("Digite o nome da receita: ");
    fgets(transacoes[quantidade_transacoes].nome, sizeof(transacoes[quantidade_transacoes].nome),stdin);

    int tem_numero = 0;

    for (int i = 0; transacoes[quantidade_transacoes].nome[i] != '\0'; i++) {
    if (isdigit((unsigned char)transacoes[quantidade_transacoes].nome[i])) {
        tem_numero = 1;
        break;
    }
}

    if (transacoes[quantidade_transacoes].nome[0] == '\n')
    {
        printf("Nome inválido. A receita não pode ter nome vazio.\n");
        return; // Sai da função sem adicionar a receita
    }

    if (tem_numero) {
        printf("Nome inválido. A receita não pode conter números.\n");
        return;
    }

    printf("Digite o valor da receita: ");

    if (scanf("%lf", &transacoes[quantidade_transacoes].valor) != 1) {
        printf("Entrada inválida. Por favor, digite um valor numérico.\n");
        int caractere;
        while ((caractere = getchar()) != '\n' && caractere != EOF) {
        }
        return;
    }

    int caractere;
    while ((caractere = getchar()) != '\n' && caractere != EOF) {
    }

    if (transacoes[quantidade_transacoes].valor < 0) {
        printf("Valor inválido. A receita não pode ser negativa.\n");
        return; // Sai da função sem adicionar a receita
    }

    transacoes[quantidade_transacoes].tipo = 'R'; //transação do tipo receita
    quantidade_transacoes++;
    printf("Receita adicionada com sucesso.\n");
}

void adicionar_despesa()
{
    printf("Você escolheu adicionar despesa.\n");
    printf("Digite o nome da despesa: ");
    fgets(transacoes[quantidade_transacoes].nome, sizeof(transacoes[quantidade_transacoes].nome),stdin);

    int tem_numero = 0;
    for (int i = 0; transacoes[quantidade_transacoes].nome[i] != '\0'; i++) {
        if (isdigit((unsigned char)transacoes[quantidade_transacoes].nome[i])) {
            tem_numero = 1;
            break;
        }
    }

    if (transacoes[quantidade_transacoes].nome[0] == '\n') {
        printf("Nome inválido. A despesa não pode ter nome vazio.\n");
        return;
    }

    if (tem_numero) {
        printf("Nome inválido. A despesa não pode conter números.\n");
        return;
    }

    printf("Digite o valor da despesa: ");
    if (scanf("%lf", &transacoes[quantidade_transacoes].valor) != 1) {
        printf("Entrada inválida. Por favor, digite um valor numérico.\n");
        int caractere;
        while ((caractere = getchar()) != '\n' && caractere != EOF) {
        }
        return;
    }

    int caractere;
    while ((caractere = getchar()) != '\n' && caractere != EOF) {
    }

    if (transacoes[quantidade_transacoes].valor < 0) {
        printf("Valor inválido. A despesa não pode ser negativa.\n");
        return;
    }

    transacoes[quantidade_transacoes].tipo = 'D'; //transação do tipo despesa
    quantidade_transacoes++; // Incrementa a quantidade de transações
    printf("Despesa adicionada com sucesso.\n");
}

void consultar_saldo()

{
    double saldo = 0.0; //Vai armazenar nosso dinheirinho

    for (int i = 0; i < quantidade_transacoes; i++) {
        if (transacoes[i].tipo == 'R') { //Condicional de comparação. Se for receita, vai somar o saldo.
            saldo += transacoes[i].valor;
        }
        else if (transacoes[i].tipo == 'D') { //Mas se for despesa, irá subtrair.
            saldo -= transacoes[i].valor;
        }
    }

    printf("Saldo atual: %.2lf\n", saldo);

    if (saldo < 0) {
        printf("Saldo negativo!\n"); //Aviso para saldo negativo.
    }
    
}

void listar_transacoes()

{
     printf("Você escolheu listar transações.\n");

    for (int i = 0; i < quantidade_transacoes; i++) {

    printf("\nTransação %d\n", i + 1);
    printf("Nome: %s", transacoes[i].nome);
    printf("Valor: %.2lf\n", transacoes[i].valor);

    if (transacoes[i].tipo == 'R') {
        printf("Tipo: Receita\n");
    }
    else if (transacoes[i].tipo == 'D') {
        printf("Tipo: Despesa\n");
    }
    }
}
int main()

{

    int opcao;  
    
    printf("Controle Financeiro\n");
    printf("Bem vindo ao sistema de controle financeiro!\n");
    sleep(2);
    printf("Este sistema irá permitir que você controle suas finanças de forma inteligente.\n");
    sleep(2);
    printf("Começaremos te apresentando suas opções\n");
    sleep(2);

    do { 

        mostrar_menu(); //Chama a função que mostra o menu
    
        scanf("%d", &opcao); //Faz a leitura da opção desejada
        getchar();
    
        switch (opcao) { // Faz a escolha entre as opções (baseado na resposta do usuário)

            case 1:

                adicionar_receita();
                break;

            case 2:

                adicionar_despesa();
                break;

            case 3:

                consultar_saldo();
                break;

            case 4:

                listar_transacoes(); 
                break;
            case 0:

                printf("Saindo do sistema...\n");
                printf("Obrigado por utilizar o sistema de controle financeiro, esperamos vermos você novamente!\n");

                break;
            default:
                printf("Opção inválida. Tente novamente.\n"); //Caso o usuário digite uma opção inválida, o sistema irá avisar e pedir para tentar novamente.
        }
    } while (opcao != 0);

    return 0;
}
