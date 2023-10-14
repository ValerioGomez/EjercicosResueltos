package com.valeriogomez.ejercicio3213;
/**
 *Ejercicio3213
 * @author vales
 */
import java.util.Arrays;

public class Ejercicio3213 {
    static int count = 0;

    public static void main(String[] args) {
        int n = 4; // Cambia el valor de 'n' según el número de objetos a permutar
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = i + 1; // Crear un arreglo de objetos ordenados del 1 al 'n'
        }
        generatePermutations(arr, 0, n);
        System.out.println("Total de permutaciones: " + count);
    }

    public static void generatePermutations(int[] arr, int currentIndex, int n) {
        if (currentIndex == n) {
            count++;
            System.out.printf("Permutación %02d: %s%n", count, Arrays.toString(arr)); // Imprimir la permutación actual
            return;
        }

        for (int i = currentIndex; i < n; i++) {
            swap(arr, currentIndex, i); // Intercambiar elementos
            generatePermutations(arr, currentIndex + 1, n); // Llamar recursivamente
            swap(arr, currentIndex, i); // Restablecer el arreglo
        }
    }

    public static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
