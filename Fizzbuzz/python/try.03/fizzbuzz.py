def fizzbuzz(num):
    return [fizzbuzz_gen(x) for x in range(1, num + 1)]

def fizzbuzz_gen(num):
    ret_val = None

    if num % 3 == 0: ret_val = 'fizz'
    if num % 5 == 0: ret_val = 'buzz'
    if num % 15 == 0: ret_val = 'fizzbuzz'
    if ret_val is None: ret_val = num

    return ret_val
