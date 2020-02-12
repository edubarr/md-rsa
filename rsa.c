#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define RUN 1

char DICIONARIO[30] = "..ABCDEFGHIJKLMNOPQRSTUVWXYZ ";

void buffclear(void) // Limpa o buffer de entrada
{
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
    return;
}

int e_primo(int n) // Verifica se o número é primo
{
    int i;
    if (n == 1 || n == 0)
    {
        return 0;
    }
    else
    {
        for (i = 2; i < n; i++)
        {
            if (n % i == 0)
            {
                return 0;
            }
        }
        return 1;
    }
}

int mdc(int n1, int n2) // Calcula o MDC de dois números utilizando o algoritmo de Euclides
{
    int resto;
    do
    {
        resto = n1 % n2;

        n1 = n2;
        n2 = resto;

    } while (resto != 0);

    return n1;
}

void sugprimo(int n, int *primos) // Sugere 10 números coprimos
{
    int i, count = 0;

    for (i = 43; count < 10; i += 13)
    {
        if (mdc(n, i) == 1)
        {
            primos[count] = i;
            count++;
        }
    }
}

long long int inversomodular(long long int e, long long int fi) //Calcula o inverso modular
{
    long long int e2, fi2; //Cópias de "e" e "fi" para que o valor original seja guardado

    long long int aux, i, j, tam = 0, resto, quo, s, t;
    long long int quocientes[99999]; //Array de quocientes
    long long int quoinvert[99999];  //Array de quo invertido

    e2 = e;   //Cópia recebe o valor passado
    fi2 = fi; //Cópia recebe o valor passado

    resto = e2 % fi2; //Calcula o resto

    //------------ Preenchendo o array com quocientes
    for (i = 0; resto != 0; i++)
    {
        quo = e2 / fi2;
        quocientes[i] = quo;
        tam++; //Tamanho da lista

        resto = e2 % fi2;
        e2 = fi2; //e2 é mdc
        fi2 = resto;
    }

    //------------ Inverter

    for (i = tam - 2, j = 0; i >= 0; i--, j++) //tam-2 porque o último elemento da lista foi ignorado
    {
        quoinvert[j] = quocientes[i];
    }

    //------------ Elementos da nova lista

    long long int novalista[tam];

    novalista[0] = 1; //apesar de não fazer parte da nova lista, esse número será utilizado nos cálculos

    novalista[1] = quoinvert[0];

    //novalista[0] * quoinvert[0] = quoinvert[0]

    for (i = 2; i <= tam; i++)
    {
        novalista[i] = (quoinvert[i - 1] * novalista[i - 1]) + novalista[i - 2];
    }

    if ((tam - 1) % 2 != 0) //Se tam-1 for ímpar, o último elemento será negativo
    {
        novalista[tam - 1] *= -1;
    }
    else //Se tam-1 for par, o penúltimo elemento será negativo
    {
        novalista[tam - 2] *= -1;
    }

    //------------ Coeficientes "s" e "t"

    if (abs(novalista[tam - 1]) >= abs(novalista[tam - 2])) //Para que o valor de s seja o menor em módulo
    {
        t = novalista[tam - 1];
        s = novalista[tam - 2];
    }
    else
    {
        t = novalista[tam - 2];
        s = novalista[tam - 1];
    }

    if (abs(e) < abs(fi)) //Caso "e" seja o menor número, há uma troca entre s e t para que o maior coeficiente o acompanhe, mas permaneça sendo entitulado como "s"
    {
        aux = s;
        s = t;
        t = aux;
    }

    while (s < 0) //Para estar dentro do anel
    {
        s += fi;
    }

    return s; //Retorna o inverso
}

long long int exp_rapido(int m, int e, int n) // Calcula a exponenciação rápida de cada elemento doa array
{
    if (e == 0)
        return 1; //Retorno da recursividade
    else
    {
        long long res = exp_rapido(m, e / 2, n); //Recursividade
        res = (res * res) % n;                   //Calculo da potência após sair da chamada recursiva
        if (e % 2 == 1)
            res = (res * m) % n; // Calcula o resto após a chamada recursiva
        return (int)res;         //Retorna o resto
    }
}

void convert(char *mensagem, int *mensagemcon) // Converta a string da mensagem em inteiros de acordo com dicionário proposto
{
    int tam, i, j;

    tam = strlen(mensagem); //Verifica o tamanho da string

    for (i = 0; i < tam - 1; i++)
    {
        for (j = 2; j <= 30; j++)
        {
            if (toupper(mensagem[i]) == DICIONARIO[j]) //Compara a letra (tanto maiuscula como minuscula) com a string DICIONARIO
            {
                mensagemcon[i] = j; //Recebe o indice da letra na string DICIONARIO
                break;
            }
        }
    }
}

void chavepublica(void) // Função para gerar chave pública
{
    long long int p = 1, q = 1, e, n, fi;

    int fiprimo[10]; //Array para armazenar as sugestões de coprimos de fi

    int i;

    while (e_primo(p) == 0 || e_primo(q) == 0 || p * q < 27) //Loop necessário para garantir que os números são primos
    {
        printf("Por favor, digite um par de números primos (quanto maior os números, maior a segurança):\n");

        scanf("%lld%lld", &p, &q); //Escaneia os primos

        system("clear"); //Limpa o terminal

        if (e_primo(p) == 0 && e_primo(q) == 0) //Verifica se p  e q digitado não é primo
        {
            printf("Nenhum dos dois números digitados é um primo! Tente novamente.\n");
        }
        else if (e_primo(p) == 0) //Verifica se p digitado não é primo
        {
            printf("O primeiro número digitado não é um primo! Tente novamente.\n");
        }
        else if (e_primo(q) == 0) //Verifica se q digitado não é primo
        {
            printf("O segundo número digitado não é um primo! Tente novamente.\n");
        }
        else if (p * q < 27) //Verifica se o produto dos dois primos é maior que 27 (necessário devido o tamanho do alfabeto)
        {
            printf("Por favor, digite primos maiores, tal que p * q > 27!\n");
        }
    }

    n = p * q; // Calcula n

    fi = (p - 1) * (q - 1); // Calcula a função totiente (fi de Euler)

    sugprimo(fi, fiprimo); // Chama a função para sugerir coprimos

    printf("Agora, digite um expoente 'e', que seja co-primo a fi (%lld). Sugestões:\n", fi);

    for (i = 0; i < 10; i++) //Imprime sugestões de expeonte e
    {
        printf("%d", fiprimo[i]);
        if (i != 9)
        {
            printf(", ");
        }
    }

    printf("\n\n");

    scanf("%lld", &e); //Le o expoente "e" digitado

    FILE *pont_pub;                             // Inicia o ponteiro do arquivo da chave pública
    pont_pub = fopen("chave_publica.txt", "w"); // Abre ou cria o arquivo da chave publica com permissão de escrita
    fprintf(pont_pub, "%lld %lld", n, e);       // Grava no arquivo o par de chaves
    fclose(pont_pub);                           // Fecha o arquivo

    system("clear"); //Limpa o terminal

    printf("Chave pública gerada com sucesso e salva no arquivo chave_publica.txt!\n\n");
}

void cript(void) // Passa a string convertida pada ser criptografada
{
    char mensagem[99999];               //Array para armazenar a mensagem lida
    int mensagemcon[99999];             //Array para armazenar a mensagem convertida
    long long int mensagemcript[99999]; //Array para armazenar a mensagem criptografada
    long long int n, e, tam, i;

    printf("Digite a mensagem a ser criptografada:\n");

    buffclear(); //Limpa o buffer de entrada

    fgets(mensagem, 99999, stdin); //Le a mensagem da entrada padrão

    system("clear"); //Limpa o terminal

    convert(mensagem, mensagemcon); //Chama a função de conversão, passando os dois arrays

    tam = strlen(mensagem); //Calcula o tamanho da string

    printf("Por favor, digite a chave pública para criptografar:\n");

    scanf("%lld %lld", &n, &e); //Le a chave publica

    for (i = 0; i < tam - 1; i++)
    {
        mensagemcript[i] = exp_rapido(mensagemcon[i], e, n); //Chama a função de exponenciação modular rápida para cada elemento da string, para criptografar cada caractere
    }

    FILE *out = fopen("msgcriptografada.txt", "w"); // Inicia o ponteiro e abre ou cria o arquivo da mensagem criptografada com permissão de escrita
    for (i = 0; i < tam - 1; i++)
    {
        fprintf(out, "%lld ", mensagemcript[i]); //Imprime cada elemento criptografado no arquivo
    }
    fclose(out); // Fecha o arquivo

    system("clear"); //Limpa o terminal

    printf("Mensagem criptografada com sucesso e salva em msgcriptografada.txt!\n\n");
}

void descript(void) // Passa a mensagem criptografada para ser descriptografada
{
    int i, j = 0, k, p, q, e;
    long long int mensagemc[99999]; //Armazena a mensagem criptografada
    long long int d, fi;

    printf("Digite p:\n");
    scanf("%d", &p); //Le o primeiro numero primo "p"
    system("clear");
    printf("Digite q:\n");
    scanf("%d", &q); //Le o segundo numero primo "q"
    system("clear");
    printf("Digite e:\n");
    scanf("%d", &e); //Le o expoente "e"
    system("clear");

    fi = (p - 1) * (q - 1); //Calcula a função totiente (Fi de Euler)

    d = inversomodular(e, fi); //Chama a função para calcular o inverso modular e o armazena

    FILE *in;                                // Inicia o ponteiro do arquivo da mensagem criptografada
    in = fopen("msgcriptografada.txt", "r"); // Abre o arquivo da mensagem criptografada com permissão de leitura
    while (!feof(in))
    {
        fscanf(in, "%lld", &mensagemc[j]); //Escaneia a mensagem criptografada para o array enquanto o arquivo não acabar
        j++;                               //Contador para saber o tamanho do array
    }
    fclose(in); //Fecha o arquivo da mensagem criptografada

    FILE *out;                        //Inicia o ponteiro do arquivo da mensagem descriptografada
    out = fopen("mensagem.txt", "w"); //Abre ou cria o arquivo da mensagem descriptografada com permissão de escrita

    for (i = 0; i < j - 1; i++)
    {
        long long int r = exp_rapido(mensagemc[i], d, p * q); //Chama a função de exponenciação rápida para descriptografar cada elemento do array
        fprintf(out, "%c", DICIONARIO[r]);                    //Imprime o elemento no arquivo da mensagem descriptografada
    }
    fclose(out); //Fecha o arquivo da mensagem descriptografada

    system("clear"); //Limpa o terminal

    printf("Mensagem descriptografada com sucesso e salva em mensagem.txt!\n\n");
}

int main()
{
    int opcao;

    while (RUN) //Loop para o menu rodar após o término de cada função
    {
        printf("Escolha uma opção:\n1 - Gerar chave pública\n2 - Encriptar\n3 - Desencriptar\n0 - Encerrar\n");
        scanf("%d", &opcao); //Le a opção digitada

        if (opcao == 1)
        {
            system("clear"); //Limpa o terminal
            chavepublica();  //Chama a função de gerar chave pública
        }
        else if (opcao == 2)
        {
            system("clear"); //Limpa o terminal
            cript();         //Chama a função para criptografar
        }
        else if (opcao == 3)
        {
            system("clear"); //Limpa o terminal
            descript();      //Chama a função para descriptografar
        }
        else if (opcao == 0)
        {
            break; //Quebra o loop, encerrando o programa
        }
    }

    return 0;
}