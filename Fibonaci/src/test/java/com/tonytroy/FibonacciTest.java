package com.tonytroy;

import static org.testng.Assert.*;

public class FibonacciTest {
    @org.testng.annotations.Test
    public void testFn3() {
        assertEquals(Fibonacci.calc(3), "[0, 1, 1, 2]");
    }

    @org.testng.annotations.Test
    public void testFn4() {
        assertEquals(Fibonacci.calc(4), "[0, 1, 1, 2, 3]");
    }

    @org.testng.annotations.Test
    public void testFn5() {
        assertEquals(Fibonacci.calc(5), "[0, 1, 1, 2, 3, 5]");
    }

    @org.testng.annotations.Test
    public void testFn10() {
        assertEquals(Fibonacci.calc(10), "[0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55]");
    }
}