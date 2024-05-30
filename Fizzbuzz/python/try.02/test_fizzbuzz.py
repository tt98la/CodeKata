import unittest
import fizzbuzz

class TestFizzBuzz(unittest.TestCase):
    def test_it(self):
        self.assertEqual(1, fizzbuzz.fizzbuzz_gen(1))
        self.assertEqual(2, fizzbuzz.fizzbuzz_gen(2))
        self.assertEqual('fizz', fizzbuzz.fizzbuzz_gen(3))
        self.assertEqual(4, fizzbuzz.fizzbuzz_gen(4))
        self.assertEqual('buzz', fizzbuzz.fizzbuzz_gen(5))
        self.assertEqual('fizz', fizzbuzz.fizzbuzz_gen(6))
        self.assertEqual('buzz', fizzbuzz.fizzbuzz_gen(10))
        self.assertEqual('fizzbuzz', fizzbuzz.fizzbuzz_gen(15))

        self.assertEqual([1], fizzbuzz.fizzbuzz(1))
        self.assertEqual([1,2], fizzbuzz.fizzbuzz(2))
        self.assertEqual([1,2,'fizz'], fizzbuzz.fizzbuzz(3))
        self.assertEqual([1,2,'fizz',4], fizzbuzz.fizzbuzz(4))
        self.assertEqual([1,2,'fizz',4,'buzz'], fizzbuzz.fizzbuzz(5))
        self.assertEqual([1,2,'fizz',4,'buzz','fizz'], fizzbuzz.fizzbuzz(6))
        self.assertEqual([1,2,'fizz',4,'buzz','fizz',7,8,'fizz','buzz'], fizzbuzz.fizzbuzz(10))
        self.assertEqual([1,2,'fizz',4,'buzz','fizz',7,8,'fizz','buzz',11,'fizz',13,14,'fizzbuzz'], fizzbuzz.fizzbuzz(15))

        test_list = fizzbuzz.fizzbuzz(100)
        for i in range(1,100):
            self.assertEqual(fizzbuzz.fizzbuzz_gen(i), test_list[i-1])
            #if i % 3 == 0 and i % 5 == 0:
            #    self.assertEqual('fizzbuzz', test_list[i-1])
            #elif i % 3 == 0:
            #    self.assertEqual('fizz', test_list[i-1])
            #elif i % 5 == 0:
            #    self.assertEqual('buzz', test_list[i-1])
            #else:
            #    self.assertEqual(i, test_list[i-1])

def run_tests():
    test_suite = unittest.TestLoader().loadTestsFromTestCase(TestFizzBuzz)
    unittest.TextTestRunner(verbosity=2).run(test_suite)

if __name__ == '__main__':
    run_tests()