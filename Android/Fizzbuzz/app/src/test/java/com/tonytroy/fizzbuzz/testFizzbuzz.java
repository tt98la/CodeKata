package com.tonytroy.fizzbuzz;

import org.junit.Before;
import org.junit.Test;

import java.util.TreeMap;

import static org.junit.Assert.*;

/**
 * Example local unit test, which will execute on the development machine (host).
 *
 * @see <a href="http://d.android.com/tools/testing">Testing documentation</a>
 */
public class testFizzbuzz {
    public static final int NUM_ENTRIES = 100;
    private TreeMap<Integer, String> magicNumbers = new TreeMap<>();

    @Before
    public void setUp (){
        magicNumbers.put(3, "Fizz");
        magicNumbers.put(5, "Buzz");
        magicNumbers.put(15, "FizzBuzz");
    }

    @Test
    public void test_sequence() throws Exception {
        Fizzbuzz fizzbuzz = new Fizzbuzz();
        String[] expectedList = {"1", "2", "Fizz", "4", "Buzz", "Fizz", "7", "8", "Fizz", "Buzz", "11", "Fizz", "13", "14", "FizzBuzz"};
        assertArrayEquals(expectedList, fizzbuzz.getList(15));
    }

    @Test
    public void test_3isFizz() throws Exception {
        assert_fizzBuzz(3, NUM_ENTRIES);
    }

    @Test
    public void test_5isBuzz() throws Exception {
        assert_fizzBuzz(5, NUM_ENTRIES);
    }

    @Test
    public void test_15isFizzbuzz() throws Exception {
        assert_fizzBuzz(15, NUM_ENTRIES);
    }

    @Test
    public void test_20isBuzzFizz() throws Exception {
        assert_fizzBuzz(20, NUM_ENTRIES);
    }

    public void assert_fizzBuzz(int fizzbuzzNumber, int numEntries) throws Exception {
        Fizzbuzz fizzbuzz = new Fizzbuzz();
        String[] fizzbuzzList = fizzbuzz.getList(numEntries);
        for(int i = fizzbuzzNumber; i < numEntries; i += fizzbuzzNumber)
            if(!isNumberDividableByOtherMagicNumbers(i, fizzbuzzNumber))
                assertEquals(magicNumbers.get(fizzbuzzNumber), fizzbuzzList[i-1]);
    }

    public boolean isNumberDividableByOtherMagicNumbers(int number, int currentMagicNumber) {
        for (int index : magicNumbers.keySet()) {
            if (index != currentMagicNumber && number % index == 0)
                return true;
        }

        return false;
    }
}