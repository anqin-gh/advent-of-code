#!/usr/bin/env python3
import re

def main():
	with open("input.txt", 'r') as fin:
		with open("parsed_input.txt", 'w') as fout:
			line = fin.readline()
			while line:
				parsed = re.findall(r"\d+", line)
				parsed_line = ' '.join(parsed)
				fout.write(parsed_line + "\n")
				line = fin.readline()


if __name__ == '__main__':
	main()