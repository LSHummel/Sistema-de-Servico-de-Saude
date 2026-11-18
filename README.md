# Citizen Assist AI — Módulo de Serviços de Saúde

Sistema de gerenciamento de registros de pacientes desenvolvido em linguagem C, como parte do projeto acadêmico **Citizen Assist AI**.

O projeto tem como objetivo demonstrar a aplicação de estruturas de dados dinâmicas e algoritmos para facilitar o gerenciamento de informações de pacientes, permitindo realizar operações de cadastro, consulta, busca, ordenação, edição e exclusão de registros.

## Integrantes

- Matheus Pimenta Martini — RM 569400
- Lucas Seiji Hummel — RM 569673
- Leonardo Soares Rodrigues — RM 572986

## 1. Funcionalidades

O sistema possui um menu interativo com as seguintes operações:

| Opção | Funcionalidade | Descrição |
|---|---|---|
| 1 | Cadastrar paciente | Registra um novo paciente e atribui automaticamente um número de quarto. |
| 2 | Consultar registros | Exibe todos os pacientes cadastrados, organizados por número de quarto. |
| 3 | Buscar registros | Localiza pacientes pelo nome ou número do quarto. |
| 4 | Organizar registros | Ordena os pacientes por idade, quarto, nome ou descrição do problema. |
| 5 | Excluir registro | Remove um paciente utilizando o número do quarto e libera sua memória. |
| 6 | Editar informações | Permite modificar os dados de um paciente cadastrado. |
| 7 | Análise dos registros | Apresenta a quantidade de pacientes e a média de idade. |
| 8 | Sair | Encerra o programa e libera a memória utilizada pela lista. |

## 2. Estrutura de dados

O projeto utiliza uma **lista simplesmente encadeada**, implementada por meio de uma estrutura (`struct`) chamada `Paciente`.

Cada nó armazena as informações de um paciente e um ponteiro responsável por indicar o próximo elemento da lista.

### Campos da estrutura

- `nome`: nome do paciente (`char[50]`).
- `sexo`: sexo informado no cadastro (`char[20]`).
- `idade`: idade do paciente (`int`).
- `alergia`: informações sobre alergias (`char[150]`).
- `problema`: descrição do problema informado (`char[200]`).
- `quarto`: identificador numérico atribuído automaticamente (`int`).
- `proximo`: ponteiro para o próximo paciente (`Paciente *`).

O ponteiro `inicio` representa o início da lista. O último nó possui seu campo `proximo` apontando para `NULL`, indicando o término da estrutura.

A alocação dinâmica é realizada com `malloc()`, enquanto a liberação de memória utiliza `free()`.

## 3. Algoritmos utilizados

O sistema implementa diferentes algoritmos e operações de manipulação de listas encadeadas.

| Algoritmo / Função | Finalidade | Complexidade |
|---|---|---|
| `inserir_paciente()` | Insere um novo paciente no final da lista. | O(n) |
| `buscar_quarto()` | Busca um paciente pelo número do quarto. | O(n) |
| `buscar_nome()` | Busca um paciente pelo nome. | O(n) |
| `consultar_registros()` | Percorre e apresenta todos os registros. | O(n) |
| `Ordenacao_selection()` | Organiza os pacientes utilizando Selection Sort. | O(n²) |
| `excluir_registro()` | Localiza e remove um paciente da lista. | O(n) |
| `editar_registro()` | Localiza e atualiza informações de um paciente. | O(n) |
| `proximo_quarto()` | Identifica o maior quarto e gera o próximo número. | O(n) |
| `liberar_lista()` | Percorre a lista e libera toda a memória alocada. | O(n) |
| `analisar_registros()` | Calcula a quantidade de pacientes e a média de idade. | O(n) |

**Observação:** `n` representa a quantidade de pacientes armazenados na lista.

### Selection Sort

A ordenação utiliza o algoritmo Selection Sort, que procura o menor elemento da parte ainda não organizada da lista.

São disponibilizados quatro critérios:

1. Idade em ordem crescente.
2. Número do quarto em ordem crescente.
3. Nome em ordem alfabética.
4. Descrição do problema em ordem alfabética.

A complexidade temporal do algoritmo é O(n²).

## 4. Tecnologias utilizadas

- **Linguagem C:** desenvolvimento da lógica e das funcionalidades.
- **GCC:** compilação do código-fonte.
- **Estruturas dinâmicas:** utilização de listas simplesmente encadeadas.
- **Bibliotecas padrão:**
  - `stdio.h`: entrada e saída de dados.
  - `stdlib.h`: gerenciamento de memória dinâmica.
  - `string.h`: manipulação e comparação de strings.

## 5. Como executar o projeto

### Pré-requisitos

É necessário possuir um compilador C instalado, como o GCC (MinGW no Windows).

### Compilação

Abra o terminal na pasta do projeto e execute:

```bash
gcc -std=c11 -Wall -Wextra -pedantic citizen_assist.c -o citizen_assist
```

### Execução

**Linux / macOS:**

```bash
./citizen_assist
```

**Windows (MinGW):**

```bash
.\citizen_assist.exe
```

Após executar o programa, o menu principal será apresentado no terminal. Basta selecionar a operação desejada e seguir as instruções exibidas.

## 6. Limitações do protótipo

O Citizen Assist AI é um protótipo acadêmico desenvolvido para demonstrar conceitos de programação e estruturas de dados.

Atualmente, o sistema:

- Mantém os registros somente na memória RAM durante a execução.
- Não possui banco de dados ou persistência em arquivos.
- Não utiliza inteligência artificial generativa.
- Não possui integração com sistemas hospitalares.
- Não deve ser utilizado como prontuário eletrônico ou sistema de atendimento clínico real.

Ao encerrar o programa, todos os registros armazenados são liberados da memória.

## 7. Objetivo acadêmico

O desenvolvimento deste projeto busca aplicar, na prática, conceitos fundamentais da linguagem C, especialmente estruturas, ponteiros, alocação dinâmica de memória, listas simplesmente encadeadas, algoritmos de busca, ordenação e análise de complexidade computacional.

O protótipo demonstra como essas ferramentas podem ser utilizadas na construção de um sistema de gerenciamento de informações, contribuindo para o desenvolvimento de soluções tecnológicas voltadas aos serviços de saúde.

---

**Citizen Assist AI — Módulo de Serviços de Saúde**

*Projeto acadêmico — FIAP | Ciência da Computação*
