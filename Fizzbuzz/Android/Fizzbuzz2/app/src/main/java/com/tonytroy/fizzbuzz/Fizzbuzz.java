package com.tonytroy.fizzbuzz;

import java.util.TreeMap;

/**
 * Created by TT on 4/14/2016.
 */
public class Fizzbuzz {
    public TreeMap<Integer, String> magicNumbersMap;

    public Fizzbuzz() {
        magicNumbersMap = new TreeMap<>();
        magicNumbersMap.put(3, "fizz");
        magicNumbersMap.put(5, "buzz");
        magicNumbersMap.put(15, "fizzbuzz");
    }

    public String[] Create(int listSize) {
        String[] FizzBuzzList = new String[listSize + 1];
        for(int i=0; i <= listSize; i++){
            FizzBuzzList[i] = GetFizzBuzzValue(i);
        }

        return FizzBuzzList;
    }

    private String GetFizzBuzzValue(int intValue) {
        String fizzBuzzValue = String.format("%d", intValue);

        for (int magicNumber : magicNumbersMap.descendingKeySet()) {
            if (intValue % magicNumber == 0) {
                fizzBuzzValue = magicNumbersMap.get(magicNumber);
                break;
            }
        }

        return fizzBuzzValue;
    }
}
