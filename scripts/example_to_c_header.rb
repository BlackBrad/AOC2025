#!/bin/ruby

=begin
This script is for generating a header file of the 2025 Advent of
code data that can be imported and built into an executable to be
copied onto the Pi Pico2.
=end

input_file_path = ""
output_file_path = ""

ARGV.each_with_index {
  |arg, index|
  if arg == "-i"
    input_file_path = ARGV[index + 1]
  elsif arg == "-o"
    output_file_path = ARGV[index + 1]
  elsif arg == "-h"
    puts usage_string
  end
}

if input_file_path.length == 0
  abort("An input file is required, please provide -i")
end

if output_file_path.length == 0
  abort("An output file is required, please provide -o")
end

header_file = "
#ifndef __DATA_H\n
#define __DATA_H\n
\n"

string_array = ""
longest_line = 0
File.foreach(input_file_path) do |line|
  string_array << "    \"#{line.strip!}\",\n"
  if longest_line < line.length
    longest_line = line.length
  end
end

header_file << "char data_array[#{longest_line+1}] = {\n"
header_file << string_array
header_file << "};\n"
header_file << "#endif"

File.write(output_file_path, header_file)
