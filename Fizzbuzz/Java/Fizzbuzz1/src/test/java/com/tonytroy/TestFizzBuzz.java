package com.tonytroy;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class TestFizzBuzz {
    @Test
    public void testBasicSequence(){
        assertEquals( "1,2,Fizz,4,Buzz,Fizz,7,8,Fizz,Buzz,11,Fizz,13,14,FizzBuzz", Fizzbuzz.fizzbuzz(15));
    }

    @Test
    public void testMultiples(){
        assertTrue(Fizzbuzz.fizzbuzz(30).contains("Buzz,26,Fizz,28,29,FizzBuzz"));
    }

}