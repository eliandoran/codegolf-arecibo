encodingChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!#$%&()*+,./:;<=>?@[]^_`{|}~'"

def encodeBase91(nr):
    res = ""
    d = 0
    while nr > 0:
        d, m = divmod(nr, 91)
        res += encodingChars[m]
        nr = d
    res += encodingChars[d]
    return res[::-1]

#!/bin/env python
def main():
    with open("output.txt", "w") as output_file, \
         open("../sample/output.txt", "r") as input_file:

        for line in input_file:
            if line[-1] == "\n":
                line = line[:-1]

            nr = int(line, 2)
            hex_rep = hex(nr)
            encoded = encodeBase91(nr).rjust(5, "A")

            print(line, '{:10} {:10} {}'.format(nr, hex_rep, encoded))
            print(encoded, file=output_file, end='')

    print()

if __name__ == "__main__":
    main()
