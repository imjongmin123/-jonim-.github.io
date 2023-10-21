#ifndef DATA_HPP
#define DATA_HPP

struct Data
{
	private:
	int value;
	Data();
	Data(const Data& others);
	Data& operator=(const Data& others);
	public:
	~Data();
	Data(int val);
	int getvalue();
};

#endif
