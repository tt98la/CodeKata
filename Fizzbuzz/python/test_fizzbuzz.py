import unittest
import fizzbuzz

class TestFizzBuzz(unittest.TestCase):
    def test_it(self):
        self.assertEqual([1], fizzbuzz.getList(1))
        self.assertEqual([1,2], fizzbuzz.getList(2))
        self.assertEqual([1,2,'fizz'], fizzbuzz.getList(3))
        self.assertEqual([1,2,'fizz',4,'buzz'], fizzbuzz.getList(5))
        self.assertEqual([1,2,'fizz',4,'buzz','fizz'], fizzbuzz.getList(6))
        self.assertEqual([1,2,'fizz',4,'buzz','fizz',7,8,'fizz','buzz'], fizzbuzz.getList(10))
        self.assertEqual([1,2,'fizz',4,'buzz','fizz',7,8,'fizz','buzz',11,'fizz',13,14,'fizzbuzz'], fizzbuzz.getList(15))

        test_list = fizzbuzz.getList(100)
        for i in range(1,101):
            if i % 15 == 0: self.assertEqual('fizzbuzz', test_list[i-1])
            elif i % 5 == 0: self.assertEqual('buzz', test_list[i-1])
            elif i % 3 == 0: self.assertEqual('fizz', test_list[i-1])
            else: self.assertEqual(i, test_list[i-1])

    def test_the_third_is_fizz(self):
        self.assertEqual("fizz", fizzbuzz.getList(3)[-1])

    def test_the_fifth_is_buzz(self):
        self.assertEqual("buzz", fizzbuzz.getList(5)[-1])

    def test_combinations_are_fizzbuzz(self):
        self.assertEqual("fizzbuzz", fizzbuzz.getList(3*5)[-1])

def run_tests():
    test_suite = unittest.TestLoader().loadTestsFromTestCase(TestFizzBuzz)
    unittest.TextTestRunner(verbosity=2).run(test_suite)

if __name__ == '__main__':
    run_tests()