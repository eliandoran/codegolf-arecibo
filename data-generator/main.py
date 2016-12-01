#!/bin/env python
def main():
    with open("output.txt", "w") as output_file, \
         open("../sample/output.txt", "r") as input_file:

        for line in input_file:
            if line[-1] == "\n":
                line = line[:-1]

            print(line)

            for startPos in range(0, 23, 6):
                segment = line[startPos:startPos+6]
                nr = int(segment, 2)
                hex_rep = hex(nr)
                ascii_rep = chr(nr + 35)
                print("\tSegment {:7}: {:3} {:5} {} ".format(segment, nr, hex_rep, ascii_rep))
                print(ascii_rep, file=output_file, end='')

    print()

if __name__ == "__main__":
    main()
