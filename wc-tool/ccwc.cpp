#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int get_bytes_size(string file_text)
{
    return size(file_text);
}

int get_lines_count(string file_text)
{
    // return ranges::count(file_text, '\n');
    return count(file_text.begin(), file_text.end(), '\n');
}

int get_words_count(string file_text)
{
    return count(file_text.begin(), file_text.end(), ' ');
}

int main(int argc, const char *argv[])
{
    if (argc <= 2)
    {
        cerr << "Syntax: " << argv[0] << " -c <file name>\n";
        return 1;
    }

    string flag(argv[1]);
    string input_file_path(argv[2]);

    ifstream input_file_stream{input_file_path};
    string input_file_text;
    getline(input_file_stream, input_file_text, '\0');

    if (flag == "-c")
    {
        cout << "\t" << get_bytes_size(input_file_text) << " " << input_file_path << endl;
    }
    else if (flag == "-L")
    {
        cout << "Length of the line containing most bytes" << endl;
    }
    else if (flag == "-l")
    {
        cout << "\t" << get_lines_count(input_file_text) << " " << input_file_path << endl;
    }
    else if (flag == "-m")
    {
        cout << "Number of characters" << endl;
    }
    else if (flag == "-w")
    {
        cout << "\t" << get_words_count(input_file_text) << " " << input_file_path << endl;
    }
    else
    {
        cout << "ccwc: illegal option -- q\nusage : ccwc[-Lclmw][file...]" << endl;
    }

    return 0;
}