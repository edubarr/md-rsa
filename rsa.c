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

int mdc(int n1, int n2) // Calcula o MDC de dois números
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

long long int inversomodular(long long int e, long long int fi)
{
    long long int e2, fi2; 
    //cópias de "e" e "fi" para que o valor original seja guardado

    long long int aux, i, j, tam = 0, resto, quo, s, t;
    long long int quocientes[99999]; //array de quocientes
    long long int quoinvert[99999]; //array de quo invertido
    
    e2 = e;
    fi2 = fi;
    
    resto = e2%fi2;

//------------ preenchendo o array com quocientes
    for(i = 0; resto!= 0; i++)
    {
        quo = e2/fi2;
        quocientes[i] = quo;
        tam++; //tamanho da lista

        resto = e2%fi2;
        e2 = fi2; //e2 é mdc
        fi2 = resto;
    }
   
//------------ inverter
    //tam-2 porque o último elemento da lista foi ignorado

    for( i = tam-2, j = 0; i >= 0; i--, j++)
    {
        quoinvert[j] = quocientes[i];
    }

//------------ elementos da nova lista

    long long int novalista[tam]; 
   
    novalista[0] = 1; 
    //apesar de não fazer parte da nova lista, 
    //esse número será utilizado nos cálculos

    novalista[1] = quoinvert[0]; //novalista[0] * quoinvert[0] = quoinvert[0]

    for(i = 2; i <= tam; i++)
    {
        novalista[i] = (quoinvert[i-1] * novalista[i-1]) + novalista[i-2];
    }

    //se tam-1 for ímpar, o último elemento será negativo
    if( (tam-1) % 2 != 0 )
    {
        novalista[tam-1] *= -1;
    }
    //se tam-1 for par, o penúltimo elemento será negativo
    else 
    {
        novalista[tam-2] *= -1;
    }

//------------ coeficientes "s" e "t"
    //para que o valor de s seja o menor em módulo:
    if( abs(novalista[tam-1]) >= abs(novalista[tam-2]) )
    {
        t = novalista[tam-1];
        s = novalista[tam-2];
    }
    else
    {
        t = novalista[tam-2];
        s = novalista[tam-1];
    }
    
    //caso "e" seja o menor número, há uma troca entre s e t
    //para que o maior coeficiente o acompanhe, mas permaneça 
    //sendo intitulado como "s"
    if(abs(e) < abs(fi))
    {
        aux = s;
        s = t;
        t = aux;

    }

    //para estar dentro do anel
    while(s < 0)
    {
        s += fi;
    }

    printf("%lld = (%lld) * %lld + (%lld) * %lld\n", e2, s, e, t, fi);

    printf("%lld\n", s);

    return s;
}

long long int exp_rapido(int m, int e, int n) // Calcula a exponenciação rápida de cada elemento doa array
{
    if (e == 0)
        return 1;
    else
    {
        long long res = exp_rapido(m, e / 2, n);
        res = (res * res) % n;
        if (e % 2 == 1)
            res = (res * m) % n;
        return (int)res;
    }
}

void convert(char *mensagem, int *mensagemcon) // Converta a string da mensagem em inteiros de acordo com dicionário proposto
{
    int tam, i, j;
    tam = strlen(mensagem);

    for (i = 0; i < tam - 1; i++)
    {
        for (j = 2; j <= 30; j++)
        {
            if (toupper(mensagem[i]) == DICIONARIO[j])
            {
                mensagemcon[i] = j;
                break;
            }
        }
    }
}

void chavepublica(void) // Função para gerar chave pública
{
    long long int p = 1, q = 1, e, n, fi;
    int fiprimo[10];
    int i;

    while (e_primo(p) == 0 || e_primo(q) == 0 || p * q < 27) //Loop necessário para garantir que os números são primos
    {
        printf("Por favor, digite um par de números primos (quanto maior os números, maior a segurança):\n");
        scanf("%lld%lld", &p, &q);
        system("clear");

        if (e_primo(p) == 0 && e_primo(q) == 0) //Verifica se p  e q digitado não é primo
        {
            printf("Nenhum dos dois números digitados é um primo! Tente novamente.\n");
        }
        else if (e_primo(q) == 0) //Verifica se p digitado não é primo
        {
            printf("O segundo número digitado não é um primo! Tente novamente.\n");
        }
        else if (e_primo(p) == 0) //Verifica se ambos não são primos
        {
            printf("O primeiro número digitado não é um primo! Tente novamente.\n");
        }
        else if (p * q < 27)
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

    scanf("%lld", &e);

    FILE *pont_pub;                             // Inicia o ponteiro do arquivo da chave pública
    pont_pub = fopen("chave_publica.txt", "w"); // Abre ou cria o arquivo da chave publica
    fprintf(pont_pub, "%lld %lld", n, e);       // Grava no arquivo o par de chaves
    fclose(pont_pub);                           // Fecha o arquivo

    printf("Chave pública gerada com sucesso e salva no arquivo chave_publica.txt!\n\n");
}

void cript(void) // Passa a string convertida pada ser criptografada
{
    char mensagem[99999];
    int mensagemcon[99999];
    long long int mensagemcript[99999];
    long long int n, e, tam, i;

    printf("Digite a mensagem a ser criptografada:\n");

    buffclear();

    fgets(mensagem, 99999, stdin);

    convert(mensagem, mensagemcon);

    tam = strlen(mensagem);

    printf("Por favor, digite a chave pública para criptografar:\n");

    scanf("%lld %lld", &n, &e);

    for (i = 0; i < tam - 1; i++)
    {
        mensagemcript[i] = exp_rapido(mensagemcon[i], e, n);
    }

    FILE *out = fopen("msgcriptografada.txt", "w");
    for (i = 0; i < tam - 1; i++)
    {
        fprintf(out, "%lld ", mensagemcript[i]);
    }
    fclose(out);

    system("clear");

    printf("Mensagem criptografada com sucesso e salva em msgcriptografada.txt\n\n");
}

void descript(void) // Passa a mensagem criptografada para ser descriptografada
{
    int i, j = 0, k, p, q, e;
    long long int mensagemc[99999], d, fi;

    printf("Digite p:\n");
    scanf("%d", &p);
    printf("Digite q:\n");
    scanf("%d", &q);
    printf("Digite e:\n");
    scanf("%d", &e);

    fi = (p - 1) * (q - 1);

    d = inversomodular(e, fi);

    FILE *in;
    in = fopen("msgcriptografada.txt", "r");
    while (!feof(in))
    {
        fscanf(in, "%lld", &mensagemc[j]);
        j++;
    }
    fclose(in);

    FILE *out;
    out = fopen("mensagem.txt", "w");

    for (i = 0; i < j - 1; i++)
    {
        long long int r = exp_rapido(mensagemc[i], d, p * q);
        fprintf(out, "%c", DICIONARIO[r]);
    }
    fclose(out);

    system("clear");

    printf("Mensagem descriptografada com sucesso e salva em mensagem.txt\n\n");
}

int main()
{
    int opcao;

    while (RUN)
    {
        printf("Escolha uma opção:\n1 - Gerar chave pública\n2 - Encriptar\n3 - Desencriptar\n0 - Encerrar\n");
        scanf("%d", &opcao);

        if (opcao == 1)
        {
            chavepublica();
        }
        else if (opcao == 2)
        {
            cript();
        }
        else if (opcao == 3)
        {
            descript();
        }
        else if (opcao == 0)
        {
            break;
        }
    }

    return 0;
}
