from functs import mdc, eucl

x, y, z = input().split()
x, y, z = int(x), int(y), int(z)
a = abs(x)
b = abs(y)
c = abs(z)

collum_q = ['-']
collum_xy = [1]
x_y = []

eucl_result = eucl(a, b)

# montando a table a q | xy

for i in range(len(eucl_result)-2, 0, -1):
    collum_q.append(eucl_result[i])

collum_xy.append(collum_q[1])

for i in range(2, len(collum_q)):
    collum_xy.append(collum_q[i]*collum_xy[i-1]+collum_xy[i-2])

# salvando so resultados x e y

x_y = [collum_xy[-2], collum_xy[-1]]

# Verificando quem é negativo:

if((len(collum_q)-1) % 2 == 0):
    x_y[0] = x_y[0]*(-1)
if((len(collum_q)-1) % 2 != 0):
    x_y[1] = x_y[1]*(-1)

# Verificando se devem ser invertidos

if(eucl_result[0]):
    x_y = [x_y[1], x_y[0]]

# Verificando se é diofontina negativa
if(x < 0):
    x_y[0] = x_y[0]*(-1)
if(y < 0):
    x_y[1] = x_y[1]*(-1)

# Multiplicando por c / mdc (a, b)

x_y[0] = int(x_y[0]*(c/mdc(a, b)))
x_y[1] = int(x_y[1]*(c/mdc(a, b)))

print("Valor de X: {}\nValor de Y: {}".format(x_y[0], x_y[1]))
print('Q -> {}'.format(collum_q))
print('xy -> {}'.format(collum_xy))
print("Equação geral de X ->  x = {} + {}t".format(x_y[0], int(y/mdc(x, y))))
print("Equação geral de Y ->  y = {} + {}t".format(x_y[1], int(x/mdc(x, y))))

