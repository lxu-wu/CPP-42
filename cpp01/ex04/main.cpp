# include <iostream>
# include <fstream>

void replace(std::string& str, std::string s1, std::string s2)
{
	size_t	s2_len = s2.length();
	size_t	s1_len = s1.length();
	int pos = -s2_len;

	if (s1_len == 0)
		return ;
	while ((pos = str.find(s1, pos + s2_len)) != -1)
	{
		str.replace(pos, s1_len, s2);
		// std::cout << str << std::endl;
		if (pos > 10)
			break ;
	}
}

int main(int argc, char **argv)
{

	if (argc != 4)
	{
		std::cout << "one filename and two strings. ./replace <file> <s1> <s2>" << std::endl;
		return (1);
	}
	std::string		filename = argv[1];
	std::ifstream	infile(filename);
	if (infile.fail())
	{
		std::cout << "ifstream error: " << filename << "maybe because: file doesn't exist, no permissions" << std::endl;
		return (1);
	}
	else
	{
		std::ofstream	outfile(filename.append(".replace"));
		if (outfile.fail())
		{
			std::cout << "ofstream error" << std::endl;
			return (1);
		}
		std::string		s1 = argv[2], s2 = argv[3];
		std::string 	str;
		while (getline(infile, str))
		{
			replace(str, s1, s2);
			outfile << str << std::endl;
		}
	}
	return (0);
}