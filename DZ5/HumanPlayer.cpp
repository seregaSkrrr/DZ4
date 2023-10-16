#include "HumanPlayer.h"
#include "LADACar.h"
#include "GASelCar.h"

HumanPlayer::HumanPlayer() : Player(HumanPlayer::SelectCar()){

}

void HumanPlayer::FinishTurn(){
	cout <<"[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]" << endl << endl;
	cout << "�������� ��������: " << endl << "1 - ������� ��� �����\n2 - ������� ��� �������" << endl
		<< "�� 3 �� ������������ �� 90 ��. 8 - ������ �� ������! " << endl;
	cout <<"[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]" << endl << endl;
	int Select;
	cin >> Select;
	switch (Select) {
	case 1:
		GetPlayerCar()->ChangeChassis();
		break;
	case 2:
		GetPlayerCar()->ChangeFuel();
		break;
	default:
		break;
	}
	
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
