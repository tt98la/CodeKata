package com.tonytroy.fizzbuzz;

import java.util.Iterator;
import java.util.TreeMap;

/**
 * Created by TT on 10/13/2016.
 */
public class Fizzbuzz {
    private TreeMap<Integer, String> magicNumbers = new TreeMap<>();

    Fizzbuzz(){
        magicNumbers.put(3, "Fizz");
        magicNumbers.put(5, "Buzz");
        magicNumbers.put(15, "FizzBuzz");
    }

    String[] getList(int numEntries){
        String[] fizzbuzzList = new String[numEntries];
        for(Integer i=1; i <= numEntries; i++) {
            fizzbuzzList[i-1] = GetFizzBuzzValue(i);
        }
        return fizzbuzzList;
    }

    private String GetFizzBuzzValue(Integer i) {
        String fizzbuzzValue = i.toString();
        for(int index : magicNumbers.descendingKeySet()) {
            if (i % index == 0){
                fizzbuzzValue = magicNumbers.get(index);
                break;
            }
        }

        return fizzbuzzValue;
    }
}
