package com.tonytroy;

import java.util.*;

public class Fizzbuzz {

    private static TreeMap<Integer, String> magicNumbers;

    public static String fizzbuzz(int size) {
        init();

        StringBuilder fizzbuzzNumbers = new StringBuilder();
        for(int i = 1; i <= size; i++){
            boolean isMagicNumber = false;
            for (int magicNumber : magicNumbers.descendingKeySet()) {
                if (i % magicNumber == 0) {
                    fizzbuzzNumbers.append(magicNumbers.get(magicNumber));
                    isMagicNumber = true;
                    break;
                }
            }

            if (!isMagicNumber)
                fizzbuzzNumbers.append(i);

            if (i < size) fizzbuzzNumbers.append(",");
        }

        return fizzbuzzNumbers.toString();
    }

    private static void init() {
        magicNumbers = new TreeMap<>();
        magicNumbers.put(15, "FizzBuzz");
        magicNumbers.put(5, "Buzz");
        magicNumbers.put(3, "Fizz");
    }
}