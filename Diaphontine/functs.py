def mdc(x, y):
  if(x>=y):
    for num in range(x, 0, -1):
      if(x % num == 0 and y % num == 0):
        return num
  if(y>x):
    for num in range(y, 0, -1):
      if(x % num == 0 and y % num == 0):
        return num

def eucl(x, y):

  resto = 1
  resultados = []
  is_inverted = False
  maior = x
  menor = y
  

  if(x < y):
    maior = y
    menor = x
    is_inverted = True  

  resultados.append(is_inverted)
  
  while(resto != 0):
    resultados.append(int(maior/menor))
    resto = maior % menor
    maior=menor
    menor=resto
  return resultados
