# md-rsa
Repositório para o projeto final da disciplina de Matemática Discreta sobre criptografia RSA.

Membros do grupo:
-Eduardo Araujo de Barros, Enderson, Kleber, Rebeca, Ullyanne Julia Freire Patriota.

Professor: Lucas Amorim 
Data de entrega/apresentação: 10/02 a 17/02

Informações gerais:
• Projeto a ser realizado por equipes de até cinco pessoas. Todos os membros deverão participar ativamente da elaboração e apresentação do projeto.
• Atenção: O aluno que ainda não pagou Programação 01 poderá contribuir com a parte teórica, explicações matemáticas, que serão fundamentais para elaboração e apresentação do projeto.
• Data de definição das equipes: 27/01/2020 (enviar e-mail para lucas@ic.ufal.br)
• Data de entrega e apresentação do projeto para todas as equipes: 10/02 a 17/02 (ordem das equipes
definida por sorteio)

Requisitos do projeto sobre Criptografia RSA: Desenvolver um programa numa linguagem de programação à escolha da equipe que realize a seguinte tarefa:
- Solicite que o usuário escolha entre 3 opções: 1 - Gerar chave pública, 2 - Criptografar, 3 - Descriptografar.

- Caso escolhida a opção 1 - Gerar chave pública:
- Solicite que o usuário digite um par de números primos p e q e um expoente e relativamente primo a (p - 1)(q- 1).
- Salve, no diretório de execução do programa, um arquivo txt com os dois números que formam a chave pública.

- Caso escolhida a opção 2 - Criptografar:
- Solicite que o usuário digite a mensagem de texto a encriptar.
- Solicite que o usuário digite a chave pública recebida previamente.
- Salve, no diretório de execução do programa, um arquivo txt com a mensagem criptografada.

- Caso escolhida a opção 3 - Descriptografar:
- Solicite que o usuário digite p, q e e.
- Salve, no diretório de execução do programa, um arquivo txt com a mensagem desencriptada.

Obs1.: A mensagem deve ser criptografada usando o alfabeto de letras A - Z, codificado com inteiros de 2 a 28, onde 2 = A, 1 = B, ..., 27 = Z, 28 = espaço (para facilitar).
Obs2.: Os programas apresentados serão testados da seguinte forma: Uma primeira equipe fornecerá uma chave pública para uma segunda equipe, que criará uma mensagem e a encriptará com a chave fornecida pela primeira equipe. Em seguida, a segunda equipe entregará a mensagem criptografada para a primeira equipe (via e-mail ou pendrive) que terá que realizar a desencriptação sem quaisquer problemas. Em seguida, o processo inverso será testado (a segunda equipe recebe a mensagem).

Critérios de Avaliação:
1. Uso e entendimento correto dos conceitos matemáticos envolvidos (30%);
2. Organização do programa (20%);
3. Eficácia do programa: Funcionamento correto no teste final, descrito na Obs2 (25%);
4. Apresentação: Didática e clareza na explicação, demonstração de domínio do assunto, e etc (25%).
