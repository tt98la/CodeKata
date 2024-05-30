def getList(num):
    ret_list = list()
    
    for i in range(1, num+1):
        ret_list.append(fizzbuzz(i))

    return ret_list

def fizzbuzz(num):
    values = ([15,'fizzbuzz'], [5,'buzz'], [3,'fizz'])
    
    for divisor, fizzbuzz_word in values:
        if num % divisor == 0: return fizzbuzz_word
        
    return num