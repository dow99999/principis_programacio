def triangular_superior(matriz, pasos = False):
    # if len(matriz) != len(matriz[0]): return "E"

    for i in range(0, len(matriz) - 1):
        for j in range(i + 1, len(matriz)):
            head_n = matriz[i][i]
            current_n = matriz[j][i]
            if head_n == 0 or current_n == 0: continue

            for k in range(len(matriz[j])):
                matriz[j][k] = (head_n * matriz[j][k]) - (current_n * matriz[i][k])

        if pasos:
            printm(matriz)
            print("-------------------------------")


def triangular_inferior(matriz, pasos = False):
    # if len(matriz) != len(matriz[0]): return "E"

    for i in range(len(matriz) - 1, -1, -1):
        for j in range(i - 1, -1, -1):
            head_n = matriz[i][i]
            current_n = matriz[j][i]
            if head_n == 0 or current_n == 0: continue

            for k in range(len(matriz[j])):
                matriz[j][k] = (head_n * matriz[j][k]) - (current_n * matriz[i][k])

        if pasos:
            printm(matriz)
            print("------------------------------------------------------")

def normalitzar_diagonal(matriz, forzar_enteros=False):
    for i in range(len(matriz)):
        div = matriz[i][i]
        if div == 0: continue

        for j in range(len(matriz[i])):
            matriz[i][j] /= div
            if forzar_enteros:
                matriz[i][j] = int(matriz[i][j])
            
            if matriz[i][j] == 0: 
                matriz[i][j] = 0

def printm(m):
    for f in m:
        for c in f:
            print("\t", c, sep="", end="")
        print()







d1 = [
    [1,-2,3,-4,4],
    [0,1,-1,1,-3],
    [1,3,0,-3,1],
    [0,-7,3,1,-3]
]

triangular_superior(d1, True)
triangular_inferior(d1, True)
normalitzar_diagonal(d1, forzar_enteros=True)

printm(d1)
