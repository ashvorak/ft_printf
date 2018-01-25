int size_char(int bits)
{
	if (bits <= 7)
		return (1);
	else if (bits > 7 && bits <= 11)
		return (2);
	else if (bits > 11 && bits <= 16)
		return (3);
	else
		return (4);
}

