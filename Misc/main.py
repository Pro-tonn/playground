# Define the array of characters and the target string
char_array = ['m', 'a', 'd', 'u', 'i', 'e', 'r', 's', 'n', 'f', 'o', 't', 'v', 'b', 'y', 'l']
target_string = "sabres"

# Step 1: Generate a list of all characters that, when ANDed with 0xf, map to each letter in "flyers"
def get_possible_chars(target_char):
    # Get the index of the target character in the array
    idx = char_array.index(target_char)
    
    # Now, find all ASCII characters that when ANDed with 0xf give this index
    possible_chars = []
    for i in range(32, 127): # printable ASCII characters
        if i & 0xf == idx:
            possible_chars.append(chr(i))
    return possible_chars

# This will contain lists of possible characters for each character in the target string
all_possible_chars = [get_possible_chars(ch) for ch in target_string]

# Step 2: Try all possible combinations
from itertools import product

for combo in product(*all_possible_chars):
    candidate = "".join(combo)
    
    # Transform the candidate string and check if it matches the target string
    transformed = "".join(char_array[ord(ch) & 0xf] for ch in candidate)
    if transformed == target_string:
        print(f"Found a valid input: {candidate}")
        break
