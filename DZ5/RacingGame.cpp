#include "RacingGame.h"
#include <math.h>

int RacingGame::GetNextRoadMaximumSpeed() {
	switch (this->_NextRoadType) {
	case RoadType::AsphaltRoad:
		return _NextRoadSpeed;
	case RoadType::MountainRoad:
		return _NextRoadSpeed * 0.4;
	case RoadType::Primer:
		return _NextRoadSpeed * 0.7;
	default:
		GetNextRoadMaximumSpeed();
	}
}

void RacingGame::GenerateNewNextRoadType() {
	this->_NextRoadType = (RoadType)(_Random() % 3);
}

void RacingGame::ShowRoadTypeDescription() {
	switch (_NextRoadType) {
	case RoadType::AsphaltRoad:
		_nextroadtype = "������� 8";
		break;
	case RoadType::MountainRoad:
		_nextroadtype = "������ ������";
		break;
	case RoadType::Primer:
		_nextroadtype = "��������� ������";
		break;
	default:
		_nextroadtype = "����������������";
		break;
	}
	cout << "[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]" << endl;
	cout << "����� �� �����e" << endl;
	cout << "�������� �������� = "<< _NextRoadSpeed << endl;
	cout << "��������� ������: " << _nextroadtype << endl;
	cout << "������������ �������� �� ��������� ������ = " << GetNextRoadMaximumSpeed() << endl;
	cout << "[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]" << endl;

}

void RacingGame::generateNewTrack() {
	this->_NextRoadSpeed = 60 + (trunc(_Random() % 90));
	this->GenerateNewNextRoadType();
}

void RacingGame::StartGame() {

	players = new Player * [2];
	players[0] = new HumanPlayer();
	players[1] = new AIPlayer();

	generateNewTrack();
	ShowRoadTypeDescription();

	for (int counter = 0; counter < 10; counter++) {
		cout << "������� �������� " << endl;
		players[0]->GetPlayerCar()->ShowCarInfo();
		cout << "������� ���������� " << endl;
		players[1]->GetPlayerCar()->ShowCarInfo();

		FinishTurn(players, GetNextRoadMaximumSpeed());
	}
}

void RacingGame::FinishTurn(Player** _players, int NextRoadTypeMaxSpeed) {
	for (int counter = 0; counter < 2; counter++) {
		_players[counter]->GetPlayerCar()->Move(NextRoadTypeMaxSpeed);
	}
}