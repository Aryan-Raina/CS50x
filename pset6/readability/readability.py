from cs50 import get_string


# Declaring All the main vars
text = get_string("Text: ")
letters = 0
words = len(text.split(" "))
textcpy = text.replace("?", ".")
textcpy = textcpy.replace("!", ".")
sentences = len(textcpy.split(".")) - 1

# Counts alphabets
for c in text:
    if c.isalpha():
        letters += 1

# Gets the L and S of the index Calc        
L = 100 * float(letters) / float(words)
S = 100 * float(sentences) / float(words)

# Index Calc
index = (0.0588 * L) - (0.296 * S) - 15.8

# Conditions
if index > 16:
    print("Grade 16+")
elif index < 1:
    print("Before Grade 1")
else:
    print(f"Grade {round(index)}")
