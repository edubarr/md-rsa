#include <stdio.h>
#include <string.h>

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

void convert(char *message, int *messagec)
{
    int size, i;
    size = strlen(message);

    for (i = 0; i < size; i++)
    {
        if (message[i] == 'A')
        {
            messagec[i] = 2;
        }
        else if (message[i] == 'B')
        {
            messagec[i] = 3;
        }
        else if (message[i] == 'C')
        {
            messagec[i] = 4;
        }
        else if (message[i] == 'D')
        {
            messagec[i] = 5;
        }
        else if (message[i] == 'E')
        {
            messagec[i] = 6;
        }
        else if (message[i] == 'F')
        {
            messagec[i] = 7;
        }
        else if (message[i] == 'G')
        {
            messagec[i] = 8;
        }
        else if (message[i] == 'H')
        {
            messagec[i] = 9;
        }
        else if (message[i] == 'I')
        {
            messagec[i] = 10;
        }
        else if (message[i] == 'J')
        {
            messagec[i] = 11;
        }
        else if (message[i] == 'K')
        {
            messagec[i] = 12;
        }
        else if (message[i] == 'L')
        {
            messagec[i] = 13;
        }
        else if (message[i] == 'M')
        {
            messagec[i] = 14;
        }
        else if (message[i] == 'N')
        {
            messagec[i] = 15;
        }
        else if (message[i] == 'O')
        {
            messagec[i] = 16;
        }
        else if (message[i] == 'P')
        {
            messagec[i] = 17;
        }
        else if (message[i] == 'Q')
        {
            messagec[i] = 18;
        }
        else if (message[i] == 'R')
        {
            messagec[i] = 19;
        }
        else if (message[i] == 'S')
        {
            messagec[i] = 20;
        }
        else if (message[i] == 'T')
        {
            messagec[i] = 21;
        }
        else if (message[i] == 'U')
        {
            messagec[i] = 22;
        }
        else if (message[i] == 'V')
        {
            messagec[i] = 23;
        }
        else if (message[i] == 'W')
        {
            messagec[i] = 24;
        }
        else if (message[i] == 'X')
        {
            messagec[i] = 25;
        }
        else if (message[i] == 'Y')
        {
            messagec[i] = 26;
        }
        else if (message[i] == 'Z')
        {
            messagec[i] = 27;
        }
        else if (message[i] == ' ')
        {
            messagec[i] = 28;
        }
    }
}

void crypt()
{
    char message[99999];
    int messagecon[99999], messagecrypt[99999], size, i;
    long long int n, e;
    printf("Digite a mensagem a ser criptografada:\n");

    getchar();

    fgets(message, 99999, stdin);

    convert(message, messagecon);

    size = strlen(message);

    printf("Por favor, digite a chave pública para criptografar:\n");

    //scanf("%lld %lld", n, e);
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