def altera(nome, nota_antiga, nota_nova):
    medias = open("Medias.txt", "r")
    medias2 = open("medias2.txt", "w")
    for texto in medias:
        nome_no_arquivo = ""
        for char in texto:
            if char.isalpha():
                nome_no_arquivo += char
        if nome_no_arquivo == nome:
            medias2.write(substitui(texto, str(nota_antiga), str(nota_nova)) + "\n")
        else:
            medias2.write(texto)



def substitui(f, a, n):
    posicao = len(f)
    f2 = ""
    for i in range(-len(a), -len(f)-1, -1):
        p = ""
        aux = i
        for j in range(aux, aux+len(a), 1):
            p += f[j]
            aux -= 1
        if p == a:
            posicao += i
            break
    cont = 0
    while cont < len(f):
        if cont == posicao:
            for i in range(0, len(n), 1):
                f2 += n[i]
            cont += len(a)-1
        else:
            f2 += f[cont]
        cont += 1
    if f == f2:
        return f
    else:
        return f2


def imprimir():
    medias = open("Medias.txt", "r")
    for texto in medias:
        print(texto)

n = input("Informe o nome do aluno: ")
nota_a = input("Informe a nota antiga: ")
nota_n = input("Informe a nota nova: ")
altera(n, nota_a, nota_n)
