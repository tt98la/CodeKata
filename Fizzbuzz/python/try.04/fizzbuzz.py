def fizzbuzz(num):
    ret_list = list()
    for x in range(1, num + 1):
        ret_list.append(fizzbuzz_gen(x))
    return ret_list

def fizzbuzz_gen(num):
    ret_val = None

    if num % 3 == 0: ret_val = 'fizz'
    if num % 5 == 0: ret_val = 'buzz'
    if num % 15 == 0: ret_val = 'fizzbuzz'
    if ret_val is None: ret_val = num

    return ret_val
