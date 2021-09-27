
using System;

namespace punto1_sistemas
{
    class IntArray
    {
        int[] arr; //heap

        public IntArray()
        {
            //aca se define el tamaño del array.
            Console.WriteLine("¿cual es el tamaño del arreglo?");
            int size = Convert.ToInt32(Console.ReadLine()); //stack   50
            arr = new int[size]; //heap
            //acá se define los valores de cada una de los enteros de la array, empezando de 0 a size-1.
            for(int i = 0; i < size; i++)//stack [i]
            {
                arr[i] = i;//stack
            }
        }

        public void printArray()
        {
            //con esta funcion se muestra en la consola todas las posiciones y su contenido de la array.
            for(int i = 0; i < this.arr.Length; i++)//stack [i]
            {
                Console.WriteLine($"parr[{i}]: {this.arr[i]}");
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            IntArray hola = new IntArray();//heap
            hola.printArray();
            
        }
    }
}
