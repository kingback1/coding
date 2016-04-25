//×Ö·û´®·Ö¸î
void SplitString(const std::string& s, vector<int>& v, const std::string& c)
{
	std::string::size_type pos1, pos2;
	pos2 = s.find(c);
	pos1 = 0;
	while (std::string::npos != pos2)
	{
		if (pos1 != pos2)
		{
			v.push_back(atoi((s.substr(pos1, pos2 - pos1)).c_str()));
		}
		
		pos1 = pos2 + c.size();
		pos2 = s.find(c, pos1);
	}

	if (pos1 != s.length())
		v.push_back(atoi((s.substr(pos1)).c_str()));

}