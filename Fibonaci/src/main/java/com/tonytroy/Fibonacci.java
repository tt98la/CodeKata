package com.tonytroy;

import java.util.ArrayList;

public class Fibonacci {
    public static String calc(int size) {
        ArrayList<Integer> fibNumbers = new ArrayList<>(size+1);
        fibNumbers.add(0);
        for (int i = 1; i <= size; i++) {
            if (i < 2) fibNumbers.add(i);
            else fibNumbers.add(fibNumbers.get(i - 1) + fibNumbers.get(i - 2));
        }

        return fibNumbers.toString();
    }
}