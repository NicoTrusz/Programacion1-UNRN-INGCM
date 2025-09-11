/* 
 * Ejercicio 2.3
 * Autor: Nicolás Trusz
 * Usuario GitHub: nicotrusz
 */

 /* REFERENCIA PARA EJERCICIO ECHO EN CLASE CON EL PROFESOR DANIEL
Ordenar de mayor a menor

[4,6,87,9,0]

buscar_mayor (desde el 0) -> 87, pos 2
intercambiar pos 0 con pos 2

[87,6,4,9,0]

buscar_mayor (desde el 1) -> 9, pos 3
intercambiar pos 1 con pos 3

[87,9,4,6,0]

buscar_mayor(arr,n,pos_inicio)

    max_valor = arr[pos_inicio]
    pos_max = pos_inicio

    para los indices (i) de pos_inicio a (n-1)
        si arr[i]>max_valor
            max_valor = arr[i]
            pos_max = i 
    
    devolver pos_max


ordenamiento(arr,n)
    para los indices (i) de 0 a n-1
        posicion_mayor = buscar_mayor (desde la posición i)
        intercambiar (posición_mayor, i)

*/