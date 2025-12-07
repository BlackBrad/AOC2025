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
\n
#include <stdint.h>\n
\n
const char **get_data();\n
uint64_t get_size();\n
\n
#endif
"

c_file = "
#include \"data.h\"\n
\n
"

getter_function = "
const char **get_data(){\n
    return data;\n
}
"

get_size_function = "
uint64_t get_size(){\n
    return size;\n
}\n
"

string_array = ""
longest_line = 0
line_count = 0
File.foreach(input_file_path) do |line|
  string_array << "    \"#{line.strip!}\",\n"
  line_count = line_count + 1
  if longest_line < line.length
    longest_line = line.length
  end
end

c_file << "const char *data[] = {\n"
c_file << string_array
c_file << "};\n\n"
c_file << getter_function
c_file << "uint64_t size = #{line_count};\n"
c_file << get_size_function

File.write("#{output_file_path}/data.c", c_file)
File.write("#{output_file_path}/data.h", header_file);
