#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int gcodp = 0;
int ga = 0;
int gcod_pedido = 0;
int gentregadores[100];
int totalPizzasVendidas=0;
int valorTotalVendas = 0;
typedef struct {
    char nome[100];
    int numero;
    char end[100];
} Cli;

typedef struct {
    char sabor[100];
    int cod;
    int valor;
    char descricao[1000];
} Piz;

typedef struct {
    int numero_pedido;
    int telefone_cliente;
    int codigo_pizza;
    int codigo_entregador;
    int situacao;
} Ped;

void cliente();
void pizza();
void cadc();
void altc();
void altcli();
void remc();
void mostrarPizzas(Piz pizzas[], int count);
void fazp();
void remp();
void cadp();
void altPiz();



Piz pizzas[100];
int pizzaCount = 0;
Cli cli[100]; 
int clientCount = 0; 
Ped pedidos[100]; 
int pedidoCount = 0;

int main() {
    sleep(1);
    system("cls");
    int a;
    printf("MENU\n[1]. Area do Cliente\n[2]. Area da Loja\n");
    scanf("%d", &a);

    if (a == 1) {
        cliente();
    } else if (a == 2) {
        pizza();
    } else if (a == 0) {
        return 0;
    }

    return 0;
}

void cliente() {
    int a;
    printf("1. Cadastrar Cliente\n2. Alterar Cliente\n3. Remover Cliente\n4. Menu de Pizzas\n5. Fazer Pedido\n6. Confirmar recebimento\n7.Retornar ao menu\n");
    scanf("%d", &a);

    switch (a) {
        case 1:
            cadc();
            break;
        case 2:
            altcli();
            break;
        case 3:
            remc();
            break;
        case 4:
            mostrarPizzas(pizzas, pizzaCount);
            break;
        case 5:
            fazp();
            break;
        case 6:
            confr();
            break;
        case 7:
            return main();
            break;
    }
}

void pizza() {
    int a;
    printf("1. Cadastrar Pizza\n2. Alterar Pizza\n3. Remover Pizza\n4. Alterar Status da entrega\n5. Entregadores Disponiveis\n6. Montante\n7.Retornar ao menu\n");
    scanf("%d", &a);

    switch (a) {
        case 1:
            cadp();
            break;
        case 2:
            altPiz();
            break;
        case 3:
            remp();
            break;
        case 4:
            despacho();
            break;
        case 5:
            mos_entre();
            break;
        case 6:
            montante();
            break;
        case 7:
            main();
            break;
    }
}

void cadc() {
    int a;
    printf("Quantos clientes deseja cadastrar: ");
    scanf("%d", &a);
    getchar(); // Limpar o buffer do teclado

    for (int z = 0; z < a; z++) {
        printf("Digite o nome do cliente: ");
        fgets(cli[clientCount].nome, 100, stdin);
        printf("Digite o telefone do cliente: ");
        scanf("%d", &cli[clientCount].numero);
        getchar(); // Limpar o buffer do teclado
        printf("Digite o endereco do cliente: ");
        fgets(cli[clientCount].end, 100, stdin);
        printf("Nome: %s\nTelefone: %d\nEndereco: %s\n", cli[clientCount].nome, cli[clientCount].numero, cli[clientCount].end);
        clientCount++;
    }

    int b;
    printf("Retornar ao menu [1]: ");
    scanf("%d", &b);

    if (b == 1) {
        main();
    }
}

void cadp() {
    printf("Deseja cadastrar quantas pizzas? ");
    scanf("%d", &ga);
    getchar();
    for (int z = 0; z < ga; z++) {
        printf("Digite o sabor: ");
        fgets(pizzas[pizzaCount].sabor, 100, stdin);
        gcodp = gcodp + 1;
        pizzas[pizzaCount].cod = gcodp;
        printf("Digite o valor: ");
        scanf("%d", &pizzas[pizzaCount].valor);
        getchar(); 
        printf("Descreva a pizza: ");
        fgets(pizzas[pizzaCount].descricao, 1000, stdin);
        printf("Sabor: %s\nCod: %d\nValor: %d\nDescricao: %s\n", pizzas[pizzaCount].sabor, pizzas[pizzaCount].cod, pizzas[pizzaCount].valor, pizzas[pizzaCount].descricao);
        pizzaCount++;
    }

    int b;
    printf("Retornar ao menu [1]: ");
    scanf("%d", &b);

    if (b == 1) {
        main();
    }
}

void altPiz() {
    int a;
    printf("Digite o codigo da pizza que deseja alterar: ");
    scanf("%d", &a);

    for (int i = 0; i < pizzaCount; i++) {
        if (pizzas[i].cod == a) {
            printf("Sabor atual: %s\n", pizzas[i].sabor);
            printf("Digite o novo sabor: ");
            getchar();
            fgets(pizzas[i].sabor, 100, stdin);

            printf("Valor atual: %d\n", pizzas[i].valor);
            printf("Digite o novo valor: ");
            scanf("%d", &pizzas[i].valor);
            getchar();

            printf("Descricao atual: %s\n", pizzas[i].descricao);
            printf("Digite a nova descricao: ");
            fgets(pizzas[i].descricao, 1000, stdin);

            printf("Pizza alterada com sucesso!\n");
            break;
        }
    }

    int b;
    printf("Retornar ao menu [1]: ");
    scanf("%d", &b);

    if (b == 1) {
        main();
    }
}

void altcli() {
    int a;
    printf("Digite o telefone do cliente que deseja alterar: ");
    scanf("%d", &a);

    for (int i = 0; i < clientCount; i++) {
        if (cli[i].numero == a) {
            printf("Nome atual: %s\n", cli[i].nome);
            printf("Digite o novo nome: ");
            getchar(); //Limpar o buffer do teclado
            fgets(cli[i].nome, 100, stdin);

            printf("Endereco atual: %s\n", cli[i].end);
            printf("Digite o novo endereco: ");
            fgets(cli[i].end, 100, stdin);

            printf("Cliente alterado com sucesso!\n");
            break;
        }
    }

    int b;
    printf("Retornar ao menu [1]: ");
    scanf("%d", &b);

    if (b == 1) {
        main();
    }
}

void mostrarPizzas(Piz pizzas[], int count) {
    if (count == 0) {
        printf("Nenhuma pizza cadastrada.\n");
    } else {
        printf("Pizzas cadastradas:\n");
        for (int i = 0; i < count; i++) {
            printf("Sabor: %s\nCodigo: %d\nValor: %d\nDescrição: %s\n", pizzas[i].sabor, pizzas[i].cod, pizzas[i].valor, pizzas[i].descricao);
        }
    }

    int b;
    printf("Retornar ao menu [1]: ");
    scanf("%d", &b);

    if (b == 1) {
        main();
    }
}

void remc() {
    int telefone;
    printf("Digite o telefone do cliente que deseja remover: ");
    scanf("%d", &telefone);

    int index = -1; 

    
    for (int i = 0; i < clientCount; i++) {
        if (cli[i].numero == telefone) {
            index = i; 
            break;
        }
    }


    if (index != -1) {
        for (int i = index; i < clientCount - 1; i++) {
            strcpy(cli[i].nome, cli[i + 1].nome);
            cli[i].numero = cli[i + 1].numero;
            strcpy(cli[i].end, cli[i + 1].end);
        }

        clientCount--; // Atualizar o contador de clientes

        printf("Cliente removido com sucesso!\n");
    } else {
        printf("Cliente nao encontrado.\n");
    }

    int b;
    printf("Retornar ao menu [1]: ");
    scanf("%d", &b);

    if (b == 1) {
        main();
    }
}

void fazp() {
    int telefone;
    printf("Digite o telefone do cliente: ");
    scanf("%d", &telefone);
    int index_cliente = -1; // Índice do cliente no array cli[]
    for (int i = 0; i < clientCount; i++) {
        if (cli[i].numero == telefone) {
            index_cliente = i;
            break;
        }
    }

    if (index_cliente == -1) {
        printf("Cliente nao encontrado.\n");
        main();
    }

    int codigo_pizza;
    printf("Digite o codigo da pizza: ");
    scanf("%d", &codigo_pizza);

    int index_pizza = -1; // Índice da pizza no array pizzas[]
    for (int i = 0; i < pizzaCount; i++) {
        if (pizzas[i].cod == codigo_pizza) {
            index_pizza = i;
            break;
        }
    }

    if (index_pizza == -1) {
        printf("Pizza nao encontrada.\n");
        main();
    }

    // Fazer o pedido
    pedidos[pedidoCount].numero_pedido = gcod_pedido + 1;
    pedidos[pedidoCount].telefone_cliente = cli[index_cliente].numero;
    pedidos[pedidoCount].codigo_pizza = pizzas[index_pizza].cod;
    pedidos[pedidoCount].codigo_entregador = 0; // Ainda sem entregador
    pedidos[pedidoCount].situacao = 1; // Em preparo

    printf("Pedido realizado com sucesso!\n");
    totalPizzasVendidas++; // Incrementar o montante total de pizzas vendidas
    valorTotalVendas += pizzas[index_pizza].valor; // Incrementar o valor total das vendas

    pedidoCount++;
    int b;
    printf("Retornar ao menu [1]: ");
    scanf("%d", &b);

    if (b == 1) {
        main();
    }
}
void remp() {
    int codigo;
    printf("Digite o código da pizza que deseja remover: ");
    scanf("%d", &codigo);

    int index = -1; // Variável para armazenar o índice da pizza a ser removida

    // Procurar a pizza com base no código
    for (int i = 0; i < pizzaCount; i++) {
        if (pizzas[i].cod == codigo) {
            index = i; // Armazenar o índice da pizza encontrada
            break;
        }
    }

    // Remover a pizza, se encontrada
    if (index != -1) {
        // Deslocar as pizzas à direita do índice para a esquerda para preencher o espaço
        for (int i = index; i < pizzaCount - 1; i++) {
            strcpy(pizzas[i].sabor, pizzas[i + 1].sabor);
            pizzas[i].cod = pizzas[i + 1].cod;
            pizzas[i].valor = pizzas[i + 1].valor;
            strcpy(pizzas[i].descricao, pizzas[i + 1].descricao);
        }

        pizzaCount--; // Atualizar o contador de pizzas

        printf("Pizza removida com sucesso!\n");
    } else {
        printf("Pizza não encontrada.\n");
    }

    int b;
    printf("Retornar ao menu [1]: ");
    scanf("%d", &b);

    if (b == 1) {
        main();
    }
}
void despacho() {
    int numero_pedido;
    printf("Digite o número do pedido: ");
    scanf("%d", &numero_pedido);

    int index_pedido = -1; // Índice do pedido no array pedidos[]
    for (int i = 0; i < pedidoCount; i++) {
        if (pedidos[i].numero_pedido == numero_pedido) {
            index_pedido = i;
            break;
        }
    }

    if (index_pedido == -1) {
        printf("Pedido não encontrado.\n");
        main();
    }

    // Selecionar o entregador disponível
    int codigo_entregador;
    printf("Digite o código do entregador: ");
    scanf("%d", &codigo_entregador);

    // Verificar se o entregador está disponível e atualizar o número de pedidos que ele está levando
    if (codigo_entregador >= 1 && codigo_entregador <= 100) {
        gentregadores[codigo_entregador - 1]++;
        pedidos[index_pedido].codigo_entregador = codigo_entregador;
        pedidos[index_pedido].situacao = 2; // Alterar o status do pedido para "2 - a caminho"
        printf("Pedido despachado com sucesso!\n");
    } else {
        printf("Entregador inválido.\n");
    }

    int b;
    printf("Retornar ao menu [1]: ");
    scanf("%d", &b);

    if (b == 1) {
        main();
    }
}
int confr()
{
    int numero_pedido;
    printf("Digite o número do pedido: ");
    scanf("%d", &numero_pedido);

    int index_pedido = -1; // Índice do pedido no array pedidos[]
    for (int i = 0; i < pedidoCount; i++) {
        if (pedidos[i].numero_pedido == numero_pedido) {
            index_pedido = i;
            break;
        }
    }

    if (index_pedido == -1) {
        printf("Pedido não encontrado.\n");
        main();
    }

    // Alterar o status do pedido para "3 - recebido"
    pedidos[index_pedido].situacao = 3;

    printf("Pedido recebido com sucesso!\n");

    int b;
    printf("Retornar ao menu [1]: ");
    scanf("%d", &b);

    if (b == 1) {
        main();
    }
}
int mos_entre()
{
    printf("Pedidos por entregador:\n");
    for (int i = 0; i < 100; i++) {
        if (gentregadores[i] > 0) {
            printf("Entregador %d: %d pedidos\n", i + 1, gentregadores[i]);
        }
    }

    int b;
    printf("Retornar ao menu [1]: ");
    scanf("%d", &b);

    if (b == 1) {
        main();
    }
}
int montante()
{
    printf("Total de pizzas vendidas: %d\n", totalPizzasVendidas);
    printf("Valor total das vendas: R$ %d\n", valorTotalVendas);
    int b;
    printf("Retornar ao menu [1]: ");
    scanf("%d", &b);

    if (b == 1) {
        main();
    }
}