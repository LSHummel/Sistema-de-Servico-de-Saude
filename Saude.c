#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// STRUCT
typedef struct Paciente{
    char nome[50];
    char sexo[20];
    int idade;
    char alergia[150];
    char problema[200];
    int quarto;
    struct Paciente *proximo;
}Paciente;

// MENU
void MENU(void){
    printf("\n===========================\n");
    printf("    Servico de Saude\n");
    printf("===========================\n");
    printf("1 - Cadastrar paciente\n");
    printf("2 - Consultar registros\n");
    printf("3 - Buscar registros\n");
    printf("4 - Organizar registros\n");
    printf("5 - Excluir registro completo\n");
    printf("6 - Editar informacoes do registro\n");
    printf("7 - Analise dos registros\n");
    printf("8 - Sair\n");
    printf("\nO que deseja fazer?\nR: ");
}

// FUNÇÃO VOLTAR
void voltar(void){
    int opcao;
    printf("\nDigite 0 para voltar ao menu: ");
    while(scanf("%d", &opcao) != 1 || opcao != 0){
        while(getchar() != '\n'){}
        printf("Opcao invalida. Digite 0 para voltar ao menu: ");
    }
    while(getchar() != '\n'){}
}

// FUNÇÃO INSERIR PACIENTE
int inserir_paciente(Paciente **inicio, const char nome[], const char sexo[],
                     int idade, const char alergia[], const char problema[],
                     int quarto){
    Paciente *novo = malloc(sizeof(Paciente));
    if(novo == NULL){
        printf("\nErro: nao foi possivel alocar memoria.\n");
        return 0;
    }

    strcpy(novo->nome, nome);
    strcpy(novo->sexo, sexo);
    novo->idade = idade;
    strcpy(novo->alergia, alergia);
    strcpy(novo->problema, problema);
    novo->quarto = quarto;
    novo->proximo = NULL;

    if(*inicio == NULL){
        *inicio = novo;
    }else{
        Paciente *atual = *inicio;
        while(atual->proximo != NULL){
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }
    return 1;
}

// FUNÇÃO BUSCAR QUARTO
Paciente *buscar_quarto(Paciente *inicio, int quarto){
    Paciente *atual = inicio;
    while(atual != NULL){
        if(atual->quarto == quarto){
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

// FUNÇÃO BUSCA NOME
Paciente *buscar_nome(Paciente *inicio, char nome[]){
    nome[strcspn(nome, "\n")] = '\0';
    Paciente *atual = inicio;
    while(atual != NULL){
        atual->nome[strcspn(atual->nome, "\n")] = '\0';
        if(strcmp(atual->nome, nome) == 0){
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

// FUNÇÃO CONSULTAR REGISTRO
void consultar_registros(Paciente *inicio){
    Paciente *atual = inicio;

    if(atual == NULL){
        printf("\nNenhum paciente cadastrado.\n");
        return;
    }

    while(atual != NULL){
        printf("--------------------------------\n");
        printf("Nome: %s\n", atual->nome);
        printf("Sexo: %s\n", atual->sexo);
        printf("Idade: %d\n", atual->idade);
        printf("Alergias: %s\n", atual->alergia);
        printf("Descricao: %s\n", atual->problema);
        printf("Quarto: %d\n", atual->quarto);
        atual = atual->proximo;
    }
    printf("--------------------------------\n");
}

// FUNÇÃO TROCAR DADOS
void trocar_dados(Paciente *a, Paciente *b){
    char texto[200];
    int numero;

    strcpy(texto, a->nome);
    strcpy(a->nome, b->nome);
    strcpy(b->nome, texto);

    strcpy(texto, a->sexo);
    strcpy(a->sexo, b->sexo);
    strcpy(b->sexo, texto);

    numero = a->idade;
    a->idade = b->idade;
    b->idade = numero;

    strcpy(texto, a->alergia);
    strcpy(a->alergia, b->alergia);
    strcpy(b->alergia, texto);

    strcpy(texto, a->problema);
    strcpy(a->problema, b->problema);
    strcpy(b->problema, texto);

    numero = a->quarto;
    a->quarto = b->quarto;
    b->quarto = numero;
}

// FUNÇÃO SELECTION SORT
void Ordenacao_selection(Paciente *inicio, int criterio){
    Paciente *i;
    for(i = inicio; i != NULL && i->proximo != NULL; i = i->proximo){
        Paciente *menor = i;
        Paciente *j;

        for(j = i->proximo; j != NULL; j = j->proximo){
            int comparar = 0;

            if(criterio == 1){
                comparar = (j->idade < menor->idade);
            }else if(criterio == 2){
                comparar = (j->quarto < menor->quarto);
            }else if(criterio == 3){
                comparar = (strcmp(j->nome, menor->nome) < 0);
            }else if(criterio == 4){
                comparar = (strcmp(j->problema, menor->problema) < 0);
            }

            if(comparar){
                menor = j;
            }
        }

        if(menor != i){
            trocar_dados(i, menor);
        }
    }
}

// FUNÇÃO EXCLUIR REGISTRO
int excluir_registro(Paciente **inicio, int quarto){
    Paciente *atual = *inicio;
    Paciente *anterior = NULL;

    while(atual != NULL && atual->quarto != quarto){
        anterior = atual;
        atual = atual->proximo;
    }

    if(atual == NULL){
        return 0;
    }

    if(anterior == NULL){
        *inicio = atual->proximo;
    }else{
        anterior->proximo = atual->proximo;
    }

    free(atual);
    return 1;
}

// FUNÇÃO EDITAR REGISTRO
int editar_registro(Paciente *inicio, int quarto, int criterio){
    Paciente *paciente = buscar_quarto(inicio, quarto);

    if(paciente == NULL){
        return 0;
    }

    switch(criterio){
        case 1:
            printf("Novo nome: ");
            fgets(paciente->nome, sizeof(paciente->nome), stdin);
            break;
        case 2:
            printf("Novo sexo: ");
            fgets(paciente->sexo, sizeof(paciente->sexo), stdin);
            break;
        case 3:
            printf("Nova idade: ");
            if(scanf("%d", &paciente->idade) != 1){
                while(getchar() != '\n'){}
                return -1;
            }
            while(paciente->idade <= 0){
                printf("Idade invalida! Digite novamente: ");
                if(scanf("%d", &paciente->idade) != 1){
                    while(getchar() != '\n'){}
                    return -1;
                }
            }
            while(getchar() != '\n'){}
            break;
        case 4:
            printf("Nova alergia: ");
            fgets(paciente->alergia, sizeof(paciente->alergia), stdin);
            break;
        case 5:
            printf("Nova descricao do problema: ");
            fgets(paciente->problema, sizeof(paciente->problema), stdin);
            break;
        default:
            return -1;
    }
    return 1;
}

// FUNÇÃO CONTAGEM QUARTO
int proximo_quarto(Paciente *inicio){
    int maior = 0;
    Paciente *atual = inicio;

    while(atual != NULL){
        if(atual->quarto > maior){
            maior = atual->quarto;
        }
        atual = atual->proximo;
    }
    return maior + 1;
}

// FUNÇÃO LIBERAR LISTA
void liberar_lista(Paciente **inicio){
    Paciente *atual = *inicio;

    while(atual != NULL){
        Paciente *temporario = atual;
        atual = atual->proximo;
        free(temporario);
    }
    *inicio = NULL;
}

// FUNÇÃO ANALISAR REGISTRO
void analisar_registros(Paciente *inicio){
    Paciente *atual = inicio;

    int total = 0;
    int soma_idades = 0;

    if(inicio == NULL){
        printf("\nNao existem pacientes cadastrados.\n");
        return;
    }

    while(atual != NULL){
        total++;
        soma_idades += atual->idade;

        atual = atual->proximo;
    }

    printf("\n================================\n");
    printf("       ANALISE DOS REGISTROS\n");
    printf("==================================\n");

    printf("Total de pacientes: %d\n", total);
    printf("Media de idade: %.2f anos\n", (float)soma_idades / total);

    printf("----------------------------------\n");
}

// FUNÇÃO REMOVER QUEBRA DE LINHA
void remover_enter(char texto[]){
    texto[strcspn(texto, "\n")] = '\0';
}


// CÓDIGO PRINCIPAL
int main(void){
    Paciente *inicio = NULL;
    int menu = 0;
    int pacientes_atual = 0;
    int quarto = 0;
    int opcao_busca;
    int resultado;
    char nome_busca[50];
    int criterio;

    while(menu != 8){
        MENU();

        if(scanf("%d", &menu) != 1){
            while(getchar() != '\n'){}
            printf("\nOpcao invalida!\n");
            continue;
        }
        while(getchar() != '\n'){}

        switch(menu){
            case 1: {
                char nome[50], sexo[20], alergia[150], problema[200];
                int idade;

                printf("===========================\n");
                printf("  Cadastro do Paciente\n");
                printf("===========================\n\n");

                printf("Nome do paciente: ");
                fgets(nome, sizeof(nome), stdin);
                remover_enter(nome);

                printf("\nSexo do paciente: ");
                fgets(sexo, sizeof(sexo), stdin);
                remover_enter(sexo);

                printf("\nIdade do paciente: ");
                if(scanf("%d", &idade) != 1){
                    while (getchar() != '\n') {}
                    printf("\nIdade invalida!\n");
                    voltar();
                    break;
                }
                while(idade <= 0){
                    printf("Idade invalida, digite um numero acima de 0 (zero): ");
                    if(scanf("%d", &idade) != 1){
                        while (getchar() != '\n') {}
                        idade = 0;
                    }
                }
                while(getchar() != '\n'){}

                printf("\nPossui alergias? Quais?\nR: ");
                fgets(alergia, sizeof(alergia), stdin);
                remover_enter(alergia);

                printf("\nDescricao do problema:\nR: ");
                fgets(problema, sizeof(problema), stdin);
                remover_enter(problema);

                quarto = proximo_quarto(inicio);
                if(inserir_paciente(&inicio, nome, sexo, idade,
                                     alergia, problema, quarto)){
                    pacientes_atual++;
                    printf("\nPaciente cadastrado! Numero do quarto: %d\n", quarto);
                }
                voltar();
                break;
            
            }
            case 2: {
                printf("===========================\n");
                printf("  Consulta de Registros\n");
                printf("===========================\n\n");
                Ordenacao_selection(inicio, 2);
                consultar_registros(inicio);
                voltar();
                break;
            }
            case 3: {
                printf("===========================\n");
                printf("     Buscar Paciente\n");
                printf("===========================\n\n");
                printf("1 - Buscar por quarto\n");
                printf("2 - Buscar por nome\n");
                printf("\nEscolha uma opcao: ");

                if(scanf("%d", &opcao_busca) != 1){
                    while(getchar() != '\n'){}
                    printf("\nOpcao invalida!\n");
                    voltar();
                    break;
                }
                while(getchar() != '\n'){}

                Paciente *encontrado = NULL;
                if(opcao_busca == 1){
                    printf("\nDigite o quarto do paciente: ");
                    if(scanf("%d", &quarto) != 1){
                        while(getchar() != '\n'){}
                        printf("\nQuarto invalido!\n");
                        voltar();
                        break;
                    }
                    while(getchar() != '\n'){}
                    encontrado = buscar_quarto(inicio, quarto);
                }else if(opcao_busca == 2){
                    printf("\nDigite o nome do paciente: ");
                    fgets(nome_busca, sizeof(nome_busca), stdin);
                    encontrado = buscar_nome(inicio, nome_busca);
                }else{
                    printf("\nOpcao de busca invalida!\n");
                }

                if(encontrado != NULL){
                    printf("\n     PACIENTE ENCONTRADO\n");
                    printf("----------------------------\n");
                    printf("Quarto: %d\n", encontrado->quarto);
                    printf("Nome: %s\n", encontrado->nome);
                    printf("Sexo: %s\n", encontrado->sexo);
                    printf("Idade: %d\n", encontrado->idade);
                    printf("Alergias: %s\n", encontrado->alergia);
                    printf("Descricao: %s\n", encontrado->problema);
                    printf("----------------------------\n");
                }else if(opcao_busca == 1 || opcao_busca == 2){
                    printf("\nPACIENTE NAO ENCONTRADO!\n");
                }
                voltar();
                break;
            }
            case 4: {
                printf("===========================\n");
                printf("   Organizar Registros\n");
                printf("===========================\n");
                printf("1 - Ordenar por idade\n");
                printf("2 - Ordenar por quarto\n");
                printf("3 - Ordenar por nome\n");
                printf("4 - Ordenar por problema\n");
                printf("\nEscolha o criterio: ");

                if(scanf("%d", &criterio) != 1){
                    while(getchar() != '\n'){}
                    printf("\nCriterio invalido!\n");
                    voltar();
                    break;
                }
                while(getchar() != '\n'){}

                if(criterio >= 1 && criterio <= 4){
                    Ordenacao_selection(inicio, criterio);
                    printf("\nRegistros organizados!\n");
                    consultar_registros(inicio);
                }else{
                    printf("\nCriterio invalido!\n");
                }
                voltar();
                break;
            }
            case 5: {
                printf("===========================\n");
                printf("     Excluir Paciente\n");
                printf("===========================\n");
                printf("Digite o numero do quarto: ");

                if(scanf("%d", &quarto) != 1){
                    while (getchar() != '\n'){}
                    printf("\nQuarto invalido!\n");
                    voltar();
                    break;
                }
                while(getchar() != '\n'){}

                if(excluir_registro(&inicio, quarto)){
                    pacientes_atual--;
                    printf("\nPaciente excluido com sucesso!\n");
                }else{
                    printf("\nPaciente nao encontrado!\n");
                }
                voltar();
                break;
            }
            case 6: {
                printf("===========================\n");
                printf("     Editar Paciente\n");
                printf("===========================\n");
                printf("Digite o quarto do paciente: ");

                if(scanf("%d", &quarto) != 1){
                    while(getchar() != '\n'){}
                    printf("\nQuarto invalido!\n");
                    voltar();
                    break;
                }
                while(getchar() != '\n'){}

                printf("\nQual informacao deseja editar?\n");
                printf("1 - Nome\n");
                printf("2 - Sexo\n");
                printf("3 - Idade\n");
                printf("4 - Alergia\n");
                printf("5 - Problema\n");
                printf("\nEscolha: ");

                if(scanf("%d", &criterio) != 1){
                    while (getchar() != '\n') {}
                    printf("\nOpcao invalida!\n");
                    voltar();
                    break;
                }
                while(getchar() != '\n'){}

                resultado = editar_registro(inicio, quarto, criterio);
                if(resultado == 1){
                    printf("\nRegistro atualizado com sucesso!\n");
                }else if(resultado == 0){
                    printf("\nPaciente nao encontrado!\n");
                }else{
                    printf("\nOpcao invalida!\n");
                }
                voltar();
                break;
            }
            case 7: {
                analisar_registros(inicio);
                voltar();
                break;    
            }
            case 8: {
                printf("\nEncerrando o programa...\n");
                break;
            }
            default:
                printf("\nOpcao invalida!\n");
                voltar();
        }
    }

    liberar_lista(&inicio);
    printf("Memoria da lista liberada.\n");
    return 0;
}
