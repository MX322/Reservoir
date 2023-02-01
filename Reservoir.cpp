#include "Reservoir.h"
#include <fstream>
#include <iostream>

Reservoir::Reservoir() = default;

Reservoir::Reservoir(int width, int lenth, int depth)
{
	this->width = width;
	this->lenth = lenth;
	this->depth = depth;
}

Reservoir::Reservoir(Reservoir& obj)
{
	this->width = obj.width;
	this->lenth = obj.lenth;
	this->depth = obj.depth;
}

int Reservoir::capacity()
{
	return width * lenth * depth;
}

int Reservoir::area()
{
	return width * lenth;
}

bool Reservoir::IsSea()
{
	if (depth > 1000)
	{
		return true;
	}

	else
	{
		return false;
	}
}

void Reservoir::compare(Reservoir& obj)
{
	if (this->area() > obj.area())
	{
		std::cout << "Width: " << width << std::endl;
		std::cout << "Lenth: " << lenth << std::endl;
		std::cout << "Depth: " << depth << std::endl;
	}

	else if (this->area() < obj.area())
	{
		std::cout << "Width: " << obj.width << std::endl;
		std::cout << "Lenth: " << obj.lenth << std::endl;
		std::cout << "Depth: " << obj.depth << std::endl;
	}
}

const int Reservoir::GetWidth()
{
	return width;
}

const int Reservoir::GetLenth()
{
	return lenth;
}

const int Reservoir::GetDepth()
{
	return depth;
}


const void Reservoir::SetWidth(int _width)
{
	width = _width;
}

const void Reservoir::SetLenth(int _lenth)
{
	lenth = _lenth;
}

const void Reservoir::SetDepth(int _depth)
{
	depth = _depth;
}


std::ostream& operator<<(std::ostream& ConsoleOut, Reservoir& obj)
{
	ConsoleOut << "Width: " << obj.GetWidth() << std::endl;
	ConsoleOut << "Lenth: " << obj.GetLenth() << std::endl;
	ConsoleOut << "Depth: " << obj.GetDepth() << std::endl;

	return ConsoleOut;
}


std::istream& operator>>(std::istream& ConsoleIn, Reservoir& obj)
{
	int width;
	std::cout << "Width: ";
	ConsoleIn >> width;
	obj.SetWidth(width);

	int lenth;
	std::cout << "Lenth: ";
	ConsoleIn >> lenth;
	obj.SetLenth(lenth);

	int depth;
	std::cout << "Depth: ";
	ConsoleIn >> depth;
	obj.SetDepth(depth);

	return ConsoleIn;
}


void ShowArray(Reservoir* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << std::endl;
	}
}


void WriteInTXT(Reservoir* arr, int size)
{
	std::ofstream out;
	out.open("info.txt");

	if (out.is_open())
	{
		for (int i = 0; i < size; i++)
		{
			out << arr[i] << std::endl;
		}
	}
	out.close();
}


void WriteInBin(Reservoir* arr, int& size)
{
	std::fstream out;
	out.open("info.bin", std::ios::out | std::ios::app | std::ios::binary);

	out.write((char*)arr, size * sizeof(Reservoir));
	out.close();
}


void RemoveFromArr(Reservoir*& arr, int& size)
{
	int element;
	std::cout << "enter element for removing: ";
	std::cin >> element;

	size -= 1;
	Reservoir* tmp = new Reservoir[size];

	int j = 0;
	for (int i = 0; i < size; i++)
	{
		if (element - 1 == i)
		{
			j += 1;
		}

		tmp[i] = arr[j];
	
		j++;
	}

	delete[] arr;
	arr = tmp;
}


void AddToArr(Reservoir*& arr, int& size)
{
	size += 1;
	Reservoir* tmp = new Reservoir[size];

	for (int i = 0; i < size - 1; i++)
	{
		tmp[i] = arr[i];
	}

	std::cin >> tmp[size - 1];
	
	delete[] arr;
	arr = tmp;
}


int main()
{
	int size = 3;
	Reservoir* arr = new Reservoir[size];
	arr[0].SetWidth(100);
	arr[0].SetLenth(400);
	arr[0].SetDepth(90);

	arr[1].SetWidth(230);
	arr[1].SetLenth(410);
	arr[1].SetDepth(110);

	arr[2].SetWidth(400);
	arr[2].SetLenth(760);
	arr[2].SetDepth(390);

}