#!/bin/env python
def main():
    with open("output.txt", "w") as output_file, \
         open("../sample/output.txt", "r") as input_file:

        for line in input_file:
            if line[-1] == "\n":
                line = line[:-1]

            nr = int(line, 2)
            hex_rep = hex(nr)

            print(line, '{:10} {}'.format(nr, hex_rep))
            print(hex_rep, file=output_file, end=',')

    print()

if __name__ == "__main__":
    main()
