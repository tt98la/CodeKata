package com.tonytroy.fizzbuzz;

import org.junit.Test;

import static org.junit.Assert.*;

/**
 * To work on unit tests, switch the Test Artifact in the Build Variants view.
 */
public class TestFizzbuzz {
    private Fizzbuzz fizzbuzz;

    public TestFizzbuzz() {
        fizzbuzz = new Fizzbuzz();
    }

    @Test
    public void TestSequence() throws Exception {
        String[] expected = {"0","1", "2","fizz","4","buzz","fizz","7","8","fizz","buzz","11","fizz","13","14","fizzbuzz"};
        assertArrayEquals(expected, fizzbuzz.Create(expected.length));
    }

    @Test
    public void Test3IsFizz() throws Exception {
        int listSize = 100;
        String[] fizzBuzzList = fizzbuzz.Create(listSize);

        for(int i=3; i <= listSize; i+=3) {
            if(i % 5 != 0)
                assertEquals("fizz", fizzBuzzList[i]);
        }
    }

    @Test
    public void Test5IsBuzz() throws Exception {
        int listSize = 100;
        String[] fizzBuzzList = fizzbuzz.Create(listSize);

        for(int i=5; i <= listSize; i+=5) {
            if(i % 3 != 0)
                assertEquals("buzz", fizzBuzzList[i]);
        }
    }

    @Test
    public void Test15IsFizzBuzz() throws Exception {
        int listSize = 100;
        String[] fizzBuzzList = fizzbuzz.Create(listSize);

        for(int i=15; i <= listSize; i+=15) {
            assertEquals("fizzbuzz", fizzBuzzList[i]);
        }
    }
}