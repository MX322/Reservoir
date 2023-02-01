#pragma once
class Reservoir
{
private:
	int width;
	int lenth;
	int depth;

public:
	Reservoir();
	Reservoir(int width, int lenth, int depth);
	Reservoir(Reservoir& obj);


	int capacity();
	int area();
	bool IsSea();


	const void SetWidth(int _width);
	const void SetLenth(int _lenth);
	const void SetDepth(int _depth);


	const int GetWidth();
	const int GetLenth();
	const int GetDepth();

	void compare(Reservoir& obj);

};

