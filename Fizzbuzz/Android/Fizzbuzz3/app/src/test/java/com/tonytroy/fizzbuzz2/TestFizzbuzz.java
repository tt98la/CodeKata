package com.tonytroy.fizzbuzz2;

import org.junit.Test;

import static org.junit.Assert.*;

/**
 * To work on unit tests, switch the Test Artifact in the Build Variants view.
 */
public class TestFizzbuzz {

    public static final int LIST_SIZE = 100;

    @Test
    public void test_sequence() throws Exception {
        String[] expected = {"1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"};
        Fizzbuzz fizzbuzz = new Fizzbuzz();
        String[] fizzbuzzList = fizzbuzz.getList(expected.length);
        assertArrayEquals(expected, fizzbuzzList);
    }

    @Test
    public void test_three_is_fizz() throws Exception {
        String expected = "Fizz";
        Fizzbuzz fizzbuzz = new Fizzbuzz();
        String [] fizzbuzzList = fizzbuzz.getList(LIST_SIZE);
        for(int i = 0; i < LIST_SIZE; i++)
            if (i % 3 == 0) assertSame(expected, fizzbuzzList[i]);
    }
}