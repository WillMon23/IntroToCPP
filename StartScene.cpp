#include "StartScene.h"


void StartScene::draw()
{
	std::cout << "Would You Like To Start Application\n";
	std::cout << "Yes(1) or No(2) \n>";
	
}

void StartScene::update()
{
	std::cin >> m_userInput;

	if (m_userInput == '1')
		Engine::getCurrentScene();
	else if (m_userInput == '2')
		Engine::getApplicationShouldClose();
	else
		std::cout << "Invalade Input Please Try Again";
	system("pasue");
	system("cls");
		

}
