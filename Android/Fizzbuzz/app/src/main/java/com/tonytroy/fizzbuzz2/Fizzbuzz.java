package com.tonytroy.fizzbuzz2;

/**
 * Created by TT on 6/19/2016.
 */
public class Fizzbuzz {

    public String[] getList(int listSize) {
        String[] list = new String[listSize];
        for (int i = 1; i <= listSize; i++) {
            list[i-1] = GetFizzbuzzValue(i);
        }
        return list;
    }

    private String GetFizzbuzzValue(int i) {
        String value = Integer.toString(i);

        if (i % 15 == 0)
            value = "FizzBuzz";
        else if (i % 5 == 0)
            value = "Buzz";
        else if (i % 3 == 0)
            value = "Fizz";

        return value;
    }
}