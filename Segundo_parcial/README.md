# Segundo parcial
## Problema 1
### Peso-Altura
**1. Enunciado**

**2. Metodología**

**3. Variables**

**4. Diagrama de flujo**
## Problema 2
### Newton Raphson:
**1. Enunciado:** Utilizando el método de Newton Raphson encontrar una raiz de la ecuación
$$ x^3-2x^2-3x+10 $$
Realizar la gráfica de la ecuación,  comparar el resultado con la respuesta del programa realizado en C.

**2. Metodología**
El método de Newton Raphson es un método númerico para encontrar aproximaciones a los ceros de una función.
Consiste en aplicar las siguintes ecuaciones:
$$ x_{i+1}= x_i-\frac{f(x_i)}{f'(x_i)} $$
Para este caso:
$$ x_{i+1}= x_i-\frac{x_i^3-2x_i^2-3x_i+10}{3x_i^2-4x_i-3}  $$
**3. Variables**

Entrada
 - *xi* variable en la que inicia el método
 - *iteracion* variable que lleva el número de veces que que se puede hacer el metodo para cada xi
 - *tolerancia* distancia o "pasos" entre cada iteración
 - *iteracionA* iteración anterior

Salida
 - *sol* variable que devuelve la solucion del problema

**4. Diagrama de flujo**

**5. Solución**
El problema se resolvió aplicando el método de Newton Raphson donde el valor aproximado de x puede encontrarse mediante la siguiente grafica de la función
![Problema2](newtonraphson.jpg)
En la gráfica se ve que la raiz es -2 y por ser un número exacto el programa nos devuelve ese número exacto. Por lo tanto el programa si encuentra la raiz de la función especificada en el enunciado.
