
num = input("Enter a number: ")

def int_to_roman(num):
    roman_mapping = {
        1000: 'M',
        900: 'CM',
        500: 'D',
        400: 'CD',
        100: 'C',
        90: 'XC',
        50: 'L',
        40: 'XL',
        10: 'X',
        9: 'IX',
        5: 'V',
        4: 'IV',
        1: 'I'
    }

    roman = ''
    for value in roman_mapping:
        while num >= value:
            roman += roman_mapping[value]
            num -= value
    return roman
print(int_to_roman(int(num)))