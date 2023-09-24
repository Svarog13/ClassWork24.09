#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

//void Print(std::vector<int>v)
//{
//	for (int elem : v)
//	{
//		std::cout << elem << " ";
//	}
//	std::cout << std::endl;
//}

struct Time
{
	short h, m, s;
public:
	Time() : h(0),m(0),s(0){}
    Time(short h,short m,short s): h(h),m(m),s(s) {}
};

class Train
{ 
private:

	int number;
	Time departureTime;
    std::string destination;
public:
	Train() :number(0), /*departureTime(),*/ destination("Ukraine station") {}
	Train(int _n, short _h, short _m, short _s, std::string _dest) :number(_n), departureTime(_h, _m, _s), destination(_dest) {}
	Train(int _n, Time _time, std::string _dest) :number(_n), departureTime(_time), destination(_dest) {}
	
	int getNumber()const
	{
		return number;
	}

	void SetTime(Time time)
    {
		departureTime = time;
	}

	friend std::ostream& operator<< (std::ostream& out, Train& train);
	friend std::istream& operator>> (std::istream& in, Train& train);
};

std::ostream& operator<<(std::ostream& out, Train& train)
{
	out << "Train: " << train.number << std::endl;
	out << "Time: " << train.departureTime.h << ":"<< train.departureTime.m <<":"<< train.departureTime.s <<std::endl;
	out << "Destination: " << train.destination << std::endl;
	return out;
}
std::istream& operator >> (std::istream& in, Train& train)
{
	in >> train.number;
	in >> train.departureTime.h >> train.departureTime.m >> train.departureTime.s;
	in >> train.destination;

	return in;
}

class Railway
{
private:
	std::vector<Train> trains;
public:
	
	void AddTrain(Train& train)
	{
		trains.push_back(train);
    }

	void ShowAllTrains()const
	{
		for (Train elem : trains)
		{
			std::cout << elem << " ";
		}
	}

	void ShowTrainInfo(int number)const
	{
		for (Train elem : trains)
		{
			if (number == elem.getNumber())
			{
				std::cout << elem;
			}
		}
	}

	void EditTime(int number)
	{   
		short h, m, s = 0;
		for (Train elem : trains)
		{
			if (number == elem.getNumber())
			{
				std::cout << "Enter hours: ";
				std::cin >> h;
				std::cout << "Enter minutes : ";
				std::cin >> m;
				std::cout << "Enter secundes: ";
				std::cin >> s;
				Time newTime(h, m, s);
				elem.SetTime(newTime);
			}
		}
	}
	void SortTrains()
	{
		std::sort(trains.begin(), trains.end());
	}

};

int main()
{
	


	/*std::vector<int>arr;
	std::vector<int>v = { 1,2,3,4,5,6,7,8,9 };
	std::vector<int>v2 = { 10,20,30,40,50,60,70,80,90 };*/

	//for (size_t i = 0; i < v.size(); i++)
	//{
	//	std::cout << v[i] << " ";
	//}
	//std::cout << std::endl;

	//v.erase(v.begin());
	//Print(v);
	//v.erase(v.end() - 1);
	//Print(v);
	//v.erase(v.begin() + 3);
	//Print(v);
	//v.erase(v.begin(), v.begin() + 2);
	//Print(v);
	//v.insert(v.begin(), v.begin() + 1, v.begin() + 3);
	//Print(v);
	//v[2] = 555;
	//Print(v);
	//v.push_back(12345);
	//Print(v);
	//v.pop_back();
	//Print(v);
	//std::sort(v.begin(), v.end());
	//Print(v);
	//std::reverse(v.begin(), v.end());
	//Print(v);
	///*v.swap(v2);
	//Print(v);*/
	//std::cout << v.front() << std::endl;
	//std::cout << "Size: " << v.size() << std::endl;
	//std::cout << "Capacity : " << v.capacity() << std::endl;
	//v.shrink_to_fit();
	//std::cout << "Capacity : " << v.capacity() << std::endl;
}