#include <stdio.h>

#define RUN 1

int is_prime(int n)
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

int mdc(int n1, int n2)
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

void suggprime(int n, int *primes)
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

        if (is_prime(p) == 0) //Verifica se p digitado não é primo
        {
            printf("O primeiro número digitado não é um primo! Tente novamente.\n");
        }
        else if (is_prime(q) == 0) //Verifica se p digitado não é primo
        {
            printf("O segundo número digitado não é um primo! Tente novamente.\n");
        }
        else if (is_prime(p) == 0 && is_prime(q) == 0) //Verifica se ambos não são primos
        {
            printf("Nenhum dos dois número digitados é um primo! Tente novamente.\n");
        }
    }

    n = p * q; //Calcula n;

    fi = (p - 1) * (q - 1); //Calcula a função totiente (fi de Euler);

    suggprime(fi, fiprime);

    printf("Agora, digite um expoente e que seja co-primo a fi. Sugestões:\n");

    for (i = 0; i < 10; i++) //Imprime sugestões de expeonte e;
    {
        printf("%d", fiprime[i]);
        if (i != 9)
        {
            printf(", ");
        }
    }

    printf("\n\n");

    scanf("%lld", &e);

    FILE *pont_pub;
    pont_pub = fopen("chave_publica.txt", "w");
    fprintf(pont_pub, "%lld %lld", n, e);
    fclose(pont_pub);

    printf("Chave pública gerada com sucesso e salva no arquivo chave_publica.txt!\n\n");
}

int crypt()
{
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