#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define RUN 1

int is_prime(int n) // Verifica se o número é primo
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
    int remainder;
    do
    {
        remainder = n1 % n2;

        n1 = n2;
        n2 = remainder;

    } while (remainder != 0);

    return n1;
}

void suggprime(int n, int *primes) // Sugere 10 números coprimos
{
    int i, count = 0;

    for (i = 50; count < 10; i++)
    {
        if (mdc(n, i) == 1)
        {
            primes[count] = i;
            count++;
            i += 17;
        }
    }
}

void keygen() //Função para gerar chave pública
{
    long long int p = 1, q = 1, e, n, fi;
    int fiprime[10];
    int i;

    while (is_prime(p) == 0 || is_prime(q) == 0) //Loop necessário para garantir que os números são primos
    {
        printf("Por favor, digite um par de números primos (quanto maior os números, maior a segurança):\n");
        scanf("%lld%lld", &p, &q);

        if (is_prime(p) == 0 && is_prime(q) == 0) //Verifica se p digitado não é primo
        {
            printf("Nenhum dos dois número digitados é um primo! Tente novamente.\n");
        }
        else if (is_prime(q) == 0) //Verifica se p digitado não é primo
        {
            printf("O segundo número digitado não é um primo! Tente novamente.\n");
        }
        else if (is_prime(p) == 0) //Verifica se ambos não são primos
        {
            printf("O primeiro número digitado não é um primo! Tente novamente.\n");
        }
    }

    n = p * q; // Calcula n

    fi = (p - 1) * (q - 1); // Calcula a função totiente (fi de Euler)

    suggprime(fi, fiprime); // Chama a função para sugerir coprimos

    printf("Agora, digite um expoente e que seja co-primo a fi. Sugestões:\n");

    for (i = 0; i < 10; i++) //Imprime sugestões de expeonte e
    {
        printf("%d", fiprime[i]);
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

int fastexp(int m, int e, int n)
{
    if (e == 0)
        return 1;
    else
    {
        long long res = fastexp(m, e / 2, n);
        res = (res * res) % n;
        if (e % 2 == 1)
            res = (res * m) % n;
        return (int)res;
    }
}

void convert(char *message, long long int *messagecon)
{
    int size, i;
    size = strlen(message);

    for (i = 0; i < size; i++)
    {
        if (toupper(message[i]) == 'A')
        {
            messagecon[i] = 2;
        }
        else if (toupper(message[i]) == 'B')
        {
            messagecon[i] = 3;
        }
        else if (toupper(message[i]) == 'C')
        {
            messagecon[i] = 4;
        }
        else if (toupper(message[i]) == 'D')
        {
            messagecon[i] = 5;
        }
        else if (toupper(message[i]) == 'E')
        {
            messagecon[i] = 6;
        }
        else if (toupper(message[i]) == 'F')
        {
            messagecon[i] = 7;
        }
        else if (toupper(message[i]) == 'G')
        {
            messagecon[i] = 8;
        }
        else if (toupper(message[i]) == 'H')
        {
            messagecon[i] = 9;
        }
        else if (toupper(message[i]) == 'I')
        {
            messagecon[i] = 10;
        }
        else if (toupper(message[i]) == 'J')
        {
            messagecon[i] = 11;
        }
        else if (toupper(message[i]) == 'K')
        {
            messagecon[i] = 12;
        }
        else if (toupper(message[i]) == 'L')
        {
            messagecon[i] = 13;
        }
        else if (toupper(message[i]) == 'M')
        {
            messagecon[i] = 14;
        }
        else if (toupper(message[i]) == 'N')
        {
            messagecon[i] = 15;
        }
        else if (toupper(message[i]) == 'O')
        {
            messagecon[i] = 16;
        }
        else if (toupper(message[i]) == 'P')
        {
            messagecon[i] = 17;
        }
        else if (toupper(message[i]) == 'Q')
        {
            messagecon[i] = 18;
        }
        else if (toupper(message[i]) == 'R')
        {
            messagecon[i] = 19;
        }
        else if (toupper(message[i]) == 'S')
        {
            messagecon[i] = 20;
        }
        else if (toupper(message[i]) == 'T')
        {
            messagecon[i] = 21;
        }
        else if (toupper(message[i]) == 'U')
        {
            messagecon[i] = 22;
        }
        else if (toupper(message[i]) == 'V')
        {
            messagecon[i] = 23;
        }
        else if (toupper(message[i]) == 'W')
        {
            messagecon[i] = 24;
        }
        else if (toupper(message[i]) == 'X')
        {
            messagecon[i] = 25;
        }
        else if (toupper(message[i]) == 'Y')
        {
            messagecon[i] = 26;
        }
        else if (toupper(message[i]) == 'Z')
        {
            messagecon[i] = 27;
        }
        else if (toupper(message[i]) == ' ')
        {
            messagecon[i] = 28;
        }
    }
}

void crypt()
{
    char message[99999];
    long long int messagecon[99999], messagecrypt[99999];
    long long int n, e, size, i;

    printf("Digite a mensagem a ser criptografada:\n");

    getchar();

    fgets(message, 99999, stdin);

    convert(message, messagecon);

    size = strlen(message);

    printf("Por favor, digite a chave pública para criptografar:\n");

    scanf("%lld %lld", &n, &e);

    for (i = 0; i < size - 1; i++)
    {
        messagecrypt[i] = fastexp(messagecon[i], e, n);
    }

    FILE *out = fopen("msgcriptografada.txt", "w");
    for (i = 0; i < size - 1; i++)
    {
        fprintf(out, "%lld ", messagecrypt[i]);
    }

    fclose(out);
}

int decrypt()
{
}

int main()
{
    int option;

    while (RUN)
    {
        printf("Escolha uma opção:\n1 - Gerar chave pública\n2 - Encriptar\n3 - Desencriptar\n0 - Encerrar\n");
        scanf("%d", &option);

        if (option == 1)
        {
            keygen();
        }
        else if (option == 2)
        {
            crypt();
        }
        else if (option == 3)
        {
            decrypt();
        }
        else if (option == 0)
        {
            break;
        }
    }

    return 0;
}