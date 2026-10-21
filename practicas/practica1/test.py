import sys
from subprocess import Popen, PIPE

TESTS = [
    ["1 -3 2", "Dos soluciones reales: x1 = 2.0000, x2 = 1.0000"],
    ["1 -2 1", "Una solucion doble: x = 1.0000"],
    ["1 2 5", "Complejas: x1 = -1.0000 + 2.0000i, x2 = -1.0000 - 2.0000i"],
    ["1 0 4", "Complejas: x1 = 0.0000 + 2.0000i, x2 = 0.0000 - 2.0000i"],
    ["-1 2 -5", "Complejas: x1 = 1.0000 - 2.0000i, x2 = 1.0000 + 2.0000i"],
    ["2 2 1", "Complejas: x1 = -0.5000 + 0.5000i, x2 = -0.5000 - 0.5000i"],
    ["2 3 1", "Dos soluciones reales: x1 = -0.5000, x2 = -1.0000"],
    ["4 4 1", "Una solucion doble: x = -0.5000"],
    ["0 2 -4", "Ecuacion lineal: x = 2.0000"],
    ["0 2 3", "Ecuacion lineal: x = -1.5000"],
    ["0 0 0", "Infinitas soluciones"],
    ["0 0 5", "Sin solucion"],
    ["2 0 -8", "Dos soluciones reales: x1 = 2.0000, x2 = -2.0000"],
    ["1 0 0", "Una solucion doble: x = 0.0000"],
    ["-1 3 0", "Dos soluciones reales: x1 = 0.0000, x2 = 3.0000"]
]

errores = []

if len(sys.argv) <= 1:
    print("Uso: py test.py <...archivos_a_testear.cpp>")

p = Popen(["g++", *sys.argv[1:], "-Wall", "-Wextra", "-o", "test.exe"], stdin=PIPE, stdout=PIPE, stderr=PIPE, shell=True)
output, error = p.communicate()

for i in range(len(TESTS)):
    test = TESTS[i]
    p = Popen(["test.exe"], stdin=PIPE, stdout=PIPE, stderr=PIPE, shell=True)
    output, error = p.communicate(input=test[0].encode())

    entrada = test[0]
    esalida = test[1]
    salida = output.decode("utf8")
    
    if(salida != esalida):
        errores.append([i, entrada, esalida, salida])


if len(errores) > 0:
    for e in errores:
        print("Entrada:", e[1])
        print("Se esperaba:", e[2])
        print("  Se evalua:", e[3])
        print("---------------------------------------------------------")

print(f"Tests pasados {len(TESTS) - len(errores)}/{len(TESTS)}")

if len(errores) == 0:
    print("Todo bien, oleee!!")