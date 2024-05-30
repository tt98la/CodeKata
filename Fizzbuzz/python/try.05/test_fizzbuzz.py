import unittest
import fizzbuzz

class TestFizzBuzz(unittest.TestCase):
    def test_it(self):
        self.assertEqual(1,fizzbuzz.fizzbuzz_gen(1))
        self.assertEqual('fizz',fizzbuzz.fizzbuzz_gen(3))
        self.assertEqual('buzz',fizzbuzz.fizzbuzz_gen(5))
        self.assertEqual('fizz',fizzbuzz.fizzbuzz_gen(6))
        self.assertEqual('buzz',fizzbuzz.fizzbuzz_gen(10))
        self.assertEqual('fizzbuzz',fizzbuzz.fizzbuzz_gen(15))
        self.assertEqual('fizzbuzz',fizzbuzz.fizzbuzz_gen(30))

        test_list = fizzbuzz.fizzbuzz(100)
        for i in range(1, 101):
            self.assertEqual(fizzbuzz.fizzbuzz_gen(i), test_list[i-1])
            

def run_tests():
    test_suite = unittest.TestLoader().loadTestsFromTestCase(TestFizzBuzz)
    unittest.TextTestRunner(verbosity=2).run(test_suite)

if __name__ == '__main__':
    run_tests()