#include "HumanPlayer.h"
#include "LADACar.h"
#include "GASelCar.h"

HumanPlayer::HumanPlayer() : Player(HumanPlayer::SelectCar()){

}

Car* HumanPlayer::SelectCar()
{
	cout << "�������� ������:\n1 - ����\n2 - ������" << endl;
	cout << "[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]" << endl;
	
	int ChooseCar = 0;
	cin >> ChooseCar;

	switch (ChooseCar) {
	case 1:
		return new LADACar();
	case 2:
		return new GASelCar();
	default:
		cout << "�����������" << endl;
		SelectCar();
		return 0;
	}
}
