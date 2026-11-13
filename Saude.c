#include<stdio.h>
#include<string.h>




void MENU(){
    printf("\n===========================\n");
    printf("    Servico de Saude\n");
    printf("===========================\n");
    printf("1 - Cadastrar paciente\n");
    printf("2 - Consultar registros\n");
    printf("3 - Buscar registros\n");
    printf("4 - Organizar registros\n");
    printf("5 - Sair\n");
    printf("\nO que deseja fazer?\nR: ");
}

typedef struct{
    char nome[50];
    int idade;
    char problema[200];
    int quarto;
}Paciente;




int main(){
    Paciente paciente[10];
    int menu = 0;
    int paciente_atual = 0;

    while(menu != 5){
        MENU();
        scanf("%d", &menu);
        getchar();


        switch(menu){

            case 1:
                printf("===========================\n");
                printf("  Cadastro do Paciente\n");
                printf("===========================\n\n");    
                printf("Nome do paciente: ");
                fgets(paciente[paciente_atual].nome, 50, stdin);

                printf("Idade do paciente: ");
                scanf("%d", &paciente[paciente_atual].idade);
                getchar();

                printf("Descricao do problema:\nR: ");
                fgets(paciente[paciente_atual].problema, 200, stdin);

                printf("Qual quarto sera colocado?\nR: ");
                scanf("%d", &paciente[paciente_atual].quarto);
                getchar();


                paciente_atual++;

                break;


            case 2:
                printf("===========================\n");
                printf("  Consulta de Registros\n");
                printf("===========================\n\n"); 

                for(int i = 0; i < paciente_atual; i++){    
                    
                    printf("--------------------------------\n");
                    printf("Nome: %s", paciente[i].nome);
                    printf("Idade: %d\n", paciente[i].idade);
                    printf("Descricao: %s", paciente[i].problema);
                    printf("Quarto: %d\n", paciente[i].quarto);

                }



                break;

            case 3:
                printf("caso 3");
                break;

            case 4:
                printf("caso 4");
                break;

            case 5:
                printf("Registros salvos!");
                break;

            default:
                printf("Opcao invalida");

        }
    }

    return 0;
}