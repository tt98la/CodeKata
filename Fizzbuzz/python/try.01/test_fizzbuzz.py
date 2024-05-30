import unittest
import fizzbuzz

class TestFizzBuzz(unittest.TestCase):
    def testGen(self):
        self.assertEqual(1, fizzbuzz.fizzbuzz_gen(1))
        self.assertEqual(2, fizzbuzz.fizzbuzz_gen(2))
        self.assertEqual('fizz', fizzbuzz.fizzbuzz_gen(3))
        self.assertEqual(4, fizzbuzz.fizzbuzz_gen(4))
        self.assertEqual('buzz', fizzbuzz.fizzbuzz_gen(5))
        self.assertEqual('fizz', fizzbuzz.fizzbuzz_gen(6))
        self.assertEqual(7, fizzbuzz.fizzbuzz_gen(7))
        self.assertEqual('fizz', fizzbuzz.fizzbuzz_gen(9))
        self.assertEqual('buzz', fizzbuzz.fizzbuzz_gen(10))
        self.assertEqual('fizzbuzz', fizzbuzz.fizzbuzz_gen(15))
        self.assertEqual('buzz', fizzbuzz.fizzbuzz_gen(20))
        self.assertEqual('fizzbuzz', fizzbuzz.fizzbuzz_gen(30))
        self.assertEqual('fizzbuzz', fizzbuzz.fizzbuzz_gen(60))

        fizzbuzz_list = fizzbuzz.fizzbuzz(100)
        for i in range(1, len(fizzbuzz_list) + 1):
            self.assertEqual(fizzbuzz.fizzbuzz_gen(i), fizzbuzz_list[i-1])
            #if i % 3 == 0 and i % 5 == 0:
            #    self.assertEqual('fizzbuzz', fizzbuzz_list[i-1])
            #elif i % 3 == 0:
            #    self.assertEqual('fizz', fizzbuzz_list[i-1])
            #elif i % 5 == 0:
            #    self.assertEqual('buzz', fizzbuzz_list[i-1])
            #else:
            #    self.assertEqual(i, fizzbuzz_list[i-1])
                
def run_tests():
    test_suite = unittest.TestLoader().loadTestsFromTestCase(TestFizzBuzz)
    unittest.TextTestRunner(verbosity=2).run(test_suite)

if __name__ == '__main__':
    run_tests()