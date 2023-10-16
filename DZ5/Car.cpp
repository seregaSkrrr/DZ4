#include "Car.h"
void Car::ShowCarInfo() {
	cout << "[][][][][][][][][][][]���������� �� ������[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]" << endl;
	cout << "������ " << _Model << "\nH���� " << _Number << endl;
	cout << "��� ����� " << _Chassis->GetName() << endl;
	cout << "������� " << _Fuel->GetName() << endl;
	cout << "������������ �������� " << _MaxSpeed << endl;
	cout << "����������� ������������ �������� "<<_Chassis->GetMaxSpeedModifier() << endl;
	cout << "������������ ��������� " << _MaxAcceleration << endl;
	cout << "����������� ������������� y�������� �� �������� �������� " << _Fuel->GetLowAccelerationModifier() << endl;
	cout << "����������� ������������� y�������� ����� �������� �������� " << _Fuel->GetHighAccelerationModifier() << endl;
	cout << "�������� �������� " << _Speed << endl;
	cout << "�������� ��������� " << _Acceleration << endl;
	cout << "��������� " << _Distance << endl;
	cout << "[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]" << endl << endl;

}

void Car::Move(int RoadTypeMaxSpeed){

	int CurrentMaxSpeed = _MaxSpeed * _Chassis->GetMaxSpeedModifier();
	int CurrentAcceleration = _Acceleration;

	if (_Speed < _MaxSpeed / 2) {
		CurrentAcceleration = _Acceleration * _Fuel->GetLowAccelerationModifier();
	}
	if (_Speed > _MaxSpeed / 2) {
		CurrentAcceleration = _Acceleration * _Fuel->GetHighAccelerationModifier();
	}

	_Speed += _Acceleration;

	if (_Speed > CurrentMaxSpeed) {
		_Speed = CurrentMaxSpeed;
	}

	if (_Speed > RoadTypeMaxSpeed) {
		_Speed *= 0.25;
	}

	_Distance += _Speed;
}

void Car::ChangeChassis(){
	int NextChassisID = _Random() % 2;
	switch (NextChassisID)
	{
	case 1:
		_Chassis = new Track();
		break;
	case 2:
		_Chassis = new Wheels();
		break;
	default:
		break;
	}
}

void Car::ChangeFuel() {
	int NextFuelID = _Random() % 4;
	switch (NextFuelID)
	{
	case 1:
		_Fuel = new Petrol();
		break;
	case 2:
		_Fuel = new Diesel();
		break;
	case 3:
		_Fuel = new Thermonuclear();
		break;
	case 4:
		_Fuel = new Nuclear();
		break;
	default:
		break;
	}
}

int Car::GetDistance()
{
	return _Distance;
}

Car::Car(string model, string number, Chassis* chassis, Fuel* fuel) {
	_Fuel = fuel;
	_Chassis = chassis;
	_Number = number;
	_Model = model;

	_Speed = 0;
	_Acceleration = 10;
	_MaxSpeed = 60 + (_Random() % 90);
	_MaxAcceleration = 20 + (_Random() % 90);
	_Distance = 0;
}

string Car::GenerateNumber() {
	random_device _Random;
	string number = "A00AA0000";
	number[0] = CreateRandomLetter(_Random);
	number[1] = CreateRandomDigit(_Random);
	number[2] = CreateRandomDigit(_Random);
	number[3] = CreateRandomDigit(_Random);
	number[4] = CreateRandomLetter(_Random);
	number[5] = CreateRandomLetter(_Random);
	number[6] = CreateRandomDigit(_Random);
	number[7] = CreateRandomDigit(_Random);
	number[8] = CreateRandomDigit(_Random);
	return number;
}

unsigned int Car::CreateRandomDigit(random_device& randomizer)
{
	return "0"[0] + randomizer() % 10;
}

unsigned int Car::CreateRandomLetter(random_device& randomizer)
{
	return "�"[0] + randomizer() % 32;
}