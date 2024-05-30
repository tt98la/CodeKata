def fizzbuzz(num):
    return [fizzbuzz_gen(x) for x in range(1, num + 1)]

def fizzbuzz_gen(num):
    ret_val = ''

    if num % 3 == 0:
        ret_val += 'fizz'
    
    if num % 5 == 0:
        ret_val += 'buzz'

    if ret_val == '':
        ret_val = num

    return ret_val
